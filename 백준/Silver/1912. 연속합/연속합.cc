#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //iostream과 stdio의 동기화 끊는 역할
	cout.tie(NULL);	//입출력의 연결을 끊음. 입력을 연달아 하고 출력이 되는 형식
	cin.tie(NULL);

	int n, max = 0x80000000, sum = 0;
	
	cin >> n;

	int* n_array = new int[n + 1]{ 0 };

	for (int i = 1; i <= n; i++)
	{
		cin >> n_array[i];
		if (n_array[i - 1] > 0) n_array[i] = n_array[i] + n_array[i - 1];
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (max < n_array[i]) max = n_array[i];
	}

	cout << max;

	return 0;
}