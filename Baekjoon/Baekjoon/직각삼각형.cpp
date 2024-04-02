#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, c;

	while (cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0)
			break;

		if (pow(a, 2) == pow(b, 2) + pow(c, 2) || pow(b, 2) == pow(a, 2) + pow(c, 2) || pow(c, 2) == pow(b, 2) + pow(a, 2))
		{
			cout << "right" << endl;
		}
		else
			cout << "wrong" << endl;
	}

	return 0;
}