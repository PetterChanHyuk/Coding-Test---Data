#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;

	vector<int> T(N);

	for (int i = 0; i < N; i++)
	{
		cin >> T[i];
	}

	int max=0;
	for (int j = 0; j < N-2; j++)
	{
		for (int k = j+1; k < N-1; k++)
		{
			for (int l = k + 1; l < N; l++)
			{
				if (max < T[j] + T[k] + T[l] && T[j] + T[k] + T[l] <= M)
					max = T[j] + T[k] + T[l];
			}
		}
	}
	cout << max;
}