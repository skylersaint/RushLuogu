
// 快速乘
long long fastMultiply(long long a, long long b, long long mod)
{
    long long res = 0; // 注意：加法的初始值是 0，快速幂是 1
    while (b > 0)
    {
        // 如果 b 的当前二进制位是 1，就加上 a
        if (b & 1)
        {
            res += a; // 用加法和取模，绝不溢出
        }
        a = a + a; // a 自身翻倍，相当于 a = a * 2
        b >>= 1;   // b 右移一位，相当于 b /= 2
    }
    return res;
}
// 快速乘取模
long long fastMultiply(long long a, long long b, long long mod)
{
    long long res = 0; // 注意：加法的初始值是 0，快速幂是 1
    a %= mod;
    while (b > 0)
    {
        // 如果 b 的当前二进制位是 1，就加上 a
        if (b & 1)
        {
            res = (res + a) % mod; // 用加法和取模，绝不溢出
        }
        a = (a + a) % mod; // a 自身翻倍，相当于 a = a * 2 % mod
        b >>= 1;           // b 右移一位，相当于 b /= 2
    }
    return res;
}