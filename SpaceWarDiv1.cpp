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

class SpaceWarDiv1
{
public:
	long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount);
};

vector <int> girl;
int N, M;
vector < pair <int, long long > > enemyy;

bool check(long long F, vector < pair < int, long long > > enemy) {
	for(int i = 0; i < N; ++i) {
		long long curF = 0;
		for(int j = 0; j < M; ++j) if(girl[i] >= enemy[j].first ) {
			long long diff = min(F - curF, enemy[j].second );
			curF += diff;
			enemy[j].second -= diff;
		}
	}
	for(int i = 0; i < M; ++i) {
		if(enemy[i].second > 0 ) {
			return false;
		}
	}
	return true;
}

long long SpaceWarDiv1::minimalFatigue (vector <int> _girl, vector <int> _enemy, vector<long long> _enemyCnt) 
{
//	cout << "\n" << "\n";
	girl = _girl;
	if(*max_element(girl.begin(), girl.end() ) < *max_element(_enemy.begin(), _enemy.end() ))
		return -1ll;

	enemyy.clear();

	for(int i = 0; i < _enemy.size(); ++i) {
		enemyy.push_back(make_pair(_enemy[i], _enemyCnt[i]));
	}
	N = girl.size();
	M = enemyy.size();

	sort(girl.begin(), girl.end() );
	reverse(girl.begin(), girl.end() );
	sort(enemyy.begin(), enemyy.end() );
	reverse(enemyy.begin(), enemyy.end() );
/*
	for(__typeof((girl).begin()) it = (girl).begin(); it != (girl).end(); ++it) {
		 cout << *it << " ";
	}
	cout << "\n" << "\n";
	for(__typeof((enemyy).begin()) it = (enemyy).begin(); it != (enemyy).end(); ++it) {
		 printf("(%d %lld) ", it->first, it->second);
	}
	cout << "\n" << "\n";
*/
	long long l = 1, r = 1e18;

	while(l < r) {
		long long mid = (l+r)/2;
		if(check(mid, enemyy))
			r = mid;
		else
			l = mid+1;
	}
	return l;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector<long long> p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	SpaceWarDiv1 *obj;
	long long answer;
	obj = new SpaceWarDiv1();
	clock_t startTime = clock();
	answer = obj->minimalFatigue(p0, p1, p2);
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
	
	vector <int> p0;
	vector <int> p1;
	vector<long long> p2;
	long long p3;
	
	{
	// ----- test 0 -----
	int t0[] = {2,3,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,3,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	long long t2[] = {2ll,9ll,4ll};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 7ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {2,3,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	long long t2[] = {2ll,9ll,4ll};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 5ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {14,6,22};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {8,33};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	long long t2[] = {9ll,1ll};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = -1ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {869,249,599,144,929,748,665,37,313,99,33,437,308,137,665,834,955,958,613,417};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {789,57,684,741,128,794,542,367,937,739,568,872,127,261,103,763,864,360,618,307};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	long long t2[] = {20626770196420ll,45538527263992ll,52807114957507ll,17931716090785ll,65032910980630ll,88711853198687ll,26353250637092ll,61272534748707ll,89294362230771ll,52058590967576ll,60568594469453ll,23772707032338ll,43019142889727ll,39566072849912ll,78870845257173ll,68135668032761ll,36844201017584ll,10133804676521ll,6275847412927ll,37492167783296ll};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 75030497287405ll;
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
// Magical Girls are girls who have magical powers.
// They fight against evil to protect the Earth.
// Cosmic enemies have just attacked the Earth, and the Magical Girls are going to fight them.
// 
// You are given a vector <int> magicalGirlStrength that describes the Magical Girls:
// for each i, magicalGirlStrength[i] is the strength of one of the girls.
// You are also given a vector <int> enemyStrength and a vector<long long> enemyCount that describe their enemies:
// for each i, there are enemyCount[i] enemies that each have strength enemyStrength[i].
// 
// Each Magical Girl will always fight one enemy at a time.
// A Magical Girl will defeat her enemy if her strength is greater than or equal to the strength of that enemy.
// 
// At the beginning of the fight the fatigue of each Magical Girl is 0.
// Each time a Magical Girl defeats an enemy, her fatigue increases by 1.
// 
// The Magical Girls want to defeat all the enemies.
// That is, each of the enemies must be defeated by one of the Magical Girls.
// Additionally, the Magical Girls want to minimize the maximum fatigue among them.
// 
// If it is impossible to defeat all of the enemies, return -1.
// Otherwise, return the smallest F with the following property:
// the Magical Girls can defeat all enemies in such a way that at the end the fatigue of each girl is at most F.
// 
// DEFINITION
// Class:SpaceWarDiv1
// Method:minimalFatigue
// Parameters:vector <int>, vector <int>, vector<long long>
// Returns:long long
// Method signature:long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount)
// 
// 
// NOTES
// -The elements of enemyStrength are not necessarily pairwise distinct.
// 
// 
// CONSTRAINTS
// -magicalGirlStrength will contain between 1 and 50 elements, inclusive.
// -Each element of magicalGirlStrength will be between 1 and 10,000, inclusive.
// -enemyStrength and enemyCount will each contain between 1 and 50 elements, inclusive.
// -enemyStrength and enemyCount will contain the same number of elements.
// -Each element of enemyStrength will be between 1 and 10,000, inclusive.
// -Each element of enemyCount will be between 1 and 100,000,000,000,000 (10^14), inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {2, 3, 5}
// {1, 3, 4}
// {2, 9, 4}
// 
// Returns: 7
// 
// There are 3 Magical Girls, their strength are 2, 3, and 5.
// There are 3 kinds of enemies: 2 enemies with strength 1 each, 9 enemies with strength 3 each, and 4 enemies with strength 4 each.
// This is one of the ways how to minimize the maximal fatigue:
// 
// Magical girl 0 defeats 2 enemies with strength 1.
// Magical girl 1 defeats 7 enemies with strength 3.
// Magical girl 2 defeats 2 enemies with strength 3 and 4 enemies with strength 4.
// 
// 
// 1)
// {2, 3, 5}
// {1, 1, 2}
// {2, 9, 4}
// 
// Returns: 5
// 
// Each of the Magical Girls can defeat any of the enemies. The optimal strategy is that each girl should defeat 5 of the enemies.
// 
// 2)
// {14, 6, 22}
// {8, 33}
// {9, 1}
// 
// Returns: -1
// 
// None of the magical girls can defeat the enemy with strength 33.
// 
// 3)
// {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417}
// {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307}
// {20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
//  61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
//  78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296}
// 
// Returns: 75030497287405
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
