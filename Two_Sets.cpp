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
    ll n;
    cin >> n;
    if(n%2 == 0)
    {
        if(n%4 != 0)
        cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            vector<ll> set1, set2;
            //set1.push_back(1);
            for (ll i = 1; i <= n/2; i++)
            {
                if(i%2)
                {
                    set1.push_back(n/2+i);
                    set1.push_back(n/2-i+1);
                }
                else{
                    set2.push_back(n/2+i);
                    set2.push_back(n/2-i+1);
                }
            }
            
            cout << set1.size() << endl;
            for(auto x: set1)
            cout << x << " ";
            cout << endl;
            cout << set2.size() << endl;
            for(auto x: set2)
            cout << x << " ";
            cout << endl;
        }
    }
    else
    { 
        if((n+1)%4 != 0)
        cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            vector<ll> set1, set2;
            bool chance = true;
            int count1 = 0, count2 = 0;
            for (ll i = 1; i <= n; i++)
            {
                if(chance)
                {
                    count2 = 0;
                    set1.push_back(i);
                    count1++;
                    if(count1 == 2)
                    chance = !chance;
                }
                else
                {
                    count1 = 0;
                    set2.push_back(i);
                    count2++;
                    if(count2 == 2)
                    chance = !chance;
                }
            }
            cout << set1.size() << endl;
            for(auto x: set1)
            cout << x << " ";
            cout<< endl;
            cout << set2.size() << endl;
            for(auto x: set2)
            cout << x << " ";
            cout << endl;
        }
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