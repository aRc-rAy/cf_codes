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
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    if (k == 1)
    {
        ll ml = *max_element(begin(v), end(v) - 1);
        ll mr = *max_element(begin(v) + 1, end(v));
        cout << max(ml + v[n - 1], mr + v[0]) << endl;
        return;
    }

    sort(rbegin(v), rend(v));
    ll sum = 0;
    for (int i = 0; i <= k; i++)
        sum += v[i];
    cout << sum << endl;
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