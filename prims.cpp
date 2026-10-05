#include<bits/stdc++.h>
using namespace std;
int minkey(vector<int> &key, vector<bool> &inMST)
{
 int minval=INT_MAX,minindex=-1;
 for(int i=0; i<key.size(); i++)
 {
     if(!inMST[i] && key[i]<minval)
     {
         minval=key[i];
         minindex=i;
     }
 }
 return minindex;
}
void printMST(vector<vector<int>> &graph, vector<int> &parent,int V)
{
    cout<<"ini"<<"\t"<<"dest"<<"\t"<<"cost"<<endl;
    for(int i=1; i<V;i++)
    {
        cout<<parent[i]<<"\t"<<i<<"\t"<<graph[parent[i]][i]<<endl;
    }
}
int prims(vector<vector<int>> &graph)
{
    int V=graph.size();

    vector<int> parent(V);
    vector<int> key(V,INT_MAX);
    vector<bool>inMST(V,false);

    key[0]=0;
    parent[0]=-1;
    for(int i = 0 ; i<V-1; i++)
    {
        int u = minkey(key,inMST);
        inMST[u]= true;
        for (int v=0; v<V; v++)
        {
            if(!inMST[v] && graph[u][v]!=0 && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    printMST(graph,parent,V);
}
int main(){
vector<vector<int>> graph ={
{0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
};
prims(graph);
}
