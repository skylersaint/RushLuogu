#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

// 线段树不开 4 倍空间容易 RE（越界）
int tree[MAXN << 2];
int arr[MAXN]; // 原始数组
int n;

// ---------------- 1. 建树 ----------------
// p: 当前节点编号, l/r: 当前节点维护的区间左右端点
void build(int p, int l, int r)
{
    if (l == r)
    {
        tree[p] = arr[l]; // 叶子节点，直接赋原数组的值
        return;
    }
    int mid = (l + r) >> 1;
    int left_child = p << 1;      // p * 2
    int right_child = p << 1 | 1; // p * 2 + 1

    build(left_child, l, mid);      // 递归建左子树
    build(right_child, mid + 1, r); // 递归建右子树

    // 回溯时，父节点的值 = 左孩子 + 右孩子
    tree[p] = tree[left_child] + tree[right_child];
}

// ---------------- 2. 单点修改 ----------------
// 在 pos 位置加上 k
void add(int p, int l, int r, int pos, int k)
{
    if (l == r)
    {
        tree[p] += k; // 找到目标叶子节点，修改
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        add(p << 1, l, mid, pos, k); // 目标在左子树
    }
    else
    {
        add(p << 1 | 1, mid + 1, r, pos, k); // 目标在右子树
    }
    // 回溯时，更新受影响的所有父节点
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

// ---------------- 3. 区间查询 ----------------
// 查询 [ql, qr] 的和
int query(int p, int l, int r, int ql, int qr)
{
    // 剪枝1：当前区间完全在查询范围外，直接返回 0（不影响结果）
    if (ql > r || qr < l)
        return 0;

    // 剪枝2：当前区间完全被查询范围包含，直接返回该节点的值（核心提速点）
    if (ql <= l && r <= qr)
        return tree[p];

    // 剪枝3：部分重叠，必须往下递归
    int mid = (l + r) >> 1;
    // 左边查左边的，右边查右边的，加起来
    return query(p << 1, l, mid, ql, qr) +
           query(p << 1 | 1, mid + 1, r, ql, qr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 假设输入 n 和数组
    if (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        // 1 号节点代表区间 [1, n]
        build(1, 1, n);

        // 测试：把第 2 个位置加上 5
        add(1, 1, n, 2, 5);

        // 测试：查询 [1, 4] 的和
        cout << query(1, 1, n, 1, 4) << "\n";
    }
    return 0;
}
