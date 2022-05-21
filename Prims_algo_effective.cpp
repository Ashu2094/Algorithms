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

     priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    //  priority queue with vertex weight pair and is of min heap property

    int cost=0;

    pq.push({0,0});
    while(!pq.empty())
    {
        int u=pq.top().first;
        pq.pop();

        mst[u]=true;
        for(auto it:graph[u])
        {
            int v=it.first;
            int wt=it.second;
            if(mst[v]==false and wt<key[v])
            {
                parent[v]=u;
                key[v]=wt;
                pq.push({v,wt});
            }
        }
    }

    for (int i = 1; i < Vertex; i++) 
        cout << parent[i] << " - " << i <<" \n"; 

    for(int i=0;i<Vertex;i++)
    cost=cost+key[i];
    cout << "Total Cost=>" << cost;
    return 0;
}











// 6 9
// 0 4 4
// 0 3 1
// 3 4 9
// 3 2 5
// 3 1 3
// 0 1 2
// 2 1 3
// 2 5 8
// 1 5 7
// PrintGraph
// 0-4-4
// 0-3-1
// 0-1-2
// 1-3-3
// 1-0-2
// 1-2-3
// 1-5-7
// 2-3-5
// 2-1-3
// 2-5-8
// 3-0-1
// 3-4-9
// 3-2-5
// 3-1-3
// 4-0-4
// 4-3-9
// 5-2-8
// 5-1-7
// 0 - 1 
// 1 - 2 
// 0 - 3 
// 0 - 4 
// 1 - 5 
// Total Cost=>17
