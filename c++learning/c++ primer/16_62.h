#ifndef SALES_DATA_H
#define SALES_DATA_H
//定义你自己版本的hash<Sales_data>,并定义一个Sales_data对象的unordered_multiset,将多条交易记录保存到容器中，并打印其内容
#include <string>
#include <iostream>
class Sales_data{
    friend std::hash<Sales_data>;
    friend std::ostream& operator<<(std::ostream&,const Sales_data&);
    friend std::istream& operator>>(std::istream&,Sales_data&);
    friend bool operator==(const Sales_data &,const Sales_data&);

    friend std::ostream &print(std::ostream&,const Sales_data&);
    friend std::istream &read(std::istream&,Sales_data&);

public:
    Sales_data()=default;
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s,unsigned n,double p):
        bookNo(s),units_sold(n),revenue(p*n){}
    Sales_data(std::istream &);

    std::string isbn() const {return bookNo;}
    Sales_data& operator+=(const Sales_data&);
private:
    double avg_price()const;
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};

inline bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs){
    return lhs.isbn()<rhs.isbn();
}

inline bool operator==(const Sales_data&lhs,const Sales_data &rhs){
    return lhs.isbn()==rhs.isbn()&&
            lhs.units_sold==rhs.units_sold&&
            lhs.revenue==rhs.revenue;
}
inline bool operator!=(const Sales_data &lhs,const Sales_data &rhs){
    return !(lhs==rhs);
}

Sales_data add(const Sales_data&,const Sales_data&);
std::ostream &print(std::ostream&,const Sales_data&);
std::istream &read(std::istream,Sales_data&);

Sales_data operator+(const Sales_data&, const Sales_data&);
std::ostream& operator<<(std::ostream&,const Sales_data&);
std::istream& operator>>(std::istream&,Sales_data&);

namespace std{
    template<>
    struct hash<Sales_data>{
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data& s)const{
            return hash<string>()(s.bookNo)^
                hash<unsigned>()(s.units_sold)^
                hash<unsigned>()(s.revenue);
        }
    };
}

#endif