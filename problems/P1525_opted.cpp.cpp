#include <bits/stdc++.h>

const int MAXN = 2e4 + 5;
const int MAXM = 1e5 + 5;
const int INF = 0x3f3f3f3f;
typedef std::tuple<int, int, int> wuv;
int N, M;
int p[2 * MAXN]; // disjoinset
std::vector<wuv> e;

// disjoinset
int find(int x, int fa[]) { return fa[x] == x ? x : fa[x] = find(fa[x], fa); }
void unite(int x, int y, int fa[]) { fa[find(x, fa)] = find(y, fa); }

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;
    for (int i = 1; i <= 2 * N; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        e.push_back({c, a, b});
    }
    std::sort(e.begin(), e.end(), std::greater<wuv>());
    for (auto [c, a, b] : e)
    {
        if (find(a, p) == find(b, p))
        { // at the same prison
            std::cout << c << "\n";
            return 0;
        }
        if (find(a + N, p) == find(b, p))
        { // at the different prison
            continue;
        }
        unite(a + N, b, p);
        unite(b + N, a, p);
    }
    std::cout << "0\n";
    return 0;
}