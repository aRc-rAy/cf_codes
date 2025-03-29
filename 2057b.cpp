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
      ll n, k;
      cin >> n >> k;
      map<ll, ll> ump;
      for (int i = 0; i < n; i++)
      {
            ll num;
            cin >> num;
            ump[num]++;
      }
      vector<ll> low;
      ll cnt = 0;
      for (auto it : ump)
      {
            low.push_back(it.second);
      }
      sort(begin(low), end(low));

      ll ctot = 0;
      ll rem = 0;

      bool bichme = 0;

      for (int i = 0; i < low.size() - 1; i++)
      {
            if (low[i] + ctot <= k)
            {
                  ctot += low[i];
            }
            else
            {
                  bichme = 1;
                  rem = (low.size() - 1 - i);
                  break;
            }
      }
      cout << rem + 1 << endl;
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