getline 可以作为字符串分段的函数来用：

刚刚在leetcode上做了一题 [71.Simplify Path](https://leetcode.com/problems/simplify-path/#/description) 这个题目主要是字符串处理问题，有个解法写的非常巧妙，记录一下。
```c++
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        stringstream ss(path);
        string tmp;
        while(getline(ss,tmp,'/')) {
            if (tmp == "" || tmp == ".") continue;
            if (tmp == ".." && !v.empty()) v.pop_back();
            else if (tmp != "..") v.push_back(tmp);
        }
        string ret;
        for(auto x : v) {
            ret += '/' + x;
        }
        return ret.empty()?"/":ret;    
    }
};
```
下面是从[cppreference](http://en.cppreference.com/w/cpp/string/basic_string/getline)上对std::getline 的学习记录：
> std::getline   
> 	Defined in header&lt;string&gt;   
>  1.      
> template < class CharT, class Traits, class Allocator >   
> std::base_istream<CharT,Traits>& getline(std::basic_istream<CharT,Traits>&input,std::basic_string<CharT,Traits,Allocator>&str, CharT delim);
>  2.   
> template < class CharT, class Traits,class Allocator >   
> std::basic_istream<CharT,Traits>& getline(std::basic_istream < CharT,Traits > &&input,std::basic_string < CharT,Traits,Allocator>& str,CharT delim);   
>  3.   
> template< class CharT,class Traits,class Allocator >   
> std::basic_istream < CharT,Traits>& getline(std::basic_istream < ChatT,Traits>& input,std::basic_string < CharT,Traits,Allocator> &str );   
>  4.   
>  template< class CharT, class Traits,class Allocator >   
>  std::basic_istream < CharT, Traits> & getline(std::basic_istream < ChatT, Traits> &&input,std::basic_string < ChatT,Traits,Allocator>&str );   

> Same as  getline(input,str,input.widen('\n')) , the default delimiter is the endline character.    
    
有个问题就是我能不能同时设定两个delim呢？