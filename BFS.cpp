
#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

int a[7][7] = {
	{0,0,0,0,0,0,0},
	{0,1,1,0,1,1,0},
	{0,1,1,0,1,1,0},
	{0,1,0,0,0,1,0},
	{0,1,1,1,0,1,0},
	{0,1,1,1,1,1,0},
	{0,0,0,0,0,0,0},
};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
//          ��,��,��,��
//           0  1  2  3
struct BFS {//Breath First Search
	bool success = 0;//��󷵻ص��Ƿ��ܹ�BFS
	int step = 0;    //��󷵻ص�step��
	stack<int>Trace; //���õ���·�����裬�����ƶ����ӣ�ÿһ��ֻ��Ҫ֪����������

	template<typename T, int M, int N>
	void CALC(int startx, int starty, int endx, int endy, T(&Map)[M][N]);//Breath First Search����
};
template<typename T, int M, int N>
void BFS::CALC(int startx, int starty, int endx, int endy, T(&Map)[M][N]) {
	struct NODE
	{
		int x = 0;
		int y = 0;
		int step = 0;
	};
	bool isVisited[M][N] = {};
	int preStep[M][N] = {};
	queue<NODE>queueBFS;

	NODE cur;
	cur.x = startx, cur.y = starty, cur.step = 0;
	queueBFS.push(cur);      //��������
	isVisited[startx][starty] = 1;

	while (!queueBFS.empty()) {
		cur = queueBFS.front();
		if (cur.x == endx && cur.y == endy)
		{
			success = 1;
			step = cur.step;
			for (; cur.step > 0; cur.step--) {
				int k = preStep[cur.x][cur.y];
				//cout << "step" << cur.step << "x" << cur.x << "y" << cur.y << endl;
				Trace.push(k);
				cur.x -= dx[k];
				cur.y -= dy[k];
			}
			break;
		}

		for (int k = 0; k <= 3; k++) {  //k 0�� 1�� 2�� 3��
			int tx, ty;
			tx = cur.x + dx[k];
			ty = cur.y + dy[k];
			if (Map[tx][ty] == 1 && isVisited[tx][ty] == 0) { //���    //��Ҫʹǽ����NULL
				preStep[tx][ty] = k;

				NODE temp;
				temp.x = tx;
				temp.y = ty;
				temp.step = queueBFS.front().step + 1;
				queueBFS.push(temp);
				isVisited[tx][ty] = 1;
			}
		}
		queueBFS.pop();//��չ������Ҫ������Ԫ�س���		
	}
	if (success == 0)
		cout << "no answer";
}

int main()
{
	BFS bfs;
	bfs.CALC(1, 1, 1, 4, a);
	cout << bfs.step <<endl;
	for (int i = 0; i < bfs.step; i++) {
		//cout << bfs.Trace.top() << endl;
		bfs.Trace.pop();
	}

	
	return 0;
}

//BFS wall;
//BFS* contain[12][12] = {
//	{&wall,&wall,&wall,&wall,&wall,&wall,&wall,&wall,&wall,&wall,&wall,&wall,},
//	{ &wall, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&wall },
//	{ &wall, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&wall },
//	{ &wall, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&wall },
//	{ &wall, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&wall },
//	{ &wall, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&wall },
//	{ &wall, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&wall },
//	{ &wall, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&wall },
//	{ &wall, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&wall },
//	{ &wall, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&wall },
//	{ &wall, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&wall },
//	{&wall,&wall,&wall,&wall,&wall,&wall,&wall,&wall,&wall,&wall,&wall,&wall,},
//};
