#include <iostream>
using namespace std;

int main() {

	int N;
	cin >> N;


	int max, min;
	for (int i = 0; i < N; i++) {

		int number;
		cin >> number;

		if (i == 0)
		{
			max = min = number;
		}
		else {
			if (number > max) max = number;
			if (number < min) min = number;
		}
	}
	cout << min << " " << max;

	
}