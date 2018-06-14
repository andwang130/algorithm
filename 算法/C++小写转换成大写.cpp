#include<iostream>
using namespace std;
int main() {
	char character = 'a';
	int as = int(character);
	cout << as << endl;
	as = as - 32;
	cout << char(as) << endl;

	cin.get();
}