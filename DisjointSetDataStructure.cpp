#include<iostream>
using namespace std;
int findPar(int v,int parent[])
{
    if(parent[v]==v) return v;
    return parent[v]=findPar(parent[v],parent);   // path compression
}
void Union(int v1,int v2,int parent[],int rank[])
{
    int u=findPar(v1,parent);
    int v=findPar(v2,parent);

    if(rank[u]<rank[v])
    parent[u]=v;
    else if(rank[u]>rank[v])
    parent[v]=u;
    else{
        parent[v]=u;
        rank[u]++;
    }
}
int main()
{
    int nodes;
    cin>>nodes;
    int parent[nodes+1];
    for(int i=0;i<=nodes;i++)
    parent[i]=i;
    int rank[nodes+1];
    for(int i=0;i<=nodes;i++)
    rank[i]=0;
    int uopt=0;
    cin>>uopt;
    while(uopt>0)
    {
        int v1,v2;
        cin>>v1>>v2;
        Union(v1,v2,parent,rank);
        uopt--;
    }
    for(int i=1;i<=nodes;i++)
    cout<<i<<"->"<<parent[i]<<endl;
    cout<<"To check if same set or not "<<endl;
    int x=3;
    while(x)
    {
        int a,b;
        cin>>a>>b;
        if(findPar(a,parent)==findPar(b,parent))
        cout<<"Same Set"<<endl;
        else
        cout<<"Not same set"<<endl;
    x--;
        
    }
    
 return 0;
}
