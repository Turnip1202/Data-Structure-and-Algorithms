function isPalindrome(x: number): boolean {
  if (x.toString().split("").reverse().join("") === x.toString()) return true;
  else return false;
}
