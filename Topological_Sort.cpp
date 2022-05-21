#include<bits/stdc++.h>
using namespace std;
void addedge(int v1,int v2,list<int>vect[])
{
    vect[v1].push_back(v2);
   // vect[v2].push_back(v1);
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
void dfs(int v,bool visited[],list<int>vect[],stack<int>* postOrder)
{
    visited[v]=true;
    for(auto x:vect[v])
    {
        
        if(!visited[x])
        {
            dfs(x,visited,vect,postOrder);
        }
        
    }
    postOrder->push(v);
    
}


int main()
{
    int Vertex;
    cin>>Vertex;
    list<int>vect[Vertex];
    int Edges;
    cin>>Edges;
    for(int i=0;i<Edges;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        addedge(v1,v2,vect);
    }
    printgraph(vect,Vertex);

    bool visited[Vertex]={0};
    
    stack<int> postOrder;
    for(int i=0;i<Vertex;i++)
    {
        if(!visited[i])
        dfs(i,visited,vect,&postOrder);
    }
    // cout<<"Enter Destination=>";
    // int dest;
    // cin>>dest;
    // if(visited[dest])
    // cout<<"YES"<<endl;
    // else
    // cout<<"NO";
    // if(cycle==1)
    // cout<<endl<<"Cycle exists";
    // else
    // cout<<"No Cycle";
    
    while(!postOrder.empty())
    {
        cout<<postOrder.top()<<" ";
        postOrder.pop();
    }
 return 0;
}   
