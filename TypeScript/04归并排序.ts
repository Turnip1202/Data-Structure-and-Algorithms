// 归并排序
// 1，不断分组，直至拆成单个元素
// 2.怎们分的就怎么合并回去，
// 3.合并的时候，对各组元素进行排序

// 定义函数mergeSort，参数是待排序数组arr
function mergeSort(arr: number[]): number[] {
  // 计算数组长度
  const n = arr.length;
  // 如果数组长度小于等于1，则直接返回该数组
  if (n <= 1) {
    return arr;
  }
  // 计算中间位置
  const middle = Math.floor(n / 2); //使得总是左边<=右边
  //这里的递归调用，会使得分组后就可以进行合并
  // 对左边的数组进行归并排序
  const left = mergeSort(arr.slice(0, middle));
  // 对右边的数组进行归并排序
  const right = mergeSort(arr.slice(middle));
  // 合并两个排好序的数组
  return merge(left, right);
}

// 定义函数merge，参数是两个排好序的数组left和right
function merge(left: number[], right: number[]): number[] {
  // 定义指针变量，分别指向两个数组的开头
  let i = 0,
    j = 0;
  // 定义一个空数组，用来存放合并后的数组
  const result: number[] = [];
  // 比较两个数组的第一个元素，将较小的放入result数组
  while (i < left.length && j < right.length) {
    if (left[i] < right[j]) {
      result.push(left[i++]); //push后++
    } else {
      result.push(right[j++]);
    }
  }
  // console.log(i, j); //首次输出[1,0]-> result = [2,9]
  // 将没有比较完的剩余元素放入result数组
  while (i < left.length) {
    result.push(left[i++]);
  }
  while (j < right.length) {
    result.push(right[j++]);
  }
  // 返回合并后的数组
  return result;
}

// 测试数据
const testArr = [5, 2, 9, 1, 5, 6];
// 调用插入排序函数
const sortedArr = mergeSort(testArr);
// 打印结果
console.log(sortedArr);

export {};
