#ifndef __GTreePluto_h__
#define __GTreePluto_h__


#include "GTree.h"
#include "PParticle.h"
#include "TClonesArray.h"

#include <list>
#include <algorithm>
#include <exception>

class PParticle;

class  GTreePluto : public GTree
{
private:
    TClonesArray*   PlutoMCTrue;
    Long64_t        plutoID;
    Long64_t        plutoRandomID;

    class no_tree_exception : public std::exception
    {
        virtual const char* what() const throw()
        {
            return "No Pluto Tree in current file!";
        }
    } noTree;

protected:
    virtual void    SetBranchAdresses();
    virtual void    SetBranches();

public:
    GTreePluto(GTreeManager *Manager);
    virtual ~GTreePluto();


    virtual void                Clear()                 { PlutoMCTrue->Clear(); plutoID=-1; plutoRandomID=1; }
    virtual TClonesArray* 		GetMCTrue()        		{ return PlutoMCTrue; }
    virtual PParticle*          GetMCTrue(const int idx) const throw(std::exception);
    virtual TLorentzVector      GetTrueP4(const int idx) const throw(std::exception);
    virtual TLorentzVector      GetTrueBeam() const;
    virtual TLorentzVector      GetTrueBeam(const TLorentzVector, const int beamID) const;
    virtual Long64_t            GetPlutoID()       const     { return plutoID; }
    virtual Long64_t            GetPlutoRandomID() const     { return plutoRandomID; }

    typedef std::list<const PParticle*> ParticleList;

    virtual ParticleList        GetFinalState() const;
    virtual ParticleList        GetAllParticles() const;

};

#endif
