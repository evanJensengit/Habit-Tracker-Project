//
//  trackfactory.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/26/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#include "trackfactory.h"
//----------------------------------------------------------------------------
//constructor
//allocates Display, Checkout, PatronHistory and Return objects to specific
//indices of actions data member
TrackFactory::TrackFactory() {
   
   for (int i = 0; i < MAXSIZE; i++) {
      tracks[i] = nullptr;
   }
   
   tracks [hash("Date")] = new Date();
//   actions[hash('C')] = new Checkout();
//   actions[hash('H')] = new PatronHistory();
//   actions[hash('R')] = new Return();
}

//----------------------------------------------------------------------------
//destructor
//deletes memory allocates in actions data member
TrackFactory::~TrackFactory() {
for (int i = 0; i < MAXSIZE; i++) {
   if ( tracks[i] != nullptr) {
      delete tracks[i];
      tracks[i] = nullptr;
   }
}
}

//----------------------------------------------------------------------------
//createAction method
//creates action and maps action to actions hash table data member
Track* TrackFactory::createTrack(string c) const {
   int subscript = hash(c);
   
   if (tracks[subscript] == nullptr) {
      return nullptr;
   }
   
   return tracks[subscript]->create();
}

//----------------------------------------------------------------------------
//hash method (dont take in the : with the passed string
//string wrkt is passed
//hash that and store it
//then weekday is passed
int TrackFactory::hash(string c) const {
   char charArray[c.size() + 1];
   strcpy(charArray, c.c_str());
   int sum = 0;
   for (int i = 0; i < c.size() + 1; i++) {
     sum += int(charArray[i]);
   }
   sum = sum % MAXSIZE;
   //either the track does not exist or tracks is being created in constructor
   //of TrackFactory
   if (tracks[sum] == nullptr) {
      return sum;
   }
   //do this in case of collsion
   cout << tracks[sum]->getDataDescription() << endl;
   if (c != tracks[sum]->getDataDescription()) {
      for (int i = 0; i < MAXSIZE;  i++) {
         sum += (i*i);
         sum = sum % MAXSIZE;
         if (tracks[sum] == nullptr) {
            return sum;
         }
         else if (tracks[sum]->getDataDescription() == c) {
            return sum;
         }
      }
   }
   
      return sum;
}
