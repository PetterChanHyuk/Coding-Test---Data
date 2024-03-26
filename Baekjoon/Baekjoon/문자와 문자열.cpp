#include <iostream>
#include <string>
using namespace std;

int main()
{
	char s[1000];
	cin >> s;

	int num;
	cin >> num;

	cout << s[num-1] << endl;
}