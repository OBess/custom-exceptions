// C++
#include <iostream>
#include <fstream>

// Custom
#include "include/custom_exceptions.hpp"

// Enum
enum Errors
{
   FILE_OPEN_FAILED = -5,
   SIZE_DETERMINATION_FAILED,
   MEMORY_ALLOCATION_FAILED,
   READ_FAILED,
   FILE_CLOSE_FAILED
};

// Prototypes
void read_file_try();
Errors read_file_code();

int main()
{
   read_file_try();
   auto errorCode = read_file_code();

   return EXIT_SUCCESS;
}

// Implementations
void read_file_try()
{
   std::string filename = "";
   // std::string filename = "test.txt";
   try
   {
      std::ifstream file(filename);

   }
   catch (fileOpenFailed &ex)
   {
      std::cout << ex.what() << std::endl;
   }
   catch (sizeDeterminationFailed &ex)
   {
      std::cout << ex.what() << std::endl;
   }
   catch (memoryAllocationFailed &ex)
   {
      std::cout << ex.what() << std::endl;
   }
   catch (readFailed &ex)
   {
      std::cout << ex.what() << std::endl;
   }
   catch (fileClosedFailed &ex)
   {
      std::cout << ex.what() << std::endl;
   }
   catch (...)
   {
      std::cout << "Unexpected error!" << std::endl;
   }
}

Errors read_file_code()
{
   return Errors::FILE_CLOSE_FAILED;
}