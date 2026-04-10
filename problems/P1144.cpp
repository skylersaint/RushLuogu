#include <bits/stdc++.h>
const int MAXN = 1e6 + 5;
const int MOD = 1e5 + 3;
const int INF = 0x3f3f3f3f;
int N, M;
typedef std::pair<int, int> pii; // w,v
std::vector<pii> e[MAXN];
int dist[MAXN];
long long count[MAXN];
bool vis[MAXN];

void dijkstra(int s)
{
    std::memset(dist, 0x3f, sizeof(dist));
    std::memset(vis, false, sizeof(vis));
    std::memset(count, 0, sizeof(count));
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    count[s] = 1;
    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true; // u is choosed

        for (auto [w, v] : e[u])
        {

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                count[v] = count[u];
                pq.push({dist[v], v});
            }
            else if (dist[u] + w == dist[v])
            {
                count[v] = (count[v] + count[u]) % MOD;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int x, y;
        std::cin >> x >> y;
        e[x].push_back({1, y});
        e[y].push_back({1, x});
    }
    dijkstra(1);

    for (int i = 1; i <= N; i++)
    {
        std::cout << (dist[i] == INF ? 0 : (count[i] % MOD)) << "\n";
    }
    return 0;
}