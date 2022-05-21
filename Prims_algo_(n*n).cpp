#include <bits/stdc++.h>
using namespace std;
void add_edge(int u, int v, int weight, vector<pair<int, int>> graph[])
{
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}
void printGraph(int Vertex, vector<pair<int, int>> graph[])
{
    for (int i = 0; i < Vertex; i++)
    {
        for (auto x : graph[i])
        {
            cout << i << "-" << x.first << "-" << x.second << endl;
        }
    }
}
int main()
{
    int Vertex;
    cin >> Vertex;
    int Edges;
    cin >> Edges;
    vector<pair<int, int>> graph[Vertex];

    for (int i = 0; i < Edges; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        add_edge(u, v, weight, graph);
    }

    cout << "PrintGraph" << endl;
    printGraph(Vertex, graph);
    vector<int> key(Vertex, INT_MAX);
    vector<bool> mst(Vertex, false);
    vector<int> parent(Vertex, -1);

    key[0] = 0;
    parent[0] = 0;

    for (int i = 1; i < Vertex - 1; i++) // totla edges in a mst =  vertex - 1
    {
        int min = INT_MAX;
        int u;

        for (int v = 0; v < Vertex; v++)
        {
            if (mst[v] == false and key[v] < min)
                min = key[v], u = v;
        }

        mst[u] = true;

        for (auto x : graph[u])
        {
            int v = x.first;
            int weight = x.second;
            if (mst[v] == false and weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }
    int cost = 0;
    cout << "MST" << endl;
    for (int i = 0; i < Vertex; i++)
    {
        cost = cost + key[i];
        cout << parent[i] << " - " << i << endl;
        cost = cost + key[i];
    }

    cout << "Total Cost=>" << cost;
    return 0;
}
