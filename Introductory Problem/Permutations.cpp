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
    //1 2 3 4 5 6 7
    //3 1 4 2 7 5 6
    //4 7 1 6 2 5 3
    //1 2 3 4 5 6 
    //3 6 1 5 2 4 
    //3 5 1 4 2 
    ll n;
    cin >> n;
    vector<ll> v(n+1, 0);
    // for (ll i = 1; i <= n; i++)
    // {
    //     v[i] = i;
    // }
    
    if(n == 3 || n == 2)
    cout << "NO SOLUTION";

    else
    {
        if(n%2 == 1)
        {
            vector<ll> ans(n+1);
            ans[1] = n/2 + 1;
            ll count = 1;
            for(ll i=1; i<=n/2; i++)
            {
                ans[++count] = n-i+1;
                ans[++count] = i;
            } 
            for (ll i = 1; i <= n; i++)
            {
                cout << ans[i] << " ";
            }
        }
        else
        {
            vector<ll> ans(n+1);
            //1 2 3 4 5 6 
            //3 6 1 5 2 4 
            ans[1] = n/2;
            ans[n] = n/2+1;
            ll count = 1;
            for(ll i=1; i <= n/2-1; i++)
            {
                ans[++count] = n-i+1;
                ans[++count] = i;
            } 
            for (ll i = 1; i <= n; i++)
            {
                cout << ans[i] << " ";
            }
        }
        
    }
    
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