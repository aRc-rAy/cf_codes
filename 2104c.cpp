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

    set<ll> a, b;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'A')
            a.insert(i);
        if (c == 'B')
            b.insert(i);
    }

    auto alice = [&]()
    {
        cout << "Alice" << endl;
    };

    auto bob = [&]()
    {
        cout << "Bob" << endl;
    };

    if (n == 2)
    {
        if (a.count(1))
        {
            alice();
        }
        if (b.count(1))
        {
            bob();
        }
        return;
    }

    if (b.size() == 1)
    {
        alice();
        return;
    }

    if (a.count(1) && a.count(n))
    {
        alice();
        return;
    }

    if (a.count(n) && a.count(n - 1))
    {
        alice();
        return;
    }

    bob();
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