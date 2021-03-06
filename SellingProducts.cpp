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

#define Pf	printf
#define	Sf	scanf

#define	ep	1e-9
#define PI M_PI
#define E M_E

#define	CL(a, b)	memset(a, b, sizeof(a))
#define	mp	make_pair

#define	pb	push_back

#define	all(c)	(c).begin(), (c).end()
#define	tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())		//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int) b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int)b; i>=loop_ends_here; i--)

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

class SellingProducts
{
public:
	int optimalPrice(vector <int> price, vector <int> cost);
};


int SellingProducts::optimalPrice (vector <int> price, vector <int> cost) 
{
	int mxProfit = 0;
	int mnCost = -1;
	
	forn(i, price.size()) {
		int profit = 0;
		
		forn(j, price.size()) {
			if(price[j] >= price[i])
				profit += max(0, price[i] - cost[j]);
		}
		
		if(mxProfit == 0 && profit > 0) {
			mxProfit = profit;
			mnCost = price[i];
		}
		else if(mxProfit > 0 && profit > mxProfit) {
			mnCost = price[i];
			mxProfit = profit;
		}
		else if(mxProfit > 0 && profit == mxProfit && mnCost > price[i]) {
			mnCost = price[i];
		}
		
		Pf("price = %d, profit = %d, mxProfit = %d, mnCost = %d\n", price[i], profit, mxProfit, mnCost);
	}
	
	return mnCost == -1 ? 0 : mnCost;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
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
	cout << "}";
	cout << "]" << endl;
	SellingProducts *obj;
	int answer;
	obj = new SellingProducts();
	clock_t startTime = clock();
	answer = obj->optimalPrice(p0, p1);
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {13,22,35};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 22;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {13,22,35};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {5,15,30};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 13;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {13,22,35};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {15,30,40};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {10,10,20,20,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,5,11,15,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 10;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {13,17,14,30,19,17,55,16};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {12,1,5,10,3,2,40,19};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 17;
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
// You are planning to release a new product on the market and you want to find a strategy that will maximize your profit. That strategy will include fixing the optimal price for the product. You have made a customer list containing the maximum price each potential customer is willing to pay.  You also know how much it costs to deliver the product to each of those customers.  You are responsible for paying all the shipping costs, so if it's too expensive to deliver the product to a customer, you can choose not to sell to that customer.
// 
// You will be given vector <int>s price and cost, where price[i] is the maximum price customer i is willing to pay for the product and cost[i] is the cost of delivering the product to customer i.  Return the price for the product that maximizes profit. If there are multiple such prices, return the smallest among them. If it's impossible to achieve a positive profit, return 0.
// 
// DEFINITION
// Class:SellingProducts
// Method:optimalPrice
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int optimalPrice(vector <int> price, vector <int> cost)
// 
// 
// CONSTRAINTS
// -price will contain between 1 and 50 elements, inclusive.
// -Each element of price will be between 1 and 10^6, inclusive.
// -cost will contain the same number of elements as price.
// -Each element of cost will be between 0 and 10^6, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {13,22,35}
// {0,0,0}
// 
// Returns: 22
// 
// If we sell the product at 13 then all three would buy it.(3x13=39)
// If we sell the product at 22 then only two would buy it. (2x22=44)
// If we sell the product at 35 then only one would buy it. (1x35=35)
// So, 22 is the optimal price for our product.
// 
// 1)
// {13,22,35}
// {5,15,30}
// 
// Returns: 13
// 
// If we sell the product at 13 then all three would buy it, but we would only sell to the first one.(13-5=8)
// If we sell the product at 22 then only two would buy it, but we would only sell to the second one.(22-15=7).
// If we sell the product at 35 then only one would buy it. (35-30=5)
// So, 13 is the optimal price for our product.
// 
// 2)
// {13,22,35}
// {15,30,40}
// 
// Returns: 0
// 
// Here it is too expensive to sell to anyone. So the optimal price is 0.
// 
// 3)
// {10,10,20,20,5}
// {1,5,11,15,0}
// 
// Returns: 10
// 
// If we sell the product at 10 we gain 9 from the first customer and 5 from the second one(Total profit = 14). If we sell the product at 20 we gain 9 from the third customer and 5 from the fourth one(Total profit = 14). So both 10 and 20 are optimal prices but we must choose the smallest one.
// 
// 4)
// {13,17,14,30,19,17,55,16}
// {12,1,5,10,3,2,40,19}
// 
// Returns: 17
// 
// 
// 
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
