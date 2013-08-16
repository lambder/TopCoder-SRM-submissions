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

class Hyphenated
{
public:
	double avgLength(vector <string> lines);
};

bool isLatin(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

double Hyphenated::avgLength (vector <string> lines) 
{
	vector <string> words;
	words.push_back("");

	for(int i = 0; i < lines.size(); ++i) {
		string st = lines[i];
		for(int j = 0; j < st.size(); ++j) {
			if(isLatin(st[j]))
				words.back() += st[j];
			else if(st[j] == '-' && j == st.size()-1 && j > 0 && isLatin(st[j-1]))
				continue;
			else
				words.push_back("");
		}
	}
	int cnt = 0;
	double ret = 0;
	for(auto it = (words).begin(); it != (words).end(); ++it) {
//		cout << *it << "\n";
		if(it->size() > 0) {
			cnt++;
			ret += it->size();
		}
	}
	ret /= cnt;
	
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, double p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Hyphenated *obj;
	double answer;
	obj = new Hyphenated();
	clock_t startTime = clock();
	answer = obj->avgLength(p0);
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
		res = answer == answer && fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
	double p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"  now is the ex-","ample.  "};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3.75;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"  now is the ex-"," ample.  "};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3.0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"inter-","national-","ization.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 20.0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"All the time I have well-defined  "," trouble."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4.125;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"hello-","-","-","-","great"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5.0;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
// We want to be able to judge whether text is suitable for a particular age 
// group. We will base our judgment on the average length of a word in the text, so we 
// need to define what a "word" is.
// 
// We define a "word" to be a maximal sequence of letters ('A'-'Z' and/or 'a-z') within a
// single line. (Maximal means that if 2 letters are adjacent within a line, they are in the same
// word.) But if a line ends with a sequence of one or more letters immediately 
// followed by a hyphen ('-') and the next line starts with a sequence of one or more letters,
// all these letters are considered to be in the same word. It is even possible that a hyphenated
// word could extend across several lines (see Example 2). 
// 
// Create a class Hyphenated that contains a method avgLength that is given a 
// vector <string> lines containing the lines of text and that returns the average length 
// of the words within the text.
// 
// 
// DEFINITION
// Class:Hyphenated
// Method:avgLength
// Parameters:vector <string>
// Returns:double
// Method signature:double avgLength(vector <string> lines)
// 
// 
// NOTES
// -A return value with either an absolute or relative error of less than 1.0E-9 is considered correct.
// 
// 
// CONSTRAINTS
// -lines will contain between 1 and 50 elements inclusive.
// -Each element of lines will contain between 1 and 50 characters inclusive.
// -Each character in each element of lines will be a letter ('A-'Z' or 'a'-'z') or will be one of these:  ' ', '-', '.'
// -At least one element of lines will contain a letter.
// 
// 
// EXAMPLES
// 
// 0)
// {"  now is the ex-", "ample.  "} 
// 
// Returns: 3.75
// 
//    There are 4  words:  now, is, the, example
// 
// 
// 1)
// {"  now is the ex-", " ample.  "}
// 
// Returns: 3.0
// 
// 
//    There are 5 words:  now, is, the, ex, ample
//    Note that the leading blank prevents the joining of ex and ample. Also
//    note that words only consist of letters, so the hyphen is never a part of
//    a word.
// 
// 
// 2)
// {"inter-","national-","ization.."}
// 
// Returns: 20.0
// 
// 
// 
//    There is only one word.
// 
// 3)
// {"All the time I have well-defined  "," trouble."}
// 
// Returns: 4.125
// 
// Note that well-defined consists of 2 separate words.
// 
// 4)
// {"hello-","-","-","-","great"}
// 
// Returns: 5.0
// 
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!