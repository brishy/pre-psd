#ifndef INVERTEBRATECHECKER_H
#define INVERTEBRATECHECKER_H

#include "SeaChecker.h" //base class

//fwd decl
class SeaCreature;

//checks rules for invertebrates
class InvertebrateChecker : public SeaChecker {
public:
  //check rules for this specific creature
  bool canKeep(const SeaCreature& creature) const override;
};

#endif