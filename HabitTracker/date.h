//
//  date.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/23/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#ifndef date_h
#define date_h

#include "trackMetric.h"

using namespace std;

class Date : public TrackMetric {
   friend ostream& operator<< (ostream&, const Date&);
   
public:
   Date(); //constructor
   ~Date();
  
   //set class data from data file
   //returns true if the data is set, false when bad data, i.e., is eof
   virtual bool setData(string);
   
   //helper for operator<< overload
   //concatenates data members year, month and day to ostream& object
   virtual ostream& print(ostream&) const;
   
   //prints generic data member names
   virtual void printDataMemberNames() const;
   
   //virtual function to be implemented by children class to create actions
   virtual TrackMetric* create();
   
   virtual string getDataDescription();
   
protected:
   int day;
   int month;
   int year;
   string dataDescription;
   
};
#endif /* date_hpp */
