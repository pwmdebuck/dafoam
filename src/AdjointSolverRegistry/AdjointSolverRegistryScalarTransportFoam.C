/*---------------------------------------------------------------------------*\

    DAFoam  : Discrete Adjoint with OpenFOAM
    Version : v1.0

\*---------------------------------------------------------------------------*/

#include "AdjointSolverRegistryScalarTransportFoam.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

defineTypeNameAndDebug(AdjointSolverRegistryScalarTransportFoam, 0);
addToRunTimeSelectionTable(AdjointSolverRegistry, AdjointSolverRegistryScalarTransportFoam, dictionary);
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

AdjointSolverRegistryScalarTransportFoam::AdjointSolverRegistryScalarTransportFoam
(
    const fvMesh& mesh
)
    :
    AdjointSolverRegistry(mesh)
{
    // Register state variables
    // NOTE: do not include any turbulence state variables since they will be added 
    // in the AdjointRASModel class!
    volScalarStates.append("T");
    // append here if you have more state variables

    // for debugging
    //Info<<"volScalarStates: "<<volScalarStates<<endl;
    //Info<<"volVectorStates: "<<volVectorStates<<endl;
    //Info<<"surfaceScalarStates: "<<surfaceScalarStates<<endl;


    // Need to call this to check if the registered states are actually created in db
    //this->validate();
    
    // setup the derived state info
    this->setDerivedInfo();
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
