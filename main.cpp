// C++
#include <iostream>
#include <fstream>

// Custom
#include "include/custom_exceptions.hpp"

// Enum
enum Errors
{
   SUCCESSFUL = 0,
   FILE_OPEN_FAILED = -5,
   SIZE_DETERMINATION_FAILED,
   MEMORY_ALLOCATION_FAILED,
   READ_FAILED,
   FILE_CLOSE_FAILED
};

// Prototypes
void read_file_try(const std::string path);
Errors read_file_code(const std::string path);

int main()
{
   std::string filename = "test.txt";

   read_file_try(filename);

   Errors errorCode = read_file_code(filename);
   std::cout << errorCode << std::endl;

   return EXIT_SUCCESS;
}

// Implementations
void read_file_try(const std::string path)
{
   try
   {
      std::ifstream file(path);

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

Errors read_file_code(const std::string path)
{
   Errors code = Errors::SUCCESSFUL;

   std::ifstream file(path);

   if (file.is_open())
   {
      file.seekg(0, file.end);
      auto length = file.tellg();
      // For test 'readFailed', comment line under this
      file.seekg(0, file.beg);

      if (length > 0)
      {
         char *buff = new char[length];
         if (buff)
            if (file.read(buff, length))
            {
               file.close();
               if (file.fail())
                  code = Errors::FILE_CLOSE_FAILED;
            }
            else
               code = Errors::READ_FAILED;
         else
            code = Errors::MEMORY_ALLOCATION_FAILED;
      }
      else
         code = Errors::SIZE_DETERMINATION_FAILED;
   }
   else
      code = Errors::FILE_OPEN_FAILED;

   return code;
}