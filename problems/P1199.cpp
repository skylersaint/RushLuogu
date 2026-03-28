#include <bits/stdc++.h>
#define MAX 505
int N;
int chemistry[MAX][MAX];
std::priority_queue<int> general[MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            std::cin >> chemistry[i][j];
            chemistry[j][i] = chemistry[i][j];
        }
        chemistry[i][i] = -1;
    }
    chemistry[N][N] = -1;
    std::priority_queue<int> second;
    for (int i = 1; i <= N; i++)
    {
        general[i] = std::priority_queue<int>(chemistry[i] + 1, chemistry[i] + N + 1);
        general[i].pop();
        second.push(general[i].top());
    }
    std::cout << "1\n"
              << second.top() << "\n";
    return 0;
}
