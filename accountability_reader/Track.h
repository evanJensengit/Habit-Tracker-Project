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
using namespace std;

class Track {
   friend ostream& operator<< (ostream&, const Track&);
public:
   
   Track();
   virtual ~Track();
   
   //set class data from data file
   //returns true if the data is set, false when bad data, i.e., is eof
   virtual bool setData(istream&);
  
   //print for the data members of child class with spacing for
   //organized output
   virtual ostream& print(ostream&) const;
   
   //printDataMemberNames prints the framework of data that the
   //child class holds like
   virtual void printDataMemberNames() const;
   
   //virtual function to be implemented by children class to create actions
   virtual Track* create();
   
  virtual string getDataDescription();
   
protected:
   string dataDescription;
   vector<const Track*> trackHolder;
};
#endif /* Track_hpp */
