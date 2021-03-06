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

class TheTriangleBothDivs
{
public:
	string fix(string time);
};

set <string> st;

int p = 24*60;

bool isMatch(const string &st1, const string &st2) {
	assert(st1.size() == st2.size());
	forn(i, st1.size()) {
		if(st2[i] != '?') 
			if(st1[i] != st2[i])
				return false;
	}
	return true;
}

string TheTriangleBothDivs::fix (string time) 
{
	st.clear();
	
	forn(h, 24) {
		forn(m, 60) {
			forab(gmt, -9, 9) {
				SS ss;
				if(h < 10)
					ss << 0;
				ss << h << ":";
				if(m < 10)
					ss << 0;
				ss << m << " GMT";
				if(gmt < 0)
					ss << gmt;
				else 
					ss << '+' << gmt;
				if(isMatch(ss.str(), time)) {
					int mn = h*60 + m - gmt*60;
					mn = (mn + p) % p;
					SS sss;
					int hh = mn/60;
					int mm = mn%60;
					if(hh < 10)
						sss << 0;
					sss << hh << ":";
					if(mm < 10)
						sss << 0;
					sss << mm;
					st.insert(sss.str());
				}
			}
		}
	}

	return *st.begin();
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
	TheTriangleBothDivs *obj;
	string answer;
	obj = new TheTriangleBothDivs();
	clock_t startTime = clock();
	answer = obj->fix(p0);
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
	p0 = "17:45 GMT-4";
	p1 = "21:45";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "16:?" "? GMT?" "?";
	p1 = "00:00";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "?1:34 GMT-9";
	p1 = "06:34";
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
// John and Brus have always been confused by time zones.  Their recent promotions to Concorde pilot and copilot do not help.  Having to constantly fly through the Bermuda Triangle does not help either.  They have therefore purchased a special digital clock that displays the current time in one of 19 time zones, from GMT-9 to GMT+9.  The clock displays time in the format "HH:mm GMTof" (quotes for clarity), where HH is the hour of the day (between 00 and 23, inclusive), mm is the number of minutes since the start of the hour (between 00 and 59, inclusive), and of is the offset from "Greenwich Mean Time" (time zone GMT+0) to the current time zone.  If the offset is +4, for example, it means the displayed time is 4 hours ahead of the time in GMT+0, and if the offset is -4, it means the time is 4 hours behind the time in GMT+0.  GMT+0 will always be displayed with an offset of +0, so the clock will never display it as GMT-0.
// 
// In the middle of a flight, John wanted to know what time it was, so he asked Brus to check the clock.  To Brus' surprise, the Bermuda Triangle had caused the clock to malfunction, and some of the characters on the display were unrecognizable.  You are given the clock's display as a string time, where '?' characters represent the unrecognizable characters.  Assuming that all the recognizable characters are accurate, determine what time it is in time zone GMT+0.  Return this time formatted as "HH:mm" (quotes for clarity).  If there are multiple possible answers, return the one that comes earliest lexicographically.  The constraints ensure that at least one result is always possible.
// 
// DEFINITION
// Class:TheTriangleBothDivs
// Method:fix
// Parameters:string
// Returns:string
// Method signature:string fix(string time)
// 
// 
// NOTES
// -string s1 comes before string s2 lexicographically if s1 has a lexicographically smaller character at the first index where they differ.
// 
// 
// CONSTRAINTS
// -time will contain exactly 11 characters.
// -time will be formatted "xx:xx GMTsx" (quotes for clarity).
// -Each x in time will be a digit ('0'-'9') or '?'.
// -The s in time will be '-','+' or '?'.
// -time will represent a valid clock display (as described in the statement) where zero or more of the digits or the '-' or '+' sign have been replaced by '?' characters.
// 
// 
// EXAMPLES
// 
// 0)
// "17:45 GMT-4"
// 
// Returns: "21:45"
// 
// 
// 
// 1)
// "16:?? GMT??"
// 
// Returns: "00:00"
// 
// There are many possible times the clock could be displaying, for example: "16:00 GMT+8", "16:35 GMT-9", etc.
// It is possible to choose "00" minutes and the GMT-8 time zone to yield time "00:00" which is the lexicographically first result.
// 
// 2)
// "?1:34 GMT-9"
// 
// Returns: "06:34"
// 
// 
// 
// 3)
// "??:?? GMT??"
// 
// Returns: "00:00"
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
