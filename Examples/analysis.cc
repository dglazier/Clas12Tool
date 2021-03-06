//***********************************************************************
//***********************************************************************
//    ____  ____  _____  _______     ___      ______       __
//   |_   ||   _||_   _||_   __ \  .'   `.   / ____ `.    /  |
//     | |__| |    | |    | |__) |/  .-.  \  `'  __) |    `| |
//     |  __  |    | |    |  ___/ | |   | |  _  |__ '.     | |
//    _| |  | |_  _| |_  _| |_    \  `-'  / | \____) | _  _| |_
//   |____||____||_____||_____|    `.___.'   \______.'(_)|_____|
//
//=======================================================================
// Autogenerated code by HIPO 3.1 io library
// Modify the main loop to suite your needs
// Date: 07/17/2018
// Author: G.Gavalian
//***********************************************************************
#include <cstdlib>
#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "reader.h"
#include "node.h"
#include "bank.h"
#include "particle.h"
#include "detector.h"


int main(int argc, char** argv) {

   std::cout << " reading file example program (HIPO) "  << __cplusplus << std::endl;

   char inputFile[256];
   char outputFile[256];

   if(argc>1) {
      sprintf(inputFile,"%s",argv[1]);
   } else {
      std::cout << " *** please provide a file name..." << std::endl;
     exit(0);
   }

   hipo::reader  reader;
   reader.open(inputFile);

   clas12::particle  particles("REC::Particle",reader);

   clas12::vector4 beam(   0.0, 0.0, 10.5, 10.5   );
   clas12::vector4 target( 0.0, 0.0,  0.0,  0.938 );
   clas12::vector4 electron;
   clas12::vector4 w2;
   clas12::vector4 q2;

   hipo::benchmark b;
   
   while(reader.next()==true){
     b.resume();

     int size = particles.getSize();

     for(int i = 0; i < size; i++){
       int pid = particles.getPid(i);
       if(pid==11){
         particles.getVector4(i,electron,0.0005);
         w2 = beam + target - electron;
         q2 = beam - electron;
         //printf("w2 = %12.5f, q2 = %12.5f\n",w2.m(),-q2.m());
       }
     }
     b.pause();
   }
   reader.showBenchmark();
   printf(" time spend on analysis = %8.5f (ms) events = %8d\n",
   b.getTime()*1e-9,
      b.getCounter());
}
//### END OF GENERATED CODE
