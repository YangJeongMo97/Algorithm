#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int coin[101];
int value[10001];

int main()
{
	ios_base::sync_with_stdio(false); //iostream과 stdio의 동기화 끊는 역할
	cout.tie(NULL);	//입출력의 연결을 끊음. 입력을 연달아 하고 출력이 되는 형식
	cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	value[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			value[j] += value[j - coin[i]];
		}
	}

	cout << value[k];

	return 0;
}