#include <bits/stdc++.h>

const int MAXN = 2e4 + 5;
const int MAXM = 1e5 + 5;
const int INF = 0x3f3f3f3f;
typedef std::tuple<int, int, int> wuv;
int N, M;
int p[2 * MAXN]; // disjoinset
std::priority_queue<wuv, std::vector<wuv>, std::less<wuv>> pq;
std::vector<wuv> e;

// disjoinset
int find(int x, int fa[]) { return fa[x] == x ? x : fa[x] = find(fa[x], fa); }
void unite(int x, int y, int fa[]) { fa[find(x, fa)] = find(y, fa); }
bool check(int maxhate)
{
    for (int i = 1; i <= 2 * N; i++)
    {
        p[i] = i;
    }
    for (auto [c, a, b] : e)
    {
        if (find(a, p) != find(b, p) && find(a + N, p) == find(b, p))
        {
            continue;
        }
        if (find(a, p) == find(b, p))
        {
            if (c > maxhate)
                return false;
        }
        if (find(a, p) != find(b, p) && find(a + N, p) != find(b, p))
        {
            unite(a + N, b, p);
            unite(b + N, a, p);
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        pq.push({c, a, b});
        e.push_back({c, a, b});
    }
    std::sort(e.begin(), e.end(), std::greater<wuv>());
    if (M <= 2)
        std::cout << "0\n";
    if (M == 3)
    {
        pq.pop();
        pq.pop();
        auto [c, a, b] = pq.top();
        std::cout << c << "\n";
    }
    if (M >= 4)
    {
        int left = 0;
        auto [right, _, __] = pq.top();
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