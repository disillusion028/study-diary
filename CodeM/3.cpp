#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
int main() {
	int m = 0;
    unordered_set<int> S1;
    unordered_set<int> S2;
    unordered_set<int> S3;
	int line = 1,  any = 0;
	string temp1; 
    int temp2;
	bool flag = false;
	while (cin >> m) {
		if (m == 0) {
			cout << -1<<endl;
			continue;
		}
		line = 1;
		any = 0;
        S1.clear();//saved
        S2.clear();//consumed
        S3.clear();//saved2
		flag = false;
		while (m--)
		{	
			cin >> temp1;
			if (temp1 == "?") {
                if(!flag){
                    any++;
                    line++;
                    S2.clear();
                    S3.clear();
                }
			}
			else {
				cin >> temp2;
                if(temp2<=0||temp2>100000)flag=true;
                if(flag)continue;
				if (flag==false&&temp1 == "O") {
					if (S1.count(temp2)) {
						S1.erase(temp2);
                        S2.insert(temp2);
                        if(S3.count(temp2))S3.erase(temp2);
						line++;
                        continue;
					}
					else if (!S2.count(temp2)) {
                        if(any>0){
                            any--;
                            S2.insert(temp2);
                            line++;
                        }
                        else flag=true;
					}
                    else if(S2.count(temp2)){
                        flag=true;
                    }
				}
				else if (flag==false&&temp1 == "I") {
                    if(S3.count(temp2)){
                        flag=true;
                        continue;
                    }
                    else if(S1.count(temp2)){
                        if(any>0){
                            any--;
                        }
                        else{
                            flag=true;
                            continue;
                        }
                    }
					if(S2.count(temp2))S2.erase(temp2);
                    S1.insert(temp2);
                    S3.insert(temp2);
					line++;
				}
			}
		}
		if (flag == false)cout << -1<<endl;
		else cout << line<<endl;
	}
	return 0;
}