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
   
   Track();
   Track(string);
    ~Track();
   
   //set class data from data file
   //returns true if the data is set, false when bad data, i.e., is eof
   //sets
   bool setPrimerData(istream&);
  
   
   bool setRecordData(istream&);
  
   //print for the dataDescript followed by the trackMetricHolder
   //with spacing for organized output, all concatenated to ostream& object
   ostream& print(ostream&) const;
   
   //printDataMemberNames prints the framework of data that the
   //Track object holds in the trackMetricHolder
   void printDataMemberNames() const;
   
   //returns dataDescription
   string getDataDescription();
   
   //gotta
   
   
private:
   TrackMetricFactory trackMetricFactory;
   string dataDescription;
   vector<const TrackMetric*> trackMetricHolder;
};
#endif /* Track_hpp */
