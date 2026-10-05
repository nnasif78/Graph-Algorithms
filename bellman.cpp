#include<bits/stdc++.h>
using namespace std;
vector<int> bellman(vector<vector<int>> &edges, int v, int src)
{
    vector<int> dist(v,1e9);
    dist[src]=0;
    for(int i =1; i<v; i++)
    {
        for(auto e :edges)
        {
            int u= e[0],V=e[1],w=e[2];
            if(dist[u]!=1e9 && dist[u]+w<dist[V])
                dist[V]=dist[u]+w;
        }
    }
    for(auto e :edges)
        {
            int u= e[0],V=e[1],w=e[2];
            if(dist[u]!=1e9 && dist[u]+w<dist[V])
            {

                cout<<"Negative weight cycle detected!";
                return{};
            }
        }
        return dist;
}
int main()
{

    int v=5;
    vector<vector<int>> edges ={
        {1, 3, 2},
        {4, 3, -1},
        {2, 4, 1},
        {1, 2, 1},
        {0, 1, 5}
    };
    int src=0;
    vector<int> res = bellman(edges,v,src);
    for(int i : res)
        cout<<i<<" ";
}
