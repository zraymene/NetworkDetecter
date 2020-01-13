#include "UDPHandler.h"

void UDPHandler::Update()
{

    this->bufferSize = sizeof(MIB_UDPTABLE);

    if ((table = ALLOC<MIB_UDPTABLE>(bufferSize)) == nullptr) {

        printf_s(RED("ERROR : Can't alloc memory for MIB_TCPTABLE"));

        return;

    }

    if (GetUdpTable(table, &bufferSize, TRUE) == ERROR_INSUFFICIENT_BUFFER) {

        printf_s(YEL("WARNING : Buffer insufficient , creating new one !"));

        free(table);

        table = ALLOC<MIB_UDPTABLE>(bufferSize);

        if (table == nullptr) {

            printf_s(RED("ERROR : Can't alloc memory for MIB_TCPTABLE"));

            return;

        }

    }

    if (GetUdpTable(table, &bufferSize, TRUE) == NO_ERROR) {

        printf_s("Nomber of IPs : %d \n", (int)table->dwNumEntries - transformAmount);

        for (int i = 0; i < (int)table->dwNumEntries - transformAmount; i++)
        {

            IPAddress.S_un.S_addr = (u_long)table->table[i + transformAmount].dwLocalAddr;

            strcpy_s(Addr, sizeof(Addr), inet_ntoa(IPAddress));

            printf_s(UDP_PRINT_FORMAT, i + 1, (u_short)table->table[i + transformAmount].dwLocalPort, Addr, (u_short)table->table[i + transformAmount].dwLocalPort);

        }
    }



    free(table);

}
