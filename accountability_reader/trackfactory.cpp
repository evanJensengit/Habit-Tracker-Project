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
      tracks [i] = nullptr;
   }
   actions [hash('D')] = new Date();
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
Track* TrackFactory::createTrack(char c) const {
   int subscript = hash(c);
   if (subscript > MAXSIZE ) {
      return nullptr;
   }
   else if (subscript < 0) { //hash did not work
      return nullptr;
   }
   else if (tracks[subscript] == nullptr) {
      return nullptr;
   }
   return tracks[subscript]->create();
}

//----------------------------------------------------------------------------
//hash method
int TrackFactory::hash(char c) const {
   toupper(c);
   int posIndex = c % MAXSIZE;
   if (tracks[posIndex] == nullptr ) {
      return posIndex;
   }
   int collision, collisionSum ;
   
   for (int i = 1; i < MAXSIZE; i++) {
      collision = i * i;
      collisionSum = (collision + posIndex) % MAXSIZE;
      if (tracks[collisionSum] == nullptr ) {
         return collisionSum;
      }
   }
   
   
   return -1;
}
