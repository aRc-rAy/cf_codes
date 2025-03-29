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
      if (n == 1)
      {
            cout << -1 << endl;
            return;
      }
      for (int i = 0; i < n - 1; i++)
      {
            if (s[i] == s[i + 1])
            {
                  cout << s[i] << s[i] << endl;
                  return;
            }
      }
      if (n == 2)
      {
            cout << -1 << endl;
            return;
      }
      unordered_map<char, int> st;
      for (int i = 0; i < 2; i++)
      {
            st[s[i]]++;
      }
      for (int i = 2; i < n; i++)
      {
            st[s[i]]++;
            if (st.size() == 3)
            {
                  cout << s[i - 2] << s[i - 1] << s[i] << endl;
                  return;
            }
            st[s[i - 2]]--;
            if (st[s[i - 2]] == 0)
            {
                  st.erase(s[i]);
            }
      }

      cout << -1 << endl;
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