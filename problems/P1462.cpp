#include <bits/stdc++.h>
const int MAXN = 1e4 + 5;
const int MAXM = 5e4 + 5;
const int INF = 0x3f3f3f3f;
typedef std::pair<int, int> pii;
std::vector<pii> e[MAXM];
int dis[MAXN];
bool vis[MAXN];
int n, m, b;
int f[MAXN];
// std::vector<std::vector<int>> path[MAXM];
// void bfs(int s)
// {
//     std::memset(dis, INF, sizeof(dis));
//     std::memset(vis, false, sizeof(vis));
//     std::queue<pii> q;
//     q.push({0, s});
//     vis[s] = true;
//     dis[s] = 0;
//     path[s].push_back({s});

//     while (!q.empty())
//     {
//         auto [uw, u] = q.front();
//         q.pop();
//         for (auto [w, v] : e[u])
//         {
//             if (!vis[v])
//             {
//                 if (uw + w <= b)
//                 { // arrivable
//                     dis[v] = dis[u] + w;
//                     path[v] = path[u];
//                     for (auto &x : path[v])
//                     {
//                         x.push_back(v);
//                     }
//                 }
//                 q.push({dis[v], v});
//                 vis[v] = true;
//             }
//         }
//     }
// }
void dijkstra(int s, int maxvalue)
{
    std::memset(dis, INF, sizeof(dis));
    std::memset(vis, false, sizeof(vis));
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    if (f[s] <= maxvalue)
    {
        pq.push({0, s});
        dis[s] = 0;
    }
    while (!pq.empty())
    {
        auto [u_w, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto [w, v] : e[u])
        {
            if (f[v] > maxvalue)
                continue;
            if (dis[u] + w <= dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}
bool check(int maxvalue)
{
    // for (auto x : path[n])
    // { // one path
    //     for (auto y : x)
    //     {
    //         if (f[y] > maxvalue)
    //             return false;
    //     }
    // }
    dijkstra(1, maxvalue);
    if (dis[n] > b)
        return false;
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> b;
    int max_f = -INF;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> f[i];
        max_f = std::max(max_f, f[i]);
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        e[a].push_back({c, b});
        e[b].push_back({c, a});
    }
    dijkstra(1, max_f); // get min path from 1-x;
    // bfs(1);
    if (dis[n] > b)
    {
        std::cout << "AFK\n";
    }
    else
    { // answer divided by two
        int left = 0;
        int right = max_f;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (check(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        std::cout << left << "\n";
    }

    return 0;
}