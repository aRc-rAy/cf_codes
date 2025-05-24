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

    ll cp = 0;
    for (int i = 2; i < n; i++)
    {
        if (v[i] == 0)
            cp = 1;
    }

    ll fs = 0;
    if (v[0] == 0 || v[1] == 0)
        fs = 1;

    if (fs == 0 && cp == 0)
    {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;
    }
    if (fs == 1 && cp == 0)
    {
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << n - 1 << endl;
        return;
    }
    if (fs == 1 && cp == 1)
    {
        cout << 3 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << n - 1 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }
    if (fs == 0 && cp == 1)
    {
        cout << 2 << endl;
        cout << 3 << " " << n << endl;
        cout << 1 << " " << 3 << endl;
        return;
    }
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