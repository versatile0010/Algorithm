/*
BOJ : https://www.acmicpc.net/problem/2447
Recurssive, Divide & Conquer �����-10
Versatile0010
*/

#include <bits/stdc++.h>
using namespace std;

char star[2188][2188];
void setting(int x, int y, int n)
{
	if (n == 1) // ���̻� ����� ������ �� ������
	{
		star[x][y] = '*'; // * �� ����
		return;
	}
	else
	{
		int new_n = n / 3; // size�� 1/3 �� ���
		int ifis5meansCenter = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) // 1/3�� ����ϸ� �� 9���� ������ �����.
			{// 9���� ������ ��ȸ�ϸ� �˻�
				ifis5meansCenter++; // �ش� ���� 5��� ���� ���� ��� ������ Ž�� ���̶�� ��
				if (ifis5meansCenter != 5)
				{
					setting(x + i * new_n, y + j * new_n, new_n); // ����� �ƴ� ������ ��� ȣ��
				}
			}
		}
	}
}
int main()
{
	int n; // ������ ũ�� �Է¹���
	cin >> n;

	for (int i = 0; i < 2188; i++)
		fill(star[i], star[i] + 2188, ' '); // ����ϱ� ���� �ϴ� �������� ä���ΰ�

	setting(0, 0, n); //���ϴ� ũ�⸸ŭ ������ �̸� ����

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << star[i][j];
		}
		cout << '\n';
	}

	return 0;
}