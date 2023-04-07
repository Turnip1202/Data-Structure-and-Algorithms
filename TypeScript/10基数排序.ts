function radixSort(arr: number[]) {
  const maxDigit = getMaxDigit(arr); // 获取最大位数

  for (let i = 0; i < maxDigit; i++) {
    let buckets: number[][] = []; // 创建桶

    for (let j = 0; j < arr.length; j++) {
      let digit = getDigit(arr[j], i); // 获取数字的第i位数字

      if (!buckets[digit]) {
        buckets[digit] = [];
      }

      buckets[digit].push(arr[j]); // 将数字放入相应的桶中
    }
    let tempArr: number[] = [];
    arr = tempArr.concat(...buckets); // 将桶中的数字取出来，重新放入arr数组中
  }

  return arr;
}

// 获取最大位数
function getMaxDigit(arr: number[]) {
  let max = 0;

  for (let i = 0; i < arr.length; i++) {
    let digit = getDigitCount(arr[i]);
    max = Math.max(max, digit);
  }

  return max;
}

// 获取数字的位数
function getDigitCount(num: number) {
  if (num === 0) return 1;

  return Math.floor(Math.log10(Math.abs(num))) + 1;
}

// 获取数字的第i位数字
function getDigit(num: number, i: number) {
  return Math.floor(Math.abs(num) / Math.pow(10, i)) % 10;
}

export {};
