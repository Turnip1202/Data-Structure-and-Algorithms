"use strict";
debugger;
function insertionSort(arr) {
    // 对于数组的每一个元素，从它开始到0位置，比较该元素和前一个元素的大小
    for (var i = 1; i < arr.length; i++) {
        var current = arr[i];
        var j = i - 1;
        // 如果该元素小于前一个元素，那么前一个元素向后移动，并继续向前比较
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        // 如果该元素大于前一个元素，那么它将放到合适的位置
        arr[j + 1] = current;
    }
    // 返回排序后的数组
    return arr;
}
// 测试数据
var testArr = [5, 2, 9, 1, 5, 6];
// 调用插入排序函数
var sortedArr = insertionSort(testArr);
// 打印结果
console.log(sortedArr);
