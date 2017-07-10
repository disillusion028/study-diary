#ifndef _RESHANDLE_H_
#define _RESHANDLE_H_

#include "src.h"

using namespace std;

class cResHandle{
public:
	//cResHandle() :m_src(nullptr){};
	cResHandle(cSource* src) :m_src(new cSource(*src)){
		cout << "constructor...in..srchandler...\n";
	};
	cResHandle(const cSource* src) :m_src(new cSource(static_cast<const string>(*src->getPstr()))){
		cout << "const..constructor...in..src...\n";
	}; //cSource�Ĺ��캯��������const��
	/*cResHandle(const cSource& src) :m_src(new cSource(static_cast<const string>(*src.m_str))){
		cout << "constructor...in..src...\n\n";
	};*/


	~cResHandle(){
		delete m_src; //��������׳��쳣������ΪĬ��delete�����׳������Բ���Ҫ�ٴ�����
		cout << "destructor.....in...sourceHndle...\n";

	}
private:
	cResHandle(const cResHandle& srch){};  //EFC67 ����ΪʲôRAII һ�㶼�ǲ����忽�� �ƶ����� ����mutex��ʱ��
	cResHandle& operator= (const cResHandle& srch){};

	cResHandle(cResHandle&& msrch){};
	cResHandle& operator=(cResHandle&&){};
	cSource * m_src; //��efc++ 70ҳ����һ������ʹ�õ�������ָ�룬
};
#endif