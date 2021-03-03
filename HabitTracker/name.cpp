//
//  name.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 1/2/21.
//  Copyright © 2021 Evan Jensen. All rights reserved.
//

#include "name.h"
//----------------------------------------------------------------------------
//operator<< overload
//calls print(ostream&) method
ostream & operator<<(ostream & output, const Name & nameObj) {
   nameObj.print(output);
   return output;
}
//----------------------------------------------------------------------------

Name::Name() {
   dataDescription = "Amount";
   theName = "";
   
}
//----------------------------------------------------------------------------

Name::~Name() { }


//----------------------------------------------------------------------------

bool Name::setData(string the_Name) {
   theName = the_Name;
   return true;
}

//----------------------------------------------------------------------------
//print method
ostream& Name::print(ostream& output) const {
   output << dataDescription << ": " << theName;
   return output;
}
//----------------------------------------------------------------------------

void Name::printDataMemberNames() const {
   cout << dataDescription << endl;
}
//----------------------------------------------------------------------------

TrackMetric* Name::create() {
   return new Name;
}
//----------------------------------------------------------------------------

string Name::getDataDescription() {
   return dataDescription;
}
