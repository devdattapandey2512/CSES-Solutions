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
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    if(x > y)
    { 
        ans = x*x;
        if(x%2 == 0)
        ans -= (y - 1);
        else
        ans -= ((y) + (x-1));
        //ans -= (y - 1);
        
    }
    else if(x < y)
    {
        ans = y*y;
        if(y%2 == 1)
        ans -= (x - 1);
        else
        ans -= ((y-1) + (x));
    }
    else
    {
        ans = x*x;
        ans -= (x-1);
    }
    cout << ans << endl;
    //solution of some parts 
    //2 4 -> 11
    //2 5 -> 24
    //3 4 -> 12
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    ll tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}