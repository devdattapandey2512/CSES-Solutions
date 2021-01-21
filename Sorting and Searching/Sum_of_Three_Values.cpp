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

struct compare { 
    bool operator()(const pair<int, int>& value,  
                                const int& key) 
    { 
        return (value.first < key); 
    } 
    bool operator()(const int& key,  
                    const pair<int, int>& value) 
    { 
        return (key < value.first); 
    } 
}; 

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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back({a, i+1});
    }
    sort(v.begin(), v.end());
    tuple<int, int, int> ans;
    bool a = false;
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            if(v[i].first + 2*v[j].first > x)
            break;
            if(binary_search(v.begin()+j+1, v.end(), x - (v[i].first + v[j].first), compare()))
            {
                auto lt = lower_bound(v.begin()+j+1, v.end(), x - (v[i].first + v[j].first), compare());
                pair<int, int> p = *lt;
                ans = make_tuple(v[i].second, v[j].second, p.second);
                a = true;
                break;
            }
        }
        if(a)
        break;
    }
    if(a)
    {
        cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << endl; 
    }
    else
    cout << "IMPOSSIBLE" << endl;
    
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