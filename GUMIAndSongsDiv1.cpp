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

//#define debug(x)
#define debug(x)	cout << #x << " = " << x << "\n"

class GUMIAndSongsDiv1
{
public:
	int maxSongs(vector <int> duration, vector <int> tone, int T);
};

struct Songs {
	int d, t;
	Songs(int _d, int _t) {
		d = _d; t = _t;
	}
	bool operator <(const Songs&ob) const {
		return t < ob.t;
	}
};
vector <Songs> songs;

int dp[55][55];
const int inf = 1e9;

int getTime(int id, int cnt) {
	if(cnt == 0)
		return 0;
	if(cnt > id+1)
		return inf;
	if(cnt == 1)
		return songs[id].d;
	int &ret = dp[id][cnt];
	if(ret != -1)
		return ret;
	ret = inf;
	for(int i = 0; i < id; ++i) {
		ret = min(ret, getTime(i, cnt-1)+songs[id].d+abs(songs[i].t-songs[id].t));
	}
	return ret;
}

int GUMIAndSongsDiv1::maxSongs (vector <int> duration, vector <int> tone, int T) 
{
	songs.clear();
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < duration.size(); ++i) {
		songs.push_back(Songs(duration[i], tone[i]));
	}
	sort(songs.begin(), songs.end());
	int ret = 0;
	
	for(int i = 0; i < songs.size(); ++i) {
		for(int cnt = 1; cnt <= i+1; ++cnt) {
			if(getTime(i, cnt) <= T)
				ret = max(cnt, ret);
		}
	}

	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	GUMIAndSongsDiv1 *obj;
	int answer;
	obj = new GUMIAndSongsDiv1();
	clock_t startTime = clock();
	answer = obj->maxSongs(p0, p1, p2);
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
	vector <int> p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {3,5,4,11};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1,3,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 17;
	p3 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {100,200,300};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 99;
	p3 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,2,3,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 100;
	p3 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {9,11,13,17};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1,3,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 20;
	p3 = 1;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4,67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59,61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 212;
	p3 = 12;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
// Gumi loves singing.
// She knows N songs.
// The songs are numbered 0 through N-1.
// She now has some time and she would love to sing as many different songs as possible. 
// 
// You are given a vector <int> duration.
// For each i, duration[i] is the duration of song i in Gumi's time units. 
// 
// Gumi finds it difficult to sing songs with quite different tones consecutively.
// You are given a vector <int> tone with the following meaning:
// If Gumi wants to sing song y immediately after song x, she will need to spend |tone[x]-tone[y]| units of time resting between the two songs.
// (Here, || denotes absolute value.) 
// 
// You are also given an int T.
// Gumi has T units of time for singing.
// She can start singing any song she knows immediately at the beginning of this time interval.
// Compute the maximal number of different songs she can sing completely within the given time.
// 
// 
// DEFINITION
// Class:GUMIAndSongsDiv1
// Method:maxSongs
// Parameters:vector <int>, vector <int>, int
// Returns:int
// Method signature:int maxSongs(vector <int> duration, vector <int> tone, int T)
// 
// 
// CONSTRAINTS
// -duration and tone will each contain between 1 and 50 elements, inclusive.
// -duration and tone will contain the same number of elements.
// -Each element of duration will be between 1 and 100,000, inclusive.
// -Each element of tone will be between 1 and 100,000, inclusive.
// -T will be between 1 and 10,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {3, 5, 4, 11}
// {2, 1, 3, 1}
// 17
// 
// Returns: 3
// 
// There are four songs. 
// Two songs have tone 1 and their durations are 5 and 11, respectively.
// One song has tone 2 and its duration is 3.
// One song has tone 3 and its duration is 4.
// Gumi has 17 units of time to sing. 
// 
// It is impossible for Gumi to sing all four songs she knows within the given time: even without the breaks the total length of all songs exceeds 17. 
// 
// Here is one way how she can sing three songs:
// First, she sings song 0 in 3 units of time.
// Second, she waits for |2-3|=1 unit of time and then sings song 2 in 4 units of time.
// Finally, she waits for |3-1|=2 units of time and then sings song 1 in 5 units of time.
// The total time spent is 3+1+4+2+5 = 15 units of time.
// 
// 
// 1)
// {100, 200, 300}
// {1, 2, 3}
// 99
// 
// Returns: 0
// 
// In this case, T is so small that she can't sing at all.
// 
// 2)
// {1, 2, 3, 4}
// {1, 1, 1, 1}
// 100
// 
// Returns: 4
// 
// There is plenty of time, so she can sing all of 4 songs.
// 
// 3)
// {9, 11, 13, 17}
// {2, 1, 3, 4}
// 20
// 
// Returns: 1
// 
// 
// 
// 4)
// {87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4,
//  67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97}
// {88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59,
//  61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3}
// 212
// 
// Returns: 12
// 
// 
// 
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
