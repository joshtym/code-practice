const countAndSay = (n: number): string => {
  const elements = ["1"];

  for (let i = 1; i < n; ++i) {
    let index = 0;
    const elementToExamine = elements[i - 1];
    let newElement = "";

    while (index < elementToExamine.length) {
      let count = 1;
      let num = elementToExamine.charAt(index);

      while (
        ++index != elementToExamine.length &&
        elementToExamine.charAt(index) === num
      ) {
        count++;
      }

      newElement = `${newElement}${count}${num}`;
    }

    elements.push(newElement);
    newElement = "";
  }

  return elements[n - 1];
};

console.log(countAndSay(4));
