#ifndef StPicoEventMixer_hh
#define StPicoEventMixer_hh

/* **************************************************
 * Class stores event buffer used in event mixing. Mixing
 * is done automatically once buffer reaches defined maximum.
 * User should rpesonalize mixEvent() method to cosntruct 
 * desired background.
 *
 * **************************************************
 * 
 * Initial Authors:
 *          **Michael Lomnitz (mrlomnitz@lbl.gov)
 *          Musta Mustafa   (mmustafa@lbl.gov)
 *
 *  ** Code maintainer 
 *
 * **************************************************
 */

#include <vector>

#include "StThreeVectorF.hh"

class TTree;
class TH2F;
class StPicoEvent;
class StPicoTrack;
class StPicoDst;
class StMixerTrack;
class StMixerEvent;
class StMixerPair;

class StPicoEventMixer {
 public: 
  StPicoEventMixer();
  ~StPicoEventMixer(){;};
  bool addPicoEvent(StPicoDst const* picoDst);
  void setEventBuffer(int buffer);
  void mixEvents();
  bool isGoodEvent(StPicoDst const * const picoDst);
  bool isGoodTrack(StPicoTrack const * const trk);
  bool isCloseTrack(StPicoTrack const& trk, StThreeVectorF const& pVtx);
  bool isTpcPion(StPicoTrack const * const);
  bool isTpcKaon(StPicoTrack const * const);
  bool isGoodPair(StMixerPair const& pair);

  void finish();
 private:
  void fillBgME(StMixerPair const* const);
  void fillFgLS(StMixerPair const* const);
  void fillBgLS(StMixerPair const* const);
  void fillFG(StMixerPair const* const);
  bool isMixerPion(StMixerTrack const&);
  bool isMixerKaon(StMixerTrack const&);

  TH2F* mVtx;
  TH2F* mFgVtx;
  TH2F* mForeground;
  TH2F* mFgLS;
  TH2F* mBgLS;
  TH2F* mBgME;
  //TTree * ntp_ME;
  std::vector <StMixerEvent*> mEvents; 

  unsigned short int mEventsBuffer; 
  unsigned short int filledBuffer;
  float dca1, dca2, dcaDaughters, theta_hs, decayL_hs;
  float pt_hs, mass_hs, eta_hs, phi_hs;
};

inline void StPicoEventMixer::setEventBuffer(int buffer){ mEventsBuffer = buffer;}
			    
    
#endif