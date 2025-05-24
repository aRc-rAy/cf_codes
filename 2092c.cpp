#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define debug(...) cerr << RED << "Line [" << __LINE__ << "]\t" << #__VA_ARGS__ << " -> ", debug_helper(__VA_ARGS__), cerr << RESET << endl;

void debug_helper() {}

template <typename T, typename... Args>
void debug_helper(T first, Args... args)
{
    cerr << first;
    if (sizeof...(args) > 0)
    {
        cerr << ", ";
        debug_helper(args...);
    }
}
void inn()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve(ll test)
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    vector<ll> o, e;
    for (auto it : v)
    {
        if (it % 2)
            o.push_back(it);
        if (it % 2 == 0)
            e.push_back(it);
    }
    sort(rbegin(o), rend(o));
    sort(rbegin(e), rend(e));

    //
    if (e.size() == 0)
    {
        cout << o[0] << endl;
        return;
    }

    if (o.size() == 0)
    {
        cout << e[0] << endl;
        return;
    }

    //
    ll cur = o[0];

    int fi = 1;
    ll si = 0;
    while (si < e.size() && fi < o.size())
    {
        cur += o[fi] + e[si] - 1;
        si++;
        fi++;
    }
    while (si < e.size())
    {
        cur += e[si];
        si++;
    }
    while (fi < o.size())
    {
        cur += o[fi] - 1;
        fi++;
    }
    cout << cur << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    inn();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}