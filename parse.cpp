#include <iostream>
#include <iomanip>
// Compile with something like (Makefile excerpt):
// g++ -g -O0 -Wall -I/usr/local/xerces/include/ $(^) -L/usr/local/xerces/lib/ -lxerces-c

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include<time.h>
#include<cstdlib>
#include<cstring>

#include"ObservationPlan.h"

int main(int argc, char* args[]) {



	ObservationPlan plan;

/*
	vector<string> parsedDate=plan.timeParser("20160801_013846_3267001");
    plan.parsedToDateTime(parsedDate);
*/

	plan.readPlan();
/*

	plan.printTimeStamp();
    plan.waitMicroSec(100);
    plan.printTimeStamp();

*/
	plan.applyPlan(plan.slotsVect[0]);
    //std::cout<< "time stamp is "<<plan.GetTimeStamp()<<endl;


/*
	struct tm tm;
	char buf[255];

	memset(&tm, 0, sizeof(struct tm));
	strptime("20160801_013846", "%Y%m%d_%H%M%S", &tm);
	strftime(buf, sizeof(buf), "%d %b %Y %H:%M:%S", &tm);
	puts(buf);
	exit(EXIT_SUCCESS);
*/


/*

*/



}

