/*
BOJ : https://www.acmicpc.net/problem/6593
backtracking �������
Versatile0010
*/

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
const int MX = 35;
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };
int l, r, c;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    char graph[MX][MX][MX];
    int dist[MX][MX][MX];
    //freopen("input.txt", "r", stdin);
    while (1)
    {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break; // ���� ����
        queue<tuple<int, int, int>> Q; // Ʃ�� ���� ť ����

        for (int i = 0; i < l; i++)
            for (int j = 0; j < r; j++)
                fill(dist[i][j], dist[i][j] + c, 0); // �Ÿ� �迭 0���� �ʱ�ȭ

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++) // ���� for �� �ε��� : ����,����,����
                {
                    cin >> graph[i][j][k];
                    if (graph[i][j][k] == 'S') // ��������ġ �ε��� ã����
                    {
                        Q.push({ i,j,k }); // ť�� Ǫ�� -> bfs �� �������� ��
                        dist[i][j][k] = 0; // �湮�� 0���� ���� (��� �̹� 0�̱� ��)
                    }
                    if (graph[i][j][k] == '.') // ����ִ� ����
                    {
                        dist[i][j][k] = -1; // -1�� ���� ( �湮�ؾ��� )
                    }
                }
            }
        } // -1 �� ����� ���� �� ���� ����.  
        bool isescape = false; // Ż�� �÷���

        while (!Q.empty()) 
        {
            if (isescape == true) break; // Ż���ߴٸ� while �� Ż��
            auto cur = Q.front(); Q.pop(); // cur �� ť �޾ƿ��� ��
            int cur_x, cur_y, cur_h; // Ʃ�� ��ҷ� �����(����������) �������� ����
            tie(cur_h, cur_x, cur_y) = cur; // �ϳ��� ��� Ʃ�þȿ� �־��� // cur_h : ����, cur_x : ����, cur_y : ����

            for (int dir = 0; dir < 6; dir++) // 6���� ���� : �����¿� �� �ٿ�
            {
                int nx = cur_x + dx[dir];
                int ny = cur_y + dy[dir];
                int nh = cur_h + dh[dir]; // ���� ��ġ ����

                if (nx < 0 || nx >= r || ny < 0 || ny >= c || nh < 0 || nh >= l) continue; // out of bound
                if (graph[nh][nx][ny] == '#' || dist[nh][nx][ny] > 0) continue; // �湮���� ���� ����̰ų� �湮�� �ʿ� ���°�� continue
                // <- 62��° �������� �Դٴ� ����, ��¶������ nh,nx,ny ��ǥ�� �湮�� ������ ���̰� �湮�ؾ��Ѵٴ� ����
                dist[nh][nx][ny] = dist[cur_h][cur_x][cur_y] + 1;  // 1�� ����
                if (graph[nh][nx][ny] == 'E') // �ٵ� ���Ӱ� �� nh,nx,ny �� �ⱸ���?
                {
                    cout << "Escaped in " << dist[nh][nx][ny] << " minute(s)." << '\n'; // ��� ���
                    isescape = true; // flag = true 
                    break; // while �� Ż��
                }
                Q.push({ nh,nx,ny }); // �ⱸ�� �ƴϿ��ٸ� �ٽ� bfs ���ƾ��ϴϱ� ���ο� ��ǥ�� push
            }

        }
        while (!Q.empty()) Q.pop(); // �� while ���� ����� �����ߴٴ� ���� Ż�� or ���ж�� ���ε�, queue �� �Ⱥ�������� �� ���� ( ���� return)
        if (!isescape) cout << "Trapped!" << '\n';  // Ż�� �������� �̰� ����ϱ�.
    }

    return 0;
}