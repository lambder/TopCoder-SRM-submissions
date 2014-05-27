#include <bits/stdc++.h>
using namespace std;

class SmoothNumbers
{
public:
	int countSmoothNumbers(int N, int k);
};

int SmoothNumbers::countSmoothNumbers (int N, int k)
{
    vector <int> factor(N+1, 0);
    for(int i = (int)1; i <= (int)N; ++i) {
        factor[i] = i;
    }
    for(int i = (int)2; i <= (int)N; ++i) {
        if(factor[i] == i) {
            for(int j = i; j <= N; j+=i) {
                factor[j] = i;
            }
        }
    }
	int ret = 0;
    for(int i = 1; i < (int)N+1; ++i) {
        if(factor[i] <=k)
            ret++;
    }
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	SmoothNumbers *obj;
	int answer;
	obj = new SmoothNumbers();
	clock_t startTime = clock();
	answer = obj->countSmoothNumbers(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	int p0;
	int p1;
	int p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 10;
	p1 = 3;
	p2 = 7;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 10;
	p1 = 4;
	p2 = 7;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 15;
	p1 = 3;
	p2 = 8;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 5;
	p1 = 20;
	p2 = 5;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 100000;
	p1 = 100;
	p2 = 17442;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// A positive integer is said to be k-smooth if its largest prime factor is no greater than k. Compute how many positive integers less than or equal to N are k-smooth.
// 
// DEFINITION
// Class:SmoothNumbers
// Method:countSmoothNumbers
// Parameters:int, int
// Returns:int
// Method signature:int countSmoothNumbers(int N, int k)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 100,000, inclusive.
// -k will be between 1 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 10
// 3
// 
// Returns: 7
// 
// Of the first ten integers, only 5, 7 and 10 have prime factors greater than 3.
// 
// 1)
// 10
// 4
// 
// Returns: 7
// 
// 4 is not prime, so 4-smooth numbers are the same as 3-smooth numbers.
// 
// 2)
// 15
// 3
// 
// Returns: 8
// 
// 
// 
// 3)
// 5
// 20
// 
// Returns: 5
// 
// 
// 
// 4)
// 100000
// 100
// 
// Returns: 17442
// 
// 
// 
// END KAWIGIEDIT TESTING