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

#include "G4Tubs.hh"


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
  /*
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
                     
  */
  /*
  

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
*/

  G4double world_sizeX = 50*cm;
  G4double world_sizeY = 50*cm;
  G4double world_sizeZ = 50*cm;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
       0.5*world_sizeX, 0.5*world_sizeY, 0.5*world_sizeZ);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
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
                     
 
G4ThreeVector cil = G4ThreeVector(0, 0,125*mm);
G4Material* cilindro_mat = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");

G4Tubs* solidCilindro =    
    new G4Tubs("cilindro",       //its name
      4.5*mm, //radio interior
      12.5*mm, //radio radio exterior ,
      75*mm, // altura
      0,
      2*M_PI);


G4LogicalVolume* logicCilindro =                         
  new G4LogicalVolume(solidCilindro,         //its solid
                        cilindro_mat,          //its 
                        "cilindro");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    cil,                    //at position
                    logicCilindro,             //its logical volume
                    "cilindro",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


//Constuccion de cilindro interior

G4ThreeVector icil = G4ThreeVector(0, 0,0*mm);
G4Material* icilindro_mat = nist->FindOrBuildMaterial("G4_Cl");

G4Tubs* solidiCilindro =    
    new G4Tubs("icilindro",                       //its name
      0*mm, //radio interior
      4.5*mm, //radio radio exterior ,
      75*mm, // altura
      0,
      2*M_PI);


G4LogicalVolume* logiciCilindro =                         
  new G4LogicalVolume(solidiCilindro,         //its solid
                        icilindro_mat,          //its 
                        "icilindro");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    icil,                    //at position
                    logiciCilindro,             //its logical volume
                    "icilindro",                //its name
                    logicCilindro,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


// Tapa del detetor tracera

G4ThreeVector tcil = G4ThreeVector(0, 0,67*mm);
G4Material* tcilindro_mat = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");

G4Tubs* solidtCilindro =    
    new G4Tubs("tcilindro",                       //its name
      0*mm, //radio interior
      4.5*mm, //radio radio exterior ,
      8*mm, // altura
      0,
      2*M_PI);


G4LogicalVolume* logictCilindro =                         
  new G4LogicalVolume(solidtCilindro,         //its solid
                        tcilindro_mat,          //its 
                        "tcilindro");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    tcil,                    //at position
                    logictCilindro,             //its logical volume
                    "tcilindro",                //its name
                    logicCilindro,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking



// Tapa del detetor delantera

G4ThreeVector dcil = G4ThreeVector(0, 0,-74.9*mm);
G4Material* dcilindro_mat = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");

G4Tubs* soliddCilindro =    
    new G4Tubs("dcilindro",                       //its name
      0*mm, //radio interior
      4.5*mm, //radio radio exterior ,
      0.1*mm, // altura
      0,
      2*M_PI);


G4LogicalVolume* logicdCilindro =                         
  new G4LogicalVolume(soliddCilindro,         //its solid
                        dcilindro_mat,          //its 
                        "dcilindro");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    dcil,                    //at position
                    logicdCilindro,             //its logical volume
                    "dcilindro",                //its name
                    logicCilindro,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


  // Set detector as scoring volume
  //
  fScoringVolume = logicCilindro;

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
