#if 0
/*�ܳ��쳣�ͺ���������Щ��ͬ����Ҫ�쳣��Ȩ�޲��᷵�ص��׳���
  ��ʹ�ֲ���̬����Ҳ�ᷢ��������Ϊ����� throw ew��������throw��
  ��Ҫ�ܳ��ֲ���ʱ������ָ�� throw &i   ��Ҫ�ܳ�new���ϵ�ָ�룬��֪����ʱdelete......
  �̻������� ��������Ҫʹ�ó������ò�����ʱ������Դ���һ���쳣�ǳ������õģ��������ں����в��ɡ������ɼ���һ�θ��ƣ�����������û�2�Σ�
  throwֱ�Ӿ�ok  ����һ�θ��ƣ����������׳�ԭ���󣬲��Ǹ��Ƶĸ�����Ҳ���ǲ��ᷢ����̬���ͺͶ�̬�������⣬��
  catch�������ƥ��
  exception�Ŀ������캯�������ݾ�̬�����������ġ�������ˣ����throw w���ͻ��ʳ���̬����������ˡ�����
*/

#include "iostream"
#include "exception"

using namespace std;

void fun_1(){
	try{
		throw 2;
	}
	catch (const int i){  //mû����ʿ���ã���������ط�2�θ���
		cout << "catch " << i << endl;
		throw;
	}
	catch (const int &i){
		throw;//�׳�ԭ���󣬣���const���ˣ���
	}
}

void fun_2(){
	try{
		throw 2;
	}
	catch (int i){
		cout << "catch " << i << endl;
		throw;
	}
}

void fun_3(){
	try
	{
		throw  range_error("range error....\n\n");
	}
	catch (exception* e)
	{
		cout << e->what() << endl;
		cout << "excepiton...\n\n";
	}
	catch (runtime_error& e)
	{
		cout << "runtime error...." << e.what() << endl;
	}
}

int main(){
	try{
		fun_1();
	}
	catch (...){
		cout << "catch ...main...\n";
	};

	fun_3();

	fun_2();  //δ�����쳣 ���������ֹ
	cout << "ok???";
	return 0;
}
#endif