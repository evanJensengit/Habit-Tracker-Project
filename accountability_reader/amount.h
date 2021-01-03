//
//  amount.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 1/2/21.
//  Copyright © 2021 Evan Jensen. All rights reserved.
//

#ifndef amount_h
#define amount_h

#include "trackMetric.h"

using namespace std;

class Amount : public TrackMetric {
   friend ostream& operator<< (ostream&, const Amount&);
   
public:
   Amount(); //constructor
   ~Amount();
   
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
   double amount;
   string metricOfAmount;
   
};

#endif /* amount_hpp */
