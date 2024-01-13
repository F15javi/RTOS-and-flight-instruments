//
//  main.cpp
//  xpcExample
//
//  Created by Chris Teubert on 3/27/14.
//  Copyright (c) 2014 Chris Teubert. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include "../src/xplaneConnect.h"
#include "SimpleSerial.h"

#ifdef WIN32
#include <Windows.h>
#define sleep(n) Sleep(n * 1000)
#endif

int main()
{
    printf("XPlaneConnect Example: readDATA()\n\n");

    // Open Socket
    const char* xpIP = "127.0.0.1"; //IP Address of computer running X-Plane
    unsigned short xpPort = 49007;  //default port number XPC listens on
    unsigned short port = 49003;    //port number to which X-Plane is set to send UDP packets



    while (1) {
        XPCSocket sock = aopenUDP(xpIP, xpPort, port); //docs seem to be outdated on these...

        // Read 2 rows of data
        const int rows = 2;
        float data[rows][9]; //data[0] is dataset index number, data[1] to data[9] are the contents of the dataset
        readDATA(sock, data, rows);



        printf("\n%f,", data[0][1]);

        printf("\n lat = %f, lon = %f, alt = %f", data[1][1], data[1][2], data[1][3]);


        Sleep(500);
        closeUDP(sock);


    }
    //keep console open on Windows


    return 0;
}
