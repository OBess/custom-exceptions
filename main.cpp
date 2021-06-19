// C++
#include <iostream>

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

}

Errors read_file_code()
{
   return Errors::FILE_CLOSE_FAILED;
}

