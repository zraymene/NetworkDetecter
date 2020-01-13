#include "Console.h"

Console::Console(int sleepTime) : sleepTime(sleepTime)
{

	this->tcpHandler = new TCPHandler();

	this->udpHAandler = new UDPHandler();

	this->Cycle();

}

void Console::Cycle()
{

	while (true)
	{

		this->ClearConsole();			// Clear console or Erease every thing 

		this->tcpHandler->Update();			// Update TCPHandler update 

	//	this->udpHAandler->Update();		// Update UDPHandler update          DISABLED UNTIL A FIX IS FOUND

		Sleep(sleepTime);				// Force sleep 

	}

}

void Console::ClearConsole()
{
	system("CLS");
}
