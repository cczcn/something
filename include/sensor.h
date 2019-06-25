#ifndef __SENSOR__H__
#define __SENSOR__H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class sensor{
public:
    explicit sensor(char* devPath):dev_path(devPath),quaternion(4,0){
        dev_=std::string(dev_path);
    }
    ~sensor(){}
    float quaternion_read();
    int devOpen();
private:
    char* dev_path;
    std::string dev_;
    std::vector<float> quaternion;
    float qua_max;
    // int next;
    int fd;
    char buf[256];
    std::string input;
    // int serialOpen();
};

#endif