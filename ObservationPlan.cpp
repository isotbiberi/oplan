/*
 * ObservationPlan.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: ismail
 */

#include "ObservationPlan.h"

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <xercesc/dom/DOMNodeFilter.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/parsers/AbstractDOMParser.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/XMLException.hpp>
#include <xercesc/util/XMLString.hpp>
#include <stdexcept>
#include <utility>

using namespace std;
using namespace xercesc;
using namespace std;
using namespace xercesc_3_1;

#include <fstream>
#include <sstream>




ObservationPlan::ObservationPlan() {
	// TODO Auto-generated constructor stub

}

ObservationPlan::~ObservationPlan() {
	// TODO Auto-generated destructor stub
}

int ObservationPlan::initializeXML()
{
	try {
				XMLPlatformUtils::Initialize();
			}
	catch (const XMLException& toCatch)
	{
				char* message = XMLString::transcode(toCatch.getMessage());
				cout << "Error during initialization! :\n" << message << "\n";
				XMLString::release(&message);
				return 1;
			}
}

int ObservationPlan::applyPlan(slot selectedSlot)

{

	for (int i = 0; i < selectedSlot.mounts.size(); i++)
						{

            cout<<"goto time "<<selectedSlot.mounts[i][1].second<<" mount is moving to azimuth :"<<selectedSlot.mounts[i][2].second<<" Elevation "<<selectedSlot.mounts[i][3].second <<endl;
	        cout <<" Exp start time is " << selectedSlot.images[i][1].second <<endl;


						}

}



