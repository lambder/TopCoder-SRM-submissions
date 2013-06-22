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

class TravellingPurchasingMan
{
public:
	int maxStores(int N, vector <string> interestingStores, vector <string> roads);
};

const int oo = 1<<28;
int N, M;
/*
void printBin(int x) {
	for(int i = 0; i < M; i++) {
		cout << ((x & (1<<i)) == 0 ? 0 : 1);
	}
	cout << " " ;
}
*/
struct Store {
	int open, close, duration;
	Store(int o, int c, int d): open(o), close(c), duration(d) {}
};

vector < Store > store;
int dist[55][55];
int Ans[1<<18][18];

int solve(int flag, int idx) {
	int &ans = Ans[flag][idx];
	if(ans != -2)
		return ans;

	if(__builtin_popcount(flag) == 1) {
		if(dist[N-1][idx] > store[idx].close)
			return ans = -1;
		return ans = max(dist[N-1][idx], store[idx].open) + store[idx].duration;
	}

	ans = oo;

	for(int i = 0; i < M; i++)	if( i != idx && (flag & (1<<i)) != 0) {
		int tm = solve(flag ^ (1<<idx), i);
		if(tm == -1 || tm + dist[i][idx] > store[idx].close) {
			continue;
		}
		int tmp = tm + dist[i][idx];
		tmp = max(store[idx].open, tm) + store[idx].duration;
	//	printBin(flag ^ (1<<idx));
	//	printf("%d: %d\n", i, tmp );
		ans = min(ans, tmp);
	}
	if(ans == oo)
		ans = -1;
	return ans;
}

