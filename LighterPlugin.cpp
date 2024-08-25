#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "LighterPlugin.h"

void LighterPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void LighterPlugin::run() {}

void LighterPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "lighter";
myCommand += " ";
myCommand += "-r";
myCommand += " ";
myCommand += parameters["fastqfile"];
myCommand += " ";
myCommand += "-K";
myCommand += " ";
myCommand += parameters["kmersize"];
myCommand += " ";
myCommand += parameters["genomesize"];
myCommand += " ";
myCommand += "-od";
myCommand += " ";
myCommand += outputfile + " ";
 system(myCommand.c_str());
}

PluginProxy<LighterPlugin> LighterPluginProxy = PluginProxy<LighterPlugin>("Lighter", PluginManager::getInstance());
