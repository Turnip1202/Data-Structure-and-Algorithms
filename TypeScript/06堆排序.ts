// 堆排序的函数
function heapSort(arr: number[]) {
  // 先建立大根堆（从最后一个非叶子节点向上调整）
  for (let i = Math.floor(arr.length / 2) - 1; i >= 0; i--) {
    adjustHeap(arr, i, arr.length);
  }
  // 每次把堆顶的数与最后一个数交换，并重新调整堆
  for (let i = arr.length - 1; i > 0; i--) {
    [arr[0], arr[i]] = [arr[i], arr[0]];
    adjustHeap(arr, 0, i);
  }
  return arr;
}

// 堆调整函数
function adjustHeap(arr: number[], i: number, len: number) {
  let temp = arr[i];
  // 将当前节点与其左右子节点比较，找出最大的那个
  for (let j = 2 * i + 1; j < len; j = 2 * j + 1) {
    if (j + 1 < len && arr[j + 1] > arr[j]) {
      j++;
    }
    // 如果子节点比父节点大，就交换
    if (arr[j] > temp) {
      arr[i] = arr[j];
      i = j;
    } else {
      break;
    }
  }
  arr[i] = temp;
}

// 测试数据
const testArr = [5, 2, 9, 1, 5, 6];
// 调用插入排序函数
const sortedArr = heapSort(testArr);
// 打印结果
console.log(sortedArr);

export {};
