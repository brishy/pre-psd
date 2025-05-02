#include "SimpleSeaCreatureFactory.h"
#include "InvertebrateCreature.h" //need concrete types
#include "SeaCreatureData.h"
#include "VertebrateCreature.h"   //need concrete types
#include <iostream>               //cerr
#include <stdexcept>              //maybe for runtime_error later
#include <string>                 //string compare

//implementation of the factory method
std::unique_ptr<SeaCreature> SimpleSeaCreatureFactory::createSeaCreature(
    const SeaCreatureData& details) const {

  //get category from details struct
  std::string category = details.category;

  //make right creature based on category string
  if (category == "Vertebrate") {
    return std::make_unique<VertebrateCreature>(details);
  } else if (category == "Invertebrate") {
    return std::make_unique<InvertebrateCreature>(details);
  } else {
    //unknown category? fail.
    std::cerr << "ERROR: SimpleFactory: Unknown creature category '" << category
              << "' for species '" << details.species << "'" << std::endl;
    //throw std::runtime_error("Unknown creature category"); //or throw?
    return nullptr; //return null for now
  }
}