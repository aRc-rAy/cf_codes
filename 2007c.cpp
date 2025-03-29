#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}
void solve(ll test)
{
      ll n, a, b;
      cin >> n >> a >> b;
      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }

      ll gc = __gcd(a, b);

      vector<ll> rem;
      for (auto it : v)
      {
            rem.push_back(it % gc);
      }

      sort(begin(rem), end(rem));
      ll ans = rem.back() - rem[0];
      for (int i = 0; i < n - 1; i++)
      {
            ans = min(ans, rem[i] + gc - rem[i + 1]);
      }

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