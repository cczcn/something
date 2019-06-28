#ifndef __SENSOR__H__
#define __SENSOR__H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class sensor{
public:
    explicit sensor(char* devPath);
    int outToFile(char* out_);
    ~sensor(){}
    float quaternion_read();
    int devOpen();
private:
    char* dev_path;
    int outfile;
    std::string dev_;
    std::vector<float> quaternion;
    float qua_max;
    // int next;
    std::ofstream outF;
    int fd;
    char buf[256];
    std::string input;
    // int serialOpen();
};

#endif