/*
BOJ : https://www.acmicpc.net/problem/9935
backtracking ���ڿ� ����
Versatile0010
*/

#include <bits/stdc++.h>
using namespace std;

string input;
string mine;
bool flag = false;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> input >> mine; // ���ڿ��� ���� ���ڿ� �Է�
	vector<char> str; // �Է� ���ڿ��� ������ vector
	const int input_size = (int)input.size(); // ���ڿ��� ���� ���
	const int mine_size = (int)mine.size(); // ���� ���ڿ��� ���� ���
	for (int i = 0; i < input_size; i++) // ���ڿ� ��ȯ
	{
		str.push_back(input[i]); // �ѱ��ھ� push
		if (str.size() >= mine_size) // str �� ����� ���ڰ� ���߹��ڿ����� ũ�� Ž��
		{
			flag = true; // �ϴ� flag �� true �� ���� ( ���߹��ڿ� �������� �ʴٸ� false�� �ٲ� )
			for (int j = 0; j < mine_size; j++) // ���߹��ڿ��� ���̸�ŭ �ݺ�
			{
				if (str[str.size() - mine_size + j] != mine[j]) // str �� ���߹��ڿ��� ����?
				{
					flag = false; // false
					break; // Ż��
				}
			}
			if (flag == true) // �� �ݺ��� ���Ŀ��� flag �� true �̸� ���߹��ڿ��� ���Ե� ��
			{
				for (int k = 0; k < mine_size; k++) // ���߹��ڿ��� ���̸�ŭ
				{
					str.pop_back(); // ���ڿ� ��
				}//���ڿ� ����
				flag = false; // ���������ϱ� flag �� �ٽ� false �� ����
			}
		}
	}//�ݺ�

	if (str.empty() == true) // str �� ����ִٸ� ���߷� ������ ���ư� ��
	{
		cout << "FRULA"; // ����ó��
	}
	else
	{
		for (int i = 0; i < str.size(); i++) // str �� ������� �ʴٸ�.
		{
			cout << str[i]; // �״�� ��� 
		}
	}

	return 0;
}