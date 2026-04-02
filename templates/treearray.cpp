int tree[N], n;

int lowbit(x)
{
    return x & -x;
}
void add(int x, int k)
{
    for (; x <= n; x += lowbit(x))
    {
        tree[x] += k;
    }
}
int query(int x)
{
    int sum = 0;
    for (; x <= n; x -= lowbit(x))
    {
        sum += tree[x];
    }
    return sum;
}
int range_query(int l, int r)
{
    return query(r) - query(l - 1);
}