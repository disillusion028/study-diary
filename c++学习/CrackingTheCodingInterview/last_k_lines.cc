//title : Write a method to print the last K lines of an input file using C++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class PrintKLines{
public:
    PrintKLines(string _filename,int _K):filename(_filename),K(_K){
    }
    int print(){
        ifstream ifs(this->filename);
        if(!ifs.is_open()){
            cout<<"error open"<<endl;
            return -1;
        }
        string str;
        int k=this->K;
        vector<string> vecstr(k);
        int i=0;
        while(getline(ifs,str)){
            vecstr[(i++)%k]=str;
        }
        if(i<k){
            k=i;
        }
        for(int j=0;j<k;j++){
            cout<<vecstr[(i+j)%k]<<endl;
        }
        cout<<"sz of str"<<sizeof(vecstr)<<endl;
        return 0;
    }
private:
    string filename;
    int K;    
};
int main(){
    PrintKLines PK("/home/caoqi/testvalues.txt",10);
    PK.print();
    return 0;
}
