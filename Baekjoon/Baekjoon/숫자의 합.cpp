#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		answer += s[i]- '0';
	}
	cout << answer;
}

