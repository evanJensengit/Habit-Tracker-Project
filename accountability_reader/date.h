//
//  date.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/23/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#ifndef date_h
#define date_h

#include "Track.h"

using namespace std;

class Date : public Track {
   friend ostream& operator<< (ostream&, const Date&);
   
public:
   Date(); //constructor
   ~Date();
   virtual bool setData(istream&); //sets data for Date object
   virtual ostream& print(ostream&);
   
protected:
   int day;
   int month;
   int year;
   
};
#endif /* date_hpp */
