/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "forwardtagger.h"


namespace clas12 {

 
  void   forwardtagger::init(const char *bankName, hipo::reader &r,std::string items){
    std::cout<<" forwardtagger::init "<<bankName<<std::endl;

    particle_detector::init(bankName,r,items);
    
    if(useItem("energy"))_energy_order  = getEntryOrder("energy");
    if(useItem("path"))_path_order    = getEntryOrder("path");
    if(useItem("time"))_time_order    = getEntryOrder("time");
    if(useItem("status"))_status_order    = getEntryOrder("status");
    if(useItem("time"))_time_order    = getEntryOrder("time");
    if(useItem("x"))_x_order  = getEntryOrder("x");
    if(useItem("y"))_y_order  = getEntryOrder("y");
    if(useItem("z"))_z_order  = getEntryOrder("z");
    if(useItem("dx"))_dx_order  = getEntryOrder("dx");
    if(useItem("dy"))_dy_order  = getEntryOrder("dy");
    if(useItem("radius"))_radius_order  = getEntryOrder("radius");
    if(useItem("size"))_size_order  = getEntryOrder("size");
    if(useItem("chi2"))_chi2_order  = getEntryOrder("chi2");
   
  }


}
