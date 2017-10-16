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
#include<thread>
#include"Timer.h"
#include"ObservationPlan.h"

int main(int argc, char* args[]) {
	using namespace timeOp;


/*
	ObservationPlan plan;

  /*
   long long runTime = plan.nonParsedToDateMilliSec("20171012_152400_0")-plan.return_current_time_and_date();

   std::cout<<runTime<<std::endl;
   plan.waitMicroSec(runTime*1000);
   std::cout<<plan.return_current_time_and_date()<<std::endl;
   plan.nonParsedToDateMilliSec("20171012_152400_0");
*/


	ObservationPlan plan;


	/*
	plan.nonparsedToDateMicroSec("20171012_152400_123345");
	plan.timeParser("20171012_152400_123345");
	std::cout<<plan.nonparsedToDateMicroSec("124567");

*/
	/*
	 auto start = std::chrono::high_resolution_clock::now();
	  // Code to time here...
	  auto end = std::chrono::high_resolution_clock::now();

	  auto dur = end - start;
	  auto i_millis = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
	  auto f_secs = std::chrono::duration_cast<std::chrono::duration<float>>(end);
	  std::cout << i_millis.count() << '\n';
	  std::cout << f_secs.count() << '\n';

*/




	plan.readPlan();

	plan.applyPlan(plan.slotsVect[0]);









	/*
	 vector<string> parsedDate=plan.timeParser("20160801_013846_3267001");
	 for (std::vector<string>::const_iterator i = parsedDate.begin(); i != parsedDate.end(); ++i)
	 std::cout << *i << ' ';
	 */
	// plan.parsedToDateTime(parsedDate);

//	plan.readPlan();
//	cout<<plan.return_current_time_and_date();
	/*

	 plan.printTimeStamp();
	 plan.waitMicroSec(100);
	 plan.printTimeStamp();

	 */
	//plan.applyPlan(plan.slotsVect[0]);
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

	/*

	 Timer tmr;
	 double t = tmr.elapsed();
	 std::cout << t << std::endl;

	 tmr.reset();
	 t = tmr.elapsed();
	 std::cout << t << std::endl;

	 */

	return 0;

}

