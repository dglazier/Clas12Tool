/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   bank.h
 * Author: gavalian
 *
 * Created on April 12, 2017, 10:14 AM
 */

#ifndef HIPO_BANK_H
#define HIPO_BANK_H
#include <iostream>
#include <vector>
#include <cstring>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "dictionary.h"

namespace hipo {
  
  class structure {

    private:

      std::vector<char> structureBuffer;
      char *structureAddress;
      void setAddress(const char *address);

    protected:
      void initStructureBySize(int __group, int __item, int __type, int __size);
    public:

      structure(){ structureAddress = NULL;}
      structure(int size){ allocate(size);}

      virtual     ~structure(){}
      bool         allocate(int size);
      int          getSize();
      int          getType();
      int          getGroup();
      int          getItem();
      void         init(const char *buffer, int size);
      const char  *getAddress();
      void         show();

      int          getIntAt   ( int index) {
        return *reinterpret_cast<int32_t*>(&structureAddress[index+8]);
      }
      int16_t      getShortAt ( int index){
        return *reinterpret_cast<int16_t*>(&structureAddress[index+8]);
      }
      int8_t       getByteAt  ( int index){
        return *reinterpret_cast<int8_t*>(&structureAddress[index+8]);
      }
      float        getFloatAt ( int index){
        return *reinterpret_cast<float*>(&structureAddress[index+8]);
      }
      double       getDoubleAt( int index){
        return *reinterpret_cast<double*>(&structureAddress[index+8]);
      }
      long         getLongAt  ( int index){
        return *reinterpret_cast<int64_t*>(&structureAddress[index+8]);
      }

      std::string  getStringAt(int index);

      friend class event;
  };

  //typedef std::auto_ptr<hipo::generic_node> node_pointer;

    class bank : public hipo::structure {

    private:

      hipo::schema  bankSchema;
      int           bankRows;

    protected:

    public:

        bank();
        // constructor initializes the nodes in the bank
        // and they will be filled automatically by reader.next()
        // method.
        bank(hipo::schema __schema){
          bankSchema = __schema;
          bankRows   = -1;
        }

        bank(hipo::schema __schema, int __rows){
          bankSchema = __schema;
          bankRows   = __rows;
          int size   = bankSchema.getSizeForRows(__rows);
          initStructureBySize(bankSchema.getGroup(),bankSchema.getItem(), 11, size);
        }

        ~bank();
        // display the content of the bank
        //void show();

        hipo::schema  &getSchema() { return bankSchema;}


        //virtual  void notify(){ };
  };

}


#endif /* EVENT_H */