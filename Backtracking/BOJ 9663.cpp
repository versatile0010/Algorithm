/*
BOJ : https://www.acmicpc.net/problem/9663
backtracking N-Queen
Versatile0010
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;

bool isused_col[30];
bool isused_Increasing_diagonal[30];
bool isused_Decreasing_diagonal[30];

void func(int cur) // cur ��° �࿡ ���� ��ġ��
{
	if (cur == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) // cur �� i ���� ��ȸ
	{
		if (isused_col[i] || isused_Increasing_diagonal[cur+i] || isused_Decreasing_diagonal[cur-i+n-1])
			continue; // ���� ���� �� ���� ���
		else // ���� ���� �� �ִ� ���
		{
			isused_col[i] = true; // �ش� ĭ ���ο� true
			isused_Increasing_diagonal[cur + i] = true; //�ش� ĭ ����� �밢���� true
			isused_Decreasing_diagonal[cur - i + n - 1] = true; //�ش� ĭ ������ �밢���� true ó��
			func(cur + 1);
			isused_col[i] = false; 
			isused_Increasing_diagonal[cur + i] = false;
			isused_Decreasing_diagonal[cur - i + n - 1] = false;
		}
	}


}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	func(0);
	cout << cnt;
	return 0;
}