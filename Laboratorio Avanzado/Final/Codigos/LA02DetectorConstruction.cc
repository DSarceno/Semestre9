/*
 * LA02DetectorConstruction.cc: Implementación para la clase
 * LA02DetectorConstrucion.
 *
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 *
 * Héctor Pérez
 * abril 2021
 *
 * Basado en el ejemplo B1 de Geant4.10.06.p03
 *
 * Editado: proyecto final Diego Sarceño 201900109, may23-2023.
 */



#include "LA02DetectorConstruction.hh"

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
//esto es para poder usar los cilindros

#include "G4Tubs.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA02DetectorConstruction::LA02DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LA02DetectorConstruction::~LA02DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* LA02DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();

  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //
  // World
  //

  //hice mas pequeno el mundo
  G4double world_sizeX = 50*cm;
  G4double world_sizeY = 50*cm;
  G4double world_sizeZ = 50*cm;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

  G4Box* solidWorld =
    new G4Box("World",                       //its name
       world_sizeX, world_sizeY, world_sizeZ);     //its size

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


  // la fuente

   G4ThreeVector sloc = G4ThreeVector(0, 0, 0);
        //Vamos a suponer que es del mismo material
  G4Material* smat = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");

  G4Tubs* solids =
    new G4Tubs("Source",                       //its name


       0, 15*mm, 0.5*mm, 0, 2*M_PI);


  G4LogicalVolume* logics =
    new G4LogicalVolume(solids,         //its solid
                        smat,          //its material
                        "Source");           //its name

  new G4PVPlacement(0,                       //no rotation
                    sloc,                    //at position
                    logics,             //its logical volume
                    "Source",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking



  //
  // El cilindro
  //
 G4ThreeVector loc = G4ThreeVector(0, 0, 120*mm);
        //el codigo de este material lo vimos en clase
  G4Material* target_mat = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");

  G4Tubs* solidTarget =
    new G4Tubs("Det",                       //its name

    //sacamos el radio interno, externo y el largo como nos dice el instructivo
    //es importante tomar en cuenta que este cilindro esta *desplazado* y el largo se dupolica
       4.5*mm, 12.5*mm, 33.5*mm, 0, 2*M_PI);


  G4LogicalVolume* logicTarget =
    new G4LogicalVolume(solidTarget,         //its solid
                        target_mat,          //its material
                        "Det");           //its name

  new G4PVPlacement(0,                       //no rotation
                    loc,                    //at position
                    logicTarget,             //its logical volume
                    "Det",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking



  // Set Target as scoring volume
  //
  fScoringVolume = logicTarget;


// la tapadera, queda 157.5 porque le restamos la mitad del cilindro al total

G4ThreeVector finaloc = G4ThreeVector(0, 0, 157.5*mm);

  G4Material* endmat = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");
  G4Tubs* solidemat =
    new G4Tubs("Tapa",                       //its name
       0*mm, 12.5*mm, 4*mm, 0, 2*M_PI);

  G4LogicalVolume* logicend =
    new G4LogicalVolume(solidemat,         //its solid
                        endmat,          //its material
                        "Tapa");           //its name

  new G4PVPlacement(0,                       //no rotation
                    finaloc,                    //at position
                    logicend,             //its logical volume
                    "Tapa",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking











  //la ventana

G4ThreeVector wloc = G4ThreeVector(0, 0, 82.5*mm);

  G4Material* wmat = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");
  G4Tubs* solidwmat =
    new G4Tubs("Window",                       //its name
       0*mm, 4.5*mm, .05*mm, 0, 2*M_PI);

  G4LogicalVolume* logicw =
    new G4LogicalVolume(solidwmat,         //its solid
                        wmat,          //its material
                        "Window");           //its name

  new G4PVPlacement(0,                       //no rotation
                    wloc,                    //at position
                    logicw,             //its logical volume
                    "Window",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking




// el gas

G4ThreeVector gloc = G4ThreeVector(0, 0, 120*mm);

  G4Material* gtm = nist->FindOrBuildMaterial("G4_Cl");
  G4Tubs* sgt =
    new G4Tubs("Gas",                       //its name
    // dentro del cilindro
       0*mm, 4.5*mm, 33.5*mm, 0, 2*M_PI);

  G4LogicalVolume* logicg =
    new G4LogicalVolume(sgt,         //its solid
                        gtm,          //its material
                        "Gas");           //its name

  new G4PVPlacement(0,                       //no rotation
                    gloc,                    //at position
                    logicg,             //its logical volume
                    "Gas",                //its name
                    logicWorld,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking



  // Set Target as scoring volume
  //
  fScoringVolume = logicg;

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
