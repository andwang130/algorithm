#include<iostream>
using namespace std;
int sortnum(int num) {
	int oldnum = num;
	int newnum = 0;
	while (oldnum>0)
	{
		cout << "new:" << newnum << "  new*10: " << newnum * 10 << " old: " << oldnum << " old%10: " << oldnum % 10 << endl;
		newnum = newnum * 10 + oldnum % 10;
		oldnum = oldnum / 10;
	}
	cout << newnum << endl;
	return newnum;
}
int main() {
	sortnum(332);
	cin.get();
	return 0;
}