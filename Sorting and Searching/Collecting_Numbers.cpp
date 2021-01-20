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
    vector<pair<int, int>> s;
    ll ans = 1;  
    for (ll i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.push_back({a, i+1});
    }
    sort(s.begin(), s.end());
    for (ll i = 1; i < n; i++)
    {
        if(s[i-1].second > s[i].second)
        ans++;
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