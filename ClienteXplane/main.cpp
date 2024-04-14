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



                const char data[] = "111.11111 111.11111";

                WriteFile(serial, telemetry, 100, &bytesWritten, NULL);
                printf("\n CreateFile failed with error %d.", GetLastError());


            }
        }

        CloseHandle(serial);
    }
    else {
        printf("\n writeFile failed with error %d.", GetLastError());
    }

}


void Serial_RX() {

    HANDLE serial2 = CreateFile(L"COM6", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (serial2 != INVALID_HANDLE_VALUE) {
        DCB dcbSerialParams = { 0 };
        dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
        COMMTIMEOUTS timeout;

        timeout.ReadIntervalTimeout = 0;
        timeout.ReadTotalTimeoutMultiplier = 0;
        timeout.ReadTotalTimeoutConstant = 15;
        timeout.WriteTotalTimeoutMultiplier = 0;
        timeout.WriteTotalTimeoutConstant = 0;

        if (GetCommState(serial2, &dcbSerialParams)) {
            dcbSerialParams.BaudRate = CBR_9600;
            dcbSerialParams.ByteSize = 8;
            dcbSerialParams.StopBits = ONESTOPBIT;
            dcbSerialParams.Parity = NOPARITY;

            if (SetCommState(serial2, &dcbSerialParams)) {
                DWORD bytesRead;

                char dataRx[100];


                //const char data[] = "Hello There";

                ReadFile(serial2, dataRx, 100, &bytesRead, NULL);


                printf("\n ReadFile failed with error %d.", GetLastError());


            }
        }

        CloseHandle(serial2);
    }

}
void aircraft_control(const char* xpIP, unsigned short xpPort, unsigned short port) {



    XPCSocket sock = aopenUDP(xpIP, xpPort, port); //docs seem to be outdated on these...
    int ac = 0;
    int size = 6;
    float values[] = {
        1.0F, // Latitudinal Stick [-1,1]
        1.0F, // Longitudinal Stick [-1,1]
        -1.0F, // Rudder Pedals [-1, 1]
        0.0F, // Throttle [0, 1]
        0.0F, // Gear (0=up, 1=down)
        0.0F  // Flaps [0, 1]


    };
    //sendDATA(sock,)











    closeUDP(sock);


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
        const int rows = 9;
        float data[rows][9]; //data[0] is dataset index number, data[1] to data[9] are the contents of the dataset
        readDATA(sock, data, rows);



        printf("\nVtas: %f,", data[0][2]);

        printf("\n pitch = %f, roll = %f, heading = %f, alt = %f", data[1][1], data[1][2], data[1][3], data[2][3]);

        
        closeUDP(sock);

        int speed = (int)data[0][2];
        int altitude = (int)data[2][3];
        int rpm = (int)data[3][1];
        int temp = (int)data[5][1];
        int OilP = (int)data[6][1];
        int OilT = (int)data[7][1];
        char telemetry[100];
        sprintf_s(telemetry, "%d %f %f %f %d %d %f %d %d %d %f %f", 
            speed,
            data[1][1], data[1][2], data[1][3],
            altitude,
            rpm,
            data[4][1], 
            temp,
            OilP,
            OilT,
            data[8][1], data[8][2]);

        Serial_TX(telemetry);
        Sleep(15);
        //Serial_RX();
        //aircraft_control(xpIP, xpPort, port);


    }


    return 0;
}
