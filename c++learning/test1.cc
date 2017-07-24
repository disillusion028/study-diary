#include "iostream"  
#include "vector"  
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <string>
#include <set>
#include <climits>
#include <initializer_list>
#include <utility>
#include <cassert>
#include <cmath>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;  
// void fun(char *s, int a, double f)
// {
//     FILE * fp;
//     char str[100], str1[100], str2[100], str3[100];
//     int a1; double f1;
//     fp = fopen("filel.txt", "w");
//     fprintf(fp, "%s%d%f\n", s, a, f);

//     fclose(fp) ;
//     fp = fopen("file1.txt", "r");

//     fscanf( fp , "%s%s%s", str, str1, str2);
//     fclose(fp);
//     a1 = atoi(str1);
//     f1 = atof(str2);
//     printf ("\nThe result :\n\n% s % d %f\n", str , a1, f1);
// }  
// int main(void)  
// {  
//     vector<int>array;  
//     array.push_back(100);  
//     array.push_back(300);  
//     array.push_back(300);  
//     array.push_back(500);  
//     vector<int>::iterator itor;  
//     for(itor=array.begin();itor!=array.end();itor++)  
//     {  
//         if(*itor==300)  
//         {  
//             itor = array.erase(itor);  
//         }  
//     }  
//     for(itor=array.begin();itor!=array.end();itor++)  
//     {  
//         cout<<*itor<<" ";  
//     }  
//     return 0;  
// }
// class A{
//     public:
//     void test(){printf("test A");}
// };
// int main(){
//     A*pA=NULL;
//     pA->test();
// return 0;
// }
// int main()
// {
//     char*a[]={"work","at","alibaba"};
//     char**pa=a;
//     pa++;
//     printf("%s",*pa);
//     return 0;
// }
// class Solution {
// public:
//     bool Findline(int target,vector<int>&line){
//         if(line.empty())return false;
//         if(target<line.front()||target>line.back())return false;
//         int sz=line.size();
//        	int begin=0,end=sz-1;
//         int mid;
//         while(begin<end){
//             mid=begin+(end-begin)/2;
//             if(target==line[mid])return true;
//             if(target<line[mid]){
//                 end=mid;
// 			}
//             else{
//                 begin=mid+1;
// 			}
// 		}
//         return false;
// 	}
//     bool Find(int target, vector<vector<int> > array) {
//         if(array.empty())return false;
//         int sz=array.size();
//         int i;
//         for(i=0;i<sz;i++){
//             if(array[i].back()>target)
//                 break;
// 		}
//         for(;i<sz;i++){
//             if(Findline(target,array[i]))
//                 return true;
//             if(array[i].front()>target)
//                 break;
// 		}
//         return false;
//     }
// };
// int main(){
//     vector<vector<int> >v;
//     v.push_back({1,2,8,9});
//     v.push_back({2,4,9,12});
//     v.push_back({4,7,10,13});
//     v.push_back({6,8,11,15});
    
//     Solution a;
//     cout<<a.Find(15,v)<<endl;
//     return 0;
// }

// void replaceSpace(char *str,int length) {
//     string s(str);
//     string res;
//     int sz=s.length();
//     int b=0;
//     for(int i=0;i<sz;i++){
//         if(s[i]==' '){
//             res+=s.substr(b,i-b)+"%20";
//             b=i+1;
//         }
//     }
//     if(b!=sz)res+=s.substr(b);
//     strcpy(str,const_cast<char*>(res.c_str()));
// }
// int main(){
//     char str[50]="hello world ";
//     replaceSpace(str,strlen(str));
//     cout<<str<<endl;
// }
// #include <iostream>
// int main( )
// {
// char s[]="123",*p;
// p=s;
// cout<<*p++<<endl;
// return 0;
// }
// class Solution {
// public:
//     int minNumberInRotateArray(vector<int> rotateArray) {
//         if(rotateArray.empty())return -1;
//         int b=0,e=rotateArray.size()-1,m;
//         while(b<e){
//             m=b+(e-b)/2;
//             if(b+1==e){
//                 return min(rotateArray[b],rotateArray[e]);
//             }
//             if(rotateArray[m]>rotateArray[e]){
//                 b=m;
//                 continue;
//             }
//             if(rotateArray[m]<rotateArray[b]){
//                 e=m;
//                 continue;
//             }
//             return rotateArray.front();
            
