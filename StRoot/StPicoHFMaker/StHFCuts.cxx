#include <limits>

#include "StHFCuts.h"

#include "StHFPair.h"
#include "StHFClosePair.h"
#include "StHFTriplet.h"

ClassImp(StHFCuts)

// _________________________________________________________
StHFCuts::StHFCuts() : StPicoCutsBase("HFCutsBase"), 
  mSecondaryPairDcaDaughtersMax(std::numeric_limits<float>::max()), 
  mSecondaryPairDecayLengthMin(std::numeric_limits<float>::lowest()), mSecondaryPairDecayLengthMax(std::numeric_limits<float>::max()), 
  mSecondaryPairCosThetaMin(std::numeric_limits<float>::lowest()), 
  mSecondaryPairMassMin(std::numeric_limits<float>::lowest()), mSecondaryPairMassMax(std::numeric_limits<float>::max()), 
  mSecondaryPairDcaToPvMax(std::numeric_limits<float>::max()),

  mTertiaryPairDcaDaughtersMax(std::numeric_limits<float>::max()), 
  mTertiaryPairDecayLengthMin(std::numeric_limits<float>::lowest()), mTertiaryPairDecayLengthMax(std::numeric_limits<float>::max()), 
  mTertiaryPairCosThetaMin(std::numeric_limits<float>::lowest()), 
  mTertiaryPairMassMin(std::numeric_limits<float>::lowest()), mTertiaryPairMassMax(std::numeric_limits<float>::max()), 
  mTertiaryPairDcaToPvMax(std::numeric_limits<float>::max()),

  mSecondaryTripletDcaDaughters12Max(std::numeric_limits<float>::max()), mSecondaryTripletDcaDaughters23Max(std::numeric_limits<float>::max()), 
  mSecondaryTripletDcaDaughters31Max(std::numeric_limits<float>::max()), 
  mSecondaryTripletDecayLengthMin(std::numeric_limits<float>::lowest()), mSecondaryTripletDecayLengthMax(std::numeric_limits<float>::max()), 
  mSecondaryTripletCosThetaMin(std::numeric_limits<float>::lowest()), 
  mSecondaryTripletMassMin(std::numeric_limits<float>::lowest()), mSecondaryTripletMassMax(std::numeric_limits<float>::max()),
  mSecondaryTripletDcaToPvMax(std::numeric_limits<float>::max()),
  mSecondaryTripletPtMin(std::numeric_limits<float>::lowest()) {
  // -- default constructor
}

// _________________________________________________________
StHFCuts::StHFCuts(const Char_t *name) : StPicoCutsBase(name), 
  mSecondaryPairDcaDaughtersMax(std::numeric_limits<float>::max()), 
  mSecondaryPairDecayLengthMin(std::numeric_limits<float>::lowest()), mSecondaryPairDecayLengthMax(std::numeric_limits<float>::max()), 
  mSecondaryPairCosThetaMin(std::numeric_limits<float>::lowest()), 
  mSecondaryPairMassMin(std::numeric_limits<float>::lowest()), mSecondaryPairMassMax(std::numeric_limits<float>::max()), 
  mSecondaryPairDcaToPvMax(std::numeric_limits<float>::max()),

  mTertiaryPairDcaDaughtersMax(std::numeric_limits<float>::max()), 
  mTertiaryPairDecayLengthMin(std::numeric_limits<float>::lowest()), mTertiaryPairDecayLengthMax(std::numeric_limits<float>::max()), 
  mTertiaryPairCosThetaMin(std::numeric_limits<float>::lowest()), 
  mTertiaryPairMassMin(std::numeric_limits<float>::lowest()), mTertiaryPairMassMax(std::numeric_limits<float>::max()), 
  mTertiaryPairDcaToPvMax(std::numeric_limits<float>::max()),

  mSecondaryTripletDcaDaughters12Max(std::numeric_limits<float>::max()), mSecondaryTripletDcaDaughters23Max(std::numeric_limits<float>::max()), 
  mSecondaryTripletDcaDaughters31Max(std::numeric_limits<float>::max()), 
  mSecondaryTripletDecayLengthMin(std::numeric_limits<float>::lowest()), mSecondaryTripletDecayLengthMax(std::numeric_limits<float>::max()), 
  mSecondaryTripletCosThetaMin(std::numeric_limits<float>::lowest()), 
  mSecondaryTripletMassMin(std::numeric_limits<float>::lowest()), mSecondaryTripletMassMax(std::numeric_limits<float>::max()),
  mSecondaryTripletDcaToPvMax(std::numeric_limits<float>::max()),
  mSecondaryTripletPtMin(std::numeric_limits<float>::lowest()) {
  // -- constructor
}

