//
//  trackfactory.cpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/26/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#include "trackmetricfactory.h"
//----------------------------------------------------------------------------
//constructor
//allocates Display, Checkout, PatronHistory and Return objects to specific
//indices of actions data member
TrackMetricFactory::TrackMetricFactory() {
   
   for (int i = 0; i < MAXSIZE; i++) {
      trackMetrics[i] = nullptr;
   }
   
   trackMetrics [hash("Date")] = new Date();

}

//----------------------------------------------------------------------------
//destructor
//deletes memory allocates in actions data member
TrackMetricFactory::~TrackMetricFactory() {
for (int i = 0; i < MAXSIZE; i++) {
   if ( trackMetrics[i] != nullptr) {
      delete trackMetrics[i];
      trackMetrics[i] = nullptr;
   }
}
}

//----------------------------------------------------------------------------
//createAction method
//creates action and maps action to actions hash table data member
TrackMetric* TrackMetricFactory::createTrack(string c) const {
   int subscript = hash(c);
   
   if (trackMetrics[subscript] == nullptr) {
      return nullptr;
   }
   
   return trackMetrics[subscript]->create();
}

//----------------------------------------------------------------------------
//hash method (dont take in the : with the passed string
//string wrkt is passed
//hash that and store it
//then weekday is passed
int TrackMetricFactory::hash(string c) const {
   char charArray[c.size() + 1];
   strcpy(charArray, c.c_str());
   int sum = 0;
   for (int i = 0; i < c.size() + 1; i++) {
     sum += int(charArray[i]);
   }
   sum = sum % MAXSIZE;
   //either the track does not exist or tracks is being created in constructor
   //of TrackFactory
   if (trackMetrics[sum] == nullptr) {
      return sum;
   }
   //do this in case of collsion
 //  cout << tracks[sum]->getDataDescription() << endl;
   if (c != trackMetrics[sum]->getDataDescription()) {
      for (int i = 0; i < MAXSIZE;  i++) {
         sum += (i*i);
         sum = sum % MAXSIZE;
         if (trackMetrics[sum] == nullptr) {
            return sum;
         }
         else if (trackMetrics[sum]->getDataDescription() == c) {
            return sum;
         }
      }
   }
   
      return sum;
}
