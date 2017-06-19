#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>
using namespace std;
int main() {
	int m = 0;
	char P[100001];
    unordered_set<int> S1;
    unordered_set<int> S2;
    memset(P,0,sizeof(P));

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
        memset(P,0,sizeof(P));
		flag = false;
		while (m--)
		{	
			cin >> temp1;
			if (temp1 == "?") {
                if(!flag){
                    any++;
                    for(int i=0;i<=100000;i++){
                        if(!P[i]){
                            P[i]=2;
                        }
                    }
                    line++;
                }
			}
			else {
				cin >> temp2;
                if(flag)continue;
				if (flag==false&&temp1 == "O") {
					if (P[temp2]==1) {
						P[temp2]=0;
						line++;
					}
					else if (P[temp2]==2) {
						any--;
                        //cout<<"any: "<<any<<endl;
                        if(any==0){
                            for(int i=0;i<=100000;i++){
                                if(P[i]==2)P[i]=0;
                            }
                        }
                        P[temp2]=0;
						line++;
					}
					else {
						flag = true;
                        //cout<<"find"<<endl;
					}
				}
				else if (flag==false&&temp1 == "I") {
					P[temp2]=1;
					line++;
				}
			}
            //cout<<"debug:  "<<P[3]<<endl;
		}
		if (flag == false)cout << -1<<endl;
		else cout << line<<endl;
	}
	//system("pause");
	return 0;
}