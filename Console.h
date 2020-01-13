#pragma once

#include "TCPHandler.h"

#include "UDPHandler.h"

class Console
{
public :

	Console(int sleepTime);

	void Cycle();

private :
	
	TCPHandler* tcpHandler;

	UDPHandler* udpHAandler;

	int sleepTime; // sleep for 1 sec

	void ClearConsole();

};

