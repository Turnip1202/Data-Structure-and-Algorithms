"use strict";
// 定义函数mergeSort，参数是待排序数组arr
function mergeSort(arr) {
    // 计算数组长度
    let n = arr.length;
    // 如果数组长度小于等于1，则直接返回该数组
    if (n <= 1) {
        return arr;
    }
    // 计算中间位置
    let middle = Math.floor(n / 2);
    // 对左边的数组进行归并排序
    let left = mergeSort(arr.slice(0, middle));
    // 对右边的数组进行归并排序
    let right = mergeSort(arr.slice(middle));
    // 合并两个排好序的数组
    return merge(left, right);
}
// 定义函数merge，参数是两个排好序的数组left和right
function merge(left, right) {
    // 定义指针变量，分别指向两个数组的开头
    let i = 0, j = 0;
    // 定义一个空数组，用来存放合并后的数组
    let result = [];
    // 比较两个数组的第一个元素，将较小的放入result数组
    while (i < left.length && j < right.length) {
        if (left[i] < right[j]) {
            result.push(left[i++]);
        }
        else {
            result.push(right[j++]);
        }
    }
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
let testArr = [5, 2, 9, 1, 5, 6];
// 调用插入排序函数
let sortedArr = mergeSort(testArr);
// 打印结果
console.log(sortedArr);
