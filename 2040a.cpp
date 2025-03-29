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
      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }

      for (int i = 0; i < n; i++)
      {
            bool pos = 1;
            for (int j = 0; j < n; j++)
            {
                  if (i != j && abs(v[i] - v[j]) % k == 0)
                  {
                        pos = 0;
                  }
            }
            if (pos)
            {
                  cout << "yes" << endl;
                  cout << i + 1 << endl;
                  return;
            }
      }
      cout << "no" << endl;
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