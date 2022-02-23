/*
BOJ : https://www.acmicpc.net/problem/1932
DP ���� �ﰢ��
Versatile0010
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n; // 1~500
int dp[500][500] = { 0, };

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) // ���ʳ�
			{
				dp[i][j] = dp[i - 1][0] + dp[i][j];
				continue;

			}
			if (j == i) // ������ ��
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
				continue;
			}
			else // ���
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];
			}
		}

	}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (dp[n - 1][i] >= ans) ans = dp[n - 1][i];
	}
	cout << ans;
	
	return 0;
}