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
 
vector<ll> tree, arr, lazy;
 

ll construct_ST(ll ss, ll se, ll si)
{
    if(ss == se)
    {
        tree[si] = arr[ss];
        return tree[si];
    }
    ll mid = (ss + se)/2;
    tree[si] = construct_ST(ss, mid, 2*si + 1) + construct_ST(mid + 1, se, 2*si + 2);
    return tree[si];
}

void update_rec(ll a, ll b, ll ss, ll se, ll si, ll u)
{
    if(lazy[si] != 0)
    {
        tree[si] += (se - ss + 1)*lazy[si];

        if(ss != se)
        {
            lazy[2*si + 1] += lazy[si];
            lazy[2*si + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if(a > se || b < ss)
    return;

    if(ss >= a && se <= b)
    {
        tree[si] += (se - ss + 1)*u;
        if(se > ss)
        {
            lazy[2*si + 1] += u;
            lazy[2*si + 2] += u;
        }
        return;    
    }
    ll mid = (ss+se)/2;

    update_rec(a, b, ss, mid, 2*si + 1, u);
    update_rec(a, b, mid + 1, se, 2*si + 2, u);
    tree[si] = tree[2*si + 1] + tree[2*si + 2];
}

void update(ll a, ll b, ll u, ll n)
{
    update_rec(a, b, 0, n-1, 0, u);
}

ll find_ST(ll k, ll ss, ll se, ll si)
{
    if(lazy[si] != 0)
    {
        tree[si] += (se - ss + 1)*lazy[si];

        if(ss != se)
        {
            lazy[2*si + 1] += lazy[si];
            lazy[2*si + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    
    if(ss == se)
    {
        return tree[si];
    }
    

    ll mid = (ss + se)/2;
    if(k <= mid)
    return find_ST(k, ss, mid, 2*si + 1);
    else
    return find_ST(k, mid + 1, se, 2*si + 2);
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    
    arr.resize(n);
    tree.resize(4*n);
    lazy.resize(4*n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    construct_ST(0, n-1, 0);
    for (ll i = 0; i < q; i++)
    {
        ll op;
        cin >> op;
        if(op == 1)
        {
            ll a, b, u;
            cin >> a >> b >> u;
            update(a-1, b-1, u, n);
        }
        if(op == 2)
        {
            ll k;
            cin >> k;
            cout << find_ST(k-1, 0, n-1, 0) << endl;
        }
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