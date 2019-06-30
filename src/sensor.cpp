#include "sensor.h"
//#include "boost/asio.hpp"
//#include "boost/bind.hpp"
#include <stdio.h>
#include <iostream>
// #include <fstream>
#include <string>
#include <string.h>
#include <vector>

#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>


#include <unistd.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>
#include <sys/time.h>

using namespace std;

int search(char* list,int n,unsigned char x){
    int i;
    for(i=0;i<n;++i){
        if(list[i] == x)
        return i;
    }
    return -1;
}

sensor::sensor():outfile(0),quaternion(4,0),sum_num(0),error_num(0){
    }

int sensor::outToFile(char* out_){
    outF.open(out_,ios::app);
    if(!outF.is_open()){
        perror("errout");
        cout << "Output File Open Fail."<< endl;
        return 1;
    }
    else{
        cout << "Output to file >>"<<endl;
        outfile = 1;
    }
    return 0;
}

int sensor::devOpen(char* devPath){
    fd = open(devPath,O_RDONLY );
    if(fd==-1){
        perror("errno");
        return -1;
    }
    else
        cout << "Open dev successed." << endl;
    return 1;
}

float sensor::quaternion_read(){
    // boost::asio::io_service inserve;
    // boost::asio::serial_port sp(inserve,"/dev/ttyUSB0");
    // sp.set_option(boost::asio::serial_port::baud_rate(115200));
    // sp.set_option(boost::asio::serial_port::flow_control());
    // sp.set_option(boost::asio::serial_port::parity());
    // sp.set_option(boost::asio::serial_port::stop_bits());
    // sp.set_option(boost::asio::serial_port::character_size(8));
    struct timeval tv,tv_ori;
    gettimeofday(&tv_ori,NULL);
    unsigned long long now_time =  (unsigned long long)tv_ori.tv_sec*1000+(unsigned long long)tv_ori.tv_usec/1000;
    std::string read;
    int start_flag;
    if(fd){
        // int read_len=read(buf,1,110,fd);
        //cout<<"fd:"<<fd<<endl;
        int read_len=::read(fd,buf,110);
        // std::cout<<"read len"<<read_len<<std::endl;//64
        buf[read_len-1]='\0';
        input+=std::string(buf);
        while(input.length()>=11){
            start_flag=input.find(0x55);
            if(start_flag!=std::string::npos && start_flag+11!=std::string::npos){
                if(input[start_flag+1]==0x59){ 
                        ++sum_num;                    
                        int Q0,Q1,Q2,Q3;
                        float Q0F,Q1F,Q2F,Q3F;
                        unsigned char sum=0x00;
                        Q0  =((0xff&(unsigned char)input[start_flag+3])<<8)|(0xff&(unsigned char)input[start_flag+2]);
                        Q1  =((0xff&(unsigned char)input[start_flag+5])<<8)|(0xff&(unsigned char)input[start_flag+4]);
                        Q2  =((0xff&(unsigned char)input[start_flag+7])<<8)|(0xff&(unsigned char)input[start_flag+6]);
                        Q3  =((0xff&(unsigned char)input[start_flag+9])<<8)|(0xff&(unsigned char)input[start_flag+8]);

                        for(int i=0;i<10;++i)
                            sum += (unsigned char)buf[start_flag+i];
                        
                        if(sum != (unsigned char)buf[start_flag+10]){
                            ++error_num;  
                        }else{
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
                            if(outfile)
                                outF<<quaternion[0]<<"\t"<<quaternion[1]<<"\t"<<quaternion[2]<<"\t"<<quaternion[3]<<"\t"<< now_time<<endl;
                            else
                                std::cout<<"\t"<<quaternion[0]<<"\t"<<quaternion[1]<<"\t"<<quaternion[2]<<"\t"<<quaternion[3]<<"\t"<< now_time <<endl;   
                        }
                        cout << 100*error_num/sum_num <<"%"<<endl;
                        input.erase(0,start_flag+11);        
                }else{
                    if(input.length()>=start_flag+11)
                        input.erase(0,start_flag+1);
                    else
                        input.erase(0,start_flag);
                }
            }else 
                input.clear();
        }
    }
    else{
        std::cout<<"error fd"<<std::endl;
    }


    return 0;

}