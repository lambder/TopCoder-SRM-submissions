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

class SandwichBar
{
public:
	int whichOrder(vector <string> available, vector <string> orders);
};

int SandwichBar::whichOrder (vector <string> available, vector <string> orders) 
{
	vector <vector <string> > order;
	forn(i, orders.size()) {
		order.pb(vector <string>());
		SS ss(orders[i]);
		string st;
		while(ss >> st)
			order[i].pb(st);
	}

	forn(i, order.size()) {
		bool flag = true;
		tr(it, order[i])
			flag &= find(all(available), *it) != available.end();
		if(flag)
			return i;
	}

	return -1;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	SandwichBar *obj;
	int answer;
	obj = new SandwichBar();
	clock_t startTime = clock();
	answer = obj->whichOrder(p0, p1);
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
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"ham","cheese","mustard"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"ham cheese"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"cheese","mustard","lettuce"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"cheese ham","cheese mustard lettuce","ketchup","beer"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"cheese","cheese","cheese","tomato"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"ham ham ham","water","pork","bread","cheese tomato cheese","beef"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"foo","bar","baz","gazonk","quux","bat","xyzzy","shme","hukarz","grault","waldo","bleh"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"kalatehas","spam eggs","needle haystack","bleh blarg","plugh","the best sandwich in the universe"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
// It's time to get something to eat and I've come across a sandwich bar. Like most people, I prefer certain types of sandwiches. In fact, I keep a list of the types of sandwiches I like.
// 
// The sandwich bar has certain ingredients available. I will list the types of sandwiches I like in order of preference and buy the first sandwich the bar can make for me. In order for the bar to make a sandwich for me, it must include all of the ingredients I desire.
// 
// Given a vector <string> available, a list of ingredients the sandwich bar can use, and a vector <string> orders, the types of sandwiches I like, in order of preference (most preferred first), return the 0-based index of the sandwich I will buy. Each element of orders represents one type of sandwich I like as a space-separated list of ingredients in the sandwich. If the bar can make no sandwiches I like, return -1.
// 
// DEFINITION
// Class:SandwichBar
// Method:whichOrder
// Parameters:vector <string>, vector <string>
// Returns:int
// Method signature:int whichOrder(vector <string> available, vector <string> orders)
// 
// 
// CONSTRAINTS
// -available will contain between 1 and 50 elements, inclusive.
// -Each element of available will contain between 1 and 50 lowercase letters ('a' - 'z'), inclusive.
// -orders will contain between 1 and 50 elements, inclusive.
// -Each element of orders will contain between 1 and 50 lowercase letters ('a' - 'z') and spaces, inclusive.
// -Each element of orders will represent a list of desired ingredients separated by single spaces, with no leading or trailing spaces.
// 
// 
// EXAMPLES
// 
// 0)
// { "ham", "cheese", "mustard" }
// { "ham cheese" }
// 
// Returns: 0
// 
// I only like plain ham and cheese sandwiches, and since both ham and cheese are available, I'll take that.
// 
// 1)
// { "cheese", "mustard", "lettuce" }
// { "cheese ham", "cheese mustard lettuce", "ketchup", "beer" }
// 
// Returns: 1
// 
// They've run out of ham, but I'll consider other options now.
// 
// 2)
// { "cheese", "cheese", "cheese", "tomato" }
// { "ham ham ham", "water", "pork", "bread", "cheese tomato cheese", "beef" }
// 
// Returns: 4
// 
// Ignore any duplicate elements in the lists.
// 
// 3)
// { "foo", "bar", "baz", "gazonk", "quux", "bat", "xyzzy",
//   "shme", "hukarz", "grault", "waldo", "bleh" }
// { "kalatehas", "spam eggs", "needle haystack", "bleh blarg", "plugh", 
//   "the best sandwich in the universe" }
// 
// Returns: -1
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!