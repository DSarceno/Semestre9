#ifndef RuExAccumulable_h
#define RuExAccumulable_h 1

#include "G4VAccumulable.hh"
#include "globals.hh"
#include <valarray>

class RuExAccumulable : public G4VAccumulable
{
  public:
    RuExAccumulable();
    RuExAccumulable(const RuExAccumulable& other);

    virtual ~RuExAccumulable() {}

    void AddHitToDetector(G4int detector) { fDetectorHitCounter[detector]++; }

    G4int GetDetectorCount(G4int detector) const { return fDetectorHitCounter[detector]; }

    virtual void Merge(const G4VAccumulable& other);
    virtual void Reset();

  private:
    std::valarray<G4int> fDetectorHitCounter = std::valarray<G4int>(10);
};

#endif // RuExAccumulable_h