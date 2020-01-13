#pragma once

#include "MainHeader.h"

#define TCP_PRINT_FORMAT "[TCP]ID: %d | Local Port: %d | IP: %s:%d\n"

class TCPHandler
{
	public: 

		void Update();

	private:
		PMIB_TCPTABLE table;

		struct in_addr IPAddress;

		char Addr[128];

		DWORD bufferSize = sizeof(MIB_TCPTABLE);

		byte transformAmount = 35;

};

