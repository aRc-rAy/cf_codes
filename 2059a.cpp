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
      set<ll> a, b;
      for (int i = 0; i < n; i++)
      {
            ll num;
            cin >> num;
            a.insert(num);
      }
      ll sa = a.size();
      for (int i = 0; i < n; i++)
      {
            ll num;
            cin >> num;
            b.insert(num);
      }
      ll sb = b.size();

      if (sa > sb)
            swap(a, b);

      if (sa >= 3)
      {
            cout << "yes" << endl;
            return;
      }

      if (sa >= 2)
      {
            if (sb >= 2)
            {
                  cout << "yes" << endl;
                  return;
            }
      }
      if (sa >= 1)
      {
            if (sb >= 3)
            {
                  cout << "yes" << endl;
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