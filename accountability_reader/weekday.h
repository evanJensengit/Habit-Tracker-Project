//
//  weekday.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/30/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#ifndef weekday_hpp
#define weekday_hpp

#include "trackMetric.h"

using namespace std;

class Weekday : public TrackMetric {
   friend ostream& operator<< (ostream&, const Weekday&);
   
public:
   Weekday(); //constructor
   ~Weekday();
   
   //set class data from data file
   //returns true if the data is set, false when bad data, i.e., is eof
   virtual bool setData(istream&);
   
   //helper for operator<< overload
   //concatenates data members year, month and day to ostream& object
   virtual ostream& print(ostream&) const;
   
   //prints generic data member names
   virtual void printDataMemberNames() const;
   
   //virtual function to be implemented by children class to create actions
   virtual TrackMetric* create();
   
   virtual string getDataDescription();
   
protected:
   string dayOfWeek;
   string dataDescription;
};
   

#endif /* weekday_hpp */
