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
    ll n, x;
    cin >> n >> x;

    ll sb = __builtin_popcount(x);
    // debug(sb);

    if (n <= sb)
    {
        cout << x << endl;
        return;
    }
    n = n - sb;
    debug(n, sb);

    if (n % 2 == 0)
    {
        cout << x + n << endl;
    }

    if (x & 1)
    {

        if (x == 1)
        {
            cout << x + (n - 1) + 4 << endl;
        }
        else
            cout << x + 1 + n << endl;
    }
    if ((x & 1) == 0)
    {

        if (x != 0)
        {
            cout << x + n + 1 << endl;
        }
        else
        {
            if (n == 1)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << n - 1 + 4 << endl;
            }
        }
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