#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 201

typedef struct Vertex {

	std::vector<int> adjust;

};

int match[MAX];
bool visit[MAX];
Vertex vert[MAX];

bool dfs(int idx) {

	int size = vert[idx].adjust.size();

	for (int i = 0; i < size; i++) {

		int adj = vert[idx].adjust[i];

		if (visit[adj]) continue;
		visit[adj] = true;

		if (match[adj] == -1 || dfs(match[adj])) {

			match[adj] = idx;
			return true;

		}

	}

	return false;

}

int main() {

	int n, m; std::cin >> n >> m;

	for (int i = 0; i < n; i++) {

		int a; std::cin >> a;

		vert[i].adjust.resize(a);

		for (int j = 0; j < a; j++)
			std::cin >> vert[i].adjust[j];

	}

	std::fill(match, match + MAX, -1);

	int result = 0;

	for (int i = 0; i < n; i++) {

		std::fill(visit, visit + MAX, false);

		if (dfs(i)) result++;

	}

	std::cout << result << "\n";

	return 0;

}