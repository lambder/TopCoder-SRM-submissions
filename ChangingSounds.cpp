#include <bits/stdc++.h>
using namespace std;

class ChangingSounds
{
public:
	int maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel);
};

int dp[1111][55];
int mxLevel, beginLevel;
vector <int> diffs;

int solve(int level, int n) {
	if(n==0)
		return level == beginLevel ? 1 : 0;
	if(level < 0 || level > mxLevel)
		return 0;
	int &ret = dp[level][n];
	if(ret != -1)
		return ret;
	ret = 0;
	if(solve(level - diffs[n-1], n-1) || solve(level + diffs[n-1], n-1))
		ret = 1;
	return ret;
}

int ChangingSounds::maxFinal (vector <int> changeIntervals, int _beginLevel, int _maxLevel) 
{
	beginLevel = _beginLevel;
	mxLevel = _maxLevel;
	diffs = changeIntervals;
	memset(dp, -1, sizeof(dp));

	int ret = -1;

	for(int i = 0; i <= mxLevel; ++i) {
			if(solve(i, diffs.size()))
				ret = i;
	}
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	ChangingSounds *obj;
	int answer;
	obj = new ChangingSounds();
	clock_t startTime = clock();
	answer = obj->maxFinal(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {5,3,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	p2 = 10;
	p3 = 10;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {15,2,9,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 8;
	p2 = 20;
	p3 = -1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {74,39,127,95,63,140,99,96,154,18,137,162,14,88};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 40;
	p2 = 243;
	p3 = 238;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// You are a guitar player and you are going to play a concert.  You don't like to play all the songs at the same volume, so you decide to change the volume level of your guitar before each new song.  Before the concert begins, you make a list of the number of intervals you will be changing your volume level by before each song.  For each volume change, you will decide whether to add that number of intervals to the volume, or substract it.
// 
// You are given a vector <int> changeIntervals, the i-th element of which is the number of intervals you will change your volume by before the i-th song. You are also given an int beginLevel, the initial volume of your guitar, and an int maxLevel, the highest volume setting of your guitar. You cannot change the volume of your guitar to a level above maxLevel or below 0 (but exactly 0 is no problem). Return the maximum volume you can use to play the last song. If there is no way to go through the list without exceeding maxLevel or going below 0, return -1.
// 
// 
// DEFINITION
// Class:ChangingSounds
// Method:maxFinal
// Parameters:vector <int>, int, int
// Returns:int
// Method signature:int maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel)
// 
// 
// CONSTRAINTS
// -changeIntervals will contain between 1 and 50 elements, inclusive.
// -Each element of changeIntervals will be between 1 and maxLevel, inclusive.
// -maxLevel will be between 1 and 1000, inclusive.
// -beginLevel will be between 0 and maxLevel, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {5, 3, 7}
// 5
// 10
// 
// Returns: 10
// 
// First we turn the volume down to 0 (-5), then we turn it up to 3 (+3), and then up to 10 (+7) for the last song.
// 
// 1)
// {15, 2, 9, 10}
// 8
// 20
// 
// Returns: -1
// 
// Adding 15 to 8 or substracting 15 from 8 both give an invalid sound level.
// 
// 2)
// {74,39,127,95,63,140,99,96,154,18,137,162,14,88}
// 40
// 243
// 
// Returns: 238
// 
// 
// 
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