//         }
//         return rotateArray[m];
//     }
// };
// int main(){
//     Solution S;
//     vector <int> t={6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335};
//     cout<<S.minNumberInRotateArray(t)<<endl;
//     return 0;
// }
// class Solution {
// public:
//     void push(int value) {
//         mymap[value]++;
//         mystack.push(value);
//     }
//     void pop() {
//         int x=mystack.top();
//         mystack.pop();
//         mymap[x]--;
//     }
//     int top() {
//         return mystack.top();
//     }
//     int min() {
//         return mymap.begin()->first;
//     }
// private:
//     stack<int> mystack;
//     map<int,int> mymap;
// };
// struct TreeNode {
// 	int val;
// 	struct TreeNode *left;
// 	struct TreeNode *right;
// 	TreeNode(int x) :
// 			val(x), left(NULL), right(NULL) {
// 	}
// };
// class Solution {
// public:
//     vector<int> PrintFromTopToBottom(TreeNode* root) {
// 		vector<int> ret;
//         vector<TreeNode*> v;
//         if(root==nullptr)return ret;
//         v.push_back(root);
//         while(!v.empty()){
//             vector<TreeNode*> t;
//             for(auto &&i:v){
//                 if(i->)
//             }
//         }
//     }
// };

// class Solution {
// public:
//     bool VerifySquenceOfBST(vector<int> sequence) {
// 		return foo(sequence,0,sequence.size());
//     }
//     bool foo(vector<int> &sequence,int be,int ed){
//         if(be>=ed)return true;
//         vector<int> v(sequence.begin()+be,sequence.begin()+ed);
//  		if(v.size()==1)return true;
//         sort(v.begin(),v.end());
//         int x=sequence[ed-1];
//         cout<<"x: "<<x<<endl;
//         int ord=getOrder(v,x);
//         cout<<"ord: "<<ord<<endl;
//         if(ord==-1)return false;
//         vector<int>left(sequence.begin()+be,sequence.begin()+be+ord);
//         cout<<"left: ";
//         for(auto i:left){
//             cout<<i<<" ";
//         }
//         cout<<endl;
        
//         vector<int>right(sequence.begin()+be+ord,sequence.begin()+ed-1);
//         cout<<"right: ";
//         for(auto i:right){
//             cout<<i<<" ";
//         }
        
//         cout<<endl;
//         for(int i=0;i<left.size();i++){
//             if(left[i]>=x)return false;
//         }
//         for(int i=0;i<right.size();i++){
//             if(right[i]<=x)return false;
//         }
//         return foo(sequence,be,be+ord)&&foo(sequence,be+ord,ed-1);
//     }
//     int getOrder(vector<int>& vec,int x){
//         //binary search
//         for(auto i:vec){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//         int sz=vec.size();
//         int e=sz-1;
//         int b=0,m;
//         while(b<=e){
//             m=b+(e-b)/2;
//             if(vec[m]==x)return m;
//             if(vec[m]>x){
//                 e=m-1;
//             }else{
//                 b=m+1;
// 			}
//         }
//         return -1;
//     }
// };
// int main(){
//     vector<int> test={4,6,7,5};
//     Solution s;
//     cout<<s.VerifySquenceOfBST(test)<<endl;
//     return 0;
// }

// class Solution {
// public:
//     vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//         int sz=input.size();
//         if(k>sz)return vector<int>();
//         vector<int>v(input.begin(),input.begin()+k);
//         make_heap(v.begin(),v.end());
//         pop_heap(v.begin(),v.end());
//         for(int i=k;i<sz;i++){
//             if(input[i]<v.back()){
//                 v.pop_back();
//                 v.push_back(input[i]);
//                 push_heap(v.begin(),v.end());
//                 pop_heap(v.begin(),v.end());
//             }
//         }
//         sort(v.begin(),v.end());
//         return v;
//     }
// };
// int main(){
//     vector<int> a={1,8,3,45,6,32,4,6,1};
//     Solution S;
//     vector<int> x=S.GetLeastNumbers_Solution(a,4);
//     for(auto i:x){
//         cout<<i<<endl;
//     }
//     return 0;
// }

