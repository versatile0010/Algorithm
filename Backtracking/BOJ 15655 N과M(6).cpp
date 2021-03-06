/*
BOJ : https://www.acmicpc.net/problem/15655
backtracking N과 M(6)
Versatile0010
*/

#include <bits/stdc++.h>
using namespace std;

int n, m; // N 개의 자연수 중에서 M 개를 고른 수열
int arr[10];
int input_arr[10];
bool isused[10];

void solve(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << input_arr[arr[i]] << ' ';
		cout << '\n';
		return;
	}
	else
	{
		int start = 0;
		if (k != 0) start = arr[k-1] + 1;
		for (int i = start; i < n; i++)
		{
			if (!isused[i])
			{
				arr[k] = i;
				isused[i] = true;
				solve(k + 1);
				isused[i] = false;
			}
		}


	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> input_arr[i];
	sort(input_arr, input_arr + n);
	solve(0);

	return 0;
}
