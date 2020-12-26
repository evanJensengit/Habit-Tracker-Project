//
//  Track.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/23/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#ifndef Track_h
#define Track_h

#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Track {
   friend ostream& operator<< (ostream&, const Track&);
public:
   Track();
   virtual ~Track();
   
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
   virtual Track* create() = 0;
   
protected:
   int hash(char) const;
   string dataDescription;
};
#endif /* Track_hpp */
