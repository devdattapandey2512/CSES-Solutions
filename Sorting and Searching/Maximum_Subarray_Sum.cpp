/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna) 
Date: --/--/----

Finding logic and writing code is an art. It is once intellectual property. 
So please don't copy or use it only for reference. Try to solve the question yourself.
*/ 

#include <bits/stdc++.h>
#include <stdio.h>
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

bool mycmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void solve()
{
    ll n;
    scanf("%lld", &n);
    //cin >> n;
    vector<ll> v(n);
    ll mx = LONG_MIN, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld ", &v[i]);
        //cin >> v[i];
        sum += v[i];
        mx = max(mx, sum);
        if(sum < 0)
        sum = 0;
    }
    printf("%lld \n", mx);
    //cout << mx << endl;

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