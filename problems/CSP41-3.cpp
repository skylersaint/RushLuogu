#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> free_by_left;
set<pair<ll, ll>> free_by_size;

void add_free(ll l, ll r)
{
    free_by_left[l] = r;
    free_by_size.insert({r - l + 1, l});
}
void remove_free(ll l, ll r)
{
    free_by_left.erase(l);
    free_by_size.erase({r - l + 1, l});
}

struct Interface
{
    ll a, b, last_pos;
};
vector<Interface> proc[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    add_free(0LL, (ll)4e18); // 初始一整块空闲内存

    int n, q;
    cin >> n >> q;
    while (q--)
    {
        string op;
        cin >> op;

        if (op == "new")
        {
            int p, L;
            cin >> p >> L;
            // Best-Fit：最小的够用块，同大小取最左
            auto it = free_by_size.lower_bound({(ll)L, 0LL});
            ll size = it->first, l = it->second;
            ll r = l + size - 1;
            remove_free(l, r);
            if (l + L <= r)
                add_free(l + L, r); // 剩余归还
            proc[p].push_back({l, l + L - 1, -1LL});
            cout << l << "\n";
        }
        else if (op == "send")
        {
            int p;
            cin >> p;
            ll sum = 0;
            for (auto &iface : proc[p])
            {
                ll pos;
                if (iface.last_pos == -1)
                    pos = iface.a;
                else if (iface.last_pos < iface.b)
                    pos = iface.last_pos + 1;
                else
                    pos = iface.a; // 循环回头
                iface.last_pos = pos;
                sum += pos;
            }
            cout << sum << "\n";
        }
        else
        { // delete
            int p, idx;
            cin >> p >> idx;
            idx--; // 转0-indexed
            ll a = proc[p][idx].a, b = proc[p][idx].b;
            proc[p].erase(proc[p].begin() + idx);

            // 合并相邻空闲块
            ll new_l = a, new_r = b;
            auto it = free_by_left.lower_bound(a);
            if (it != free_by_left.begin())
            {
                --it;
                if (it->second + 1 == a)
                { // 左邻居
                    new_l = it->first;
                    remove_free(it->first, it->second);
                }
            }
            it = free_by_left.lower_bound(b + 1);
            if (it != free_by_left.end() && it->first == b + 1)
            { // 右邻居
                new_r = it->second;
                remove_free(it->first, it->second);
            }
            add_free(new_l, new_r);
        }
    }
}