/*
BOJ : https://www.acmicpc.net/problem/15650
backtracking N�� M(2)
Versatile0010
*/

#include <bits/stdc++.h>
using namespace std;

int n, m; // 1~n ������ �ڿ��� �� �ߺ����� m ���� ����.
bool isused[10];  // Ư�� ���� ���Ǿ����� Ȯ���ϱ� ����
int arr[10]; // �ϼ��� ������ ���ʴ�� ��� ����


void solve(int k)
{
	if (k == m) // ���ϴ� ������ ������ ������ٸ� ����ϰ� �ش��Լ� ����
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	else
	{
		int start = 1;
		if (k != 0) start = arr[k - 1] + 1;
		for (int i = start; i <= n; i ++ )
		{
			if (!isused[i]) // �ش� ���� ������� �ʾҴٸ�?
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

	solve(0);
	return 0;

	return 0;
}