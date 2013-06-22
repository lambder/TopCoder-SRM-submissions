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

#if (0)
	#define debug 
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

class BouncingBalls
{
public:
	double expectedBounces(vector <int> x, int T);
};

int N, T;
int cnt = 0;
vi x;
int dir[15];

void get(int id = 0) {
	if(id == N) {
/*
		forn(i, N)
			Pf("%+d ", dir[i]);
		cout << endl;
*/
		forn(i, N)	if(dir[i] == 1) {
			forab(j, i+1, N-1) 	if(dir[j] == -1){
				if(x[j] - x[i] <= 2*T)
					cnt++;
			}
		}
		return;
	}
	for(int i = -1; i <= 1; i+=2) {
		dir[id] = i;
		get(id+1);
	}
}

double BouncingBalls::expectedBounces (vector <int> _x, int _T) 
{
	x = _x;
	T = _T;
	N = x.size();
	sort(all(x));
	cnt = 0;

//	cout << endl;
	get();
//	cout << endl;

	debug(cnt);

	return 1.0*cnt/(1<<N);
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	BouncingBalls *obj;
	double answer;
	obj = new BouncingBalls();
	clock_t startTime = clock();
	answer = obj->expectedBounces(p0, p1);
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
		res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	double p2;
	
	{
	// ----- test 0 -----
	int t0[] = {5,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 0.25;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {5,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 0.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {91,857,692,54,8679,83,792,86,9537,913,64,592};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 458;
	p2 = 11.5;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {75432};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 386;
	p2 = 0.0;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,2,3,4,5,6,7,8,9,10,11,12};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 12.75;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
// John is playing with balls. All of the balls are identical in weight and considered to have a zero radius. All balls are located on the same straight line and can move only along this line. If a ball rolling to the right and a ball rolling to the left at the same speed collide, they do not change speed, but they change direction.
// 
// 
// You are given vector <int> x. x[i] is the initial position of the i-th ball. John decides the direction for each ball (right or left) with equal probability. At time 0, he rolls the balls in the chosen directions simultaneously at a speed of one unit per second. Return the expected number of bounces between all balls during T seconds (including those collisions that happen exactly at T seconds).
// 
// DEFINITION
// Class:BouncingBalls
// Method:expectedBounces
// Parameters:vector <int>, int
// Returns:double
// Method signature:double expectedBounces(vector <int> x, int T)
// 
// 
// NOTES
// -There is no friction. Each ball continues rolling at the same speed forever.
// -Your return value must have an absolute or relative error less than 1e-9.
// 
// 
// CONSTRAINTS
// -x will contain between 1 and 12 elements, inclusive.
// -Each element of x will be between 0 and 100,000,000, inclusive.
// -All elements of x will be distinct.
// -T will be between 1 and 100,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {5, 8}
// 2
// 
// Returns: 0.25
// 
// If he rolls the left ball to the right and right ball to the left, they collide at time 1.5. Otherwise, they don't collide.
// 
// 1)
// {5, 8}
// 1
// 
// Returns: 0.0
// 
// x is the same as in example 0, but T is too small.
// 
// 2)
// {91, 857, 692, 54, 8679, 83, 792, 86, 9537, 913, 64, 592}
// 458
// 
// Returns: 11.5
// 
// 
// 
// 3)
// {75432}
// 386
// 
// Returns: 0.0
// 
// 
// 
// 4)
// {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
// 3
// 
// Returns: 12.75
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!