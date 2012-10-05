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

class LeftRightDigitsGame
{
public:
	string minNumber(string digits);
};

ST dig[55];

string LeftRightDigitsGame::minNumber (string digits) 
{
	forn(i, 55)
		dig[i] = "";
	dig[0].resize(1);
	dig[0][0] = digits[0];
	DEBUG(dig[0]);
	int idx = -1;
	bool appendAtLast = false;

	forab(i, 1, digits.size()-1) {

		if(appendAtLast == true) {
			dig[i] = dig[i-1] + digits[i];
			continue;
		}

		else if(idx == i) {
			appendAtLast = true;
		}
		else {
			ST st1 = string(1, digits[i]) + dig[i-1];
			ST st2 = dig[i-1] + digits[i];
			dig[i] = min(st1, st2);
			DEBUG(dig[i]);
		}
	}

	return dig[digits.size()-1];
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	LeftRightDigitsGame *obj;
	string answer;
	obj = new LeftRightDigitsGame();
	clock_t startTime = clock();
	answer = obj->minNumber(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	string p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = "565";
	p1 = "556";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "9876543210";
	p1 = "1234567890";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "8016352";
	p1 = "1086352";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
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
// You are playing a solitaire game called Left-Right Digits Game. This game uses a deck of N cards. Each card has a single digit written on it. These digits are given as characters in the string digits. More precisely, the i-th character of digits is the digit written on the i-th card from the top of the deck (both indices are 0-based).
// 
// The game is played as follows. First, you place the topmost card (whose digit is the 0-th character of digits) on the table. Then, you pick the cards one-by-one from the top of the deck. For each card, you have to place it either to the left or to the right of all cards that are already on the table.
// 
// After all of the cards have been placed on the table, they now form an N-digit number. This number must not have leading zeros; i.e., the leftmost card on the table must not be a '0'. The goal of the game is to make this N-digit number as small as possible.
// 
// Return the smallest possible resulting number you can achieve in this game as a string.
// 
// DEFINITION
// Class:LeftRightDigitsGame
// Method:minNumber
// Parameters:string
// Returns:string
// Method signature:string minNumber(string digits)
// 
// 
// CONSTRAINTS
// -digits will contain between 1 and 50 characters, inclusive.
// -Each character of digits will be between '0' and '9', inclusive.
// -digits will contain at least one character that is not '0'.
// 
// 
// EXAMPLES
// 
// 0)
// "565"
// 
// Returns: "556"
// 
// The solution is as follows.
// 
// Place the first card on the table.
// Place the second card to the right of all cards on the table.
// Place the last card to the left of all cards on the table.
// 
// 
// 1)
// "9876543210"
// 
// Returns: "1234567890"
// 
// The resulting number cannot have leading zeros.
// 
// 2)
// "8016352"
// 
// Returns: "1086352"
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
