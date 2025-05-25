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
    sort(begin(v), end(v));

    // even bnane ka cost
    ll fe, fo, le, lo;
    fe = fo = le = lo = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            if (fe == -1)
            {
                fe = i;
            }
            le = i;
        }

        if (v[i] % 2)
        {
            if (fo == -1)
            {
                fo = i;
            }
            lo = i;
        }
    }
    ll anso = fo + (-lo + n - 1);
    ll anse = fe + (-le + n - 1);
    cout << min(anse, anso) << endl;
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