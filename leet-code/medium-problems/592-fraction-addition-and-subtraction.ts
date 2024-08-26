/*
Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

 

Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"

Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"

Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"

 

Constraints:

    The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
    Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
    The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
    The number of given fractions will be in the range [1, 10].
    The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

*/
const fractionAddition = (expression: string): string => {
  let denominator: number = 2520;
  let numerator: number = 0;
  let primes: number[] = [2, 3, 5, 7];
  let isNegative = false;
  let index = 0;

  const getNumber = (): number => {
    let stringNumber: string = "";

    while (
      index < expression.length &&
      expression.charAt(index) >= "0" &&
      expression.charAt(index) <= "9"
    ) {
      stringNumber += expression.charAt(index++);
    }

    return parseInt(stringNumber);
  };

  while (index < expression.length) {
    if (index === 0) {
      isNegative = !(
        expression.charAt(index) >= "0" && expression.charAt(index) <= "9"
      );

      if (isNegative) {
        index++;
      }
    } else {
      isNegative = expression.charAt(index++) === "-";
    }

    let newNumerator = getNumber();
    index++;
    const newDenominator = getNumber();

    if (isNegative) {
      numerator -= newNumerator * (denominator / newDenominator);
    } else {
      numerator += newNumerator * (denominator / newDenominator);
    }
  }

  primes.forEach((prime) => {
    while (numerator % prime === 0 && denominator % prime === 0) {
      numerator /= prime;
      denominator /= prime;
    }
  });

  return `${numerator}/${denominator}`;
};

console.log(fractionAddition("-1/2+1/2+1/3"));
