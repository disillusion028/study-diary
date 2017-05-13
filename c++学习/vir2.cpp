//from Effective C++
#include <iostream>
#include <vector>
using namespace std;
typedef enum ProductTypeTag
{
	Atomic,
	Water,
	Wrist
}PRODUCTTYPE;
class TimeKeeper{
public:
	TimeKeeper(){};
	//~TimeKeeper(){};//派生类对象经由一个基类指针被删除，而该基类带着一个non-virtual析构函数，其结果未有定义，实际执行时通常发生的是对象的派生类成分未被销毁，而其基类成分已经销毁
	//造成了“局部销毁”情况。
	virtual ~TimeKeeper(){};//正确情况
	/*
		带多态性质的基类应该声明一个virtual析构函数，如果class带有任何virtual函数，它就应该拥有一个virtual析构函数；
		classes的设计如果不是作为基类来使用，或者不是为了具备多态性，就不该声明virtual析构函数。	
	*/
	virtual int getTime()=0;
};
class AtomicClock:public TimeKeeper{
public:
	int getTime(){return 1;}

};
class WaterClock:public TimeKeeper{
public:
	int getTime(){return 2;}
};
class WristWatch:public TimeKeeper{
public:
	int getTime(){return 3;}
};
class Factory
{
public:
	TimeKeeper* CreateProduct(PRODUCTTYPE type)
	{
		switch(type)
		{	
			case Atomic:
				return new AtomicClock();
			case Water:
				return new WaterClock();
			case Wrist:
				return new WristWatch();
			default:
				return NULL;
		}
	}
};
int main(){
	Factory *ProductFactory = new Factory();
	TimeKeeper *productA=ProductFactory->CreateProduct(Atomic);
	if(productA!=NULL) cout<<productA->getTime()<<endl;

	TimeKeeper *productB=ProductFactory->CreateProduct(Water);
	if(productB!=NULL) cout<<productB->getTime()<<endl;

	TimeKeeper *productC=ProductFactory->CreateProduct(Wrist);
	if(productC!=NULL) cout<<productC->getTime()<<endl;

	delete ProductFactory;
	ProductFactory=NULL;

	delete productA;
	productA=NULL;

	delete productB;
	productB=NULL;

	delete productC;
	productC=NULL;
	return 0;
}
