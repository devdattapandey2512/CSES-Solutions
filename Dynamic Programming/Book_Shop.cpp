/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna)
Date: --/--/---- 

Finding logic and writing code is an art. It is once intellectual property.
So please don't copy or use it only for reference. Try to solve the question yourself.
*/


#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <chrono>
#include <complex>
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
}
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
}
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
}
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
}

void solve()
{
    int n, price;
    cin >> n >> price;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }
    
    int dp[price+1]; //dp[i] -> maximum number of pages with price i
    dp[0] = 0;
    memset(dp ,0, sizeof(dp));
    for(int i = 0; i < n; i++)
    {
        for(int j = price; j >= v[i].first; j--)
        {
            if(v[i].first <= j)
            dp[j] = max(dp[j], v[i].second + dp[j - v[i].first]);
        }
    }
    cout << dp[price] << endl;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    ll tc = 1;
    //cin >> tc;

    for (ll i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}