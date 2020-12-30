//
//  date.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/23/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#include "date.h"

//----------------------------------------------------------------------------
//operator<< overload
//calls print(ostream&) method
ostream & operator<<(ostream & output, const Date & date) {
   date.print(output);
   return output;
}
//----------------------------------------------------------------------------

Date::Date() {
   dataDescription = "Date";
   day = 0;
   month = 0;
   year = 0;
}
//----------------------------------------------------------------------------

Date::~Date() { }


//----------------------------------------------------------------------------

bool Date::setData(istream &infile) {
   string theMonth;
   getline(infile, theMonth, '/');
   month = stoi(theMonth);
   if (month < 1 || month > 12) {
      cout << "Invalid month '" << year << "'" << endl;
      month = 0;
      return false;
   }
 
   infile >> day;
   
   if (day < 1 || day > 31) {
      cout << "Invalid day '" << day << "'" << endl;
      day = 0;
      return false;
   }
   getline(infile, theMonth);
   cout << theMonth;
   return true;
}

//----------------------------------------------------------------------------
//print method
ostream& Date::print(ostream& output) const {
   output << dataDescription << ": " << month << "/" << day;
   return output;
}
//----------------------------------------------------------------------------

 void Date::printDataMemberNames() const {
   cout << dataDescription << endl;
}
//----------------------------------------------------------------------------

Track* Date::create() {
   return new Date;
}
//----------------------------------------------------------------------------

string Date::getDataDescription() {
   return dataDescription;
}
