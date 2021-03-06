//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <map>
//#include <vector>
//#include <math.h>
//#include <limits.h>
//#include <queue>
//
//#define MAX 2100000
//
//#define UP 0
//#define DOWN 1
//#define LEFT 2
//#define RIGHT 3
//
//#define INF INT_MAX
//
//typedef long l;
//
//typedef struct Vector2 {
//
//	int x, y;
//
//	Vector2 operator+(Vector2 vec) { return { x + vec.x, y + vec.y }; }
//	Vector2 operator-(Vector2 vec) { return { x + vec.x, y + vec.y }; }
//	Vector2 operator*(int ratio) { return { x * ratio, y * ratio }; }
//
//	bool operator==(Vector2 vec) { return ((x == vec.x) && (y == vec.y)); }
//
//};
//
//typedef struct Vertex {
//
//	Vector2 pos;
//
//	l num = INF;
//
//	l weight[4];
//
//};
//
//typedef struct Area {
//
//	Vector2 pos1, pos2;
//
//	int cost;
//
//};
//
//struct comp {
//	bool operator()(const Vertex &a, const Vertex &b)
//	{
//		return a.num > b.num;
//	}
//};
//
//Vector2 dv[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
//
//Area area[1001];
//
//Vertex vert[2001][2001];
//bool visit[2001][2001];
//Vector2 start, end;
//
//std::map<int, int> xidx, yidx;
//std::vector<int> xpos, ypos;
//
//int xpos_size, ypos_size;
//
//void SetNode(Vector2 pos, int dir, l value) {
//
//	Vector2 sub = pos + dv[dir];
//
//	if (sub.x < 0 || sub.y < 0 || sub.x >= xpos_size || sub.y >= ypos_size) return;
//
//	vert[pos.x][pos.y].pos = pos;
//	vert[pos.x][pos.y].weight[dir] = (std::abs(pos.x - sub.x) + std::abs(pos.y - sub.y)) * value;
//
//}
//
//int main() {
//
//	std::ios::sync_with_stdio(false);
//	std::cout.tie(NULL); std::cin.tie(NULL);
//
//	//�Է�
//	std::cin >> start.x >> start.y >> end.x >> end.y;
//
//	std::set<int> xorder, yorder;
//
//	xorder.insert(start.x), xorder.insert(end.x);
//	yorder.insert(start.y), yorder.insert(end.y);
//
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//
//		int x1, y1, x2, y2, cost;
//
//		std::cin >> x1 >> y1 >> x2 >> y2 >> cost;
//
//		area[i] = { {x1, y1}, {x2, y2}, cost };
//
//		xorder.insert(x1), xorder.insert(x2);
//		yorder.insert(y1), yorder.insert(y2);
//
//	}
//
//	//���� �ձ�
//
//	int size_x = 0, size_y = 0;
//
//	for (auto itr = xorder.begin(); itr != xorder.end(); itr++) {
//
//		xidx[*itr] = size_x++;
//		xpos.push_back(*itr);
//
//	}
//
//	for (auto itr = yorder.begin(); itr != yorder.end(); itr++) {
//
//		yidx[*itr] = size_y++;
//		ypos.push_back(*itr);
//
//	}
//
//	xpos_size = xpos.size(), ypos_size = ypos.size();
//
//	for (int x = 0; x < xpos_size; x++)
//		for (int y = 0; y < ypos_size; y++)
//			for (int i = 0; i < 4; i++)
//				SetNode({ x, y }, i, 10);
//
//	for (int i = 0; i < n; i++) {
//
//		int start_x = xidx[area[i].pos1.x],
//			start_y = yidx[area[i].pos1.y];
//
//		int end_x = xidx[area[i].pos2.x],
//			end_y = yidx[area[i].pos2.y];
//
//		for (int x = start_x; x < end_x; x++)
//			for (int y = start_y; y < end_y; y++) {
//
//				if (x != start_x) {
//
//					SetNode({ x, y }, UP, area[i].cost);
//					SetNode({ x, y + 1 }, DOWN, area[i].cost);
//
//				}
//
//				if (y != start_y) {
//
//					SetNode({ x, y }, RIGHT, area[i].cost);
//					SetNode({ x + 1, y }, LEFT, area[i].cost);
//
//				}
//
//			}
//
//	}
//
//	//A*
//
//	std::priority_queue<Vertex, std::vector<Vertex>, comp> q;
//
//	vert[xidx[start.x]][yidx[start.y]].num = 0;
//
//	q.push(vert[xidx[start.x]][yidx[start.y]]);
//
//	while (!q.empty()) {
//
//		Vertex v = q.top(); q.pop();
//
//		if (visit[v.pos.x][v.pos.y]) continue;
//
//		visit[v.pos.x][v.pos.y] = true;
//
//		//std::cout << "visit : " << xpos[v.pos.x] << ", " << ypos[v.pos.y] << ", " << v.num << "\n";
//
//		for (int i = 0; i < 4; i++) {
//
//			Vector2 pos = v.pos + dv[i];
//
//			if (pos.x < 0 || pos.y < 0 || pos.x >= xpos_size || pos.y >= ypos_size) continue;
//
//			vert[pos.x][pos.y].num = std::min(vert[pos.x][pos.y].num, v.num + v.weight[i]);
//
//			q.push(vert[pos.x][pos.y]);
//
//		}
//
//	}
//
//	std::cout << vert[xidx[end.x]][yidx[end.y]].num << "\n";
//
//	return 0;
//
//}