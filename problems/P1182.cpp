#include <bits/stdc++.h>

int A[100005] = {0};
int N = 0, M = 0;
bool check(long ans) // ans expresses the max sum of every segments
{
    // check ans
    int segments = 1;
    long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (A[i] > ans)
        {
            // 单个元素就超过ans，不可能
            return false;
        }

        if (sum + A[i] <= ans)
        {
            // 当前段可以继续扩展
            sum += A[i];
        }
        else
        {
            // 需要开启新段
            segments++;
            sum = A[i];
            if (segments > M)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;
    long left = 1, right = 0;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> A[i];
        right += A[i];
    }
    while (left < right)
    {
        long mid = left + (right - left) / 2;
        if (check(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    } // left is the min value of anses
    std::cout << left << "\n";
    return 0;
}