//
//  trackMetric.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/31/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//



#ifndef trackMetric_h
#define trackMetric_h

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
//class TrackMetric is the metrics ( amount, frequency, name)
//of the trackobject
class TrackMetric {
   friend ostream& operator<< (ostream&, const TrackMetric&);
public:
   static const int MAXSIZE = 47;
   TrackMetric();
   virtual ~TrackMetric();
   
   //set class data from data file
   //returns true if the data is set, false when bad data, i.e., is eof
   virtual bool setData(istream&) = 0;
   
   //print for the data members of child class with spacing for
   //organized output
   virtual ostream& print(ostream&) const = 0;
   
   //printDataMemberNames prints the framework of data that the
   //child class holds like
   virtual void printDataMemberNames() const = 0;
   
   //virtual function to be implemented by children class to create actions
   virtual TrackMetric* create() = 0;
   
   virtual string getDataDescription() = 0;
   
protected:
   int hash(string) const;
};

#endif /* trackMetric_hpp */
