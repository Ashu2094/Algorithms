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
void dfs(int v,bool visited[],list<int>vect[],int count,int connArray[])
{
    visited[v]=true;
    connArray[v]=count;
    for(auto x:vect[v])
    {
        
        if(!visited[x])
        {    
            dfs(x,visited,vect,count,connArray);
        }
    }
}
int main()
{
    int Vertex=13;
    list<int>vect[Vertex];
    int Edges=13;
    for(int i=0;i<Edges;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        addedge(v1,v2,vect);
    }
    printgraph(vect,Vertex);

    bool visited[Vertex]={0};
   // int source=0;
     int count=1;
    int connArray[Vertex]={0};
    for(int i=0;i<Vertex;i++)
    {
        if(visited[i]==0)
        {
            dfs(i,visited,vect,count,connArray);
            count++;
        }
        
    }

    for(int i=0;i<Vertex;i++)
    {
        cout<<i<<"\t"<<connArray[i]<<endl;
    }
    cout<<"Total Connected Components=>"<<count-1;
 return 0;
}   
