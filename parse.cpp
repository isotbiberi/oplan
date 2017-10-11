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

#include"ObservationPlan.h"

int main(int argc, char* args[]) {

// This is where our data will go after it's pulled out of the XML file

	ObservationPlan plan;
	plan.readPlan();

	plan.applyPlan(plan.slotsVect[0]);




	return 0;
}

