/**
 *           بسم الله الرحمان الرحيم
 *
 * Author:    Zeroual Aymene
 *
 * Created:   12.01.2020
 * 
 **/

#include "Console.h"
#include <string>

int main(int argc, char* argv[])
{   
     
    int sleeptime,mode;

    do {

        printf_s("Select mode (0: repeat , 1: sequence) : ");

        scanf_s("%d", &mode);

    } while ( mode < 0 || mode > 1 );

    switch (mode) {

        case 1:

            system("netstat");

            break;

        case 0:

            do {

                printf_s("Enter Update rate (Seconds) : ");

                scanf_s("%d", &sleeptime);

            } while ( sleeptime <= 0);


            Console* console = new Console(sleeptime * 1000);

            delete console;

            break;
    }


     return 0;

}
