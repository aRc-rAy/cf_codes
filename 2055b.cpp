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
      ll n;
      cin >> n;

      ll red = 0;
      vector<ll> a(n), b(n);

      for (auto &it : a)
      {
            cin >> it;
      }

      for (auto &it : b)
      {
            cin >> it;
      }

      auto t = a;

      for (int i = 0; i < n; i++)
      {
            if (b[i] > a[i])
            {
                  ll dif = b[i] - a[i];
                  t[i] += 2 * dif;
                  red -= dif;
            }
      }
      for (auto &it : t)
      {
            it += red;
      }

      for (int i = 0; i < n; i++)
      {
            if (t[i] < b[i])
            {
                  cout << "NO" << endl;
                  return;
            }
      }
      cout << "YES" << endl;
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