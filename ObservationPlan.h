/*
 * ObservationPlan.h
 *
 *  Created on: Oct 11, 2017
 *      Author: ismail
 */

#ifndef OBSERVATIONPLAN_H_
#define OBSERVATIONPLAN_H_
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

struct slot
		   {
				string slotID,ObjectID,StartTime,EndTime;
				vector<vector<pair<string, string> > > mounts;
				vector<vector<pair<string, string> > > images;
		   };

class ObservationPlan {
public:
	ObservationPlan();
	virtual ~ObservationPlan();
	int readPlan();
	int initializeXML();
	int applyPlan(slot);

    vector<pair<string, string> > imageLine;
	vector<vector<pair<string, string> > > imageLines;

	vector<pair<string, string> > mountLine;
	vector<vector<pair<string, string> > > mountLines;
	vector<slot> slotsVect;

private:


    int slotNumber = 0;
};

#endif /* OBSERVATIONPLAN_H_ */
