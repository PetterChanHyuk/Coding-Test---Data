#include <iostream>
using namespace std;

int main()
{
	int h, m;
	int result_h, result_m;
	cin >> h >> m;

	result_m = m - 45;
	result_h = h;
	if (result_m < 0)
	{
		result_h--;
		result_m += 60;
	}
	if (result_h < 0)
		result_h += 24;

	cout << result_h<< " " << result_m << endl;


}