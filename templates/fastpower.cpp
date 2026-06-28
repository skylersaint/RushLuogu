// 快速幂
long long fastPower(long long base, long long power)
{
    long long res = 1;
    while (power > 0)
    {
        // 如果当前二进制最后一位是 1，说明需要乘上当前的 base
        if (power & 1)
        {
            res *= base;
        }
        base *= base; // 底数不断平方变大：a -> a^2 -> a^4 -> a^8 ...
        power >>= 1;  // 指数右移一位，相当于除以 2
    }
    return res;
}

// 快速幂取模
long long fastPowerMod(long long base, long long power, long long mod)
{
    long long res = 1;
    base %= mod; // 防止 base 本身比 mod 还大
    while (power > 0)
    {
        if (power & 1)
        {
            res = (res * base) % mod; // 乘一次，模一次
        }
        base = (base * base) % mod; // 自身平方后立刻取模
        power >>= 1;
    }
    return res;
}