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

class UndoHistory
{
public:
	int minPresses(vector <string> lines);
};

int UndoHistory::minPresses (vector <string> lines) 
{
	string buff = "";
	set <string> st;
	st.insert(buff);
	int ret = 0;

	for(__typeof((lines).begin()) it = (lines).begin(); it < (lines).end(); it++) {
		string str = *it;
		int ans= 1e9;
		if(str.find(buff) == 0)
			ans = str.size() - buff.size() +1;
		for(int l = str.size(); l >= 0; l--) {
			if(st.find(str.substr(0, l)) != st.end()) {
				int tmp = 2 + str.size() - l + 1;
				ans = min(ans, tmp);
			}
		}
//		cout << "ans = " << ans << "\n"; 
		buff = str;
		ret += ans;
		for(int l = 0; l <= str.size(); l++) {
			st.insert(str.substr(0, l));
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	UndoHistory *obj;
	int answer;
	obj = new UndoHistory();
	clock_t startTime = clock();
	answer = obj->minPresses(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"tomorrow","topcoder"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 18;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"a","b"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 6;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"a","ab","abac","abacus"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"pyramid","sphinx","sphere","python","serpent"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 39;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"ba","a","a","b","ba"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 13;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"abc","bcdefghi","abcdefghi"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	all_right = KawigiEdit_RunTest(5, p0, false, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"b","a","b"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 9;
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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
// Bob is using a peculiar text editor to write a sequence of lines of text.
// The editor consists of three parts: a results window, a text buffer and an undo history.
// More details about the three parts follow.
// 
// The results window contains a sequence of strings: the lines of text you already wrote. Initially, the results window is empty.
// The text buffer contains a string: the line you are writing at the moment. Initially, the string in the text buffer is empty.
// The undo history contains a sequence of strings: all the past states of the text buffer. Initially, the undo history contains a single element: an empty string.
// 
// 
// You are given a vector <string> lines.
// Bob would like to print the contents of lines into the results window.
// (At the end, the sequence of strings stored in the results window must be precisely equal to lines. Order of elements matters.)
// Additionally, Bob would like to do so as quickly as possible.
// He is able to take the following actions:
// 
// 
// Bob may type a lowercase letter. The letter is appended to the text buffer. The new text buffer is then added as a new element of the undo history. (For example, if the text buffer currently contains "do", then pressing 'g' changes the text buffer to "dog" and then stores "dog" into the undo history.)
// Bob may press Enter. When he does so, the current content of the text buffer is printed to the results window as a new line, after the lines that were printed earlier. The text buffer remains unmodified. (For example, if the text buffer contains "dog" and Bob presses Enter, "dog" will be appended to the results window, and the results buffer still contains "dog".)
// Bob may use two mouse clicks to restore any entry from the undo history to the text buffer. This operation does not modify the undo history.
// 
// 
// Return the minimum total number of button presses (keyboard and mouse) that Bob needs to print all the given lines into the results window.
// 
// DEFINITION
// Class:UndoHistory
// Method:minPresses
// Parameters:vector <string>
// Returns:int
// Method signature:int minPresses(vector <string> lines)
// 
// 
// CONSTRAINTS
// -lines will contain between 1 and 50 elements, inclusive.
// -Each element of lines will contain between 1 and 50 characters, inclusive.
// -Each element of lines will contain only lowercase letters ('a'-'z').
// 
// 
// EXAMPLES
// 
// 0)
// {"tomorrow", "topcoder"}
// 
// Returns: 18
// 
// 
// Type 't'. The text buffer now contains "t", and the undo history now contains "" and "t".
// Type 'o'. The text buffer now contains "to", and the undo history now contains "", "t", and "to".
// Using six more keypresses, type the letters in "morrow". The text buffer now contains "tomorrow" and the undo history contains all prefixes of "tomorrow". The results window is still empty.
// Press Enter. The results window now contains one string: "tomorrow".
// Click the mouse twice to restore "to" from undo history.
// Using another six keypresses, type the letters in "pcoder".
// Press Enter. The results window now contains "tomorrow" and "topcoder", in this order, and we are done.
// 
// The total number of button presses was 8 (typing "tomorrow") + 1 (Enter) + 2 (mouse) + 6 (typing "pcoder") + 1 (Enter) = 18.
// 
// 1)
// {"a","b"}
// 
// Returns: 6
// 
// After typing "a" and pressing enter, we need to restore the empty string (which is always present at the top of the undo buffer) before typing "b".
// 
// 2)
// {"a", "ab", "abac", "abacus" }
// 
// Returns: 10
// 
// There are times when it is not necessary to use the undo history at all.
// 
// 3)
// {"pyramid", "sphinx", "sphere", "python", "serpent"}
// 
// Returns: 39
// 
// 
// 
// 4)
// {"ba","a","a","b","ba"}
// 
// 
// Returns: 13
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
