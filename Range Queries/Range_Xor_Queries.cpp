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
    tree[si] = construct_ST(ss, mid, 2*si + 1) ^ construct_ST(mid+1, se, 2*si+2);
    return tree[si];
}

ll query(ll qs, ll qe, ll ss, ll se, ll si)
{
    if(se < qs || ss > qe)
    return 0;
    
    if(qs <= ss && qe >= se)
    return tree[si];
    
    ll mid = (ss + se)/2;
    
    return query(qs, qe, ss, mid, 2*si + 1) ^ query(qs, qe, mid+1, se, 2*si+2);
}

ll update_rec(ll ss, ll se, ll i, ll si, ll new_val)
{
    if(i > se || i < ss)
    return tree[si];

    if(se == ss)
    {
        tree[si] = new_val;
        return tree[si];
    }
    

    if(se > ss)
    {
        ll mid = (se + ss)/2;

        tree[si] = update_rec(ss, mid, i, 2*si+1, new_val)^update_rec(mid+1, se, i, 2*si+2, new_val);
        return tree[si];
    }
    return 0;
}

void update(ll i, ll new_val, ll n)
{
    //ll diff = new_val - arr[i];
    arr[i] = new_val;
    update_rec(0, n-1, i, 0, arr[i]);
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    tree.resize(4*n, 0);
    arr.resize(n, 0);
    
    //vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    construct_ST(0, n-1, 0);
    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        cout << query(a-1, b-1, 0, n-1, 0) << endl;
        // ll ans = 0;
        // for (ll j = a-1; j < b; j++)
        // {
        //     ans ^= arr[j];
        // }
        // cout << ans << endl;
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