// class Solution {
// public:
//     string PrintMinNumber(vector<int> numbers) {
//         sort(numbers.begin(),numbers.end(),[](int a,int b){
//             if(a==b)return false;
//             string s=to_string(a);
//             string t=to_string(b);
//             int sz1=s.length();
//             int sz2=t.length();
//             int sz=sz1<sz2?sz1:sz2;
//             int i;
//             char x;
//             for(i=0;i<sz;i++){
//                 if(s[i]<t[i])return true;
//                 if(s[i]>t[i])return false;
//                 x=s[i];
//             }
//             if(i<sz1){
//                 for(;i<sz1;i++){
//                     if(x>s[i])return true;
//                     else if(x<s[i])return false;
//                 }
//                 return false;
//             }
//             else if(i<sz2){
//                 for(;i<sz2;i++){
//                     if(x>t[i])return false;
//                     else if(x<t[i])return true;
//                 }
//                 return true;
//             }
//             return false;
//         });
//         string res;
//         for(auto &&i:numbers){
//             res+=to_string(i);
//         }
//         return res;
//     }
// };
// int main(){
//     vector<int> v={3,33,321,21};
//     Solution S;
//     string str=S.PrintMinNumber(v);
//     cout<<str<<endl;
//     return 0;
// }
// #pragma pack(2)
// class BU
// {
//     public:
//     int number;
//     union UBffer
//     {
//         char buffer[13];
//         int number;
//     }ubuf;
//     void foo(){}
//     typedef char*(*f)(void*);
//     enum{hdd,ssd,blueray}disk;
// }bu;
// int main(){
//     cout<<sizeof(bu)<<endl;
//     cout<<sizeof(bu.disk)<<endl;
//     return 0;
//}
// class Solution {
// public:
//     vector<vector<int> > FindContinuousSequence(int sum) {
//         vector<vector<int> > res;
//         if(sum==0)return res;
//         vector<int> v;
//         int r=1;
//         int s=0;
//         while(1){
//             if(r>sum+1)break;
//             if(s==sum){
//                 res.push_back(v);
//                 s-=v.front();
//                 v.erase(v.begin());
//             }
//             else if(s>sum){
//                 s-=v.front();
//                 v.erase(v.begin());
//             }
//             else{
//                 v.push_back(r);
//                 s+=r;
//                 r++;
//             }
//         }
//         return res;
//     }
// };
// int main(){
//     Solution S;
//     vector<vector<int> > v=S.FindContinuousSequence(0x7ff3);
//     for(auto i:v){
//         for(auto j:i){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }
// class Solution {
// public:
//     vector<int> FindNumbersWithSum(vector<int> array,int sum) {
//          vector<vector<int>> res;
//         set<int> s;
//         sort(array.begin(),array.end());
//         for(auto &&i:array){
//             if(s.count(sum-i)){
//             	res.push_back({sum-i,i});
//         	}
//             s.insert(i);
//         }
//     	return res.back();
//     }
// };
// int main(){
//     vector<int> a={2,4,6,6,5,7,4,9,3,7,8,11,1};
//     Solution S;
//     vector<int> m=S.FindNumbersWithSum(a,12);
//     for(auto i:m){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     return 0;
// }
// class Solution {
// public:
//     string ReverseSentence(string str) {
//         int sz=str.length();
//         string res;
//         string t;
//         for(int i=sz-1;i>=0;i--){
//             if(str[i]==' '){
//                 res=res+t+" ";
//                 t="";
//             }
//             else{
//                 t=str[i]+t;
//             }
// 		}
//         if(!t.empty()){
//             res=res+t;
//         }
//         return res;
//     }
// };
// int main(){
//     string x="student. a am I";
//     Solution S;
//     string y=S.ReverseSentence(x);
//     cout<<y<<endl;
//     cout<<y.size()<<endl;
//     return 0;
// }
// class Solution {
// public:
//     int LastRemaining_Solution(int n, int m)
//     {
//         set<int> S;
//         for(int i=0;i<n;i++){
//             S.insert(i);
//         }
//         int r=0;
//         int x=0;
//         auto a=S.begin();
//        	while(!S.empty()){
//             if(x==m-1){
//                 r=*a;
//                 a=S.erase(a);
//                 x=0;
//             }
//             else{ 
//                 x++;
//                 a++;
//             }
//             if(a==S.end()){
//                 a=S.begin();
//             }
//         }
//         return r;
//     }
// };
// int main(){
//     Solution P;
//     cout<<P.LastRemaining_Solution(100,1)<<endl;
//     return 0;
// }
// class Solution {
// public:
//     int Add(int num1, int num2)
//     {
//         int res=0;
//         __asm__(
//             "addl %1, %2\n\t"
//             "movl %2, %0\n\t"
//             : "=a"(res)
//             : "r"(num1), "r"(num2)
//         );
//         return res;
//     }
// };
// class Solution
// {
// public:
//   //Insert one char from stringstream
//     void Insert(char ch)
//     {
//         if(!ex.count(ch)){
//             ex.insert(ch);
//             if(myset.count(ch)){
//                 myset.erase(ch);
//             }
//         }
//         if(!myset.empty())
//         	res=*(myset.begin());
//     }
//   //return the first appearence once char in current stringstream
//     char FirstAppearingOnce()
//     {
//     	if(myset.empty())return '#';
//         else return res;
//     }
// 	char res='#';
// 	set<char> myset;
//     set<char> ex;
// };
// int main(){
//     Solution S;

