#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

vector<pair<int, int>> node[10001];
bool visited[10001];
int Max;
int End;

void dfs(int v, int sum) 
{
	if (visited[v]) return;

	visited[v] = true;
	
	if (Max < sum) {
		Max = sum;
		End = v;
	}
	
	for (int i = 0; i < node[v].size(); i++) {
		dfs(node[v][i].first, sum + node[v][i].second);
	}
}

int main(int argc, char** argv) 
{
	cin.tie(nullptr)->sync_with_stdio(false);
	
	int n;
	cin >> n;
	while(--n) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back(make_pair(b, c));
		node[b].push_back(make_pair(a, c));
	}
	
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(End, 0);
	
	cout << Max;
	
	return 0;
}