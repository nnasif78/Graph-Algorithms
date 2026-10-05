#include<bits/stdc++.h>
using namespace std;

class DSU{
vector<int> parent,rank;
public:
    DSU(int n){
    parent.resize(n);
    rank.resize(n,0);
    for(int i=0;i<n;i++)parent[i]=i;
    }
    int findS(int x){
    if(parent[x]==x)return x;
    return parent[x]=findS(parent[x]);
    }
    void unite(int x, int y)
    {
        int px = findS(x);
        int py = findS(y);

        if(px == py) return;

        if(rank[px]>rank[py])parent[py]=px;
        if(rank[py]>rank[px])parent[px]=py;
        if(rank[px]==rank[py])
        {
            parent[py]=px;
            rank[px]++;
        }

    }
};
bool compare(vector<int> &a,vector<int> &b)
{
    return a[2]<b[2];
}
int krus(vector<vector<int>> &edges, int v){
    sort(edges.begin(),edges.end(),compare);
    DSU dsu(v);

    int mstcost=0,edgecnt=0;
    for(auto e : edges)
    {
        int u=e[0],V=e[1],w=e[2];
        if(dsu.findS(u)!=dsu.findS(V))
        {
            dsu.unite(u,V);
            mstcost+=w;
            edgecnt++;
        }
        if(edgecnt==v-1)break;
    }
    return mstcost;
}
int main(){
int v=4;
vector<vector<int>> edges={
{0, 1, 10},
        {1, 3, 15},
        {2, 3, 4},
        {2, 0, 6},
        {0, 3, 5}
};
int res = krus(edges,v);
cout<<res;
}
