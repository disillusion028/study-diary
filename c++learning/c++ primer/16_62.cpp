#include "16_62.h"
#include <unordered_set>
#include <memory>
using std::istream;
using std::ostream;
Sales_data::Sales_data(istream &is){
    is>>*this;
}
double Sales_data::avg_price() const{
    if(units_sold)return revenue/units_sold;
    else return 0;
}

Sales_data add(const Sales_data& s1,const Sales_data& s2){
    return s1+s2;
}
ostream &print(ostream& os,const Sales_data s){
    return os<<s;
}
istream &read(istream& is,Sales_data& s){
    return is>>s;
}
Sales_data& Sales_data::operator+=(const Sales_data& s){
    this->revenue+=s.revenue;
    this->units_sold+=s.units_sold;
    return *this;
}
Sales_data operator+(const Sales_data& s1,const Sales_data& s2){
    Sales_data ret=s1;
    ret+=s2;
    return ret;
}
ostream& operator<<(ostream& os,const Sales_data& s){
    os<<"bookNo"<<s.bookNo<<std::endl;
    os<<"units_sold"<<s.units_sold<<std::endl;
    os<<"revenue"<<s.revenue<<std::endl;
    os<<"avg"<<s.avg_price()<<std::endl;
    return os;
}
istream& operator>>(istream& is,Sales_data& s){
    double price;
    is>>s.bookNo>>s.units_sold>>price;
    if(is)s.revenue=s.units_sold*price;
    else s=Sales_data();
    return is;
}

int main(){
    std::unordered_multiset<Sales_data> mset;
    Sales_data sd("Bible",10,0.98);
    mset.emplace(sd);
    mset.emplace("C++ Primer",5, 9.99);
    for(const auto &item : mset)
        std::cout << "the hash code of " << item.isbn()
                  <<":\n0x" << std::hex << std::hash<Sales_data>()(item)
                  << "\n";
    //std::cout<<std::hash<int>()(213132);
    return 0;
}