// _________________________________________________________
StHFCuts::~StHFCuts() { 
  // destructor
  
}

// =======================================================================

// _________________________________________________________
bool StHFCuts::isClosePair(StHFPair const & pair) const {
  // -- check for a pair which is close in dca w/o mass constraint,
  //    using secondary vertex cuts
  return ( std::cos(pair.pointingAngle()) > mSecondaryPairCosThetaMin &&
	   pair.decayLength() > mSecondaryPairDecayLengthMin && pair.decayLength() < mSecondaryPairDecayLengthMax &&
	   pair.dcaDaughters() < mSecondaryPairDcaDaughtersMax);
}

// _________________________________________________________
bool StHFCuts::isClosePair(StHFClosePair const & pair) const {
  // -- check for a pair which is close in dca w/o mass constraint works with the faster StHFClosePair
  return (pair.dcaDaughters() < mSecondaryPairDcaDaughtersMax);
}

// _________________________________________________________
bool StHFCuts::isGoodSecondaryVertexPair(StHFPair const & pair) const {
  // -- check for good secondary vertex pair

  return ( pair.m() > mSecondaryPairMassMin && pair.m() < mSecondaryPairMassMax &&
	   std::cos(pair.pointingAngle()) > mSecondaryPairCosThetaMin &&
	   pair.decayLength() > mSecondaryPairDecayLengthMin && pair.decayLength() < mSecondaryPairDecayLengthMax &&
	   pair.dcaDaughters() < mSecondaryPairDcaDaughtersMax &&
	   pair.DcaToPrimaryVertex() < mSecondaryPairDcaToPvMax);
}

// _________________________________________________________
bool StHFCuts::isGoodTertiaryVertexPair(StHFPair const & pair) const {
  // -- check for good tertiary vertex pair

  return ( pair.m() > mTertiaryPairMassMin && pair.m() < mTertiaryPairMassMax &&
	   std::cos(pair.pointingAngle()) > mTertiaryPairCosThetaMin &&
	   pair.decayLength() > mTertiaryPairDecayLengthMin && pair.decayLength() < mTertiaryPairDecayLengthMax &&
	   pair.dcaDaughters() < mTertiaryPairDcaDaughtersMax &&
	   pair.DcaToPrimaryVertex() < mTertiaryPairDcaToPvMax);
}

// _________________________________________________________
bool StHFCuts::isGoodSecondaryVertexTriplet(StHFTriplet const & triplet) const {
  // -- check for good secondary vertex triplet

  bool isGood =  ( triplet.m() > mSecondaryTripletMassMin && triplet.m() < mSecondaryTripletMassMax &&
	   std::cos(triplet.pointingAngle()) > mSecondaryTripletCosThetaMin &&
	   triplet.decayLength() > mSecondaryTripletDecayLengthMin && triplet.decayLength() < mSecondaryTripletDecayLengthMax &&
	   triplet.dcaDaughters12() < mSecondaryTripletDcaDaughters12Max &&
	   triplet.dcaDaughters23() < mSecondaryTripletDcaDaughters23Max &&
	   triplet.dcaDaughters31() < mSecondaryTripletDcaDaughters31Max &&
	   fabs(std::sin(triplet.pointingAngle())*triplet.decayLength()) < mSecondaryTripletDcaToPvMax) &&
	   triplet.pt() > mSecondaryTripletPtMin;

  // if(isGood)
  // {
    // float dcaDaughters = triplet.dcaDaughters12() > triplet.dcaDaughters23() ? triplet.dcaDaughters12() : triplet.dcaDaughters23();
    // dcaDaughters = dcaDaughters > triplet.dcaDaughters31() ? dcaDaughters : triplet.dcaDaughters31();
    // cout << triplet.m() << endl;
    // cout << std::cos(triplet.pointingAngle()) << endl;
    // cout << triplet.particle3Dca() << endl;
    // cout << triplet.particle1Dca() << endl;
    // cout << triplet.particle2Dca() << endl;
    // cout << triplet.decayLength()             << endl;
    // cout << dcaDaughters << endl;
    // cout << fabs(std::sin(triplet.pointingAngle())*triplet.decayLength()) << endl;
    // cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
  // }
  return isGood;
}
