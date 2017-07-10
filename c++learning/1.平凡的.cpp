/*
	�Ⲣ����˵Aggregate���;Ͳ����й��캯������ʵ�ϣ�������ӵ��һ��Ĭ�Ϲ��캯������һ�����ƹ��캯����ֻҪ�����Ǳ������������ģ������Ǳ��û��Լ������ġ�
	����ӵ��˽�л��߱������͵ķǾ�̬���ݳ�Ա������Զ���������˽�л��߱������͵ĳ�Ա���������������캯�����;�̬���͵����ݳ�Ա�ͷ������ⶼ��Υ��Aggregate���͵Ĺ���
	Aggregate���Ϳ���ӵ���û�������/�û������ ��ֵ������������������
	������Aggregate���ͣ������Ƿ�Aggregate����Ԫ�ص����顣

	�ֽڸ�ֵ����ʹ��memcpy��memset��ʼ��������stl���������ľͲ�����ù��캯���ˣ�
	��c���ݣ��ǰ�ȫ��
	pod���͵ľ�̬��ʼ��Ϊ0����.bss�����棬��ռ�ռ䣬��̬initialization
*/
#include "iostream"
#include "string"
#include "type_traits"
#include "iomanip"
using namespace std;

class NotAggregate1
{
	virtual void f(){} //remember? no virtual functions
};

class NotAggregate2
{
	int x; //x is private by default and non-static 
};

class NotAggregate3
{
public:
	NotAggregate3(int) {} //oops, user-defined constructor
};

class Aggregate1
{
public:
	NotAggregate1 member1;   //ok, public member
	Aggregate1& operator = (Aggregate1 const & rhs) {/* */ } //ok, copy-assignment  
private:
	void f() {} // ok, just a private function

};
struct cStr{
//	virtual ~cStr(){};
};
class Cperson{
public:
	Cperson() = default;
	virtual ~Cperson(){};
private:
	int i;
};

class cMan : public Cperson{
public:
	cMan() :Cperson(){

	}
	~cMan(){};
private:
	string name;
};



int main(){
	cout << std::boolalpha;
	cout << is_trivial<cStr>::value << endl;
	cout << is_trivial<Cperson>::value << endl;
	
	cout << "\n��׼���֣�\n";
	cout << is_standard_layout<Cperson>::value << endl;


	cout << "\n�ǲ���pod��\n";
	cout << is_pod<Cperson>::value << endl;

	return 0;
}