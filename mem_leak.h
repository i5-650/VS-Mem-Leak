#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>  
#include <crtdbg.h>
#include <Windows.h>
#include <conio.h>
#include "color.h"

_CrtMemState init_valgrind() {
    _CrtMemState sOld;
    _CrtMemCheckpoint(&sOld);
    return sOld;
}

_CrtMemState end_valgrind(_CrtMemState& sOld) {
    _CrtMemState sNew;
    _CrtMemState sDiff;
    _CrtMemCheckpoint(&sNew);
    if (_CrtMemDifference(&sDiff, &sOld, &sNew)) {
        OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
        _CrtMemDumpStatistics(&sDiff);
        OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
        _CrtMemDumpAllObjectsSince(&sOld);
        OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
        _CrtDumpMemoryLeaks();
        puts("Press any key to end\n");
        while (!_kbhit()) {

        }
    }
    return sDiff;
}