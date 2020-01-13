#pragma once

#include "MainHeader.h"

#define UDP_PRINT_FORMAT "[UDP]ID: %d | Local Port: %d | IP: %s:%d\n"

class UDPHandler
{

public:

	void Update();

private:
	PMIB_UDPTABLE table;

	struct in_addr IPAddress;

	char Addr[128];

	DWORD bufferSize = sizeof(MIB_UDPTABLE);

	byte transformAmount = 0;

};

