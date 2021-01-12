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
    vector<ll> v(n+1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll index = n/2 + 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += abs(v[i] - v[index]);
    }
    cout << ans << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    int tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}