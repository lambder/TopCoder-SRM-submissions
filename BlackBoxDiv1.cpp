#include <bits/stdc++.h>
using namespace std;

class BlackBoxDiv1
{
public:
	int count(int N, int M);
};

int BlackBoxDiv1::count (int N, int M)
{
	int ret;
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	BlackBoxDiv1 *obj;
	int answer;
	obj = new BlackBoxDiv1();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
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
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	int p0;
	int p1;
	int p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 2;
	p1 = 2;
	p2 = 5;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 1;
	p1 = 1;
	p2 = 0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 3;
	p1 = 5;
	p2 = 32478;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 194;
	p1 = 197;
	p2 = 647560542;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Cat Upper has a rectangular black box.
// On the bottom of the box there is a grid that divides the box into identical square cells.
// There are N rows of cells, each containing M cells.
// There are no walls between the cells.
// The sides of the box are transparent.
// 
// Each cell contains a single mirror.
// Seen from above, the mirror is a segment that connects two opposite corners of the cell.
// The mirror surface is on both sides of the segment.
// (Note that for each cell there are two possible positions of the mirror.)
// 
// Cat Upper has a laser which can be used to cast rays.
// When casting a ray, the following rules must be obeyed:
// 
// The ray must be cast from outside of the black box.
// The ray must enter the box exactly in the middle of a side of a cell.
// The ray must enter the box in the direction perpendicular to the side of the box it enters through.
// 
// 
// Once inside the box, the laser follows the laws of reflection: it travels in a straight line through open space, and it reflects whenever it hits a mirror.
// (Note that this means that the laser will always travel in a direction parallel to one of the sides of the box.)
// 
// The process ends when the ray exits the black box.
// (Note that this always has to happen, and that the ray will necessarily leave through the middle of some other cell wall.)
// 
// Cat Upper used the laser to cast a ray through each of the 2N+2M cell sides that were visible from the outside.
// For each cell side C, Upper recorded where the laser that entered through C exited the black box.
// 
// Afterwards, Upper removed a single mirror from the grid and repeated the entire experiment.
// Surprisingly, the results were completely identical to the first experiment.
// 
// Cat Upper has lost the black box and he does not remember the cell from which he removed the mirror.
// The only thing he remembers are the dimensions of the black box.
// 
// You are given the two ints N and M.
// Return the number of possible initial states of the black box, modulo 1,000,000,007.
// 
// 
// DEFINITION
// Class:BlackBoxDiv1
// Method:count
// Parameters:int, int
// Returns:int
// Method signature:int count(int N, int M)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 200, inclusive.
// -M will be between 1 and 200, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 2
// 
// Returns: 5
// 
// There are 5 possible patterns.
// 
// 
// 
// In the leftmost configuration Upper could remove any of the four mirrors. In each of the other four configurations, Upper can remove the mirror that does not touch the other three mirrors.
// 
// 
// 1)
// 1
// 1
// 
// Returns: 0
// 
// 
// 
// 2)
// 3
// 5
// 
// Returns: 32478
// 
// 
// 
// 3)
// 194
// 197
// 
// Returns: 647560542
// 
// 
// 
// END KAWIGIEDIT TESTING
