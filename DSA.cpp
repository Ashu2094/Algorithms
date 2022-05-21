#include<bits/stdc++.h>
using namespace std;
int cycle=0;
bool alreadystack[5]={0};
void addedge(int v1,int v2,list<int>vect[])
{
    vect[v1].push_back(v2);
    vect[v2].push_back(v1);
}
void printgraph(list<int>vect[],int Vertex)
{
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
void dfs(int v,bool visited[],list<int>vect[])
{
    visited[v]=true;
    alreadystack[v]=true;;
    for(auto x:vect[v])
    {
        
        if(!visited[x])
        {
            for(auto y:vect[x])
            {
                if(visited[y]==true&&alreadystack[y]==true&&y!=v)
                cycle=1;
            }
            dfs(x,visited,vect);
        }
    }
}
int main()
{
    int Vertex=10;
    list<int>vect[Vertex];
    int Edges=10;
    for(int i=0;i<Edges;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        addedge(v1,v2,vect);
    }
    printgraph(vect,Vertex);

    bool visited[Vertex]={0};
    int source=0;
    dfs(source,visited,vect);
    // cout<<"Enter Destination=>";
    // int dest;
    // cin>>dest;
    // if(visited[dest])
    // cout<<"YES"<<endl;
    // else
    // cout<<"NO";
    if(cycle==1)
    cout<<endl<<"Cycle exists";
    else
    cout<<"No Cycle";
 return 0;
}   
