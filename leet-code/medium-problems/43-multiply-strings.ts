/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

 

Constraints:

    1 <= num1.length, num2.length <= 200
    num1 and num2 consist of digits only.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.

*/

const multiply = (num1: string, num2: string): string => {
  if (num1 === "0" || num2 === "0") {
    return "0";
  }

  const addStrings = (addOne: string, addTwo: string): string => {
    const firstNum = addOne.length > addTwo.length ? addOne : addTwo;
    const secondNum = addOne.length > addTwo.length ? addTwo : addOne;
    let result = "";
    let carry = false;

    for (let i = 0; i < firstNum.length; ++i) {
      let addedValue: number =
        parseInt(firstNum.charAt(firstNum.length - 1 - i)) + Number(carry);
      const secondNumVal = parseInt(secondNum.charAt(secondNum.length - i - 1));

      if (!isNaN(secondNumVal)) {
        addedValue += secondNumVal;
      }

      carry = addedValue / 10 >= 1;
      addedValue = addedValue % 10;
      result = `${addedValue}${result}`;
    }

    return carry ? `1${result}` : result;
  };

  const topNum = num1.length > num2.length ? num1 : num2;
  const bottomNum = num1.length > num2.length ? num2 : num1;
  let result = "";

  for (let i = 0; i < bottomNum.length; ++i) {
    let tmp = new Array(i).fill("0").join("");
    const multiplicator = parseInt(bottomNum.charAt(bottomNum.length - 1 - i));
    let carry = 0;

    for (let j = 0; j < topNum.length; ++j) {
      let val =
        parseInt(topNum.charAt(topNum.length - 1 - j)) * multiplicator + carry;
      carry = Math.floor(val / 10);
      val = val % 10;
      tmp = `${val}${tmp}`;
    }

    result = addStrings(result, carry > 0 ? `${carry}${tmp}` : tmp);
  }

  return result;
};

console.log(multiply("123456789", "4562341"));
