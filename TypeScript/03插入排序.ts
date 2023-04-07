function insertionSort(arr: number[]): number[] {
  // 对于数组的每一个元素，从它开始到0位置，比较该元素和前一个元素的大小
  for (let i = 1; i < arr.length; i++) {
    let current = arr[i];
    let j = i - 1;
    // 如果该元素小于前一个元素，那么前一个元素向后移动，并继续向前比较
    while (j >= 0 && arr[j] > current) {
      //元素相同了，直接跳过
      arr[j + 1] = arr[j];
      j--; //和前面的元素比较
    }
    // 如果该元素大于前一个元素，那么它将放到合适的位置
    arr[j + 1] = current;
  }
  // 返回排序后的数组
  return arr;
}

// 测试数据
const testArr = [5, 2, 9, 1, 5, 6];
// 调用插入排序函数
const sortedArr = insertionSort(testArr);
// 打印结果
console.log(sortedArr);

export {};
