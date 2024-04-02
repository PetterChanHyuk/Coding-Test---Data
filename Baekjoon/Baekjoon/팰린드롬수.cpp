#include <iostream>

using namespace std;

int main()
{
	string a;

	while (true)
	{
		bool palindrome = true;
		cin >> a;
		if (a == "0")
			break;
		for (int i = 0; i < a.length() / 2; i++)
		{
			if (a[i] != a[a.length() - 1 - i])
			{
				palindrome = false;
				break;
			}
		}
		if (palindrome) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}