// }
// class Solution {
// public:
//     vector<int> maxInWindows(const vector<int>& num, unsigned int size)
//     {
//         multiset<int> window;
//         vector<int> ret;
//         int sz=num.size();
//         for (int i = 0; i < sz; i++) {
//             window.insert(num[i]);
//             if (window.size() < size)  continue;
//             int sm=INT_MIN;
//             for(auto x=window.begin();x!=window.end();x++){
//                 sm=max(*x,sm);
//             }
//             ret.push_back(sm);
//             window.erase(window.find(num[i-size+1]));
//         }
//         return ret;
//     }
// };
// int main(){
//     Solution S;
//     vector<int> v={2,3,4,2,6,2,5,1};
//     vector<int> res=S.maxInWindows(v,3);
//     for(auto i:res){
//         cout<<i<<endl;
//     }
//     return 0;
// }
// class Solution {
// public:
//     int movingCount(int threshold, int rows, int cols)
//     {
//         count=0;
//         vector<vector<bool> > *isGone=new vector<vector<bool> >(rows,vector<bool>(cols));
//         dfs(threshold,0,0,rows,cols,*isGone);
//         delete (isGone);
//         return count;
//     }
//     bool canGo(int k,int x,int y,int m,int n,vector<vector<bool> > &v){
//         if(x<0||y<0)return false;
//         if(x>=m||y>=n)return false;
//         if(v[x][y]==false){
//             v[x][y]=true;
//         }
//         else return false;
//         int a=0,b=0;
//         while(x){
//             a+=x%10;
//             x=x/10;
//         }
//         while(y){
//             b+=y%10;
//             y=y/10;
//         }
//         if(a+b<=k)return true;
//         else return false;
//     }
//     void dfs(int k,int x,int y,int rows,int cols,vector<vector<bool> > &v){
//         if(canGo(k,x,y,rows,cols,v)){

