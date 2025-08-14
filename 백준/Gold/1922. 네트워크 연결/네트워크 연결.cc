#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

struct Node
{
    int from, to, weight;

    Node(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }

    bool operator<(const Node &other) const
    {
        return this->weight > other.weight;
    }
};

int N, M; // node, edge
vector<bool> visited;
vector<Node> mst;
vector<Node> nodeList;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;
    visited.resize(N + 1, false);

    priority_queue<Node> pq; // min heap operator
    int startNode;

    for (int i = 0; i < M; i++) // 10만 + a
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        if (i == 0)
            startNode = from;

        nodeList.push_back(Node(from, to, weight));
        nodeList.push_back(Node(to, from, weight));
    }

    for (auto &node : nodeList)
    {
        if (startNode == node.from)
            pq.push(node);
    }

    long long total = 0;
    visited[startNode] = true;

    while (!pq.empty())
    {
        Node top = pq.top();
        pq.pop();

        if (visited[top.to])
            continue;
        visited[top.to] = true;

        mst.push_back(top);
        total += top.weight;

        if (mst.size() == N - 1)
            break;

        for (auto &node : nodeList)
        {
            if (node.from == top.to)
                pq.push(node);
        }
    }

    cout << total;
}