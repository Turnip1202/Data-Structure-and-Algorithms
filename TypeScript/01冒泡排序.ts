// 定义函数，用于实现冒泡排序算法
function bubbleSort(arr: number[]): number[] {
  // 外层循环，控制需要比较的轮数(元素的个数-1轮)
  for (let i = 0; i < arr.length - 1; i++)
    // 内层循环，控制每轮需要比较的次数
    for (let j = 0; j < arr.length - 1 - i; j++)
      // 如果前一个元素比后一个元素大，则交换它们的位置
      if (arr[j] > arr[j + 1]) [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];

  // 返回排序后的数组
  return arr;
}

// 测试代码
const arr = [3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48];
console.log(bubbleSort(arr));
// 输出：[2, 3, 4, 5, 15, 19, 26, 27, 36, 38, 44, 46, 47, 48, 50]

export {};