//             count++;
//             dfs(k,x+1,y,rows,cols,v);
//             dfs(k,x-1,y,rows,cols,v);
//             dfs(k,x,y+1,rows,cols,v);
//             dfs(k,x,y-1,rows,cols,v);
//         }
//     }
//     int count;
// };
// int main(){
//     Solution S;
//     cout<<S.movingCount(30,1000,1002)<<endl;
//     //cout<<S.canGo(18,2,3,6,6)<<endl;
//     return 0;
// }
// class Solution {
// public:
//     bool hasPath(char* matrix, int rows, int cols, char* str) {
//         int sz=strlen(matrix);
//         vector<int> flag = vector<int>(sz+1);
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 if (helper(matrix, rows, cols, i, j, str, 0, flag)){
//                     return true;
//                 }
//                 vector<int>(sz+1).swap(flag);
//             }
//         }
//         return false;
//     }
//     bool helper(char* matrix, int rows, int cols, int i, int j, char* str, int k, vector<int>& flag) {
//         int index = i * cols + j;
//         if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == 1)
//             return false;
//         if(k == strlen(str) - 1) return true;
//         flag[index] = 1;
//         if (helper(matrix, rows, cols, i - 1, j, str, k + 1, flag)
//                 || helper(matrix, rows, cols, i + 1, j, str, k + 1, flag)
//                 || helper(matrix, rows, cols, i, j - 1, str, k + 1, flag)
//                 || helper(matrix, rows, cols, i, j + 1, str, k + 1, flag)) {
//                 return true;
//         }
//         flag[index] = 0;
//         return false;
//     }
// };
// int main(){
//     char m[]="ABCESFCSADEE";
//     char s[]="ABCCED";
//     Solution Sol;
//     cout<<Sol.hasPath(m,3,4,s)<<endl;
//     return 0;
// }

// class Solution {
// public:
//     vector<string> Permutation(string str) {
//         vector<string> res;
//         if(str.empty())return res;
//         sort(str.begin(),str.end());
//         int sz=str.size();
//         vector<bool> isUsed(sz,false);
//         string t;
//         dfs(isUsed,sz,res,str,t);
//         return res;
//     }
//     void dfs(vector<bool> &isUsed,int sz,vector<string>&res,string &str,string &t){
//         if(t.size()==sz){
//             res.push_back(t);
//             return;
//         }
//         for(int i=0;i<str.size();i++){
//             if(!isUsed[i]){
//                 isUsed[i]=true;
//                 t+=str[i];
//                 dfs(isUsed,sz,res,str,t);
//                 t.pop_back();
//                 isUsed[i]=false;
//             }
//         }
//     }
// };
// int main(){
//     // Solution S;
//     // vector<string> r=S.Permutation(string("aaa"));
//     // auto last=unique(r.begin(),r.end());
//     // r.erase(last,r.end());
//     // for(auto i: r){
//     //     cout<<i<<endl;
//     // }
//     // cout<<r.size()<<endl;
//     vector<int> t={1,1,1,1,1,1};
//     //prev_permutation(t.begin(),t.end());
//     for(int i=0;i<100;i++)t.push_back(i);
//     cout<<t.capacity()<<endl;
//     while(!t.empty()){
//         t.pop_back();
//         cout<<t.capacity()<<"  ";
//     }
//     int a=100000;
//     while(a--)t.pop_back();
//     t.push_back(1);
//     return 0;
// }
// int main(){
//     string str("psafsfagaeqwdfzds sadzx");
//     cout<<count(str.begin(),str.end(),'s');
//     return 0;
// }
// template<unsigned n>
// struct Factorial{
//     enum{value=n*Factorial<n-1>::value};
// };
// template<>
// struct Factorial<0>{
//     enum{value=1};
// };
// enum Days { Saturday,Sunday,Tuesday,Wednesday,Thursday,Friday};
// class e{};
// int main(){
//     Days day = Days::Saturday;
//     if(day == Days::Saturday)
//         cout<<"bingo"<<endl;
    // cout<<sizeof(e)<<endl;
//    std::cout<<Factorial<5>::value<<endl;
//    std::cout<<Factorial<10>::value<<endl;
//  void func(){   
//     enum color{ red=1, blue=20, yellow};
//     int x=red;
//  }
//     cout<< sizeof(color)<<endl;
//     cout<<sizeof(yellow)<<endl;
//     return 0;
// }
// class Singleton1{
// public:
//     static Singleton1 * getInstance(){
//         if(instance==nullptr){
//             instance=new Singleton1();
//         }
//         return instance;
//     }
// protected:
//     Singleton1(){
        
//     }
// private:    static Singleton1 *instance;
// };
// Singleton1* Singleton1::instance=nullptr;

// void fun(initializer_list<pair<string, int>> initp){
// 	for (auto &it : initp)
// 	{
// 		cout << "pair..fisrt:" << it.first << "\nsecond.." << it.second << endl;
// 	}
// }


// int main(){
// 	int a[]{1, 2, 3, 5};
// 	fun({ { "liu", 2 }, { "feng", 3 } });
// 	return 0;
// }
// class OnlyStack{
// private:
//     void *operator new(size_t t){};
//     void operator delete(void *ptr){}; 
// public:
//     OnlyStack(){};
//     ~OnlyStack(){};
// };
// #if 1
// class OnlyHeap{
// protected:
//     ~OnlyHeap(){};
// public:
//     OnlyHeap(){};
//     void Destory(){delete this;}
// };
// #endif
// #if 0
// class OnlyHeap{
// protected:
//     ~OnlyHeap(){}
//     OnlyHeap(){}
// public:
//     static OnlyHeap* Create(){
//         return new OnlyHeap();
//     }
//     void Destory(){
//         delete this;
//     }
// };
// #endif
// int main(){
//     //OnlyHeap* a=OnlyHeap::Create();
//     OnlyHeap *a=new OnlyHeap();
//     a->Destory();
//     OnlyStack b;
//     //OnlyStack *c=new OnlyStack();
//     return 0;
// }
// class A{
// public:
// 	A(int _x){
// 		this->x=_x;
// 		cout<<"inital cons"<<endl;
// 	}
// //private:
// 	A(const A &a):x(a.x){
// 		cout<<"copy constructor"<<endl;
// 	}
// 	A(A&& a):x(a.x){
// 		cout<<"right value constructor"<<endl;
// 	}
// 	A& operator=(const A& a){
// 		cout<<"operator ="<<endl;
// 		if(this==&a){
// 			return *this;// useless in this situation
// 		}
// 		else{
// 			this->x=a.x;
// 			return *this;
// 		}
// 	}
// 	A operator+(const A &a1){
// 		A t(*this);
// 		t.x+=a1.x;
// 		return t;
// 	}
// 	A& operator+=(const A &a){
// 		this->x+=a.x;
// 		return *this;
// 	}
// 	int x;
// };
// int main(){
// 	A a1(3);
// 	A a2(5);
// //	A a3(a1+a2);
// 	cout<<a1.x<<endl;
// 	A a3(a2);
// 	cout<<a3.x<<endl;
// 	A a4(std::move(a1));
// 	// cout<<&(a4.x)<<endl;
// 	// cout<<&(a1.x)<<endl;
// 	//A a5=a2;//copy
// 	a3=a2;
// 	A a5=a1+a2;
// 	cout<<a5.x<<endl;
// 	a5+=a3;
// 	cout<<a5.x<<endl;
// 	return 0;
// }
/*
如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
{1, 2, 1}, {15, 78, 78, 15} , {112} 是回文序列, 
{1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} 不是回文序列。
现在给出一个数字序列，允许使用一种转换操作：
选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。

输入描述:
输入为两行，第一行为序列长度n ( 1 ≤ n ≤ 50)
第二行为序列中的n个整数item[i]  (1 ≤ iteam[i] ≤ 1000)，以空格分隔。


输出描述:
输出一个数，表示最少需要的转换次数

输入例子1:
4
1 1 1 3

输出例子1:
2
*/
// int main(){
// 	int n,t,x;
// 	cin>>n;
// 	x=n;
// 	assert(n>=0);
// 	if(n==0){
// 		cout<<0<<endl;
// 		return 0;		
// 	}
// 	vector<int> vec;
// 	while(x--){
// 		cin>>t;
// 		vec.push_back(t);
// 	}
// 	int start=0,end=n-1;
// 	x=0;
// 	while(start<=end){
// 		if(start==end){
// 			break;
// 		}
// 		while(vec[start]>vec[end]){
// 			vec[end-1]+=vec[end];
// 			end--;
// 			x++;
// 		}
// 		while(vec[start]<vec[end]){
// 			vec[start+1]+=vec[start];
// 			start++;
// 			x++;
// 		}
// 		if(vec[start]==vec[end]&&start!=end){
// 			start++;
// 			end--;
// 		}
// 	}
// 	cout<<x<<endl;
// 	return 0;
// }
/*
[编程题] 优雅的点
时间限制：1秒
空间限制：32768K
小易有一个圆心在坐标原点的圆，小易知道圆的半径的平方。小易认为在圆上的点而且横纵坐标都是整数的点是优雅的，小易现在想寻找一个算法计算出优雅的点的个数，请你来帮帮他。
例如：半径的平方如果为25
优雅的点就有：(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)，一共12个点。 
输入描述:
输入为一个整数，即为圆半径的平方,范围在32位int范围内。


输出描述:
输出为一个整数，即为优雅的点的个数

输入例子1:
25

输出例子1:
12
*/
// int main(){
// 	int n;
// 	cin>>n;
// 	int s=n;
// 	n=sqrt(n);
// 	//cout<<n;
// 	int start=-n;
// 	int end=n;
// 	int res=0;
// 	for(int i=start;i<=end;i++){
// 		int t=s-i*i;
// 		int t1=sqrt(t);
// 		if(t1*t1==t){
// 			res++;
// 			if(t1!=0)res++;
// 		}
// 	}
// 	cout<<res<<endl;
// 	return 0;
// }
//
/*
[编程题] 跳石板
时间限制：1秒
空间限制：32768K
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板 
输入描述:
输入为一行，有两个整数N，M，以空格隔开。
(4 ≤ N ≤ 100000)
(N ≤ M ≤ 100000)


输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1

输入例子1:
4 24

输出例子1:
5
*/
// int main(){
// 	int n=0,m=0;
// 	cin>>n>>m;
// 	if(m<n){
// 		cout<<-1<<endl;
// 		return 0;
// 	}
// 	if(m==n){
// 		cout<<0<<endl;
// 		return 0;
// 	}	 

// 	vector<int> vec(m+1,0x7fffffff);
// 	vec[n]=0;
// 	int t=1;
// 	for(int i=n;i<=m;i++){
// 		if(vec[i]==0x7fffffff)continue;
// 		t=1;
// 		for(int j=2;j*j<=i;j++){
// 			if(i%j)continue;
// 			if(i+j<=m&&vec[i+j]>vec[i]+1)vec[i+j]=vec[i]+1;
// 			if (i + i / j <= m && vec[i + i / j]>vec[i] + 1)vec[i + i / j] = vec[i] + 1;
// 			// if(i%j==0&&(i+i/j)<=m){
// 			// 	int x=vec[i]+1;
// 			// 	vec[i+i/j]=min(vec[i+i/j],x);
// 			// }
// 			//if(i+j==m)break;
// 		}
// 	}
// 	//for(auto i:vec)cout<<i<<endl;
// 	if(vec[m]==0x7fffffff)cout<<-1<<endl;
// 	else cout<<vec[m]<<endl;
// 	return 0;
// }
// #include <iostream>
// using namespace std;

// int ans[100001];

// int main()
// {
// 	int n, m;
// 	cin >> n >> m;
// 	if (n == m)
// 	{
// 		cout << 0;
// 		return 0;
// 	}
// 	for (int i = n+1; i <= m; i++)ans[i] = 100000;
// 	ans[n] = 0;
// 	for (int i = n; i < m; i++)	for (int j = 2; j*j <= i; j++)
// 	{
// 		if (i%j)continue;
// 		if (i + j <= m && ans[i + j]>ans[i] + 1)ans[i + j] = ans[i] + 1;
// 		if (i + i / j <= m && ans[i + i / j]>ans[i] + 1)ans[i + i / j] = ans[i] + 1;
// 	}
// 	if (ans[m] == 100000)ans[m] = -1;
// 	cout << ans[m];
// 	return 0;
// }
// int main(){
// 	int i;
// 	int pid=fork();
// 	if(pid==0){
// 		for(i=0;i<20;i++)printf("I am Child\n");
// 	}
// 	else{
// 		printf("I am Parent\n");
// 		while(1);
// 	}
// }
struct A{
    char a[3]{0,1,2};
};
int main(){
    vector<A>v;
    int x=0;
    
    A *a=new A();
    A b;
    v.push_back(b);
    v.push_back(b);
    cout<<&b<<endl;
    cout<<a<<endl;
    cout<<&v[0]<<endl;
    cout<<&(v[1])<<endl;
    
    cout<<&x<<endl;
    return 0;
}