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
void fill(vector<ll> &v, ll l, ll r, ll k, ll value)
{
      if (l == r)
      {
            v[l - 1] = value;
            return;
      }

      ll n = r - l;

      if (n - 1 < 60 && (1LL << (n - 1)) < k)
      {
            v[r - 1] = value;
            fill(v, l, r - 1, k - (1ll << (n - 1)), value + 1);
      }
      else
      {

            v[l - 1] = value;
            fill(v, l + 1, r, k, value + 1);
      }
}
void solve(ll test)
{
      ll n, k;
      cin >> n >> k;

      if (n - 1 < 60 && (1LL << (n - 1)) < k)
      {
            cout << -1 << endl;
            return;
      }

      vector<ll> v(n);

      fill(v, 1, n, k, 1);

      for (auto &it : v)
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