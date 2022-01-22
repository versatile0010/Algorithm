/*
BOJ : https://www.acmicpc.net/problem/15650
backtracking N�� M(2)
Versatile0010
*/

#include <bits/stdc++.h>
using namespace std;

int n, m; // 1~n ������ ���� m ���� ������ �������
int arr[10];

void solve(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			arr[k] = i;
			solve(k + 1);
		}
	}
	
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	solve(0);
	return 0;
}