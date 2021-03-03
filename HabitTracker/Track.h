//
//  Track.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/23/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#ifndef Track_h
#define Track_h

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "trackmetricfactory.h"
using namespace std;


class Track {
   friend ostream& operator<< (ostream&, const Track&);
public:
   static const int NUMBER_OF_TRACKS = 1;
   Track();
   Track(string);
   Track(const Track&);
    ~Track();
   Track& operator=(const Track&);
   
   //sets Tracks with empty TrackMetric objects from data file
   //returns true if the data is set, false when bad data, i.e., is eof
   bool setPrimerData(istream&);
   
   //fills in the Track's empty TrackMetric objects with data from data file
   //returns true if the data is set, false when bad data, i.e., is eof
   bool setRecordData(istream&);
  
   //print for the dataDescript followed by the trackMetricHolder
   //with spacing for organized output, all concatenated to ostream& object
   ostream& print(ostream&) const;
   
   //printDataMemberNames prints the framework of data that the
   //Track object holds in the trackMetricHolder
   void printDataMemberNames() const;
   
   //returns dataDescription
   string getTrackDescription();
   
private:
   TrackMetricFactory trackMetricFactory;
   string trackDescription;
   vector<TrackMetric*> trackMetricHolder; //array holding track metric objects 
};
#endif /* Track_hpp */
