#include <iostream>
#include <algorithm>
using namespace std;
class Singleton1{
public:
    static Singleton1 * getInstance(){
        if(instance==nullptr){
            instance=new Singleton1();
        }
        return instance;
    }
protected:
    Singleton1(){
        
    }
private:    static Singleton1 *instance;
};
Singleton1* Singleton1::instance=nullptr;
