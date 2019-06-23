#include "sensor.h"
//#include "boost/asio.hpp"
//#include "boost/bind.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int search(char* list,int n,unsigned char x){
    int i;
    for(i=0;i<n;++i){
        if(list[i] == x)
        return i;
    }
    return -1;
}

int sensor::devOpen(){
    fd = fopen(dev_path,"r");
    if(!fd){
        perror("errno");
        return 1;
    }
    else
        cout << "Open dev successed." << endl;
    return 0;
}

float sensor::quaternion_read(){
    // boost::asio::io_service inserve;
    // boost::asio::serial_port sp(inserve,"/dev/ttyUSB0");
    // sp.set_option(boost::asio::serial_port::baud_rate(115200));
    // sp.set_option(boost::asio::serial_port::flow_control());
    // sp.set_option(boost::asio::serial_port::parity());
    // sp.set_option(boost::asio::serial_port::stop_bits());
    // sp.set_option(boost::asio::serial_port::character_size(8));
    if(fd){
        int read_len;
        char buf[256];
        int s_flag;
        while(1){
                int next=0;
                read_len = fread(buf,1,256,fd);
                cout <<"1"<<endl;
                while(read_len-next >= 11){ 
                    s_flag = search(buf+next,sizeof(buf)/sizeof(char)-next,0x55);
                    cout << "s_f:" <<s_flag <<endl;
                    if(s_flag != -1  && buf[s_flag+next+10] && buf[s_flag+next+1] == 0x59 ){                 
                        cout <<"2"<<endl;                        
                        int Q0,Q1,Q2,Q3;
                        float Q0F,Q1F,Q2F,Q3F;
                        unsigned char sum=0;
                        Q0        =((0xff&(unsigned char)buf[s_flag+3])<<8)|(0xff&(unsigned char)buf[s_flag+2]);
                        Q1        =((0xff&(unsigned char)buf[s_flag+5])<<8)|(0xff&(unsigned char)buf[s_flag+4]);
                        Q2        =((0xff&(unsigned char)buf[s_flag+7])<<8)|(0xff&(unsigned char)buf[s_flag+6]);
                        Q3        =((0xff&(unsigned char)buf[s_flag+9])<<8)|(0xff&(unsigned char)buf[s_flag+8]);

                        if(Q0&0x8000)	Q0 = Q0-0xffff;
                        if(Q1&0x8000)	Q1 = Q1-0xffff;
                        if(Q2&0x8000)	Q2 = Q2-0xffff;
                        if(Q3&0x8000)	Q3 = Q3-0xffff;

                        Q0F = (float)Q0/32768;
                        Q1F = (float)Q1/32768;
                        Q2F = (float)Q2/32768;
                        Q3F = (float)Q3/32768;

                        quaternion = {Q0F,Q1F,Q2F,Q3F};
                        qua_max = max(Q0F,max(Q1F,max(Q2F,Q3F)));
                        for(int i=0;i<10;++i){
                             sum += (unsigned char)buf[s_flag+next+i];
                        }
                        // if(sum == buf[s_flag+next+10]){
                            return qua_max;                        
                        // }   
                    }
                    next+=(s_flag+11);
                    if(s_flag == -1)
                        break;
                }
        }
    }
    return 0;
}