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

      set<ll> st;
      for (int i = 1; i <= n; i++)
      {
            st.insert(i);
      }
      vector<ll> v(n + 1, -1);
      // start

      for (int i = k; i <= n; i += k)
      {
            v[i] = *st.begin();
            st.erase(*st.begin());
      }
      for (int i = 1; i <= n; i++)
      {
            if (v[i] == -1)
            {
                  v[i] = *st.begin();
                  st.erase(*st.begin());
            }
      }
      for (int i = 1; i <= n; i++)
      {
            cout << v[i] << " ";
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