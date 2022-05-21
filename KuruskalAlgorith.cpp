#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int weight;
    node(int weight_,int u_,int v_)
    {
        u=u_;
        v=v_;
        weight=weight_;
    }
};
bool comp (node a, node b)
{
    return a.weight<b.weight;
}
int findPar(int u,vector<int>& parent)
{
    if(parent[u]==u) return u;
    return parent[u]=findPar(parent[u],parent);
}
void Union(int u,int v,vector<int>& parent,vector<int>& rank)
{
    u=findPar(u,parent);
    v=findPar(v,parent);
    if(u!=v)
    {
        if(rank[u]<rank[v])
        parent[u]=v;
        else if(rank[v]<rank[u])
        parent[v]=u;
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
}


int main()
{
    int Vertex;
    int Edges;
    cin>>Vertex>>Edges;
    vector<node> edges;
    for(int i=0;i<Edges;i++)
    {
        int weight,u,v;
        cin>>weight>>u>>v;
        edges.push_back(node(weight,u,v));
    }
    sort(edges.begin(),edges.end(),comp);
    vector<int> parent(Vertex);
    for(int i=0;i<Vertex;i++)
    parent[i]=i;
    vector<int> rank(Vertex,0);
    int cost=0;
    vector <pair<int , int>>mst;  // to store mst
    for(auto it:edges)
    {
        if(findPar(it.u,parent)!=findPar(it.v,parent))
        {
            cost+=it.weight;
            mst.push_back({it.u,it.v});
            Union(it.u,it.v,parent,rank);
        }
    }

    cout<<"Printing Mst"<<endl;
    cout<<"Total Cost="<<cost<<endl;
    for(auto it:mst)
    {
        cout<<it.first<<"-"<<it.second<<endl;
    }
 return 0;
}



// 5     Vertex
// 12    Edges

// w u v
// 2 0 1
// 6 0 3
// 2 1 0
// 3 1 2
// 8 1 3
// 5 1 4
// 3 2 1
// 7 2 4
// 6 3 0
// 8 3 1
// 5 4 1
// 7 4 2

// Mst
// Total Cost=16
// 0-1
// 1-2
// 1-4
// 0-3
