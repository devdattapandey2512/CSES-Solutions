/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna) 
Date: --/--/----

Finding logic and writing code is an art. It is once intellectual property. 
So please don't copy or use it only for reference. Try to solve the question yourself.
*/ 

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define mod 1000000007
#define inf 1000000000000000001

using namespace std;

ll lcm(ll a, ll b)
{
    return a*b/__gcd(a, b);
}

ll expo(ll a, ll b) 
{
    ll res = 1; 
    while (b > 0) 
    {
        if (b & 1)
        res = (res * a) % mod; 
        a = (a * a) % mod; 
        b = b >> 1;
    } 
    
    return res;
}
void extendgcd(ll a, ll b, ll*v) 
{
    if (b == 0) 
    {
        v[0] = 1; 
        v[1] = 0; 
        v[2] = a; 
        return ;
    } 
    extendgcd(b, a % b, v); 
    ll x = v[1]; 
    v[1] = v[0] - v[1] * (a / b); 
    v[0] = x; 
    return;
} //pass an arry of size1 3
ll mminv(ll a, ll b) 
{
    ll arr[3]; 
    extendgcd(a, b, arr); 
    return arr[0];
} //for non prime b
ll mminvprime(ll a, ll b) 
{
    return expo(a, b - 2);
}

ll mod_add(ll a, ll b, ll m = mod) 
{
    a = a % m; 
    b = b % m; 
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m = mod) 
{
    a = a % m; b = b % m; 
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m = mod) 
{
    a = a % m; b = b % m; 
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m = mod) 
{
    a = a % m; b = b % m; 
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}  //only for prime m

ll fibonacci(ll n) 
{
    ll number = n; 
    if (n % 2 == 0) 
    {
        number /= 2; 
        while (n % 2 == 0)
        n /= 2;
    } 
    for (ll i = 3; i <= sqrt(n); i += 2) 
    {
        if (n % i == 0) 
        {
            while (n % i == 0)n /= i; 
            number = (number / i * (i - 1));
        }
    } 
    if (n > 1)
    number = (number / n * (n - 1)); 
    return number;
} //O(sqrt(N))

// ll minimum_coins(vector<ll> coins, ll n, ll sum)
// {
//     if(sum == 0)
//     {
//         return 0;
//     }
//     if(n < 0)
//     {
//         return INT_MAX;
//     }
//     if(coins[n] <= sum)
//     return min(minimum_coins(coins, n-1, sum), 1 + minimum_coins(coins, n, sum - coins[n]));
//     else
//     return minimum_coins(coins, n-1, sum);
// }
void solve()
{
    int sum, n;
    cin >> n >> sum;
    vector<int> coins(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin()+1, coins.end());

    // ll ans = minimum_coins(coins, n-1, sum);
    // if(ans == INT_MAX)
    // cout << "-1" << endl;
    // else
    // cout << ans << endl;
    int dp[sum + 1][n + 1];
    dp[0][0];
    for (int i = 1; i <= sum; i++)
    {
        dp[i][0] = INT_MAX/2;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for (int sumi = 1; sumi <= sum; sumi++)
    {
        for (int coin = 1; coin <= n; coin++)
        {
            if(coins[coin] <= sumi)
            dp[sumi][coin] = min(1 + dp[sumi-coins[coin]][coin], dp[sumi][coin-1]);
            else
            dp[sumi][coin] = dp[sumi][coin-1];
        }
        
    }
    if(dp[sum][n] >= INT_MAX/2)
    cout << "-1" << endl;
    else
    cout << dp[sum][n] << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    ll tc = 1;
    //cin >> tc;

    for (ll i = 1; i <= tc; i++)
    {
        //cout << "Case #" << tc << ": ";
        solve();
    }
    
	return 0;
}