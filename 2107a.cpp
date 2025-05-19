#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define debug(...) cerr << RED << "Line [" << __LINE__ << "]\t" << #__VA_ARGS__ << " -> ", debug_helper(__VA_ARGS__), cerr << RESET << endl;

void debug_helper() {}

template <typename T, typename... Args>
void debug_helper(T first, Args... args)
{
      cerr << first;
      if (sizeof...(args) > 0)
      {
            cerr << ", ";
            debug_helper(args...);
      }
}
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}

int findPr(int num)
{
      for (int i = 2; i <= 10000; i++)
      {
            if (num % i == 0)
                  return i;
      }
      return 1;
}

void solve(ll test)
{
      ll n;
      cin >> n;

      vector<ll> v(n);
      for (auto &it : v)
            cin >> it;

      ll mx = *max_element(begin(v), end(v));
      ll mi = *min_element(begin(v), end(v));

      if (mx == mi)
      {
            cout << "NO" << endl;
            return;
      }

      cout << "YES" << endl;
      for (auto it : v)
            cout << (it == mx ? "1" : "2") << " ";
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