int ObservationPlan::readPlan() {



        initializeXML();
		XercesDOMParser* parser = new XercesDOMParser();
		parser->setValidationScheme(XercesDOMParser::Val_Always);
		parser->setDoNamespaces(true); // optional

		ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
		parser->setErrorHandler(errHandler);

		const char * xmlFile = "../../ObservationPlan.xml";


		try {
			parser->parse(xmlFile);
		} catch (const XMLException& toCatch) {
			char* message = XMLString::transcode(toCatch.getMessage());
			cout << "Exception message is: \n" << message << "\n";
			XMLString::release(&message);
			return -1;
		} catch (const DOMException& toCatch) {
			char* message = XMLString::transcode(toCatch.msg);
			cout << "Exception message is: \n" << message << "\n";
			XMLString::release(&message);
			return -1;
		} catch (...) {
			cout << "Unexpected Exception \n";
			return -1;
		}

		cout << xmlFile << ": parse OK" << endl;

		try

		{
			// no need to free this pointer - owned by the parent parser object
			DOMDocument* xmlDoc = parser->getDocument();

			// Get the top-level element: NAme is "root". No attributes for "root"

			DOMElement* elementRoot = xmlDoc->getDocumentElement();
			if (!elementRoot)
				throw(std::runtime_error("empty XML document"));

			// Parse XML file for tags of interest: "ApplicationSettings"
			// Look one level nested within "root". (child of root)

			DOMNodeIterator * walker;
			walker = xmlDoc->createNodeIterator(elementRoot,
					DOMNodeFilter::SHOW_ELEMENT, NULL, true);

			// Some declarations
			DOMNode * current_node = NULL;
			string thisNodeName;
			string parentNodeName;
			bool imageLineParts[7] = { false, false, false, false, false, false, false };
			bool mountLineParts[4] = { false, false, false, false };
			bool slotParts[4] = { false, false, false, false };





			for (current_node = walker->nextNode(); current_node != 0;
					current_node = walker->nextNode())
			{


				thisNodeName = XMLString::transcode(current_node->getNodeName());
				parentNodeName = XMLString::transcode(current_node->getParentNode()->getNodeName());


			//	std::cout<<"this node is "<<thisNodeName<<" parent is " <<parentNodeName<<endl;


				 if (parentNodeName == "Slots")

				 {

			//   std::cout<<"slot if true"<<endl;

				slotsVect.push_back(slot());
				//slotsVectSet  = true;



				 if (thisNodeName == "SlotID") {
				 slotParts[0] = true;
	             slotsVect[slotNumber].slotID=XMLString::transcode(current_node->getFirstChild()->getNodeValue());

				 } else if (thisNodeName == "ObjectID") {
				 slotParts[1] = true;
				  slotsVect[slotNumber].ObjectID=XMLString::transcode(current_node->getFirstChild()->getNodeValue());

				 } else if (thisNodeName == "StartTime") {
				 slotParts[2] = true;
				  slotsVect[slotNumber].StartTime=XMLString::transcode(current_node->getFirstChild()->getNodeValue());


							}

				 else if (thisNodeName == "EndTime") {
				 slotParts[3] = true;
				  slotsVect[slotNumber].EndTime=XMLString::transcode(current_node->getFirstChild()->getNodeValue());

							}
				if ( slotParts[3] &&  slotParts[2] &&  slotParts[1] &&  slotParts[0])
				{


					slotParts[0] = false;
					slotParts[1] = false;
					slotParts[2] = false;
					slotParts[3] = false;

				}





				 }//end if Slot


				if (parentNodeName == "ImageLine")

				{

					// std::cout<<"imageline if true"<<endl;


					if (thisNodeName == "ImageLineID")
					{
						 imageLineParts[0] = true;

						imageLine.push_back(
								std::make_pair("ImageLineID",
										XMLString::transcode(
												current_node->getFirstChild()->getNodeValue())));
					}
					else if (thisNodeName == "Time")
					{
						 imageLineParts[1] = true;

						imageLine.push_back(
								std::make_pair("Time",
										XMLString::transcode(
												current_node->getFirstChild()->getNodeValue())));

					}
					else if (thisNodeName == "ExposureTime")
					{
						 imageLineParts[2] = true;

						imageLine.push_back(
								std::make_pair("ExposureTime",
										XMLString::transcode(
												current_node->getFirstChild()->getNodeValue())));

					}

					else if (thisNodeName == "FrameNumber")
					{
						 imageLineParts[3] = true;
						imageLine.push_back(
								std::make_pair("FrameNumber",
										XMLString::transcode(
												current_node->getFirstChild()->getNodeValue())));

					}
					else if (thisNodeName == "Gain")
					{
						 imageLineParts[4] = true;
						imageLine.push_back(
								std::make_pair("Gain",
										XMLString::transcode(
												current_node->getFirstChild()->getNodeValue())));

					}
					else if (thisNodeName == "Focus")
					{
						 imageLineParts[5] = true;
						imageLine.push_back(
								std::make_pair("Focus",
										XMLString::transcode(
												current_node->getFirstChild()->getNodeValue())));

					}
					else if (thisNodeName == "Binning")
					{
						 imageLineParts[6] = true;
						 imageLine.push_back(
								std::make_pair("Binning",
										XMLString::transcode(
												current_node->getFirstChild()->getNodeValue())));

					}

					if ( imageLineParts[6] &&  imageLineParts[5] &&  imageLineParts[4] &&  imageLineParts[3]
							&&  imageLineParts[2] &&  imageLineParts[1] &&  imageLineParts[0]) {
						//std::cout<<"imageline parts hepsi true oldu"<<imageLine[0].first<<std::endl;

						 imageLines.push_back(imageLine);
						 //std::cout<<"imageline parts hepsi true oldu"<<imageLine[0].first<<std::endl;

						 imageLine.clear();
						 imageLineParts[0] = false;
						 imageLineParts[1] = false;
						 imageLineParts[2] = false;
						 imageLineParts[3] = false;
						 imageLineParts[4] = false;
						 imageLineParts[5] = false;
						 imageLineParts[6] = false;


					}

					//std::cout<<"imageline parts hepsi true muoldu"<<imageLine[0].first<<std::endl;
					// imageLinesSet = true;
				}//end if ImageLine

			//	std::cout<<"imageline parts hepsi true oldu"<<imageLine[0].first<<std::endl;

		 if (parentNodeName == "MountLine")

		 {
	    // std::cout<<"mountline if true"<<endl;

		 if (thisNodeName == "MountLineID") {
		 mountLineParts[0] = true;

		 mountLine.push_back(
		 std::make_pair("MountLineID", XMLString::transcode(current_node->getFirstChild()->getNodeValue())));
		 }
		 else if (thisNodeName == "Time")
		 {
		 mountLineParts[1] = true;

		 mountLine.push_back(std::make_pair("Time",XMLString::transcode(current_node->getFirstChild()->getNodeValue())));

		 }
		 else if (thisNodeName == "Azimuth")
		 {
		 mountLineParts[2] = true;

		 mountLine.push_back(std::make_pair("Azimuth",XMLString::transcode(current_node->getFirstChild()->getNodeValue())));

		}

		 else if (thisNodeName == "Elevation")
		 {
		 mountLineParts[3] = true;
		 mountLine.push_back(std::make_pair("Elevation",XMLString::transcode(current_node->getFirstChild()->getNodeValue())));

		}

		 if ( mountLineParts[3] &&  mountLineParts[2] &&  mountLineParts[1] &&  mountLineParts[0])
		{

			mountLines.push_back(mountLine);

			mountLine.clear();
			mountLineParts[0] = false;
			mountLineParts[1] = false;
			mountLineParts[2] = false;
			mountLineParts[3] = false;

		}

		 }//end if MountLine





			}  //end of for loop




		}//end of try

		catch (xercesc::XMLException& e)
		{
			char* message = xercesc::XMLString::transcode(e.getMessage());
			ostringstream errBuf;
			errBuf << "Error parsing file: " << message << flush;
			XMLString::release(&message);
		}



		slotsVect[slotNumber].images = imageLines;
		slotsVect[slotNumber].mounts = mountLines;
		slotNumber++;

	/*

		for (int i = 0; i < imageLines.size(); i++)
		{
			imageLine = imageLines[i];
			cout <<"printing image line "<<i+1<<endl;
			for (int i = 0; i < imageLine.size(); i++)
			{
					cout << imageLine[i].first << ", " << imageLine[i].second <<endl;
			}
		}
	*/

	/*
		for (int i = 0; i < mountLines.size(); i++)
			{
				mountLine = mountLines[i];
				cout <<"printing image line "<<i+1<<endl;
				for (int i = 0; i < mountLine.size(); i++)
				{
						cout << mountLine[i].first << ", " << mountLine[i].second <<endl;
				}
			}
	*/




	/*

		for (int i = 0; i < slotsVect[0].imageLines.size(); i++)
				{
			cout<<"ismail"<<slotsVect[0].imageLines.size()<<endl;

							//cout << slots[i].first << ", " << slots[i].second <<endl;

				}


	*/



		delete parser;


	std::cout<<"plan readed"<<std::endl;
}




