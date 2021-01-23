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

vector<ll> tree, arr;

ll construct_ST(ll ss, ll se, ll si)
{
    if(ss == se)
    {
        tree[si] = arr[ss];
        return tree[si];
    }
    ll mid = (ss + se)/2;
    tree[si] = min(construct_ST(ss, mid, 2*si + 1), construct_ST(mid+1, se, 2*si+2));
    return tree[si];
}

ll query(ll qs, ll qe, ll ss, ll se, ll si)
{
    if(se < qs || ss > qe)
    return INT_MAX;
    
    if(qs <= ss && qe >= se)
    return tree[si];
    
    ll mid = (ss + se)/2;
    
    return min(query(qs, qe, ss, mid, 2*si + 1), query(qs, qe, mid+1, se, 2*si+2));
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    tree.resize(4*n, 0);
    arr.resize(n, 0);
    for(ll i = 0; i < n; i++)
    cin >> arr[i];
    construct_ST(0, n-1, 0);
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    for (ll i = 1; i <= m; i++)
    {
        ll l, r;
        cin >> l >> r;
        cout << query(l-1, r-1, 0, n-1, 0) << endl;
    }
    
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
    ll tc = 1;
    //cin >> tc;

    for (ll i = 1; i <= tc; i++)
    {
        //cout << "Case #" << tc << ": ";
        solve();
    }
    
	return 0;
}