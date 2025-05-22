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

    ll n, k;
    cin >> n >> k;
    ll mini = 1e11;
    ll maxi = -1;
    ll sum = 0;

    map<ll, ll> ump;
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        sum += temp;

        mini = min(mini, temp);
        maxi = max(maxi, temp);

        ump[temp]++;
    }

    if (ump[maxi] > 1)
        maxi++;

    if (sum % 2 == 0 || (maxi - 1 - mini > k))
    {
        cout << "Jerry" << endl;
        return;
    }

    cout << "Tom" << endl;
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