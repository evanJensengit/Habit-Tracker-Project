//
//  sleep.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/30/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#ifndef sleep_h
#define sleep_h

#include "trackMetric.h"

using namespace std;

class Sleep : public TrackMetric {
   friend ostream& operator<< (ostream&, const Sleep&);
   
public:
   Sleep(); //constructor
   ~Sleep();
   
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
   int bedTime;
   int wakeTime;
   
};
#endif /* sleep_hpp */
