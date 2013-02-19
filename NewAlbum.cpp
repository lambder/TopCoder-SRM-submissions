#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>
#include <cstring>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector <int> > vvi;
typedef pair<int,int> ii;
typedef vector <string> vs;

#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl 		("\n")

#define	ep		1e-9
#define PI		M_PI
#define E 		M_E

#define	CL(a, b)	memset(a, b, sizeof(a))
#define	mp		make_pair
#define	pb		push_back

#define	all(c)		(c).begin(), (c).end()
#define	tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())		//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())		//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here ; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int)b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int)b; i >= loop_ends_here; i--)

#define Pf		printf
#define	Sf		scanf

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

class NewAlbum
{
public:
	int leastAmountOfCDs(int nSongs, int length, int cdCapacity);
};

int NewAlbum::leastAmountOfCDs (int nSongs, int length, int cdCapacity) 
{
	int diskUsed = 1;
	int curCapacity = cdCapacity - length;
	int curSongs = 1;
	DEBUG(nSongs);
	DEBUG(length);
	DEBUG(cdCapacity);
	nSongs--;
	int prevSongs = 0;

	while(nSongs > 0) {
		Pf("Songs remaining = %-3d, curCapacity = %-3d, curSongs = %-3d, diskUsed = %-3d\n", nSongs, curCapacity, curSongs, diskUsed);
		if(curCapacity < 1 + length) {
			if(curSongs % 13 == 0) {
				diskUsed++;
				prevSongs = curSongs;
				curSongs = 1;
				curCapacity = cdCapacity - length;
			}
			else {
				diskUsed++;
				prevSongs = curSongs;
				curSongs = 1;
				nSongs--;
				curCapacity = cdCapacity - length;
			}
		}
		else {
			curCapacity = curCapacity - 1 - length;
			nSongs--;
			curSongs++;
		}
	}
	Pf("Songs remaining = %-3d, curCapacity = %-3d, curSongs = %-3d, diskUsed = %-3d\n", nSongs, curCapacity, curSongs, diskUsed);
	if(curSongs % 13 == 0 && curCapacity < 1 + length && prevSongs > 0 && (prevSongs - 1) % 13 != 0)
		diskUsed++;

	return diskUsed;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	NewAlbum *obj;
	int answer;
	obj = new NewAlbum();
	clock_t startTime = clock();
	answer = obj->leastAmountOfCDs(p0, p1, p2);
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
	
	int p0;
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 7;
	p1 = 2;
	p2 = 6;
	p3 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 20;
	p1 = 1;
	p2 = 100;
	p3 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 26;
	p1 = 1;
	p2 = 100;
	p3 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 26;
	p1 = 3;
	p2 = 51;
	p3 = 3;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 67;
	p1 = 271;
	p2 = 1000;
	p3 = 23;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 27;
	p1 = 1;
	p2 = 27;
	p3 = 3;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 63;
	p1 = 1;
	p2 = 99;
	p3 = 2;
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 7 -----
	p0 = 27;
	p1 = 1;
	p2 = 27;
	p3 = 3;
	all_right = KawigiEdit_RunTest(7, p0, p1, p2, true, p3) && all_right;
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
// A popular musical group 'Flattened' has decided to release a new album.
// It consists of nSongs songs. All songs are of the same length (given in seconds). A CD can store cdCapacity seconds of audio. 
// Each pair of consecutive songs must be separated by a 1 second pause.
// The group director is superstitious, so the number of songs on a CD must never be divisible by 13.
// Given these constraints, return the smallest number of CDs required to fit the entire album.
// 
// 
// 
// DEFINITION
// Class:NewAlbum
// Method:leastAmountOfCDs
// Parameters:int, int, int
// Returns:int
// Method signature:int leastAmountOfCDs(int nSongs, int length, int cdCapacity)
// 
// 
// CONSTRAINTS
// -nSongs will be between 1 and 100, inclusive.
// -cdCapacity will be between 1 and 10000, inclusive.
// -length will be between 1 and cdCapacity, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 7
// 2
// 6
// 
// Returns: 4
// 
// There are at most two songs on each CD.
// 
// 1)
// 20
// 1
// 100
// 
// Returns: 1
// 
// All the songs will fit on a single CD.
// 
// 
// 2)
// 26
// 1
// 100
// 
// Returns: 2
// 
// Even though all 26 songs will fit on a single CD, we must use two CDs because 26 is divisible by 13.
// 
// 3)
// 26
// 3
// 51
// 
// Returns: 3
// 
// 4)
// 67
// 271
// 1000
// 
// Returns: 23
// 
// 5)
// 27
// 1
// 27
// 
// Returns: 3
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!