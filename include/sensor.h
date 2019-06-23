#ifndef __SENSOR__H__
#define __SENSOR__H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class sensor{
public:
    explicit sensor(char* devPath):dev_path(devPath),quaternion(4,0){}
    ~sensor(){}
    float quaternion_read();
    int devOpen();
private:
    char* dev_path;
    std::vector<float> quaternion;
    float qua_max;
    // int next;
    FILE* fd;
    // char buf[256];
    // int serialOpen();
};

#endif