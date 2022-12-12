/********************************************************************************
 * File  :   data.h                                                             *
 * Author: Mohammad Seeam                                                       *
 * Graph Implementation In C++                                                  *
 * This header structure for all cpp and h files.                               *                                   *
 *******************************************************************************/

#include <string.h>
#include <iostream>
using namespace std;

struct Result{
	string message;
	bool success;
};

struct Tuple{
	int from;
	int to;
};