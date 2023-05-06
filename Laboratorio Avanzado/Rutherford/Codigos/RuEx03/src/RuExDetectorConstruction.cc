//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id$
//
/// \file RuExDetectorConstruction.cc
/// \brief Implementation of the RuExDetectorConstruction class

#include "RuExDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RuExDetectorConstruction::RuExDetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ 
  for(int i = 0; i<10 ; i++)
    fScoringVolumes[i] = 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RuExDetectorConstruction::~RuExDetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* RuExDetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
   
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //     
  // World
  //
  G4double world_size = 2.0*m;

  // Vacuum material
  G4double atomicNumber = 1.;
  G4double massOfMole = 1.008*g/mole;
  G4double density = 1.e-25*g/cm3;
  G4double temperature = 2.73*kelvin;
  G4double pressure = 3.e-18*pascal;
  G4Material* Vacuum =
    new G4Material("interGalactic", atomicNumber,
                    massOfMole, density, kStateGas,
                    temperature, pressure);
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_size, 0.5*world_size, 0.5*world_size);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        Vacuum,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                     
  
 
  

  //     
  // target
  //
  G4Material* target_mat = nist->FindOrBuildMaterial("G4_Au");
  G4ThreeVector target_pos = G4ThreeVector(0, 0, 0);

  // target shape       
  G4double target_XY = 10.0*cm;
  G4double target_Z  = 0.001*mm;

  G4Box* solid_target =    
    new G4Box("Target",                       //its name
       0.5*target_XY, 0.5*target_XY, 0.5*target_Z);     //its size
                
  G4LogicalVolume* logic_target =                         
    new G4LogicalVolume(solid_target,         //its solid
                        target_mat,          //its material
                        "Target");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    target_pos,                    //at position
                    logic_target,             //its logical volume
                    "Target",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                
  
//
// detectores
//
G4Material* detector_mat = nist->FindOrBuildMaterial("G4_Al");


  // detector shape       
  G4double detector_XY = 2.0*cm;
  G4double detector_Z  = 10.0*cm;

  G4Box* solid_detector =    
    new G4Box("Detector",                       //its name
       0.5*detector_XY, 0.5*detector_XY, 0.5*detector_Z);     //its size
                


for( int i = 0; i<10 ; i++ )
{
  G4double detector_rotation_i = i * 15 * deg;
  G4ThreeVector detector_pos_i = G4ThreeVector(0, 0, 55*cm);
  detector_pos_i.rotateX(-detector_rotation_i);
  G4RotationMatrix *rot_i = new G4RotationMatrix();
  rot_i->rotateX(detector_rotation_i);
  
  fScoringVolumes[i] = new G4LogicalVolume(solid_detector, detector_mat, "Detector"+std::to_string(i));
  new G4PVPlacement(rot_i, detector_pos_i, fScoringVolumes[i], "Detector"+std::to_string(i), logicWorld, false, 0, checkOverlaps);
}

  // Set detector as scoring volume
  //
  fScoringVolume = fScoringVolumes[0];

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
