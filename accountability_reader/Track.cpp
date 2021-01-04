//
//  Track.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/23/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#include "Track.h"
//----------------------------------------------------------------------------
//operator<< overload
 ostream& operator<< (ostream& output, const Track& trackObj) {
    trackObj.print(output);
    return output;
 }

//----------------------------------------------------------------------------
//constuctor
Track::Track() {
}

//----------------------------------------------------------------------------
//constructor one param overload
Track::Track(string descript) {
   trackDescription = descript;
}

Track::Track(const Track& toCopy) {
   *this = toCopy;
}

//----------------------------------------------------------------------------
//destructor
Track::~Track() {
   for (int i = 0; i < trackMetricHolder.size(); i++) {
      delete trackMetricHolder[i];
      trackMetricHolder[i] = nullptr;
   }
}

//----------------------------------------------------------------------------
//operator= overload
//the passed Track object must have the same number of Tracks as
Track& Track::operator=(const Track & toCopy) {
   if (&toCopy != this) {
     trackDescription = toCopy.trackDescription;
      cout << trackDescription;
      for (int i = 0; i < toCopy.trackMetricHolder.size(); i++) {
         trackMetricHolder.push_back(toCopy.trackMetricHolder[i]->create());
      }
   }
   return *this;
}
//----------------------------------------------------------------------------
//reads in data using commas as breaks between TrackMetrics to be made
//adds empty TrackMetric objects to TrackMetricHolder
bool Track::setPrimerData(istream & infile) {
   string trackMetricList;
   getline(infile, trackMetricList);
   string addCommatrackMetricList = trackMetricList + ",";
   std::for_each(addCommatrackMetricList.begin(),
                 addCommatrackMetricList.end(), [](char & c){
      c = ::tolower(c);
   });
   string trackMetricFromList;
   string comma = ",";
   string badInput;
 
   for (;;) {
      size_t found = addCommatrackMetricList.find(comma);
      if (found != string::npos) {
         trackMetricFromList =
                        addCommatrackMetricList.substr(0, found);
         cout << trackMetricFromList << endl;
         TrackMetric* ptr = trackMetricFactory.
                           createTrackMetric(trackMetricFromList);
        //null ptr when the trackMetric does not exist in trackMetricFactory
         if (ptr == nullptr) {
            getline(infile, badInput); //reads rest of invalid data
            break;
         }
         else {
            trackMetricHolder.push_back(ptr);
            
            addCommatrackMetricList = addCommatrackMetricList.substr(found + 1);
            if (addCommatrackMetricList.size() == 0 ) {
               break;
            }
            else {
               //changing the original string from data file to be broken down to the next
               //trackMetric object to be made in another iteration of loop
               addCommatrackMetricList = addCommatrackMetricList.substr(found + 1);
            }
         }
         
      }
      else {
         break;
         }
   }
   return true;
}

//----------------------------------------------------------------------------
//based on the number of commas or the number of objects in the
//trackMetricHolder, method takes in date from one line of file
//and fills in the data members of the empty TrackMetric objects in the
//trackMetricHolder
bool Track::setRecordData(istream & infile) {
   //gotta be able to get vector size when filling in the data for the
   //trackMetricHolder's TrackMetric objects (see comments for trackMetric.h
   //method " setData"
   
   string trackMetricList;
   string comma = ",";
   getline(infile, trackMetricList);
   
   string addCommatrackMetricList = trackMetricList + comma;
   string trackMetricFromList;
   
   string badInput;
  int count = 0;
   for (;;) {
      size_t found = addCommatrackMetricList.find(comma);
      if (found != string::npos) {
         trackMetricFromList = addCommatrackMetricList.substr(0, found);
         cout << trackMetricFromList;
         trackMetricHolder[count]->setData(trackMetricFromList);
         
         //changing the original string from data file to be broken down to the next
         //trackMetric object to be made in another iteration of loop
         //+ 2 to compensate for the comma and the space
         addCommatrackMetricList = addCommatrackMetricList.substr(found + 2);
      }
      else {
         break;
      }
   }
   
   return true;
}

//----------------------------------------------------------------------------
//print
ostream& Track::print(ostream& output) const {
   output << trackDescription << ":";
   for (int i = 0; i < trackMetricHolder.size(); i++) {
      output << " " << *trackMetricHolder[i] << ",";
   }
   return output;
}

//----------------------------------------------------------------------------
//printDataMemberNames
void Track::printDataMemberNames() const {
   cout << trackDescription << ":"; //this is the Track description
   for (int i = 0; i < trackMetricHolder.size(); i++) {
      //prints the TrackMetrics of the calling Track object
      cout << " " << trackMetricHolder[i]->getDataDescription() << ",";
   }
}

//----------------------------------------------------------------------------
//getTrackDescription
string Track::getTrackDescription() {
   return trackDescription;
}
