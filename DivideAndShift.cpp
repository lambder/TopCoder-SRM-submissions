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
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#if (0 or defined ONLINE_JUDGE)
	#define DEBUG
#else 
	#define DEBUG(x)	cout << #x << " = " << x << "\n"
#endif

class DivideAndShift
{
public:
	int getLeast(int N, int M);
};

const int sz = 1e6 + 11;

map < ii, int> Ans;
int fact[sz];

int solve(int N, int M) {
	if(M == 0)
		return 0;

	map <ii, int> :: iterator it = Ans.find(mp(N, M));

	if(it != Ans.end())
		return it->second;

	int ret = min(M, N - M);

	int n = N;
	while(n != 1) {
		int f = fact[n];
		ret = min(ret, 1 + solve(N / f, M % (N / f)));

		n /= fact[n];
	}

	return Ans[mp(N, M)] = ret;
}

int DivideAndShift::getLeast (int N, int M) 
{
	Ans.clear();

	CL(fact, -1);
	fact[1] = 1;
	for(int i = 2;i < sz; i++)	if(fact[i] == -1) {
		for(int j = i; j < sz; j+=i)
			fact[j] = i;
	}

	int ret = solve(N, M-1);
/*
	tr(it, Ans)
		Pf("(%d, %d) - %d\n", it->first.first, it->first.second, it->second);
*/
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	DivideAndShift *obj;
	int answer;
	obj = new DivideAndShift();
	clock_t startTime = clock();
	answer = obj->getLeast(p0, p1);
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
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 56;
	p1 = 14;
	p2 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 49;
	p1 = 5;
	p2 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 256;
	p1 = 7;
	p2 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 6;
	p1 = 1;
	p2 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 77777;
	p1 = 11111;
	p2 = 2;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 77;
	p1 = 11;
	all_right = KawigiEdit_RunTest(5, p0, p1, false, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 59049;
	p1 = 12157;
	all_right = KawigiEdit_RunTest(6, p0, p1, false, p2) && all_right;
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
// Manao is playing a game called "Divide and Shift". There is a sequence of N slots in the game numbered from 1 to N. Initially each of them contains an object. Manao's goal is to obtain the object which is initially in slot M. At any time of the game, he can only obtain an object that is in slot 1 at that time. 
// 
// Manao can perform two types of moves. The first is choosing a prime number p which divides N and dividing the sequence of the slots in p contiguous subsequences, namely the slots from 1 to N/p, the slots from N/p+1 to 2N/p, etc. Then, Manao keeps the subsequence which contains the desired object and gets rid of the remaining slots. The length of the chosen subsequence is then assigned to N and the slots in it are renumbered from 1 to the new value of N.
// 
// The second type of move is shifting the objects in the slots. Manao can perform a left shift and a right shift. After a left shift, for each i &gt 1 the object in slot i is moved to slot i-1 and the object in slot 1 is moved to the last slot of the sequence. After a right shift, each object is moved to the slot to the right and the object in the last slot is moved to slot 1.
// 
// Determine the least number of moves in which Manao can reach the goal. Taking the object from slot 1 is not considered a move.
// 
// DEFINITION
// Class:DivideAndShift
// Method:getLeast
// Parameters:int, int
// Returns:int
// Method signature:int getLeast(int N, int M)
// 
// 
// NOTES
// -A positive integer number is called prime if it has exactly two divisors - 1 and itself. For example, 2, 3, 5 and 7 are prime numbers, and 4, 6, 8 and 9 are not prime. By convention, 1 is not considered to be a prime number.
// -A prime number p divides N if the ratio N/p is an integer.
// 
// 
// CONSTRAINTS
// -N will be between 1 and 1,000,000, inclusive.
// -M will be between 1 and N, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 56
// 14
// 
// Returns: 3
// 
// One possible way to obtain the object in slot 14 is to perform the following operations:
// 1. Divide by 2. N becomes equal to 28 now.
// 2. Shift right. The object moves to slot 15.
// 3. Divide by 2 again. The sequence 15..28 is kept, renumbered as 1..14 and the object appears in slot 1.
// 
// 
// 1)
// 49
// 5
// 
// Returns: 2
// 
// Manao divides by 7 twice and gets a single slot.
// 
// 2)
// 256
// 7
// 
// Returns: 6
// 
// Shift left until the object is in slot 1.
// 
// 3)
// 6
// 1
// 
// Returns: 0
// 
// The object may be in slot 1 right in the beginning.
// 
// 4)
// 77777
// 11111
// 
// Returns: 2
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
