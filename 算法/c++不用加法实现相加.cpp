#include<iostream>
using namespace std;
int aplusb(int a, int b) {
	// write your code here
	if (b == 0) {
		return a;
	}
	int s = a ^ b;
	int m = a & b;
	aplusb(s, m << 1);
}
int main() {
	int b=aplusb(2, 3);
	cout << b << endl;
	cin.get();
}