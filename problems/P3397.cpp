// #include "cp.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <string>

using namespace std;
#define MAXNUM 1005
struct Point
{
    int x;
    int y;
};

int diff[MAXNUM][MAXNUM] = {0};
int res[MAXNUM][MAXNUM] = {0};
int main()
{
    // input
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        // std::cin>>rugs[i].lefttop.x>>rugs[i].lefttop.y>>rugs[i].rightbottom.x>>rugs[i].rightbottom.y;
        Point lt, rb;
        std::cin >> lt.x >> lt.y >> rb.x >> rb.y;
        // solving
        diff[lt.x][lt.y] += 1;
        diff[rb.x + 1][lt.y] -= 1;
        diff[lt.x][rb.y + 1] -= 1;
        diff[rb.x + 1][rb.y + 1] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            res[i][j] = res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1] + diff[i][j];
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // output
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         std::cout << res[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return 0;
}
