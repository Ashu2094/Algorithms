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
   vector<int> weight(Vertex,INT_MAX);
   cout<<"Enter Source=>";
   int source;
   cin>>source;

    weight[source]=0;
     priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    //  priority queue with vertex weight pair and is of min heap property

    int cost=0;

    pq.push({source,0});
    while(!pq.empty())
    {
        int prevnode=pq.top().first;
        int prevweight=pq.top().second;
        pq.pop();


        for(auto it:graph[prevnode])
        {
            int nextnode=it.first;
            int nextnodeweight=it.second;//from prevnode
            if(weight[nextnode]>nextnodeweight+prevweight)
            {
                weight[nextnode]=nextnodeweight+prevweight;
                pq.push({nextnode,weight[nextnode]});
            }
        }
    }

    for (int i = 1; i < Vertex; i++) 
        cout <<source<<"-"<<i<<"-"<< weight[i] <<" \n"; 

    
    return 0;
}











