//***********************************************************************
//***********************************************************************
//  HIPO 4.0
//=======================================================================
// Autogenerated code by HIPO 4.0 io library
// Modify the main loop to suite your needs
// Date: 07/17/2018
// Author: G.Gavalian
//***********************************************************************
#include <cstdlib>
#include <iostream>
#include "reader.h"



int main(int argc, char** argv) {

   std::cout << " reading file example program (HIPO) "  << __cplusplus << std::endl;

   char inputFile[256];

   if(argc>1) {
      sprintf(inputFile,"%s",argv[1]);
      //sprintf(outputFile,"%s",argv[2]);
   } else {
      std::cout << " *** please provide a file name..." << std::endl;
     exit(0);
   }

   hipo::reader  reader;
   reader.open(inputFile);

   hipo::dictionary  factory;

   reader.readDictionary(factory);

   factory.show();
   hipo::structure  particles;
   hipo::structure  detectors;

   hipo::event      event;
   int counter = 0;

   hipo::bank  dataPART;
   hipo::bank  dataCALO;

   hipo::bank PART(factory.getSchema("REC::Particle"));


   while(reader.next()==true){
      reader.read(event);
      //reader.next();
      //event.getStructure(dataBank,30,1);
      //dataBank.show();
      event.getStructure(PART);
      PART.show();
      int nrows = PART.getRows();

      for(int i = 0; i < nrows; i++){
        int   pid = PART.getInt("pid",i);
        float  px = PART.getFloat("px",i);
        float  py = PART.getFloat("py",i);
        float  pz = PART.getFloat("pz",i);

        printf("%6d %8.4f %8.4f %8.4f\n",pid,px,py,pz);
      }
      //event.getStructure(dataCALO,300,32);
      //dataPART.show();
      counter++;
   }
   printf("processed events = %d\n",counter);
/*
   int counter = 0;
   while(reader.next()==true){

     std::pair<int,int> index = reader.getEvent()->getStructurePosition(20100,11);
     printf("reading event # %d  DC::tdc position = %d length %d\n",counter,index.first, index.second);

     reader.getEvent()->getStructure(str,20100,11);
     str.show();
     counter++;
   }
   printf(" events read = %d\n",counter);*/
}
//### END OF GENERATED CODE
