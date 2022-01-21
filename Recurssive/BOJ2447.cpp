/*
BOJ : https://www.acmicpc.net/problem/2447
Recurssive, Divide & Conquer �����-10
Versatile0010
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int x, int y, int n) // x,y ��ǥ���� n�� ���� �ùٸ� ���� ���
{
	if (x / n % 3 == 1 && y / n % 3 == 1) // ������ ����ؾ� �ϴ� ���
		cout << ' ';
	else if (n / 3 == 0) // * �� ����ؾ� �ϴ� ���
		cout << '*';
	else
		solve(x, y, n / 3); // ���ȣ��
}

int main()
{
	int n; // ������ ũ�� �Է¹���
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{ // ��ǥ���� ��ȸ�ϸ� solve �Լ��� �־�, �ش� ��ǥ�� �ùٸ� ���� * or ' ' ���
			solve(i, j, n);
		}
		cout << '\n'; // �� ���� �� ��������� �����ٷ�
	}
	return 0;
}