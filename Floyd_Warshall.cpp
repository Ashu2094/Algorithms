#include <bits/stdc++.h>
using namespace std;
int vertices=5;
void floyd_warshall(int V, int arr[5][5])
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (arr[i][k] == INT_MAX || arr[k][j] == INT_MAX)
                    continue;
                else if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
}

void chkNegCycle(int V, int arr[5][5])
{
    for (int i = 0; i < V; i++)
        if (arr[i][i] < 0)
            cout << "Negative Cycle";
}

void printRes(int V, int arr[5][5])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            {
                if(arr[i][j]==INT_MAX)
                cout<<"INF"<<"\t";
                else
                cout << arr[i][j] << "\t";
            }
        cout << endl;
    }
}
int main()
{
    
    
    int arr[5][5] = {
        {0, 10, 5, 5, INT_MAX},
        {INT_MAX, 0, 5, 5, 5},
        {INT_MAX, INT_MAX, 0, INT_MAX, 10},
        {INT_MAX, INT_MAX, INT_MAX, 0, 20},
        {INT_MAX, INT_MAX, INT_MAX, 5, 0}
        
    };
    floyd_warshall(vertices, arr);
    chkNegCycle(vertices, arr);
    printRes(vertices, arr);

    return 0;
}
