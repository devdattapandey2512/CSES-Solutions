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
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if(v[i] < v[i-1] && i > 0)
        {
            ans += v[i-1] - v[i];
            v[i] = v[i-1];
        }
        
    }
    cout << ans << endl;
    
}

int main()
{
	std::ios::sync_with_stdio(false);
	
    int tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}