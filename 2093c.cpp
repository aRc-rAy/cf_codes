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
bool isPrime(int n)
{
      if (n < 2)
            return false;

      for (int i = 2; i <= sqrt(n); i++)
      {
            if (n % i == 0)
                  return false;
      }
      return true;
}
void solve(ll test)
{
      ll a, b;
      cin >> a >> b;

      if (b > 1 && a != 1)
      {
            cout << "no" << endl;
            return;
      }

      if (a == 1)
      {
            for (int i = 1; i < b; i++)
            {
                  a = a * 10 + 1;
            }
            // cout << a << endl;
      }

      bool check = isPrime(a);

      cout << (check ? "yes" : "no") << endl;
}
int main()
{
      auto start = std::chrono::high_resolution_clock::now();
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t = 1;
      cin >> t;
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> elapsed = end - start;

      std::cerr << "Elapsed time: " << elapsed.count() << " s\n";
      return 0;
}