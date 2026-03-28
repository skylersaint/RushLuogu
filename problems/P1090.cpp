#include <bits/stdc++.h>

#define MAX 10005
int a[MAX] = {0};
int n = 0;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        std::cin >> tmp;
        pq.push(tmp);
    }
    int mincost = 0;
    while (pq.size() != 1)
    {
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        int merge = one + two;
        mincost += merge;
        pq.push(merge);
    }
    std::cout << mincost << "\n";
    return 0;
}
