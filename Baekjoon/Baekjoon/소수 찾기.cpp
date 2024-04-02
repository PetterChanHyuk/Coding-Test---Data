#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<int> A(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	int count = 0;
	for (int j = 0; j < N; j++)
	{
		bool isPrime = true;
		if (A[j] < 2)
			isPrime = false;

		for(int k=2;k<=sqrt(A[j]);k++)
		{
			if (A[j] % k == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			count++;
	}
	cout << count<<endl;
}