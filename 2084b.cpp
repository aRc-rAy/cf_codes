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
    {
        cin >> it;
    }
    map<ll, ll> ump;
    for (auto it : v)
    {
        ump[it]++;
    }
    ll mini = ump.begin()->first;
    // count of mini
    ll cmini = ump[mini];

    if (cmini > 1)
    {
        cout << "YES" << endl;
        return;
    }

    // divide by mini
    vector<ll> dvmini;
    for (auto it : ump)
    {
        if (it.first == mini)
            continue;
        if (it.first % mini == 0)
            dvmini.push_back(it.first);
    }

    if (dvmini.size() == 0)
    {
        cout << "NO" << endl;
        return;
    }
    ll gcd = dvmini[0];
    for (int i = 1; i < dvmini.size(); i++)
    {
        gcd = __gcd(gcd, dvmini[i]);
        if (gcd == mini)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;
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