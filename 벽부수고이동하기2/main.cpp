#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int x, y, k;
char nfiled[1001][1001];
int visit[1001][1001][11] = { 0, };

typedef struct pos{
	int nx, ny, nk, val;
};


int dirx[] = { 0, 0, 1, -1 };
int diry[] = { 1, -1, 0, 0 };

int bfs()
{
	int cnt = 0;

	queue <pos> que;
	que.push({ 0, 0, 0, 1 });
	visit[0][0][0] = 1;

	pos cur = { 0, 0, 0, 0 };
	pos nxt = { 0, 0, 0, 0 };

	while (!que.empty())
	{
		cur = que.front();
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			nxt.nx = dirx[i] + cur.nx;
			nxt.ny = diry[i] + cur.ny;
			nxt.nk = cur.nk;
			nxt.val = cur.val + 1;

			if (nxt.nx >= 0 && nxt.nx < x && nxt.ny >= 0 && nxt.ny < y)
			{
				if (nfiled[nxt.ny][nxt.nx] == '0' && !visit[nxt.ny][nxt.nx][nxt.nk])
				{
					visit[nxt.ny][nxt.nx][nxt.nk] = nxt.val;
					que.push(nxt);
				}
				else if (nfiled[nxt.ny][nxt.nx] == '1' && !visit[nxt.ny][nxt.nx][nxt.nk + 1] && nxt.nk + 1 <= k)
				{
					visit[nxt.ny][nxt.nx][nxt.nk + 1] = nxt.val;
					nxt.nk++;
					que.push(nxt);
					cnt++;
				}
			}
		}
	}


	return cnt;
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> y >> x >> k;

	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			cin >> nfiled[i][j];
		}
	}

	int cnt_T = bfs();

	int MIN = 1000001;
	for (int i = 0; i < 11; i++){
		if (visit[y - 1][x - 1][i] == 0) continue;
		MIN = min(MIN, visit[y - 1][x - 1][i]);
	}
	if (MIN == 1000001)
		MIN = -1;

	cout << MIN << "\n";

	return 0;
}