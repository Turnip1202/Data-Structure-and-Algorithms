function bucketSort(arr: number[], bucketSize = 5) {
  if (arr.length === 0) {
    return arr;
  }

  // 找到数组中的最大值和最小值
  let i;
  let minValue = arr[0];
  let maxValue = arr[0];
  for (i = 1; i < arr.length; i++) {
    if (arr[i] < minValue) {
      minValue = arr[i];
    } else if (arr[i] > maxValue) {
      maxValue = arr[i];
    }
  }

  // 计算桶的数量
  let bucketCount = Math.floor((maxValue - minValue) / bucketSize) + 1;
  let buckets = new Array(bucketCount);
  for (i = 0; i < buckets.length; i++) {
    buckets[i] = [];
  }

  // 将数组中的元素分配到各个桶中
  for (i = 0; i < arr.length; i++) {
    buckets[Math.floor((arr[i] - minValue) / bucketSize)].push(arr[i]);
  }

  // 对每个桶中的元素进行排序
  arr.length = 0;
  for (i = 0; i < buckets.length; i++) {
    if (buckets[i].length > 0) {
      insertionSort(buckets[i]);
      for (let j = 0; j < buckets[i].length; j++) {
        arr.push(buckets[i][j]);
      }
    }
  }

  return arr;
}

// 插入排序
function insertionSort(arr: number[]) {
  let i;
  let j;
  let temp;
  for (i = 1; i < arr.length; i++) {
    temp = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
  return arr;
}

export {};
