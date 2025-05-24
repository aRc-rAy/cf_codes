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

    ll rs = 1;
    ll re = n;

    ll cs = 1;
    ll ce = n;

    ll tot = n * n;
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1));
    while (tot)
    {
        for (int i = cs; i <= ce; i++)
        {
            v[rs][i] = tot;
            tot--;
        }
        rs++;
        if (tot == 0)
            break;
        for (int i = rs; i <= re; i++)
        {
            v[i][ce] = tot;
            tot--;
        }
        ce--;
        if (tot == 0)
            break;
        ;
        for (int i = ce; i >= cs; i--)
        {
            v[re][i] = tot;
            tot--;
        }
        re--;
        if (tot == 0)
            break;
        for (int i = re; i >= rs; i--)
        {
            v[i][cs] = tot;
            tot--;
        }
        cs++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << v[i][j] - 1 << " ";
        }
        cout << endl;
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