"use strict";
debugger;
function selectionSort(arr) {
    var _a;
    // 循环遍历整个数组
    for (var i = 0; i < arr.length; i++) {
        // 预设最小数的索引为当前循环的索引
        var minIndex = i;
        // 在后面的数中寻找更小的数
        for (var j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[minIndex]) {
                // 如果找到更小的数，记录它的索引
                minIndex = j;
            }
        }
        // 如果当前循环的索引不是最小数的索引，交换它们
        if (i !== minIndex) {
            _a = [arr[minIndex], arr[i]], arr[i] = _a[0], arr[minIndex] = _a[1];
        }
    }
    // 返回排序后的数组
    return arr;
}
// 测试数据
var testArr = [5, 2, 9, 1, 5, 6];
// 调用插入排序函数
var sortedArr = selectionSort(testArr);
// 打印结果
console.log(sortedArr);
