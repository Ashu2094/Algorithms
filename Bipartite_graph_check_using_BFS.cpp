#include<bits/stdc++.h>
using namespace std;

queue <int> que;
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
void bfs(int source,bool visited[],int edgeto[],list<int>vect[],int vertexlevel[],int twoset[])
{
    //int level=0;
    //int x=0;
    visited[source]=true;
    twoset[source]=0;
    que.push(source);
    edgeto[source]=-1;
    vertexlevel[source]=0;
    while(!que.empty())
    {
        
      //  x++;
        int qfront=que.front();
        que.pop();
        for(auto adjacent:vect[qfront])
        {
            if(!visited[adjacent])
            {
                
                vertexlevel[adjacent]=vertexlevel[qfront]+1;
                twoset[adjacent]=vertexlevel[adjacent]%2;
                que.push(adjacent);
                visited[adjacent]=true;
                edgeto[adjacent]=qfront;
            }
        }
        
    }
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
  //  printgraph(vect,Vertex);

    bool visited[Vertex]={0};
    int source;
    cout<<"Source ";
    cin>>source;
    int edgeto[Vertex]={0};
    int vertexlevel[Vertex]={0};
    int twoset[Vertex]={0};
    bfs(source,visited,edgeto,vect,vertexlevel,twoset);
    //cout<<"ver   "<<"edgfrm   "<<"node level"<<endl;
    // for(int i=0;i<Vertex;i++)
    // {
    //     cout<<i<<"\t"<<edgeto[i]<<"\t"<<vertexlevel[i]<<endl;
    // }
    
    // for(int i=0;i<Vertex;i++)
    // cout<<i<<"\t"<<twoset[i]<<endl;
    
    
    for(int i=0;i<Vertex;i++)
    {
        for(auto x:vect[i])
        {
            if(twoset[i]==twoset[x])
            {
                cout<<"NOT BIPARTITE"<<endl;
                return 0;
            }
        }
    }
    cout<<"BIPARTITE GRAPH";
 return 0;
}   
