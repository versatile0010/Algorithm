/*
BOJ : https://www.acmicpc.net/problem/1759
backtracking ��ȣ�����
Versatile0010
*/


#include <bits/stdc++.h>
using namespace std;

int l, c; // c ���� ���ĺ��� �̿��Ͽ� l ������ ��ȣ ����
char input_arr[30];
int arr[30];
bool isused[30];

bool check_aeiou(char alphabet)
{
	if (alphabet == 'a' || alphabet == 'e' || alphabet == 'i'
		|| alphabet == 'o' || alphabet == 'u')
		return true; // �����̸� true ��ȯ
	else return false;
}


void solve(int k)
{
	if (k == l) // ���ϴ� ������ ��ȣ�� ���������
	{
		int aeiou_count = 0;
		int others_count = 0;
		bool isitgood = false;
		for (int i = 0; i < l; i++)
		{
			if (check_aeiou(input_arr[arr[i]]) == true) aeiou_count++;
			else others_count++;
		}
		if (aeiou_count >= 1 && others_count >= 2) isitgood = true;

		if (isitgood == true)
		{
			for (int i = 0; i < l; i++)
				cout << input_arr[arr[i]];
			cout << '\n';
			return;
		}
	}
	else
	{
		int start = 0;
		char temp = '0';
		if (k != 0) start = arr[k - 1] + 1;
		for (int i = start; i < c; i++)
		{
			if (isused[i] == false&&input_arr[arr[i]]!=temp)
			{
				isused[i] = true;
				arr[k] = i;
				temp = input_arr[arr[k]];
				solve(k + 1);
				isused[i] = false;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> input_arr[i]; // �Է¹ް�
	cin.ignore();
	sort(input_arr, input_arr + c); // ����
	solve(0);

	return 0;
}