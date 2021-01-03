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

Track::Track(string descript) {
   dataDescription = descript;
}

//----------------------------------------------------------------------------
//destructor
Track::~Track() {
}

//----------------------------------------------------------------------------
//reads in data using commas as breaks between TrackMetrics to be made
//adds empty TrackMetric objects to TrackMetricHolder
bool Track::setPrimerData(istream & infile) {
   string trackMetricList;
   getline(infile, trackMetricList);
   string addCommatrackMetricList = trackMetricList + ",";
   string trackMetricFromList;
   string comma = ",";
   string badInput;
 
   for (;;) {
      size_t found = addCommatrackMetricList.find(comma);
      if (found != string::npos) {
         trackMetricFromList = addCommatrackMetricList.substr(0, found);
         cout << trackMetricFromList;
         TrackMetric* ptr = trackMetricFactory.createTrackMetric(trackMetricFromList);
         if (ptr == nullptr) { //nullptr when bookType is not in UWBLibrary
            getline(infile, badInput); //reads rest of invalid data
         }
         else {
            trackMetricHolder.push_back(ptr);
         }
         //changing the original string from data file to be broken down to the next
         //trackMetric object to be made in another iteration of loop
         addCommatrackMetricList = addCommatrackMetricList.substr(found + 2);
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





