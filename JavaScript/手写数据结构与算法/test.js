let arr = [1, 3, 8, 4, 6, 5, 0, 2, 7, 9];
for (let i = 0; i < arr.length; i++) {
  for (let j = arr.length - 2; j >= i; j--)
    if (arr[j] > arr[j + 1]) [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
}
console.log(arr);
