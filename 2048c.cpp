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
      string s;
      cin >> s;
      ll n = s.size();
      ll ind = -1;
      for (int i = 0; i < n; i++)
      {
            if (s[i] == '0')
            {
                  ind = i;
                  break;
            }
      }
      if (ind == -1)
      {
            cout << 1 << " " << n << " " << n << " " << n << endl;
            return;
      }
      string ss = s.substr(ind);
      ll m = ss.size();
      map<string, ll, greater<string>> ump;

      for (int i = 0; i < n; i++)
      {
            string t = "";
            if (i + m - 1 < n)
            {
                  for (int j = i; j < m + i; j++)
                  {
                        if (ss[j - i] != s[j])
                        {
                              t += '1';
                        }
                        else
                        {
                              t += '0';
                        }
                  }

                  if (t.size())
                  {
                        ump[t] = i;
                  }
            }
      }

      cout << 1 << " " << n << " ";
      auto id = ump.begin();

      cout << id->second + 1 << " " << id->second + m << endl;
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