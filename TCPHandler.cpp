#include "TCPHandler.h"

void TCPHandler::Update()
{

    bufferSize = sizeof(MIB_TCPTABLE);

    if ((table = ALLOC<MIB_TCPTABLE>(bufferSize)) == nullptr) {

        printf_s(RED("ERROR : Can't alloc memory for MIB_TCPTABLE"));

        return;

    }

    if (GetTcpTable(table, &bufferSize, TRUE) == ERROR_INSUFFICIENT_BUFFER) {

        printf_s(YEL("WARNING : Buffer insufficient , creating new one !"));

        free(table);

        table = ALLOC<MIB_TCPTABLE>(bufferSize);

        if (table == nullptr) {

            printf_s(RED("ERROR : Can't alloc memory for MIB_TCPTABLE"));

            return;

        }

    }

    if (GetTcpTable(table, &bufferSize, TRUE) == NO_ERROR) {

        printf_s("Nomber of IPs : %d \n", (int)table->dwNumEntries - transformAmount);

        for (int i = 0; i < (int)table->dwNumEntries - transformAmount; i++)
        {

            IPAddress.S_un.S_addr = (u_long)table->table[i + transformAmount].dwRemoteAddr;

            strcpy_s(Addr, sizeof(Addr), inet_ntoa(IPAddress));

            printf_s(TCP_PRINT_FORMAT,i+1, (u_short)table->table[i + transformAmount].dwLocalPort, Addr, (u_short)table->table[i + transformAmount].dwRemotePort);

        }
    }



    free(table);

}