int TravellingPurchasingMan::maxStores (int _N, vector <string> interestingStores, vector <string> roads) 
{
	N = _N;
	M = interestingStores.size();
//	cout << "N = " << N << "\n"; 
//	cout << "M = " << M << "\n"; 

	for(int i = 0; i < (1<<18); i++) {
		for(int j = 0; j < 18; j++) {
			Ans[i][j] = -2;
		}
	}

	int ret = 0;
	store.clear();

	for(int i = 0; i < 55; i++) {
		for(int j = 0; j < 55; j++) {
			dist[i][j] = oo;
		}
		dist[i][i] = 0;
	}

	for(__typeof((roads).begin()) it = (roads).begin(); it < (roads).end(); it++) {
		 int u, v, d;
		 sscanf(it->c_str(), "%d %d %d", &u, &v, &d);
		 dist[u][v] = dist[v][u] = d;
	}

	for(__typeof((interestingStores).begin()) it = (interestingStores).begin(); it < (interestingStores).end(); it++) {
		 int o, c, d;
		 sscanf(it->c_str(), "%d %d %d", &o, &c, &d);
		 store.push_back(Store(o, c, d));
	}

	for(int k = 0; k < N; k++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
/*
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < M; j++) {
			if(i == j)
				printf("%8d ", dist[N-1][i] < oo ? dist[N-1][i] : -1);
			else
				printf("%8d ", dist[i][j] < oo ? dist[i][j] : -1);
		}
		cout << "\n";
	}
	cout << "\n";
*/
	for(int i = 1; i < (1<<M); i++) {
		for(int j = 0; j < M; j++) {
			if((i & (1<<j)) != 0) {
				int tmp = solve(i, j);
				if(tmp != -1) {
//					printBin(i);
//					printf("%d : %d\n",j, tmp );
					ret = max(ret, __builtin_popcount(i));
				}
			}
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <string> p1, vector <string> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	TravellingPurchasingMan *obj;
	int answer;
	obj = new TravellingPurchasingMan();
	clock_t startTime = clock();
	answer = obj->maxStores(p0, p1, p2);
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
	vector <string> p1;
	vector <string> p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 3;
	string t1[] = {"1 10 10","1 55 31","10 50 100"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"1 2 10"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	string t1[] = {"1 10 10","1 55 30","10 50 100"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"1 2 10"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5;
	string t1[] = {"0 1000 17"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"2 3 400","4 1 500","4 3 300","1 0 700","0 2 400"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 25;
	string t1[] = {"48740 73375 4349","46525 73309 24112","35755 65470 7242","22006 53784 30706","49689 53269 48541","47600 89571 33875","245 6630 47790","48827 106435 2758","41889 59500 35178","2580 6006 15784","4160 64058 10198","32652 37789 51826","2000 9692 54134","6174 61628 59460","24862 46545 8870"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"0 1 27896","1 3 54632","3 2 537","0 6 5326","6 8 28344","1 5 4448","2 11 29053","3 14 19006","5 10 40106","3 16 51801","14 17 26011","3 22 51841","14 4 1862","22 9 43613","22 19 7138","1 12 32428","6 24 42526","8 23 46180","10 21 20712","23 15 48846","24 13 21162","8 3 28666","17 1 56040","12 16 16216","19 1 4263","9 13 47592","17 15 8689","17 19 9609","19 11 11267","9 6 6696","22 5 59391","20 14 9770","7 1 22379","23 22 965","5 21 50833","3 11 13128","14 7 1475","4 2 4272","14 5 8418","23 10 51913","2 8 33244","4 19 12017","2 21 20484"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
// You are interested in purchasing items from a number of stores in a local market. The market is composed of N stores numbered from 0 to N-1. The stores with numbers from 0 to M-1 are interesting to you and all the other stores are not interesting. Some pairs of stores are connected by roads.
// 
// You are given a vector <string> interestingStores which contains M elements and describes the interesting stores. The i-th element corresponds to store i and is formatted "OPEN CLOSE DURATION" (quotes for clarity), where OPEN is the opening time (in seconds), CLOSE is the closing time (in seconds) and DURATION is the time (in seconds) required to make a purchase in this store. You can initiate a purchase from a store at any time T between OPEN and CLOSE, inclusive. In order to do so, you need to arrive to the store at time T (or earlier). The purchase will be finalized at time T + DURATION and you need to stay at the store for the entire duration of your purchase. Note that it is possible for a purchase to end when the store is already closed. You cannot make multiple purchases in the same store.
// 
// The roads are given by the vector <string> roads. Each element of roads describes a single bidirectional road and is formatted "A B LENGTH" (quotes for clarity). Here A and B are the numbers of stores connected by the road and LENGTH is the time (in seconds) required to move from A to B (or from B to A) using this road.
// 
// Your start at time 0 at the location of store N-1. Return the maximum number of purchases in interesting stores that you can make.
// 
// DEFINITION
// Class:TravellingPurchasingMan
// Method:maxStores
// Parameters:int, vector <string>, vector <string>
// Returns:int
// Method signature:int maxStores(int N, vector <string> interestingStores, vector <string> roads)
// 
// 
// NOTES
// -You are allowed to wait for any amount of time at any location.
// 
// 
// CONSTRAINTS
// -N will be between 1 and 50, inclusive.
// -roads will contain between 1 and 50 elements, inclusive.
// -Each element of roads will be formatted "A B LENGTH" (quotes for clarity), where A, B and LENGTH are integers with no unnecessary leading zeros.
// -In each road, A and B will each be between 0 and N-1, inclusive.
// -In each road, A and B will be distinct.
// -In each road, LENGTH will be between 1 and 604,800, inclusive.
// -There will exist at most one road between each pair of stores.
// -interestingStores will contain between 1 and min{16, N} elements, inclusive,
// -Each element of interestingStores will be formatted "OPEN CLOSE DURATION" (quotes for clarity), where OPEN, CLOSE and DURATION are integers with no unnecessary leading zeros.
// -In each store, OPEN will be between 0 and 604,800, inclusive.
// -In each store, CLOSE will be between OPEN+1 and 604,800, inclusive.
// -In each store, DURATION will be between 1 and 604,800, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// {"1 10 10" , "1 55 31", "10 50 100" }
// {"1 2 10"}
// 
// Returns: 1
// 
// It is not possible to make more than one purchase:
// If you decide to make the purchase at store 2: You need to wait 10 seconds until it opens. Then wait until time = 110 seconds for the purchase to finish. At 110 seconds, all the other stores will be closed.
// If you instead decide to make the purchase at store 1: You first need travel through the road and arrive store 1 at time = 10. The purchase finishes at time = 41. After you travel back to store 2, the time will be 51 seconds and store 2 will be closed.
// There is no way to reach store 0 when store 2 is the starting point.
// 
// 
// 1)
// 3
// {"1 10 10" , "1 55 30", "10 50 100" }
// {"1 2 10"}
// 
// Returns: 2
// 
// This time we can travel to store 1, make the purchase and return to store 2 exactly at time = 50 to make two purchases in total.
// 
// 
// 2)
// 5
// {"0 1000 17"}
// {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"}
// 
// Returns: 0
// 
// It is not possible to reach store 0 before it closes.
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
