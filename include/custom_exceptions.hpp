#pragma once

// C++
#include <exception>

struct fileOpenFailed : public std::exception
{
   const char *what() const override
   {
      return "File is exist or filename is not right.";
   }
};

struct sizeDeterminationFailed : public std::exception
{
   const char *what() const override
   {
      return "Size of file is small.";
   }
};

struct memoryAllocationFailed : public std::exception
{
   const char *what() const override
   {
      return "Memory can not be allocated.";
   }
};

struct readFailed : public std::exception
{
   const char *what() const override
   {
      return "Can not read file.";
   }
};

struct fileClosedFailed : public std::exception
{
   const char *what() const override
   {
      return "Can not close file.";
   }
};