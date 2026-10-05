#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra (int v, vector<vector<pair<int,int>>> &adj, int src)
{
    vector<int> dist(v,1e8);

    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    >pq;

    dist[src]=0;
    pq.push(make_pair(0,src));

    while(!pq.empty())
    {
        pair<int,int> current = pq.top();
        pq.pop();

        int d= current.first;
        int u = current.second;

        if(d>dist[u]) continue;

        for(auto e : adj[u])
        {
            int v=e.first;
            int w= e.second;
            if(dist[u]+w < dist[v])
            {
                dist[v]=dist[u]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    return dist;
}

int main(){
int v = 5;
vector<vector<pair<int,int>>> adj(v);

    adj[0].push_back(make_pair(1, 4));
    adj[0].push_back(make_pair(2, 8));

    adj[1].push_back(make_pair(0, 4));
    adj[1].push_back(make_pair(2, 3));
    adj[1].push_back(make_pair(4, 6));

    adj[2].push_back(make_pair(0, 8));
    adj[2].push_back(make_pair(1, 3));
    adj[2].push_back(make_pair(3, 2));

    adj[3].push_back(make_pair(2, 2));
    adj[3].push_back(make_pair(4, 10));

    adj[4].push_back(make_pair(1, 6));
    adj[4].push_back(make_pair(3, 10));

    int source = 0;
    vector<int> result = dijkstra(v, adj, source);
    cout << "Shortest distances from source " << source << ":\n";
    for (int d : result)
        cout <<d<<" ";
    cout<<endl;
    return 0;

}
