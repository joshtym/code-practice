/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

 

Constraints:

    1 <= strs.length <= 10^4
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.

*/
const groupAnagrams = (strs: string[]): string[][] => {
  let anagrams: string[][] = [];
  const mapOfAnagrams = new Map<string, string[]>();

  strs.forEach((str) => {
    const sortedString = str.split("").sort().join("");

    if (!mapOfAnagrams.has(sortedString)) {
      mapOfAnagrams.set(sortedString, [str]);
    } else {
      mapOfAnagrams.get(sortedString)?.push(str);
    }
  });

  mapOfAnagrams.forEach((val, key) => {
    anagrams.push([...val]);
  });

  return anagrams;
};

console.log(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]));
