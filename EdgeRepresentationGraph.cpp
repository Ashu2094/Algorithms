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

void addedge(int v1,int v2,list<int>vect[],vector<node>& edges,int weight)
{
    vect[v1].push_back(v2);
    vect[v2].push_back(v1);
    edges.push_back(node(weight,v1,v2));
}
void printgraph(list<int>vect[],int Vertex)
{
    cout<<"Adjancy List"<<endl;
    for(int i=0;i<Vertex;i++)
    {
        cout<<i<<"->";
        for(auto x:vect[i])
        {
            cout<<x<<"-";
        }
        cout<<endl;
    }
}
void printedge(vector<node>& edges)
{
    cout<<"Edge List"<<endl;
    for(auto x:edges)
    cout<<x.u<<"-"<<x.v<<"=="<<x.weight<<endl;
}

int main()
{
    int Vertex=10;
    cin>>Vertex;
    list<int>vect[Vertex];
    int Edges=10;
    cin>>Edges;
    vector<node> edges;
    for(int i=0;i<Edges;i++)
    {
        int v1,v2,weight;
        cin>>v1>>v2>>weight;
        addedge(v1,v2,vect,edges,weight);
    }
    printgraph(vect,Vertex);
    printedge(edges);

    
    
 return 0;
}   
