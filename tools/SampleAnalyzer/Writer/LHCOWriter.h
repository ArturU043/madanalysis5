////////////////////////////////////////////////////////////////////////////////
//  
//  Copyright (C) 2012 Eric Conte, Benjamin Fuks, Guillaume Serret
//  The MadAnalysis development team, email: <ma5team@iphc.cnrs.fr>
//  
//  This file is part of MadAnalysis 5.
//  Official website: <http://madanalysis.irmp.ucl.ac.be>
//  
//  MadAnalysis 5 is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  MadAnalysis 5 is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with MadAnalysis 5. If not, see <http://www.gnu.org/licenses/>
//  
////////////////////////////////////////////////////////////////////////////////


#ifndef LHCO_WRITER_BASE_h
#define LHCO_WRITER_BASE_h

// STL headers
#include <fstream>
#include <iostream>
#include <sstream>

// SampleAnalyzer headers
#include "SampleAnalyzer/Writer/WriterTextBase.h"

namespace MA5
{

class LHCOWriter : public WriterTextBase
{

  // -------------------------------------------------------------
  //                        data members
  // -------------------------------------------------------------
 protected:



  // -------------------------------------------------------------
  //                       method members
  // -------------------------------------------------------------
 public:

  /// Constructor without argument
  LHCOWriter() : WriterTextBase()
  {}

	/// Destructor
  virtual ~LHCOWriter()
  {}

  /// Read the sample (virtual)
  virtual bool WriteHeader(const SampleFormat& mySample);

  /// Read the event (virtual)
  virtual bool WriteEvent(const EventFormat& myEvent, 
                          const SampleFormat& mySample);

  /// Finalize the event (virtual)
  virtual bool WriteFoot(const SampleFormat& mySample);
 
 private:

  static std::string FortranFormat_SimplePrecision(Float_t value,UInt_t precision=7); 
  static std::string FortranFormat_DoublePrecision(Double_t value,UInt_t precision=11); 

  // Writing a reconstructed jet

  bool WriteEventHeader(const SampleFormat& mySample,unsigned int);
  void WriteJet(const RecJetFormat& jet,unsigned int);
  void WriteMuon(const RecLeptonFormat& muon,unsigned int);
  void WriteElectron(const RecLeptonFormat& electron,unsigned int);
  void WriteTau(const RecTauFormat& tau,unsigned int);
  void WriteMET(const ParticleBaseFormat& met,unsigned int);


};

}

#endif