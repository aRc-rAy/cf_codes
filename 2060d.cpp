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
      vector<ll> v(n);

      for (auto &it : v)
      {
            cin >> it;
      }
      for (int i = 0; i < n - 1; i++)
      {
            ll mini = min(v[i], v[i + 1]);
            v[i] -= mini;
            v[i + 1] -= mini;
      }
      for (int i = 1; i < n; i++)
      {
            if (v[i] < v[i - 1])
            {
                  cout << "no" << endl;
                  return;
            }
      }
      cout << "yes" << endl;
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