#define __SENSOR_TEST__
#ifdef __SENSOR_TEST__

#include "sensor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/time.h>

using namespace std;

#define IMU2 "/dev/IMU2"
#define IMU1 "/dev/IMU1"

int main(const int agrc, char** argv){
    // ifstream in(IMU1,ios::in);
    // while(!in.eof()){
    //     unsigned char c;
    //     in >> c;
    //     printf("    %x",c);
    // }
    // sensor imu1(in1);
    // sensor imu2(in2);
    // static float f1_ori = imu1.quaternion_read();
    // static float f2_ori = imu2.quaternion_read();
    // struct timeval tv,tv_ori;
    // gettimeofday(&tv_ori,NULL);
    // unsigned long long time0 =  (unsigned long long)tv_ori.tv_sec*1000+(unsigned long long)tv_ori.tv_usec/1000;
    sensor imu_1(IMU1);
    sensor imu_2(IMU2);
    imu_1.devOpen();
    imu_2.devOpen();    
    while(1)
    {
        float q1 = imu_1.quaternion_read();
        float q2 = imu_2.quaternion_read();
        cout  <<"1: "<<q1 <<"2: "<<endl;
    }
    
}

#endif