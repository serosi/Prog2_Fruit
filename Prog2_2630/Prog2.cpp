//---------------------------------------------------------------------
// Name:    Maggie Nordquist
// Project: Maintain and Manipulate a Catalog of Fruit products.
// Purpose: Run Catalog, with Memory Leak detection.
//---------------------------------------------------------------------
#include <iostream>
#include "catalog.h"
#include "LeakWatcher.h"
int main()
{
   _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
   _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
   _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
   _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
   try
   {
      Catalog().Run();
   }
   catch (...)
   {
      std::cout << "Uncaught Exception" << std::endl;
   }
   _CrtDumpMemoryLeaks();
   return 0;
}