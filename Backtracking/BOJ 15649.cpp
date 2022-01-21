/*
BOJ : https://www.acmicpc.net/problem/15649
backtracking N�� M(1)
Versatile0010
*/

#include <bits/stdc++.h>
using namespace std;

int n, m; // 1~n ������ ���� m�� ������ ������ �ߺ����� ����� ��
int arr[10]; // ������ ���� �迭
bool isusedNumber[10]; // �ش� ���� ���Ǿ����� Ȯ���ϴ� �뵵(�ߺ�����)

void solve(int k)
{
	if (k == m)//base condition 
	{
		// ���ϴ� ������ ���̸�ŭ ������ ���� ���
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return; // ����
	}
	// ���� ���ϴ� ������ ���̸�ŭ ������ ������ ���� ���
	for (int i = 1; i <= n; i++) // 1���� n���� ���ڸ� ���ʴ�� ��ȸ��.
	{
		if (isusedNumber[i] == false) // �ش� index �� ���� ���� ������� ���� ���
		{
			arr[k] = i; // ������ k ��° index�� i�� ����
			isusedNumber[i] = true;
			solve(k + 1); // ������ ���̸� 1�� �����ؼ� ���ȣ��
			//���ȣ���� ������ �ϳ��� ����� ���� Ž�� �Ϸ��� ���̴ϱ�
			//����ߴ� ���� '��� ���ߴٰ�' �ٲ������
			isusedNumber[i] = false;
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