function selectionSort(arr: number[]): number[] {
  // 循环遍历整个数组
  for (let i = 0; i < arr.length; i++) {
    // 预设最小数的索引为当前循环的索引
    let minIndex = i;
    // 在后面的数中寻找更小的数
    for (let j = i + 1; j < arr.length; j++) {
      //与后序元素进行比较
      if (arr[minIndex] > arr[j]) {
        // 如果找到更小的数，记录它的索引
        minIndex = j;
      }
    }
    // 如果当前循环的索引不是最小数的索引，交换它们，
    //每一轮循环都会使得预设的索引元素是最小值
    if (i !== minIndex) {
      [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
    }
  }
  // 返回排序后的数组
  return arr;
}

// 测试数据
const testArr = [5, 2, 9, 1, 5, 6];
// 调用插入排序函数
const sortedArr = selectionSort(testArr);
// 打印结果
console.log(sortedArr);
export {};
