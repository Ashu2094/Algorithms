#include<bits/stdc++.h>
using namespace std;
void addedge(int v1,int v2,list<int>vect[],list<int>Rvect[])
{
    vect[v1].push_back(v2);
    Rvect[v2].push_back(v1);
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

void dfsp2(int v,bool visited[],list<int>vect[],int count,vector <int>&SrgConnComp)
{
    visited[v]=true;
    SrgConnComp[v]=count;
    for(auto x:vect[v])
    {
        
        if(!visited[x])
        {
            dfsp2(x,visited,vect,count,SrgConnComp);
        }
        
    }
    
    
}


int main()
{
    int Vertex;
    cin>>Vertex;
    list<int>vect[Vertex];
    list<int>Rvect[Vertex];
    int Edges;
    cin>>Edges;
    for(int i=0;i<Edges;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        addedge(v1,v2,vect,Rvect);
    }
    printgraph(vect,Vertex);
    cout<<"Rvect"<<endl;
    printgraph(Rvect,Vertex);

    bool visited[Vertex]={0};
    bool Rvisited[Vertex]={0};
    
    stack<int> postOrder;
    for(int i=0;i<Vertex;i++)
    {
        if(!Rvisited[i])
        dfs(i,Rvisited,Rvect,&postOrder);
    }
    
    
    std::vector<int>topsort(Vertex,0) ;
    for(int i=0;i<Vertex;i++)
    {
        topsort[i]=postOrder.top();
        postOrder.pop();
    }
    for(auto x:topsort)
    cout<<x<<" ";
    cout<<endl;
    vector<int>SrgConnComp(Vertex,0) ;
    int count=1;
    for(auto x:topsort)
    {
        if(!visited[x])
        {
            dfsp2(x,visited,vect,count,SrgConnComp);
            count++;
        }
    }
    
   for(int i=0;i<Vertex;i++)
    {
        cout<<i<<"\t"<<SrgConnComp[i]<<endl;
    }
    cout<<"Total Connected Components=>"<<count-1;
    
 return 0;
}   
