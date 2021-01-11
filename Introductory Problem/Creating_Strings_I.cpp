/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna) 
Date: --/--/----

Finding logic and writing code is an art. It is once intellectual property. 
So please don't copy or use it only for reference. Try to solve the question yourself.
*/ 

#include <bits/stdc++.h>
#include <unordered_set>
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

// set<string> v;
// string p = "";
// vector<bool> chosen;

// void find_permutation(string s, ll n)
// {
//     if(p.length() == n)
//     {
//         v.insert(p);
//     }
//     else {
//         for (ll i = 0; i < n; i++) {
//             if (chosen[i]) continue;
//             chosen[i] = true;
//             p += s[i];
//             find_permutation(s, n);
//             chosen[i] = false;
//             p.pop_back();
//         }

//     }
// }

void solve()
{
    string s;
    cin >> s;
    // chosen.resize(s.length());
    // fill(chosen.begin(), chosen.end(), false);
    // find_permutation(s, s.length());
    vector<string> v;
    sort(s.begin(), s.end());
    do{
        v.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    cout << v.size() << endl;
    for(auto x: v)
    cout << x << endl;
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