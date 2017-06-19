#include <iostream>
using namespace std;
int main() {
	int sum, more=0, less,n,first,temp;
	cin >> sum;
	n = sum;
	cin >> first;
	n--;
	while (n--) {
		cin >> temp;
		if (temp > first)more++;
	}
	less = sum - 1 - more;
	int ret = 0;
	if (less == 0)cout << ret;
	else {
		while (less > 0) {
			sum = sum / 2;
			int x = more / 2;
			more = more - x;
			int y = sum - x;
			if (less < y) {
				break;
			}
			less = less - y;
			ret++;
		}
		cout << ret;
	}
	//system("pause");
	return 0;
}