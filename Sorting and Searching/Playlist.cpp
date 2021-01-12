/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna) 
Date: --/--/----

Finding logic and writing code is an art. It is once intellectual property. 
So please don't copy or use it only for reference. Try to solve the question yourself.
*/ 

#include <bits/stdc++.h>
#include <unordered_set>
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
    map<ll, ll> m;
    vector<ll> v(n+1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    ll j = 0, ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        while(j <= n && m[v[j]] < 1)
        {
            m[v[j++]]++;
        }
        ans = max(j-i, ans);
        m[v[i]]--;
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