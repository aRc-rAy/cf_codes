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

    vector<ll> d(n);
    for (auto &it : d)
        cin >> it;

    vector<ll> ans(n);

    ll low = 0;
    ll high = 0;

    bool ispos = 1;

    vector<pair<ll, ll>> path;
    ll pv = 0;

    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;

        if (d[i] == -1)
        {
            low = low;
            high++;
        }
        else
        {
            low += d[i];
            high += d[i];
        }

        low = max(low, l);
        high = min(high, r);

        if (low > high)
        {
            ispos = false;
        }

        path.push_back({low, high});
    }

    vector<ll> plow(n), phigh(n);
    for (int i = n - 1; i >= 0; i--)
    {
        plow[i] = path[i].first;
        phigh[i] = path[i].second;
        if (i != n - 1)
        {
            plow[i] = max(plow[i], plow[i + 1]);
            phigh[i] = min(phigh[i], phigh[i + 1]);
        }
    }

    if (!ispos)
    {
        cout << -1 << endl;
        return;
    }

    int i = 0;
    ll curh = path[n - 1].first;
    for (int i = n - 1; i >= 0; i--)
    {
        if (d[i] != -1)
        {
            ans[i] = d[i];
            curh -= d[i];
        }
        else
        {
            ll ncur = max(curh - 1, (i ? path[i - 1].first : 0));
            ans[i] = curh - ncur;
            curh -= ans[i];
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
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