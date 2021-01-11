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

void ans_rec(ll x)
{
    cout << x << " ";
    if(x == 1)
    {
        return;
    }
    if(x%2 == 0)
    {
        ans_rec(x/2);
    }
    if(x%2 == 1)
    {
        ans_rec(3*x + 1);
    }
}

void solve()
{
    ll n;
    cin >> n;
    ans_rec(n);
    cout << endl;
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