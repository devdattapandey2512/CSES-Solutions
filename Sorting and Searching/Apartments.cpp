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

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> choice(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> choice[i];
    }
    sort(choice.begin(), choice.end());
    multiset<ll> app_size;
    for (ll i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        app_size.insert(x);
    }
    ll ans = 0;
    for(auto x: choice)
    {
        int h = x-k;
        auto it = app_size.lower_bound(h);
        if(it != app_size.end() and *it <= x+k)
        {
            app_size.erase(it);
            ans++;
        }
        
    }
    cout << ans << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin .tie(0);
    
    int tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}