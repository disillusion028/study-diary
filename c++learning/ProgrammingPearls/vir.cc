#include <iostream>
using namespace std;
class Person
{
  public:
    Person(unsigned _age) : age(_age)
    {
    }
    virtual unsigned getAge()
    {
        return age;
    }

  private:
    unsigned age;
};
class Man : public Person
{
  public:
    Man(unsigned _age) : age(_age), Person(_age)
    {
    }
    unsigned getAge()
    {
        return age + 5;
    }

  private:
    unsigned age;
};
int main(){
    Person *p=new Person(10);
    unsigned Page=((Man*)p)->getAge();
    cout<<Page<<endl;
    Person *m=new Man(10);
    unsigned Mage=m->getAge();
    cout<<Mage<<endl;
    return 0;
}