#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class DebugDelete{
public:
    DebugDelete(std::ostream &s=std::cerr):os(s){}
    static int ct;
    template <typename T> 
    void operator() (T *p) const{
        os<<"deleting ptr "<<ct++<<std::endl;
        delete p;
    }
private:
    std::ostream &os;
};
int DebugDelete::ct=0;
class QueryResult;
class TextQuery{
public:
    using line_no=vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&)const;
private:
    shared_ptr<vector<string>>file;
    map<string,shared_ptr<set<line_no>>>wm;
};
TextQuery::TextQuery(ifstream &is): file(new vector<string>,DebugDelete()){
    string text;
    while(getline(is,text)){
        file->push_back(text);
        int n=file->size()-1;
        istringstream line(text);
        string word;
        while(line>>word){
            auto &lines=wm[word];
            // reset the shared_ptr, hand it a fresh instance of Foo
            // (the old instance will be destroyed after this call)
            if(!lines)lines.reset(new set<line_no>,DebugDelete());
            lines->insert(n);
        }
    }
    //cout<<file->size()<<endl;
    //cout<<wm.size()<<endl;
    // for(auto i:wm){
    //     cout<<i.first<<endl;
    // }
}
    

class QueryResult{
    friend ostream& print(ostream&,const QueryResult&);
public:
    using line_no=vector<string>::size_type;
    QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>>f):
    sought(s),lines(p),file(f){ }
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>>file;
};
QueryResult TextQuery::query(const string &sought)const{
    static shared_ptr<set<line_no>> nodata(new set<line_no>,DebugDelete());
    auto loc = wm.find(sought);// 在map 中使用find 而不是使用下标来查找，防止误添加！
    if(loc==wm.end()){
        return QueryResult(sought,nodata,file);
    }
    else
        return QueryResult(sought,loc->second,file);
}
string make_plural(size_t ctr,const string &word,const string &ending){
    return (ctr>1)?word+ending:word;
}
ostream& print(ostream & os,const QueryResult &qr){
    os<<qr.sought<<"occurs"<<qr.lines->size()<<" "<<make_plural(qr.lines->size(),"time","s")<<endl;
    for(auto num:*qr.lines)
        os<<"\t(line "<<num+1<<")"<<*(qr.file->begin()+num)<<endl;
    return os;
}

void runQueries(ifstream &infile){
    TextQuery tq(infile);
    while(1){
        cout<<"enter word to look for,or q to quit: ";
        string s;
        if(!(cin>>s)||s=="q")break;
        print(cout,tq.query(s))<<endl;
    }
}
int main(){
    ifstream ifs("blob.cpp",std::ios::in);//这个文件选的太垃圾了，没几个普通单词，全是带符号的
    if(!ifs.is_open())cout<<"failed to open"<<endl;
    runQueries(ifs);
    return 0;
}