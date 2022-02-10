/*
BOJ : https://www.acmicpc.net/problem/18808
backtracking ��ƼĿ ���̱�
Versatile0010
*/

#include <bits/stdc++.h>
using namespace std;

int note_col, note_row; // 1~40
int numSticker; // 1~100
int stick_row, stick_col; // 1~10

int notebook[40][40];
int sticker[10][10];

bool isPossible_thenPasteIt(int x, int y)
{
	//��Ʈ�Ͽ� ��ƼĿ�� ���� �� �ִ��� Ȯ��
	for (int i = 0; i < stick_row; i++)
	{
		for (int j = 0; j < stick_col; j++)
		{
			if (notebook[x + i][y + j] == 1 && sticker[i][j] == 1)
				return false;
		}
	}

	for (int i = 0; i < stick_row; i++)
	{
		for (int j = 0; j < stick_col; j++)
		{
			if (sticker[i][j] == 1)
				notebook[x + i][y + j] = 1;
			// ���� �� �ִٸ� ���̱�
		}
	}
	return true;
}
void rotate()
{
	//��ƼĿ�� 90 �� ȸ����Ŵ
	int temp[10][10];
	for (int i = 0; i < stick_row; i++)
	{
		for (int j = 0; j < stick_col; j++)
		{
			temp[i][j] = sticker[i][j];
		}
	}
	for (int i = 0; i < stick_col; i++)
	{
		for (int j = 0; j < stick_row; j++)
		{
			sticker[i][j] = temp[stick_row - j - 1][i];
		}
	}
	swap(stick_col, stick_row);
}

void print_ans()
{
	//��Ʈ�Ͽ� ��ƼĿ�� ���� ĭ�� ���� ���
	int answer = 0;
	for(int i = 0 ; i < note_row; i ++)
	{
		for(int j = 0 ; j < note_col; j ++)
		{ 
			if (notebook[i][j] == 1) answer++;
		}
	}
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> note_row >> note_col >> numSticker;
	while (numSticker--)
	{
		cin >> stick_row >> stick_col;
		for (int i = 0; i < stick_row; i++)
		{
			for (int j = 0; j < stick_col; j++)
			{
				cin >> sticker[i][j];
			}
		} // ��ƼĿ�� ������ �Է¹���

		for (int rot = 0; rot < 4; rot++)
		{
			bool pastable = false;
			for (int x = 0; x <= note_row - stick_row; x++)
			{
				if (pastable == true) break;
				for (int y = 0; y <= note_col - stick_col; y++)
				{
					if (isPossible_thenPasteIt(x, y))
					{
						pastable = true;
						break;
					}
				}
			}
			if (pastable == true) break;
			rotate();
		}
	}
	
	print_ans();

	return 0;
}