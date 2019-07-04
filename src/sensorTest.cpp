#define __SENSOR_TEST__
#ifdef __SENSOR_TEST__

#include "sensor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/time.h>
#include <thread>

using namespace std;

#define NUM_SENSORS 8

#define IMU1 "/dev/IMU1"
#define IMU2 "/dev/IMU2"
#define IMU3 "/dev/IMU3"
#define IMU4 "/dev/IMU4"
#define IMU5 "/dev/IMU5"
#define IMU6 "/dev/IMU6"
#define IMU7 "/dev/IMU7"
#define IMU8 "/dev/IMU8"
#define IMU1OUT "data1.txt"
#define IMU2OUT "data2.txt"
#define IMU3OUT "data3.txt"
#define IMU4OUT "data4.txt"
#define IMU5OUT "data5.txt"
#define IMU6OUT "data6.txt"
#define IMU7OUT "data7.txt"
#define IMU8OUT "data8.txt"

void * imuRead(sensor* imu){
    while(1){
        float data = imu->quaternion_read();
        // cout << "hello" <<endl;
    }
}

int main(const int agrc, char** argv){
    vector<char*> imuPath ={IMU1,IMU2,IMU3,IMU4,IMU5,IMU6,IMU7,IMU8};
    vector<char*> imuOutPath ={IMU1OUT,IMU2OUT,IMU3OUT,IMU4OUT,IMU5OUT,IMU6OUT,IMU7OUT,IMU8OUT};
    vector<sensor> imuVec(NUM_SENSORS);
    vector<int> imuVec_opened(NUM_SENSORS,-1);
    vector<thread> tids(NUM_SENSORS);
    int sensors_can_opned_num=0;
    for(int i=0;i<NUM_SENSORS;++i){
        int ret = imuVec[i].devOpen(imuPath[i]);
        imuVec[i].outToFile(imuOutPath[i]);
        imuVec_opened[i] = ret;
    }   

    for(int i=0;i<NUM_SENSORS;++i){
        tids[i] = thread(imuRead,&imuVec[i]);
    }
    for(int i=0;i<NUM_SENSORS;++i){
        tids[i].join();
    }
         
       
    return 0;
}

#endif