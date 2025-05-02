#include "InvertebrateChecker.h"
#include "SeaCreature.h" //need full def
#include <algorithm>     //std::equal, std::tolower, std::transform
#include <iostream>      //cout/cerr
#include <string>
#include <vector>        //vector for egg check list

//case-insensitive string compare helper
namespace { //anon namespace for helper
bool iequals(const std::string& a, const std::string& b) {
  return std::equal(a.begin(), a.end(), b.begin(), b.end(),
                    [](char a_char, char b_char) {
                      return std::tolower(a_char) == std::tolower(b_char);
                    });
}
} //namespace

//check rules for invertebrates
bool InvertebrateChecker::canKeep(const SeaCreature& creature) const {

  const std::string& species = creature.getSpecies();
  float size = creature.getSize(); //size = carapace width/length probably
  bool hasEggs = creature.carriesEggs();

  //species that need egg check (based on '+' in PDF)
  std::vector<std::string> egg_check_species = {"lobster", "crab", "bug", "crayfish"};
  bool check_eggs = false;
  std::string lower_species = species;
  std::transform(lower_species.begin(), lower_species.end(), lower_species.begin(), ::tolower);

  for (const auto& suffix : egg_check_species) {
    //simple check if species name contains keyword
    if (lower_species.find(suffix) != std::string::npos) {
      check_eggs = true;
      break;
    }
  }

  //carrying eggs? must release.
  if (check_eggs && hasEggs) {
    std::cout << " -> Creature (" << species << ") is carrying eggs and must be released." << std::endl;
    return false;
  }

  //--- NSW DPI Rules (Inverts) ---

  //Blue Swimmer Crab / Blue Crab
  if (iequals(species, "Blue Swimmer Crab") || iequals(species, "Blue Crab")) {
    return size >= 6.5; //true if >= 6.5cm (eggs checked above)
  }
  //Mud Crab
  else if (iequals(species, "Mud Crab")) {
    return size >= 8.5; //true if >= 8.5cm
  }
  //Spanner Crab
  else if (iequals(species, "Spanner Crab")) {
    return size >= 9.3; //true if >= 9.3cm
  }
  //Eastern Rock Lobster (assume "Rock Lobster" means this one)
  else if (iequals(species, "Eastern Rock Lobster") || iequals(species, "Rock Lobster")) {
    return size >= 10.4 && size <= 18.0; //true if in slot 10.4-18cm
  }
  //Southern Rock Lobster
  else if (iequals(species, "Southern Rock Lobster")) {
    //Sth Rock Lobster - applying female min size (10.5cm) for all.
    return size >= 10.5; //true if >= 10.5cm
  }
  //Balmain Bug
  else if (iequals(species, "Balmain Bug")) {
    return size >= 10.0; //true if >= 10cm
  }
  //Squid/Cuttlefish - no size limit
  else if (iequals(species, "Squid") || iequals(species, "Calamari") || iequals(species, "Cuttlefish")) {
    return true;
  }
  //Octopus - no size limit
  else if (iequals(species, "Octopus")) {
    //NOTE: location rules (rock platforms) NOT checked here!
    return true;
  }


  //unknown species
  else {
    std::cout << " -> Species '" << species << "' not found in invertebrate rules. Defaulting to RELEASE." << std::endl;
    return false;
  }
}