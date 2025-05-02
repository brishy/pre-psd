#ifndef VERTEBRATECHECKER_H
#define VERTEBRATECHECKER_H

#include "SeaChecker.h" //base class

//fwd decl
class SeaCreature;

//checks rules for vertebrates (fin fish basically)
class VertebrateChecker : public SeaChecker {
public:
  //check rules for this specific creature
  bool canKeep(const SeaCreature& creature) const override;
};

#endif