#include <iostream>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	int result = A * B * C;
	int j;
	int count[10] = { 0 };
	for (int i = 0; i <= 9; i++)
	{
		if(result!=0)
		{
			j = result % 10;
			count[j]++;
			result = result / 10;
		}
		
	}
	for (int k = 0; k < 10; k++)
	{
		cout << count[k] << endl;
	}
	return 0;
}