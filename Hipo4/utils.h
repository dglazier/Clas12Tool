/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   utils.h
 * Author: gavalian
 *
 * Created on April 27, 2017, 10:01 AM
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include<chrono>

namespace hipo {

  class utils {
  private:

  public:
    utils();
    ~utils();
    static void tokenize(const std::string& str,
			                   std::vector<std::string>& tokens,
			                   const std::string& delimiters = " ");

    static std::string substring(const std::string &str,
                                 const char *start_delim,
                                 const char *end_delim, int order);

    static int findposition(const std::string &str,
                            const char *delim, int order);

    static void printLogo();

    static std::string getHeader();
    static std::string getFileHeader();
    static std::string getFileTrailer(const char *code);
    static std::string getSConstruct();
  };

  class benchmark {
     private:

       std::chrono::high_resolution_clock clock;
       std::chrono::time_point<std::chrono::steady_clock> first, second;

       long running_time;
       int  counter;

     public:
        benchmark(){ running_time = 0;counter = 0;}
       ~benchmark(){}

       void    resume();
       void    pause();
       long    getTime();
       int     getCounter();
  };
}

#endif /* UTILS_H */
