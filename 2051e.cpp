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
ll find(vector<ll> &a, vector<ll> &b, ll mid, ll k)
{
      ll n = a.size();
      ll ck = 0;
      ll cnt = 0;

      for (int i = 0; i < n; i++)
      {
            if (a[i] >= mid)
            {
                  cnt++;
            }
            else if (b[i] >= mid)
            {
                  cnt++;
                  ck++;
            }
      }

      return ck <= k;
}

void solve(ll test)
{
      ll n, k;
      cin >> n >> k;
      vector<ll> a(n);
      vector<ll> b(n);
      for (auto &it : a)
      {
            cin >> it;
      }
      for (auto &it : b)
      {
            cin >> it;
      }

      ll ans = 0;
      map<pair<ll, ll>, ll> ump;

      ump[{0, 0}] = n;

      for (auto it : a)
      {
            ump[{it, 1}]++;
      }
      for (auto it : b)
      {
            ump[{it, 2}]++;
      }
      ll good = n;
      ll bad = 0;
      for (auto it : ump)
      {
            auto cp = it.first;
            ll cnum = cp.first;
            ll cv = cp.second;
            ll count = it.second;

            ll cans = cnum * good;

            // cout << cans << " " << good << " " << bad << endl;
            if (bad <= k)
            {
                  ans = max(ans, cans);
            }

            if (cv == 1)
            {
                  bad += count;
            }
            else if (cv == 2)
            {
                  good -= count;
                  bad -= count;
            }
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