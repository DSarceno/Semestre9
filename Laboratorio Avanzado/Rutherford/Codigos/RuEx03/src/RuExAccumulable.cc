#include "RuExAccumulable.hh"

RuExAccumulable::RuExAccumulable()
{}

RuExAccumulable::RuExAccumulable(const RuExAccumulable& other): G4VAccumulable()
{
    for(int i=0; i<10; i++)
        fDetectorHitCounter[i] = other.GetDetectorCount(i);
}

void RuExAccumulable::Merge(const G4VAccumulable& other)
{
    const RuExAccumulable& otherRuExAccumulable
    = static_cast<const RuExAccumulable&>(other);
   for(int i=0; i<10; i++)
        fDetectorHitCounter[i] += otherRuExAccumulable.GetDetectorCount(i); 
}

void RuExAccumulable::Reset()
{
   for(int i=0; i<10; i++)
        fDetectorHitCounter[i] = 0; 
}