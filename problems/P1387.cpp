#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX 105
int matrix[MAX][MAX] = {0};
int presum[MAX][MAX] = {0};
int getsum(int x1, int y1, int x2, int y2)
{
    return presum[x2][y2] - presum[x2][y1 - 1] - presum[x1 - 1][y2] + presum[x1 - 1][y1 - 1];
}
int main()
{
    int n, m = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> matrix[i][j];
            presum[i][j] = presum[i][j - 1] + presum[i - 1][j] - presum[i - 1][j - 1] + matrix[i][j];
        }
    }
    int maxsquare = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (matrix[i][j] == 0)
                continue;
            if (maxsquare < matrix[i][j])
                maxsquare = matrix[i][j];
            for (int s = maxsquare; i + s <= n && j + s <= m; s++)
            {
                int target = (s + 1) * (s + 1);
                int sum = getsum(i, j, i + s, j + s);
                if (sum == target && maxsquare < s + 1)
                    maxsquare = s + 1;
            }
        }
    }
    std::cout << maxsquare << std::endl;
    return 0;
}