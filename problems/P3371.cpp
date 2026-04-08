#include <bits/stdc++.h>
const int MAXN = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m, s;
typedef std::pair<int, int> pii; // dist, id
std::vector<pii> g[MAXN];
int dist[MAXN];
bool vis[MAXN];
void dijkstra(int s)
{
    // init
    std::memset(dist, 0x3f, sizeof(dist));
    std::memset(vis, false, sizeof(vis));
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto [w, v] : g[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // input
    std::cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
    // solve
    dijkstra(s);
    // output
    for (int i = 1; i <= n; i++)
    {
        std::cout << (dist[i] != INF ? dist[i] : INT_MAX) << " \n"[i == n];
    }
    return 0;
}
