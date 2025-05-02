#ifndef SEACREATUREDATA_H
#define SEACREATUREDATA_H

#include <map> //for misc info map
#include <string>

//simple struct for catch data passed around
struct SeaCreatureData {
  std::string species;
  float size = 0.0f; //init just in case
  bool hasEggs = false;
  std::string category; //"Vertebrate" or "Invertebrate"
  std::map<std::string, std::string> otherRelevantInfo; //unused extras map
};

#endif