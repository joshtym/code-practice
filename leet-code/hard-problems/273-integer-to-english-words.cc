/*
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

 

Constraints:

    0 <= num <= 2^31 - 1

*/

#include <iostream>
#include <string>
#include <vector>
#include "catch.hpp"

#define CATCH_CONFIG_MAIN  

std::string getBasic(int num) {
  if (num < 0)
    throw "Number is negative";
  
  if (num > 19)
    throw "Number is too large";

  std::vector<std::string> numMapBasic = {
    "",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen"
  };

  return numMapBasic[num];
}

std::string parseTwoDigits(int num) {
  if (num < 0)
    throw "Number is negative";

  if (num > 99)
    throw "Number too large";

  std::vector<std::string> numMapTens = {
    "",
    "",
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety"
  };

  if (num < 20)
    return getBasic(num);
  
  return numMapTens[num / 10] + (num % 10 != 0 ? " " + getBasic(num % 10) : "");
}

std::string parseThreeDigits(int num) {
  if (num < 0)
    throw "Number is negative";

  if (num > 999)
    throw "Number too large";
  
  std::string valueAsString = parseTwoDigits(num % 100);
  num /= 100;

  if (num > 0)
    valueAsString = getBasic(num) + " Hundred" + (valueAsString.length() > 0 ? " " + valueAsString : "");

  return valueAsString;
}

std::string numberToWords(int num) {
  if (num == 0)
    return "Zero";
  
  std::vector<std::string> appendedDenoter = {
    "",
    " Thousand",
    " Million",
    " Billion",
    " Trillion"
  };
  int cycle = 0;
  std::string valueAsString = "";

  try {
    if (num < 0)
      throw "Negative value provided. Not supported";

    while (num > 0) {
      std::string parsedDigits = parseThreeDigits(num % 1000);
      
      if (parsedDigits.length() > 0)
        valueAsString = parsedDigits + appendedDenoter[cycle] + (valueAsString.length() != 0 ? " " + valueAsString : "");
      
      cycle++;
      num /= 1000;
    }
  } catch (char const* e) {
    std::cout << "Exception was: " << std::string(e) << std::endl;
  } catch (...) {
    std::cout << "Exception?" << std::endl;
  }

  return valueAsString;
}

// int main(int argc, char** argv) {
//   int num;

//   while (std::cin >> num)
//     std::cout << numberToWords(num) << "." << std::endl;

//   return 0;
// }

TEST_CASE("Test parse for basic") {
  REQUIRE(parseThreeDigits(0) == "zero");
}