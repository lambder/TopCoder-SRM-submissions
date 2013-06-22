#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define PI		M_PI
#define E 		M_E
#define	eps		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	cl(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#if (0)
	#define debug 
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

class TravelOnMars
{
public:
	int minTimes(vector <int> range, int startCity, int endCity);
};

int TravelOnMars::minTimes (vector <int> range, int startCity, int endCity) 
{
	int ret; =fdfl;dsf
	
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
	TravelOnMars *obj;
	int answer;
	obj = new TravelOnMars();
	clock_t startTime = clock();
	answer = obj->minTimes(p0, p1, p2);
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
	int t0[] = {2,1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 4;
	p3 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {2,1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	p2 = 1;
	p3 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {2,1,1,2,1,2,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 6;
	p3 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 6;
	p2 = 13;
	p3 = 4;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 49;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, false, p3) && all_right;
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
// Bob recently went to Mars.
// 
// There are N cities on Mars. The cities all lie on a circular railroad and they are numbered 0 through N-1 along the railroad. More precisely, there is a railroad segment that connects cities N-1 and 0, and for each i (0 <= i <= N-2) there is a railroad segment that connects cities i and i+1. Trains travel along the railroad in both directions.
// 
// You are given a vector <int> range with N elements. For each i: the set of cities that are reachable from city i by a direct train is precisely the set of cities that are within the distance range[i] of city i. (The distance between two cities is the smallest number of railroad segments one needs to travel in order to get from one city to the other. For example, if N=17 and range[2]=3, the cities directly reachable from city 2 are the cities {16,0,1,2,3,4,5}.)
// 
// You are also given ints startCity and endCity. Bob starts his tour in the city startCity and wants to end it in the city endCity. Calculate and return the minimum number of succesive direct trains he needs to take.
// 
// DEFINITION
// Class:TravelOnMars
// Method:minTimes
// Parameters:vector <int>, int, int
// Returns:int
// Method signature:int minTimes(vector <int> range, int startCity, int endCity)
// 
// 
// CONSTRAINTS
// -range will contain N elements, where N is between 2 and 50, inclusive.
// -Each element of range will be between 1 and 50, inclusive.
// -startCity will be between 0 and N-1, inclusive.
// -endCity will be between 0 and N-1, inclusive.
// -startCity and endCity will be different.
// 
// 
// EXAMPLES
// 
// 0)
// {2,1,1,1,1,1}
// 1
// 4
// 
// Returns: 2
// 
// Bob wants to get from city 1 to city 4.
// The optimal solution is to travel from city 1 to city 0, and then (as range[0]=2) from city 0 to city 4.
// 
// 1)
// {2,1,1,1,1,1}
// 4
// 1
// 
// Returns: 3
// 
// This is the same test case as Example 0, only startCity and endCity have been swapped. Note that the answer is now 3 instead of 2.
// 
// 2)
// {2,1,1,2,1,2,1,1}
// 2
// 6
// 
// Returns: 3
// 
// Bob starts in city 2. There are two optimal routes: (2->3->5->6) and (2->1->0->6).
// 
// 3)
// {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3}
// 6
// 13
// 
// Returns: 4
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
