#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

// https://leetcode.com/problems/scramble-string/
// Scrambled String 
// A string is called scrambled string of another if we make a binary tree of string with non empty nodes
// and then swap any number of nodes
// ex - great
//		/ 	\
//	   gr    eat
//	  / \    / \
//	 g	 r	e	at
//				/ \
//				a  t
// binary tree is not of any one type they can be of multiple types 
// here we can swap g with r which then swaps upper node rg so srambled string becomes rgeat
// or we can swap g and r and e and at(basically swapping its child nodes) which becomes rgate 
// so this is a MCM problem because we have to find a index where swapping took place that resulted in scrambled string
// ex - great if scrambled string is also great then it is definelty scrambled as we performed 0 swaps
// otherwise for eatgr here we have performed swap at i = 2 for gr | eat 	
// so we have two options for each i either swap or dont swap to obtain scrambled string
// so for unswapped string 0..i == 0..i and for swapped string 0..i == i..n so either of these two conditions are true 
// for any value of i then given string is scrambled version of another string
bool solve(string a, string b) {
	if(a == b)
		return true;
	if(a.length() <= 1)
		return false;
	bool flag = false;
	int n = a.length();
	for(int i = 1; i <= n - 1; i++) {
		if(solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i))) {
			flag = true;
			break;
		} 
		if(solve(a.substr(i, n - i), b.substr(0, n - i)) && solve(a.substr(0, i), b.substr(n - i, i))) {
			flag = true;
			break;
		}
	}
	return flag;
}

int32_t main() {
	string a, b;
	cin >> a >> b;
	if(a.length() != b.length())
		cout << "Not Scrambled";
	if(a == b)
		cout << "Scrambled";
	if(solve(a, b))	
		cout << "Scrambled";
	else
		cout << "Not Scrambled";
	return 0;
}
