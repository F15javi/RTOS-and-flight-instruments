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

#ifdef WIN32
#include <Windows.h>
#define sleep(n) Sleep(n * 1000)
#endif

char dataRx[100];


void Serial_TX(char telemetry[100]) {
    HANDLE serial = CreateFile(L"COM4", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    if (serial != INVALID_HANDLE_VALUE) {
        DCB dcbSerialParams = { 0 };
        dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

        if (GetCommState(serial, &dcbSerialParams)) {
            dcbSerialParams.BaudRate = CBR_115200;
            dcbSerialParams.ByteSize = 8;
            dcbSerialParams.StopBits = ONESTOPBIT;
            dcbSerialParams.Parity = NOPARITY;

            if (SetCommState(serial, &dcbSerialParams)) {
                DWORD bytesWritten;



                //const char data[] = "Hello There";

                WriteFile(serial, telemetry, 100, &bytesWritten, NULL);
                printf("\n CreateFile failed with error %d.", GetLastError());


            }
        }

        CloseHandle(serial);
    }
    else {
        printf("\n CreateFile failed with error %d.", GetLastError());
    }

}


void Serial_RX(void) {

    HANDLE serial = CreateFile(L"COM6", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (serial != INVALID_HANDLE_VALUE) {
        DCB dcbSerialParams = { 0 };
        dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

        if (GetCommState(serial, &dcbSerialParams)) {
            dcbSerialParams.BaudRate = CBR_9600;
            dcbSerialParams.ByteSize = 8;
            dcbSerialParams.StopBits = ONESTOPBIT;
            dcbSerialParams.Parity = NOPARITY;

            if (SetCommState(serial, &dcbSerialParams)) {
                DWORD bytesRead;



                //const char data[] = "Hello There";

                if (ReadFile(serial, &dataRx, 100, &bytesRead, NULL)) {
                    std::cout << "Read " << bytesRead << " bytes: " << dataRx << std::endl;
                }
                else {
                    CloseHandle(serial);
                    printf("\n CreateFile failed with error %d.", GetLastError());
                }

            }
        }

        CloseHandle(serial);
    }
    
}

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
        const int rows = 3;
        float data[rows][9]; //data[0] is dataset index number, data[1] to data[9] are the contents of the dataset
        readDATA(sock, data, rows);



        printf("\nVtas: %f,", data[0][2]);

        printf("\n pitch = %f, roll = %f, heading = %f, alt = %f", data[1][1], data[1][2], data[1][3], data[2][3]);

        Sleep(15);
        closeUDP(sock);

        char telemetry[100];
        sprintf_s(telemetry, "%f %f %f %f %f", data[0][2], data[1][1], data[1][2], data[1][3], data[2][3]);
        
        Serial_TX(telemetry);
        Serial_RX();

        

    }
    

    return 0;
}
