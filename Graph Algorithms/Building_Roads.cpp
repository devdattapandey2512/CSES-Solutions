/*
Author: Devdatta Pandey
Designation: B.Tech Student(NIT Patna)
Date: --/--/---- 

Finding logic and writing code is an art. It is once intellectual property.
So please don't copy or use it only for reference. Try to solve the question yourself.
*/


#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <chrono>
#include <complex>
#define ll long long int
#define mod 1000000007
#define inf 1000000000000000001 

using namespace std; 
int n, m;
vector<vector<int>> graph;
vector<bool> visited;

void DFS(int s)
{
    visited[s] = true;
    for(auto x: graph[s])
    if(!visited[x])
    DFS(x);
}

void solve()
{
    cin >> n >> m;
    graph.resize(n);
    visited.resize(n, false);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            ans.push_back(i);
            DFS(i);
        }
    }
    cout << ans.size() - 1 << endl;
    // for(auto x: ans)
    // cout << x << " ";
    // cout << endl;
    for(int i = 0; i < ans.size()-1; i++)
    {
        cout << ans[i] + 1 << " " << ans[i+1] + 1 << endl;
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}