#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
// #define mod 1000000007
#define MAXX 100005

const int MOD = 998244353;

vector<long long> factorial, inv_factorial;

long long mod_exp(long long base, long long exp, long long mod)
{
      long long result = 1;
      while (exp > 0)
      {
            if (exp % 2 == 1)
                  result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
      }
      return result;
}

void precompute_factorials(int max_n)
{
      factorial.resize(max_n + 1);
      inv_factorial.resize(max_n + 1);
      factorial[0] = 1;
      for (int i = 1; i <= max_n; ++i)
      {
            factorial[i] = (factorial[i - 1] * i) % MOD;
      }
      inv_factorial[max_n] = mod_exp(factorial[max_n], MOD - 2, MOD);
      for (int i = max_n - 1; i >= 0; --i)
      {
            inv_factorial[i] = (inv_factorial[i + 1] * (i + 1)) % MOD;
      }
}

void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}

long long count_valid_strings(const vector<int> &c)
{
      long long total_chars = accumulate(c.begin(), c.end(), 0LL);

      // If total_chars is odd, return 0
      if (total_chars % 2 != 0)
      {
            return 0;
      }

      long long result = 1;

      // Multiply by 2 for each character with non-zero count
      for (int count : c)
      {
            if (count > 0)
            {
                  result = (result * 2) % MOD;
            }
      }

      // Multiply by total permutations of the given counts
      long long permutations = factorial[total_chars];
      for (int count : c)
      {
            if (count > 0)
            {
                  permutations = (permutations * inv_factorial[count]) % MOD;
            }
      }

      return (result * permutations) % MOD;
}

void solve(ll test)
{
      vector<int> c(26);
      for (auto &it : c)
      {
            cin >> it;
      }
      cout << count_valid_strings(c) << endl;
}
int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t = 1;
      cin >> t;

      precompute_factorials(500000);

      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}
