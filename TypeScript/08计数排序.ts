function countingSort(array: number[]): number[] {
  const n = array.length;

  // 计算数列最大值和最小值
  let max = array[0];
  let min = array[0];
  for (let i = 1; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
    if (array[i] < min) {
      min = array[i];
    }
  }

  // 统计数列中每个值出现的次数
  const count = new Array(max - min + 1).fill(0);
  for (let i = 0; i < n; i++) {
    count[array[i] - min]++;
  }

  // 累加数组
  for (let i = 1; i < count.length; i++) {
    count[i] += count[i - 1];
  }

  // 从后向前遍历原始数组，按照统计数组中的位置放置元素
  const res = new Array(n);
  for (let i = n - 1; i >= 0; i--) {
    res[--count[array[i] - min]] = array[i];
  }

  return res;
}
