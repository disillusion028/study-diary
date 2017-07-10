#include <cstdlib>
#include <iostream>
#include <cstring>

class CMyString{
public:
    CMyString(char * pData=NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator=(const CMyString& rhs);
private:
    char* m_pData;
};
// version 1
// 是否把返回值的类型声明为该类型的引用（连续赋值问题）
// 是否把传入的参数类型设置为常量引用。
// 是否释放实例自身已有的内存。（防止内存泄露）
// 是否判断传入的参数和当前的实例是不是同一个实例。
// CMyString& CMyString::operator=(const CMyString& rhs){
//     if(this==&rhs){
//         return *this;
//     }
//     delete[] this->m_pData;
//     this->m_pData=NULL;
//     int sz=strlen(rhs.m_pData)+1;
//     this->m_pData=new char[sz];
//     //memcpy(this->m_pData,rhs.m_pData,sz);
//     strcpy(m_pData,rhs.m_pData);
//     return *this;
// }

//advanced version
//version 1 违反了异常安全性原则
CMyString& CMyString::operator=(const CMyString& rhs){
    if(this!=&rhs){
        CMyString strTemp(rhs);

        char *pTemp=strTemp.m_pData;
        strTemp.m_pData=m_pData;
        m_pData=pTemp;
    }
    return *this;
}
