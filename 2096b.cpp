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
    ll k;
    cin >> k;
    vector<ll> v;

    vector<ll> f(n);
    vector<ll> s(n);
    for (auto &it : f)
        cin >> it;
    for (auto &it : s)
        cin >> it;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        a = f[i];
        b = s[i];
        if (a > b)
            swap(a, b);

        // a small
        // b large
        ans += b;

        v.push_back(a);
    }
    sort(rbegin(v), rend(v));
    debug(ans);
    for (int i = 0; i < k - 1; i++)
    {
        ans += v[i];
    }
    debug(ans);
    ans++;
    cout << ans << endl;
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