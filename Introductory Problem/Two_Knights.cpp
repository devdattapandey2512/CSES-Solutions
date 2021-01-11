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
#define ll unsigned long long int
#define mod 1000000007
#define inf 1000000000000000001

using namespace std;

void solve()
{
    ll k;
    cin >> k;
    for (ll i = 1; i <= k; i++)
    {
        ll ans = (i*i*(i*i - 1))/2 - 4*(i - 1)*(i - 2);
        cout << ans << endl;
    }
    
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    ll tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}