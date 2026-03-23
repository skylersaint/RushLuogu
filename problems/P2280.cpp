#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <algorithm>
#define MAX 5005
int matrix[MAX][MAX] = {0};
int presum[MAX][MAX] = {0};
int getsum(int x1, int y1, int x2, int y2)
{
    return presum[x2][y2] - presum[x2][y1 - 1] - presum[x1 - 1][y2] + presum[x1 - 1][y1 - 1];
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    int maxvalue = 0;
    int max_x = 0, max_y = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = 0, y = 0, value = 0;
        std::cin >> x >> y;
        x += 1;
        y += 1;
        max_x = std::max(x, max_x);
        max_y = std::max(y, max_y);
        std::cin >> value;
        matrix[x][y] += value;
    }

    for (int i = 1; i <= max_x; i++)
    {
        for (int j = 1; j <= max_y; j++)
        {
            presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + matrix[i][j];
        }
    }
    for (int i = 1; i <= max_x; i++)
    {
        for (int j = 1; j <= max_y; j++)
        {
            int sum = getsum(i, j, std::min(max_x, i + m - 1), std::min(max_y, j + m - 1));
            maxvalue = std::max(sum, maxvalue);
        }
    }
    std::cout << maxvalue << std::endl;
    return 0;
}