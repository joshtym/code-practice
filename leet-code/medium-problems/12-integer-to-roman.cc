#include <iostream>
#include <string>

std::string intToRoman(int num) {
  // Constrains are 1 <= num <= 3999
  std::string romanNum = "";
  if (num / 1000 > 0) {
    while (num >= 1000) {
      num -= 1000;
      romanNum += "M";
    }
  }

  if (num / 100 > 0) {
    if (num / 100 == 9) {
      num -= 900;
      romanNum += "CM";
    } else if (num / 100 == 4) {
      num -= 400;
      romanNum += "CD";
    } else {
      if (num / 500 > 0) {
        num -= 500;
        romanNum += "D";
      }

      while (num / 100 > 0) {
        num -= 100;
        romanNum += "C";
      }
    }
  }

  if (num / 10 > 0) {
    if (num / 10 == 9) {
      num -= 90;
      romanNum += "XC";
    } else if (num / 10 == 4) {
      num -= 40;
      romanNum += "XL";
    } else {
      if (num / 50 > 0) {
        num -= 50;
        romanNum += "L";
      }

      while (num / 10 > 0) {
        num -= 10;
        romanNum += "X";
      }
    }
  }

  if (num == 9) {
    romanNum += "IX";
  } else if (num == 4) {
    romanNum += "IV";
  } else {
    if (num >= 5) {
      num -= 5;
      romanNum += "V";
    }

    while (num > 0) {
      num--;
      romanNum += "I";
    }
  }

  return romanNum;
}

int main(int argc, char** argv) {
  int num;
  std::cout << "Input? ";
  std::cin >> num;
  std::cout << intToRoman(num) << std::endl;

  return 0;
}