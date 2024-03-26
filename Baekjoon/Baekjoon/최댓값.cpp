#include <iostream>
using namespace std;

int main()
{
	int N[9];
	int max_num = 0;
	int max = 1;
	for (int i = 0; i < 9; i++)
	{
		cin >> N[i];
	}
	max_num = N[0];
	for (int j = 0; j < 9; j++)
	{
		if (max_num < N[j])
		{
			max_num = N[j];
			max = j + 1;
		}
	}
	cout << max_num << endl;
	cout << max << endl;
	return 0;
}