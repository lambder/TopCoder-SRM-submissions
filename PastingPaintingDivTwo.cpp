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
using namespace std;

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector <int> > vvi;
typedef pair<int,int> ii;
typedef vector <string> vs;

#define endl 		("\n")
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define Pf		printf
#define	Sf		scanf

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

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

class PastingPaintingDivTwo
{
public:
	long long countColors(vector <string> clipboard, int T);
};

long long PastingPaintingDivTwo::countColors (vector <string> clip, int T) 
{
	long long ret = 0;
	bool colored[500][500] = {};
	int64 add = 0;
	int N = clip.size(), M = clip[0].size();

	forn(i, 101) {
		int64 tmp = 0;

		forn(j, N)	forn(k, M)	if(clip[j][k] == 'B') {
			if(colored[i+j][i+k] == false)
				tmp++;
			colored[i+j][i+k] = true;
		}
		ret += tmp;
		T--;
		if(T==0)
			return ret;
		if(i == 100)
			add = tmp;
	}
	ret += ((long long)T)*add;
	
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	PastingPaintingDivTwo *obj;
	long long answer;
	obj = new PastingPaintingDivTwo();
	clock_t startTime = clock();
	answer = obj->countColors(p0, p1);
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
	
	vector <string> p0;
	int p1;
	long long p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"..B","B..","BB."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 10ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"B...","....","....","...B"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 4ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"BBB"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10000;
	p2 = 30000ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1000000000;
	p2 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"BB.",".B."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	p2 = 201ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"..........B..........",".........B.B.........","........B...B........",".......B.....B.......","......B..B.B..B......",".....B...B.B...B.....","....B...........B....","...B...B.....B...B...","..B.....BBBBBB....B..",".B..........BB.....B.","BBBBBBBBBBBBBBBBBBBBB"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1000000000;
	p2 = 21000000071ll;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
// Cucumber Boy likes drawing pictures.  Today, he plans to draw a picture using a very simple graphics editor.
// 
// The editor has the following functions:
// 
// The canvas is an infinite two-dimensional grid of pixels.
// There are only two colors: black, and transparent. These are denoted 'B' and '.' (a period), respectively.
// The editor has a clipboard that contains a rectangular picture.
// The editor can take the picture in the clipboard and paste it onto any corresponding rectangle of the canvas. The user just has to select the pixel of the canvas where the upper left corner of the clipboard will be pasted.
// When pasting the picture, the black pixels of the picture in the clipboard will overwrite their corresponding pixels on the canvas. The pixels that are transparent in the clipboard picture do not change the canvas.
// 
// 
// At this moment, all pixels on the infinite canvas are transparent.  Cucumber Boy has already stored a picture in the clipboard.  You are given this picture as a vector <string> clipboard.
// 
// Cucumber Boy now wants to paste the clipboard picture onto the canvas exactly T times in a row.
// For each i, when pasting the clipboard for the i-th time, he will choose the pixel (i,i) as the upper left corner of the pasted picture.
// 
// You are given the vector <string> clipboard and the int T.  Return the number of black pixels on the canvas after all the pasting is finished.
// 
// DEFINITION
// Class:PastingPaintingDivTwo
// Method:countColors
// Parameters:vector <string>, int
// Returns:long long
// Method signature:long long countColors(vector <string> clipboard, int T)
// 
// 
// CONSTRAINTS
// -clipboard will contain between 1 and 50 elements, inclusive.
// -Each element of clipboard will contain between 1 and 50 characters, inclusive.
// -Each element of clipboard will contain the same number of characters.
// -Each character of each element of clipboard will be 'B' or '.'.
// -T will be between 1 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {
// "..B",
// "B..",
// "BB."
// }
// 3
// 
// Returns: 10
// 
// 
// 
// 1)
// {
// "B...",
// "....",
// "....",
// "...B"
// }
// 2
// 
// Returns: 4
// 
// 
// 
// 2)
// {"BBB"}
// 10000
// 
// Returns: 30000
// 
// 
// 
// 3)
// {"."}
// 1000000000
// 
// Returns: 0
// 
// 
// 
// 4)
// {
// "BB.",
// ".B."
// }
// 100
// 
// Returns: 201
// 
// 
// 
// 5)
// {
// "..........B..........",
// ".........B.B.........",
// "........B...B........",
// ".......B.....B.......",
// "......B..B.B..B......",
// ".....B...B.B...B.....",
// "....B...........B....",
// "...B...B.....B...B...",
// "..B.....BBBBBB....B..",
// ".B..........BB.....B.",
// "BBBBBBBBBBBBBBBBBBBBB"
// }
// 1000000000
// 
// Returns: 21000000071
// 
// Note that the answer may overflow a 32-bit integer variable.
// 
// 
// This is the image of clipboard in this example.
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
