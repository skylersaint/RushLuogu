#include <bits/stdc++.h>

#define MAX 30005

int w;
int n;
int p[MAX];
int flag[MAX] = {0};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> w >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> p[i];
    }
    std::fill(flag + 1, flag + n + 1, 0);
    std::sort(p + 1, p + n + 1);
    int count = 0;
    for (int i = n; i >= 1; i--)
    {
        if (flag[i] == 1)
            continue;
        if (p[i] >= w)
        {
        }
        else
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (flag[j])
                    continue;
                if (p[j] <= w - p[i])
                {
                    flag[j] = 1;
                    break;
                }
            }
        }
        flag[i] = 1;
        count++;
    }
    std::cout << count << "\n";
    return 0;
}
