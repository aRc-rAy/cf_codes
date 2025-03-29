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

bool check(vector<ll> &v, string &s)
{
      bool pos = 1;
      ll n = s.size();

      for (int i = 0; i < n; i++)
      {
            if (s[i] == 's')
            {
                  set<ll> st;
                  for (int j = i; j < n; j++)
                  {
                        st.insert(v[j]);
                  }
                  ll tot = n - i;
                  if (*st.begin() != 1)
                  {
                        pos = 0;
                  }
                  if (*st.rbegin() != (tot))
                  {
                        pos = 0;
                  }
            }

            if (s[i] == 'p')
            {
                  set<ll> st;
                  for (int j = 0; j <= i; j++)
                  {
                        st.insert(v[j]);
                  }
                  ll tot = i + 1;
                  if (*st.begin() != 1)
                  {
                        pos = 0;
                  }
                  if (*st.rbegin() != tot)
                  {
                        pos = 0;
                  }
            }
      }

      return pos;
}
void solve(ll test)
{
      ll n;
      cin >> n;
      string s;
      cin >> s;

      ll cnt = 1;

      bool pos = 1;

      vector<ll> v(n);
      for (int i = 0; i < n; i++)
      {
            v[i] = i + 1;
      }

      bool ans = check(v, s);
      if (ans)
      {
            cout << "yes" << endl;
            return;
      }

      reverse(begin(v), end(v));

      ans = check(v, s);

      cout << (ans ? "yes" : "no") << endl;
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