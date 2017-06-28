#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> test{1,2,3};
	for(auto it=test.begin();it!=test.end();it++){
		if((*it)==2)
		test.erase(it);	
	}
	return 0;
}
