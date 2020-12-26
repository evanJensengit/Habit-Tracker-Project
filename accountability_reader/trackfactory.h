//
//  trackfactory.hpp
//  accountability_reader
//
//  Created by Evan Jensen on 12/26/20.
//  Copyright © 2020 Evan Jensen. All rights reserved.
//

#ifndef trackfactory_h
#define trackfactory_h

#include <iostream>
#include <cstring>
#include "date.h"
#include "Track.h"
using namespace std;


class TrackFactory {
public:
   static const int MAXSIZE = 47;
   TrackFactory(); //constructor
   ~TrackFactory(); //destructor deallocates actions data member
   
   //creates action and maps action to actions hash table data member
   Track* createTrack(char) const;
protected:
   Track* tracks[MAXSIZE]; // stores available actions
   int hash(char) const;
};

#endif /* trackfactory_hpp */
