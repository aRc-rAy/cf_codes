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
      vector<ll> v(n), l(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      for (auto &it : l)
      {
            cin >> it;
      }
      vector<ll> ord;
      for (int i = 0; i < n; i++)
      {
            if (l[i] == 0)
            {
                  ord.push_back(v[i]);
            }
      }
      sort(rbegin(ord), rend(ord));
      ll j = 0;
      for (int i = 0; i < n; i++)
      {
            if (l[i] == 0)
            {
                  v[i] = ord[j++];
            }
      }
      for (auto it : v)
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