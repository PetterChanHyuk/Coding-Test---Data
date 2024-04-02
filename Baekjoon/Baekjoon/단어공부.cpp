#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s[1000000];
	int a[26] = {0};
	cin >> s;

	int d = strlen(s);

	for (int i = 0; i < d; i++)
	{
		if ((int)s[i] >= 'A' && (int)s[i] <= 'Z')
			a[s[i] - 'A']++;
		else if ((int)s[i] >= 'a' && (int)s[i] <= 'z')
			a[s[i] - 'a']++;
	}
	int max = 0;
	int max_num = -1;
	int count = 0;

	for (int j = 0; j < 26; j++)
	{
		if (max < a[j])
		{
			max = a[j];
			max_num = j;
			count = 1;
		}
		else if (max == a[j])
		{
			count++;
		}
	}

	if (count > 1)
		cout << "?";
	else
		cout << (char)(max_num + 'A');
	return 0;
}