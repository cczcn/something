#define __SENSOR_TEST__
#ifdef __SENSOR_TEST__

#include "sensor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/time.h>

using namespace std;

#define IMU1 "/dev/IMU1"
#define IMU2 "/dev/IMU2"
#define IMU3 "/dev/IMU3"
#define IMU4 "/dev/IMU4"
#define IMU5 "/dev/IMU5"
#define IMU6 "/dev/IMU6"
#define IMU7 "/dev/IMU7"
#define IMU8 "/dev/IMU8"


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
    sensor imu_3(IMU3);
    sensor imu_4(IMU4);
    sensor imu_5(IMU5);
    sensor imu_6(IMU6);
    sensor imu_7(IMU7);
    sensor imu_8(IMU8);
    imu_1.devOpen();
    imu_2.devOpen();
    imu_3.devOpen();    
    imu_4.devOpen();
    imu_5.devOpen();
    imu_6.devOpen();
    imu_7.devOpen();    
    imu_8.devOpen();
    imu_1.outToFile("data1.txt");  
    imu_2.outToFile("data2.txt");    
    imu_3.outToFile("data3.txt");    
    imu_4.outToFile("data4.txt"); 
    imu_5.outToFile("data5.txt");  
    imu_6.outToFile("data6.txt");    
    imu_7.outToFile("data7.txt");    
    imu_8.outToFile("data8.txt");    

    while(1)
    {
        float q1 = imu_1.quaternion_read();
        float q2 = imu_2.quaternion_read();
        float q3 = imu_3.quaternion_read();
        float q4 = imu_4.quaternion_read();
        float q5 = imu_5.quaternion_read();
        float q6 = imu_6.quaternion_read();
        float q7 = imu_7.quaternion_read();
        float q8 = imu_8.quaternion_read();

    }
    
}

#endif