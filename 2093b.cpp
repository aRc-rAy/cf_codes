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

      int n = s.size();
      int i = n - 1;
      int cnt = 0;
      while (i >= 0 && s[i] == '0')
      {
            i--;
            cnt++;
      }

      for (int t = 0; t < i; t++)
      {
            if (s[t] != '0')
                  cnt++;
      }
      cout << cnt << endl;
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