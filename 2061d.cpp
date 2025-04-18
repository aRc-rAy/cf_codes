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
      ll n, m;
      cin >> n >> m;

      priority_queue<ll> a, b;
      for (int i = 0; i < n; i++)
      {
            ll num;
            cin >> num;
            a.push(num);
      }
      for (int i = 0; i < m; i++)
      {
            ll num;
            cin >> num;
            b.push(num);
      }

      while (a.size())
      {
            if (b.empty() || b.size() > a.size())
            {
                  cout << "no" << endl;
                  return;
            }

            ll num = b.top();
            b.pop();

            if (a.top() > num)
            {
                  cout << "no" << endl;
                  return;
            }

            if (a.top() == num)
            {
                  a.pop();
                  continue;
            }

            b.push((num) / 2);
            b.push((num + 1) / 2);
      }

      if (!b.empty())
      {
            cout << "no" << endl;
            return;
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