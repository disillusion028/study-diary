
#define  _CRT_SECURE_NO_WARNINGS
#include <exception>
#include "iostream"
#include "string"

using namespace std;
class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;
void throwExp(){
	throw myexception();
}
int main(){
	// string *str = new string("abc");
	// //throw exception("abc");
	// char m_head_len_c[4];
	// sprintf(m_head_len_c, "%d", 123);
	
	// cout << "m-hed..." << m_head_len_c << endl;

	// cout << "xxx:" << m_head_len_c[0] << m_head_len_c[1] << m_head_len_c[2] << m_head_len_c[3]<< endl;
	// int len = static_cast<unsigned int>(m_head_len_c[0]) + (static_cast<unsigned int>(m_head_len_c[1]) << 8) + (static_cast<unsigned int>(m_head_len_c[2]) << 16) + (static_cast<unsigned int>(m_head_len_c[3]) << 24);
	// cout << "atoi =" << atoi(m_head_len_c)  << "  ..." << len  << endl;
	try{
		try
		{
			throwExp();
		}
		catch (exception &e)
		{	
			// char *a=const_cast<char*>(e.what());
			// cout<<a<<endl;
			cout << e.what() << endl;
			throw ;
		}
		// catch (exception &e)
		// {	
		// 	// char *a=const_cast<char*>(e.what());
		// 	// cout<<a<<endl;
		// 	cout << e.what() << endl;
		// 	throw (e);
		// }
	}
	catch(exception &e){
		cout<<e.what()<<endl;
	}
	return 0;
}