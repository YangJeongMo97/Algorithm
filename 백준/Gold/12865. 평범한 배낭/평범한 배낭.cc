#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int inventory[101][100001];
int weight[101];
int value[101];

int main()
{
	ios_base::sync_with_stdio(false); //iostream과 stdio의 동기화 끊는 역할
	cout.tie(NULL);	//입출력의 연결을 끊음. 입력을 연달아 하고 출력이 되는 형식
	cin.tie(NULL);

	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> weight[i];
		cin >> value[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= weight[i])
			{
				inventory[i][j] = max(inventory[i - 1][j], value[i] + inventory[i - 1][j - weight[i]]);
			}
			else
				inventory[i][j] = inventory[i - 1][j];
		}
	}

	cout << inventory[N][K];

	return 0;
}