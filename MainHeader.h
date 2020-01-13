#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdarg.h>
#include <iostream>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#define CONSOLE_COLOR_YELLOW  "\x1b[33m"
#define CONSOLE_COLOR_RED     "\x1b[31m"
#define CONSOLE_COLOR_RESET   "\x1b[0m"

#define RED(string) CONSOLE_COLOR_RED string CONSOLE_COLOR_RESET "\n"
#define YEL(string) CONSOLE_COLOR_YELLOW string CONSOLE_COLOR_RESET "\n"

template <class T>
T* ALLOC(int size) {

    return (T*)malloc(size);

}

