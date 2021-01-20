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


void solve()
{
    ll n, t;
    cin >> n >> t;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll lb = 1, rb = 1e18;
    while(lb < rb)
    {
        ll s = 0, mb = (lb + rb)/2;
        for (ll i = 0; i < n; i++)
        {
            s += min(mb/v[i], (ll)1e9);
        }
        //cout << lb << " " << rb << " " << mb << " " << t << " " << s << endl;
        if(s >= t)
        rb = mb;
        else
        lb = mb+1;
    }
    cout << lb << endl;
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