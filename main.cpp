// C++
#include <iostream>
#include <fstream>

// Custom
#include "include/custom_exceptions.hpp"

// Enum
enum Errors
{
   FILE_OPEN_FAILED = -5,
   length_DETERMINATION_FAILED,
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
   Errors errorCode = read_file_code();
   std::cout << errorCode << std::endl;
   return EXIT_SUCCESS;
}

// Implementations
void read_file_try()
{
   std::string filename = "test.txt";
   try
   {
      std::ifstream file(filename);

      if (!file.is_open())
         throw fileOpenFailed();

      file.seekg(0, file.end);
      auto length = file.tellg();
      // For test 'readFailed', comment line under this
      file.seekg(0, file.beg);

      if (length <= 0)
         throw sizeDeterminationFailed();

      char *buff = new char[length];
      if (buff == nullptr)
         throw memoryAllocationFailed();

      if (!file.read(buff, length))
         throw readFailed();

      file.close();
      if (file.fail())
         throw fileClosedFailed();
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