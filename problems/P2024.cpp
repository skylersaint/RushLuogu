#include <bits/stdc++.h>

// disjoinset
//  int fa[1e6+5];
int find(int x, int fa[]) { return fa[x] == x ? x : fa[x] = find(fa[x], fa); };
void unite(int x, int y, int fa[]) { fa[find(x, fa)] = find(y, fa); }

const int MAXN = 5e4 + 5;
const int MAXK = 1e5;
int N, K, count = 0;
int ani[MAXN * 3 + 5];
// int ani_eat[MAXN];
// int eat_ani[MAXN];
bool conflict(int rt, int x, int y)
{
    if (rt == 1)
    {
        // x and y is the same special
        if (find(x + N, ani) == find(y, ani) || find(x + 2 * N, ani) == find(y, ani))
        {
            return true;
        }
    }
    if (rt == 2)
    {
        // x+N and y is the same special
        if (find(x, ani) == find(y, ani) || find(x + 2 * N, ani) == find(y, ani))
        {
            return true;
        }
    }
    return false;
}
int main()
{

    std::cin >> N >> K;
    std::memset(ani, 0, sizeof(ani));
    for (int i = 1; i <= 3 * N; i++)
    {
        // ani[i] = i % N == 0 ? N : i % N; // x self
        ani[i] = i;
        // ani_eat[i] = i + N;
        // eat_ani[i] = i + 2 * N;
    } // init disjoinset

    for (int i = 1; i <= K; i++)
    {
        int rt, x, y;
        std::cin >> rt >> x >> y;
        if (x > N || y > N)
        {
            count++;
            continue;
        }
        if (rt == 2 && x == y)
        {
            count++;
            continue;
        }
        if (conflict(rt, x, y))
        {
            count++;
            continue;
        }
        if (rt == 1)
        {
            unite(x, y, ani); // the same kind
            unite(x + N, y + N, ani);
            unite(x + 2 * N, y + 2 * N, ani);
        }
        if (rt == 2)
        {
            unite(x + N, y, ani);
            unite(x + 2 * N, y + N, ani);
            unite(x, y + 2 * N, ani);
        }
    }
    std::cout << count << "\n";
    return 0;
}