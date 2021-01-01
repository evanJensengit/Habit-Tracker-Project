//
//  weekday.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/30/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#include "weekday.h"
//----------------------------------------------------------------------------
//operator<< overload
//calls print(ostream&) method
ostream & operator<<(ostream & output, const Weekday& weekdayObj) {
   weekdayObj.print(output);
   return output;
}
//----------------------------------------------------------------------------

Weekday::Weekday() {
   dayOfWeek = "";
   dataDescription = "Weekday";
   
}
//----------------------------------------------------------------------------

Weekday::~Weekday() { }


//----------------------------------------------------------------------------

bool Weekday::setData(istream &infile) {
   getline(infile, dayOfWeek);
   return true;
}

//----------------------------------------------------------------------------
//print method
ostream& Weekday::print(ostream& output) const {
   output << dataDescription << ": " << dayOfWeek;
   return output;
}
//----------------------------------------------------------------------------

void Weekday::printDataMemberNames() const {
   cout << dataDescription << endl;
}
//----------------------------------------------------------------------------

TrackMetric* Weekday::create() {
   return new Weekday;
}
//----------------------------------------------------------------------------

string Weekday::getDataDescription() {
   return dataDescription;
}
