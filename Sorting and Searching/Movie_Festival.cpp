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

bool mycmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), mycmp);
    // for(int i=0; i<n; i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    int ans=1, s = v[0].second;
    for(int i=1; i<n; i++)
    {
        if(v[i].first >= s)
        {
            ans++;
            s = v[i].second;
        }
        
    }
    cout << ans << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin .tie(0);
    
    int tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
    }

	return 0;
}