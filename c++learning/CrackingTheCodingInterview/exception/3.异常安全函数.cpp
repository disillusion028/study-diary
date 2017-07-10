#if 0

#define  _CRT_SECURE_NO_WARNINGS
#include "exception_my.h"

int cString::_num = 0;

cString::cString(const cString &str):_chArr(new char[strlen(str._chArr)]){
	//_chArr = str._chArr;  //zwenti....����
	strcpy(_chArr, str._chArr);
	cout << "copy constructor" << "num:" << ++_num << "\n";
}

cString& cString::operator=(const cString& str){
	//char* tmp(str._chArr);
	char* tmp = new char[strlen(str._chArr)]; //�����ܳ��쳣,��������Դй¶
	if (tmp != nullptr)
	{
		*tmp = *str._chArr;
	}
	else
		return *this;
	//if (this != &str)
	{
		delete[] _chArr;
		_chArr = tmp;
	}
	return *this;
}
/*
cString& cString::operator=(const cString& str){
	cString *temp = new cString(str._chArr); //���
	if (this != &str)
	{
		delete[] _chArr;
		//this = static_cast<cString * const>(temp);
		this->_chArr = temp->_chArr;
		//Ӧ��str�����char����������������newһ������
	}
	return *this;
}*/

cString& cString::operator=(const char* cha){
	//delete[] _chArr; //Ĭ��delete�ǲ����׳��쳣
	if (!cha) cha = "";
	_chArr = strcpy(new char[strlen(cha) + 1], cha);//�����쳣3,û��ϵ��������κζ����������
	delete[] _chArr; //Ĭ��delete�ǲ����׳��쳣
	return *this;
}
cString::cString(cString&& str) :_chArr(str._chArr){
	str._chArr = nullptr;

}
cString& cString::operator=(cString&& str){
	if (this != &str)
	{
		delete[] _chArr;
		_chArr = str._chArr;
		str._chArr = nullptr;
	}
	return *this;
}
int main(){
	
	return 0;
}
#endif