#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
template <typename T>
void split(const std::string &s,char delim, T result){
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while(std::getline(ss,item,delim)){
        if(item.empty())continue;//跳过空字符串，也可以选择不跳
        *(result++)=item;
    }
}
std::vector<std::string>split(const std::string &s,char delim){
    std::vector<std::string> elems;
    split(s,delim,std::back_inserter(elems));
    return elems;
}
int main(){
    
    {
        std::string s("Somewhere down the road");
        std::istringstream iss(s);

        do{
            std::string sub;
            iss>>sub;
            std::cout<<"Substring: "<<sub<<std::endl;
        }while(iss);
    }
    {
        //When reading characters, std::istream_iterator skips whitespace by default 
        //(unless disabled with std::noskipws or equivalent),
        // while std::istreambuf_iterator does not. In addition, std::istreambuf_iterator is more efficient,
        // since it avoids the overhead of constructing and destructing the sentry object once per character.
        using namespace std;
        string sentence="And I feel fine...";
        istringstream iss(sentence);
        copy(istream_iterator<string>(iss),
            istream_iterator<string>(),
            ostream_iterator<string>(cout,"\n"));
    }
    {
        using namespace std;
        string sentence="So many ways to deal with it...";
        istringstream iss(sentence);
        vector<string> tokens;
        copy(istream_iterator<string>(iss),
        istream_iterator<string>(),
        back_inserter(tokens));
        for(auto i:tokens){
            cout<<i<<endl;
        }
        //for(auto i:tokens2){
        //    cout<<i<<endl;
       // }
    }
    {
        using namespace std;
        string sentence="So many ways to deal with it...";
        istringstream iss(sentence);
        vector<string> tokens{istream_iterator<string>{iss},
                      istream_iterator<string>{}};
        for(auto i:tokens){
            cout<<i<<endl;
        }
    }
    // functions above can not support specify our own delimers
    // so this comes out
    {
        using std::string;
        using std::stringstream;
        using std::vector;
        
        vector<string> x = split(":hahahah:one:two::three", ':');
        for(auto i:x){
            std::cout<<i<<std::endl;
        }
    }
    return 0;
}