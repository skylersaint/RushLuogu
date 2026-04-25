#include <bits/stdc++.h>
using namespace std;

int Z;
char g[405][405];
char tmp[15][15]; // 子矩阵最大10x10

// rot 记录当前累计的顺时针旋转次数 (0~3)
// 含义：真实图 = 当前 g 顺时针旋转 rot 个90度
// 也就是说 g 中存的是"被逆时针转了 rot 个90度"的状态

// 给定"真实坐标"(r,c)，返回 g 中对应的位置
// 顺时针转 rot 次的逆 = 逆时针转 rot 次
// 逆时针90: (r,c) -> (Z+1-c, r)
pair<int, int> real2g(int r, int c, int rot)
{
    // 逆时针90转 rot 次
    switch (rot % 4)
    {
    case 0:
        return {r, c};
    case 1:
        return {Z + 1 - c, r};
    case 2:
        return {Z + 1 - r, Z + 1 - c};
    case 3:
        return {c, Z + 1 - r};
    }
    return {r, c}; // 不会到这
}

// 在"真实坐标系"下读取 g[r][c]
char getCell(int r, int c, int rot)
{
    auto [gr, gc] = real2g(r, c, rot);
    return g[gr][gc];
}

// 在"真实坐标系"下设置 g[r][c] = ch
void setCell(int r, int c, int rot, char ch)
{
    auto [gr, gc] = real2g(r, c, rot);
    g[gr][gc] = ch;
}

int main()
{
    scanf("%d", &Z);
    for (int i = 1; i <= Z; i++)
    {
        char s[405];
        scanf("%s", s);
        for (int j = 1; j <= Z; j++)
            g[i][j] = s[j - 1];
    }

    int k;
    scanf("%d", &k);
    vector<int> K(k);
    for (int i = 0; i < k; i++)
        scanf("%d", &K[i]);

    int t = K[0];
    vector<vector<int>> ops(t);
    int pos = 1;
    for (int i = 0; i < t; i++)
    {
        ops[i].resize(6);
        for (int j = 0; j < 6; j++)
            ops[i][j] = K[pos++];
    }

    // rot: 从"g存储的状态"到"真实图"需要顺时针转多少个90度
    // 初始 rot=0，g 就是真实图
    int rot = 0;

    for (int i = t - 1; i >= 0; i--)
    {
        int op = ops[i][0];

        if (op == 1)
        {
            // 加密过程:
            //   1) 子矩阵(u,v,L) 顺时针转 d 度
            //   2) 整体逆时针90 × r 次
            // 逆操作(倒着):
            //   1) 撤销整体旋转: 累加 rot
            //   2) 撤销子矩阵旋转: 在真实坐标系下逆向旋转

            int u = ops[i][1], v = ops[i][2], L = ops[i][3];
            int d = ops[i][4], r = ops[i][5];

            // 撤销 r 次逆时针90 = 顺时针90 × r 次
            rot = (rot + r) % 4;

            // 撤销子矩阵顺时针 d 度：
            // 在真实坐标系下，把子矩阵(u,v,L)逆时针转 d 度
            // 逆时针 d 度 = 顺时针 (360-d) 度
            // d=90 -> 逆时针90(=顺时针270, 即转3次)
            // d=180 -> 180(转2次)
            // d=270 -> 逆时针270(=顺时针90, 即转1次)
            int times; // 顺时针90的次数
            if (d == 90)
                times = 3;
            else if (d == 180)
                times = 2;
            else
                times = 1; // d==270

            // 用真实坐标读子矩阵到 tmp，顺时针转 times 个90度后写回
            for (int q = 0; q < times; q++)
            {
                // 读出子矩阵
                for (int a = 0; a < L; a++)
                    for (int b = 0; b < L; b++)
                        tmp[a][b] = getCell(u + a, v + b, rot);
                // 顺时针90: (a,b) -> (b, L-1-a)
                for (int a = 0; a < L; a++)
                    for (int b = 0; b < L; b++)
                        setCell(u + b, v + L - 1 - a, rot, tmp[a][b]);
            }
        }
        else
        {
            // op == 2 翻转, 自逆操作
            int u = ops[i][1], d2 = ops[i][2];
            int l = ops[i][3], r2 = ops[i][4];
            int o = ops[i][5];

            int h = d2 - u + 1, w = r2 - l + 1;

            if (o == 1)
            {
                // 上下翻转: (a,b) <-> (h-1-a, b)
                // 只需交换上半和下半
                for (int a = 0; a < h / 2; a++)
                    for (int b = 0; b < w; b++)
                    {
                        char c1 = getCell(u + a, l + b, rot);
                        char c2 = getCell(u + h - 1 - a, l + b, rot);
                        setCell(u + a, l + b, rot, c2);
                        setCell(u + h - 1 - a, l + b, rot, c1);
                    }
            }
            else
            {
                // 左右翻转: (a,b) <-> (a, w-1-b)
                for (int a = 0; a < h; a++)
                    for (int b = 0; b < w / 2; b++)
                    {
                        char c1 = getCell(u + a, l + b, rot);
                        char c2 = getCell(u + a, l + w - 1 - b, rot);
                        setCell(u + a, l + b, rot, c2);
                        setCell(u + a, l + w - 1 - b, rot, c1);
                    }
            }
        }
    }

    // 现在 g + rot 表示 A0
    // 找原图范围：找最大的 n,m 使得真实坐标 (n,m) 处有非'?'
    int n = 0, m = 0;
    for (int i = 1; i <= Z; i++)
        for (int j = 1; j <= Z; j++)
        {
            char ch = getCell(i, j, rot);
            if (ch != '?')
            {
                n = max(n, i);
                m = max(m, j);
            }
        }

    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            putchar(getCell(i, j, rot));
        putchar('\n');
    }

    return 0;
}