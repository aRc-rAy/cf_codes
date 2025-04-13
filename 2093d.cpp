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
ll rec(ll a, ll b, ll n)
{

      if (n == 1)
            return 1;

      ll part = (n * n) / 4;

      ll hf = n / 2;

      if (a > hf && b > hf)
      {
            return part + rec(a - hf, b - hf, hf);
      }

      if (a > hf && b <= hf)
      {
            return part * 2 + rec(a - hf, b, hf);
      }

      if (a <= hf && b > hf)
      {
            return part * 3 + rec(a, b - hf, hf);
      }

      if (a <= hf && b <= hf)
      {
            return rec(a, b, hf);
      }
      assert(false);
}
pair<ll, ll> find(ll num, ll n, ll act, ll anum)
{

      if (n == 1 || num == 1)
      {
            return {1LL, 1LL};
      }

      ll part = (n * n) / 4;

      ll group = num / part;

      if (num % part)
            group++;

      if (group == 1)
      {
            auto ans = find(num, n / 2, act, anum);
            return ans;
      }

      if (group == 2)
      {
            auto ans = find(num - part, n / 2, act, anum);

            ans.first = ans.first + n / 2;
            ans.second = ans.second + n / 2;

            return ans;
      }

      if (group == 3)
      {
            auto ans = find(num - 2 * part, n / 2, act, anum);
            ans.first = ans.first + n / 2;

            return ans;
      }

      if (group == 4)
      {
            auto ans = find(num - 3 * part, n / 2, act, anum);

            ans.second = ans.second + n / 2;

            return ans;
      }

      assert(group);
}
void solve(ll test)
{
      ll n, q;

      cin >> n >> q;

      n = (1LL << n);
      // cout << n << endl;

      while (q--)
      {
            string s;
            cin >> s;
            if (s == "->")
            {
                  ll x, y;
                  cin >> x >> y;

                  cout << rec(x, y, n) << endl;
            }
            else
            {
                  ll num;
                  cin >> num;
                  // cout << n << endl;
                  auto it = find(num, n, n, num);

                  cout << it.first << " " << it.second << endl;
            }
      }
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