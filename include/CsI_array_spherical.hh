#ifndef CsI_array_spherical_H
#define CsI_array_spherical_H 1

#include "G4Material.hh"
#include "Materials.hh"
#include "G4ThreeVector.hh"
#include "CsI_detector_spherical.hh"
#include "globals.hh"
#include "TrackerCsISD.hh"
#include "TrackerIonSD.hh"
#include "Common.hh"
#include <iostream>
#include <vector>
using namespace std;


class CsI_array_spherical
{
public:
  
  G4LogicalVolume *expHall_log;
  
  CsI_array_spherical(G4LogicalVolume*,Materials*);
  ~CsI_array_spherical();
  
  CsI_detector_spherical* GetCsIDetector(){return aCsI_detector_spherical=new CsI_detector_spherical(expHall_log,materials);};
  
  void Construct();
  void Report();
  void MakeSensitive(TrackerCsISD*);
  void SetZPos(G4double z){zpos=z;Construct();};
  G4double GetZPos(){return zpos;};
  G4double GetXPos(G4int id){return pos[id-1].getX();}; //detector position = id-1
  G4double GetYPos(G4int id){return pos[id-1].getY();};
  G4int getRingID(G4int i){return ring[i];};

private:
  vector<CsI_detector_spherical*> aCsI_array;
  CsI_detector_spherical* aCsI_detector_spherical;
  //materials
  Materials* materials;
  G4int id[NCsISph];
  G4int ring[NCsISph];
  //detector rotational position and size attributes depending on position
  G4ThreeVector pos[NCsISph];
  G4ThreeVector dim[NCsISph];
  G4double zpos;
 

};

#endif

