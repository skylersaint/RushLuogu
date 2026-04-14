#include <bits/stdc++.h>
using namespace std;

// f(x, k) = ((x*x + k*k) % 8) ^ k
int ft[8][8];

// g 的逆变换：已知输出 val 和密钥 k，求输入
// 正变换: a'=b, b'=c^f(b,k), c'=a^f(c,k)
// 逆变换: b=a', c=b'^f(a',k), a=c'^f(c,k)
int inv_g(int val, int k)
{
    int ap = (val >> 6) & 7;
    int bp = (val >> 3) & 7;
    int cp = val & 7;
    int b = ap;
    int c = bp ^ ft[ap][k];
    int a = cp ^ ft[c][k];
    return (a << 6) | (b << 3) | c;
}

int main()
{
    // 预计算 f 表
    for (int x = 0; x < 8; x++)
        for (int k = 0; k < 8; k++)
            ft[x][k] = ((x * x + k * k) % 8) ^ k;

    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> k(m);
    for (int i = 0; i < m; i++)
        scanf("%d", &k[i]);

    // 核心优化：将 m 步逆变换合成为一个 512 大小的查找表
    // 值域只有 [0, 512)，所以可以预处理整个置换
    int perm[512];
    for (int x = 0; x < 512; x++)
        perm[x] = x;

    // 从最后一步逆变换开始，逐步合成
    for (int i = m - 1; i >= 0; i--)
    {
        int tmp[512];
        for (int x = 0; x < 512; x++)
            tmp[x] = inv_g(perm[x], k[i]);
        memcpy(perm, tmp, sizeof(perm));
    }

    // 每个查询 O(1)
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        printf("%d%c", perm[a], " \n"[i == n - 1]);
    }

    return 0;
}