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
   
   for (;;) {
      size_t found = addCommatrackMetricList.find(comma);
      if (found != string::npos) {
         trackMetricFromList = addCommatrackMetricList.substr(0, found);
         
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
   return true;
}





