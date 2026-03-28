#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
const int MAXL = 65541;
const int MAXN = 205;
int n, L;
int A[MAXN][MAXN];
int twovalue[MAXN][MAXN];
std::vector<int> res;
bool flag[MAXL];
int mask[5][9] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0, 0}};
void binarization(int k)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[i][j] >= k)
                twovalue[i][j] = 1;
        }
    }
}
void getregion(int i,int j,int& min,int& max){
    for (int y = i; y <= i + 4; y++)
    {
        for (int x = j; x <= j + 8; x++)
        {
            min=std::min(A[y][x],min);
            max=std::max(A[y][x],max);
        }
    }
}
bool check(int i, int j, int k)
{
    for (int y = i; y <= i + 4; y++)
    {
        for (int x = j; x <= j + 8; x++)
        {
            if ((A[y][x] >= k) != mask[y - i][x - j])
            {
                return false;
            }
        }
    }
    return true;
}
long long ma = 0b111111111'100100101'100111110'100001100'111111100LL;
long long getbina(int i, int j, int k)
{
    long long res = 0b0LL;
    for (int y = i; y <= i + 4; y++)
    {
        for (int x = j; x <= j + 8; x++)
        {
            res <<= 1;
            if (A[y][x] >= k)
            {
                res |= 0b1LL;
            }
        }
    }
    return res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> L;
    int min = INF, max = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> A[i][j];
            min = std::min(A[i][j], min);
            max = std::max(A[i][j], max);
        }
    }
    std::fill(flag,flag+L,false);
    // for(int k=min+1;k<=max;k++){
    for (int i = 1; i <= n - 4; i++)
    {
        for (int j = 1; j <= n - 8; j++)
        {
            int l=min;
            int r=max;
            getregion(i,j,l,r);
            for (int k = l + 1; k <= r; k++)
            {
                if(flag[k])continue;
                if (check(i, j, k))
                {
                    res.push_back(k);
                    flag[k]=true;
                }
            }
            // if(!(getbina(i,j,k)^ma)){
            //     res.push_back(k);
            // 	nxt=true;
            // 	break;
            // }
        }
    }
    // }
    std::sort(res.begin(), res.end());
    for (auto x : res)
        std::cout << x << "\n";
    return 0;
}