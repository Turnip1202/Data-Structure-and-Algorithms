// 封装节点类
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

// 单向链表结构的封装
class LinkedList {
  constructor() {
    this.length = 0;
    this.head = null;
  }

  // 链表的常见操作
  // append 向链表尾部追加数据
  append(data) {
    // 1.创建新节点
    const newNode = new Node(data);
    // 2.追加新节点
    if (this.length === 0 || this.head === null) {
      // 链表长度为0，即链表里只有head时
      this.head = newNode;
    } else {
      // 链表长度大于0时，在最后面添加新节点

      // 定义一个节点指针，用于遍历节点
      let currentNode = this.head;

      // 循环，找到currentNode.next为null的节点，追加
      while (currentNode.next !== null) currentNode = currentNode.next;

      // 找到currentNode.next = null的节点了，追加
      currentNode.next = newNode;
    }

    // 追加完成length++
    this.length++;
  }
  insert(position, data) {
    //1.对越界情况进行检测
    if (position < 0 || position > this.length) return false;

    // 2.创建新节点
    const newNode = new Node(data);

    // 3.插入节点
    if (position === 0) {
      // 插入到头节点
      newNode.next = this.head;
      this.head = newNode;
    } else {
      // 用指针遍历链表
      let currentNode = this.head; //先指向头节点
      let previousNode = null; //用于记录当前节点的上一个节点
      let index = 0; //遍历到要插入的位置
      while (index++ < position) {
        previousNode = currentNode; //指向当前节点
        currentNode = currentNode.next; //移动，遍历
      }
      //  找到位置之后，插入
      previousNode.next = newNode;
      newNode.next = currentNode;
    }

    // 更新链表长度，返回插入的节点
    this.length++;
    return true;
  }
  // getData(position)获取指定位置的元素
  getData(position) {
    // 越界判断(这里不能等于)
    if (position < 0 || position > this.length - 1) return null;

    // 定义指针遍历链表
    let currentNode = this.head;
    let index = 0;
    while (index++ < position) currentNode = currentNode.next;

    // 找到指定位置,返回数据
    return currentNode.data;
  }

  // indexOf(data) 返回data对应的索引，找不到返回-1
  indexOf(data) {
    // 遍历链表
    let currentNode = this.head;
    let index = 0;
    while (currentNode) {
      if (currentNode.data === data) return index;
      currentNode = currentNode.next;
      if (!currentNode.next) return -1;
      index++;
    }
    return -1;
  }

  update(position, data) {
    // 1.越界判断
    if (position < 0 || position > this.length) return false;
    // 2.遍历，更新
    let currentNode = this.head;
    let index = 0;
    while (index++ < position) currentNode = currentNode.next;

    // 3.找到，更新
    currentNode.data = data;

    // 4.返回此节点
    return currentNode;
  }
  removeAt(position) {
    // 1.越界判断
    if (position < 0 || position >= this.length) return null;
    // 2.遍历，删除
    let currentNode = this.head;
    if (position === 0) this.head = this.head.next;
    else {
      let previousNode = null;
      let index = 0;
      while (index++ < position) {
        previousNode = currentNode;
        currentNode = currentNode.next;
      }
      previousNode.next = currentNode.next;
    }
    this.length--;
    return currentNode;
  }
  remove(data) {
    return this.removeAt(this.indexOf(data));
  }
  isEmpty() {
    return this.length === 0;
  }
  size() {
    return this.length;
  }
  toString() {
    let currentNode = this.head;
    let result = "";
    while (currentNode) {
      result += currentNode.data;
      currentNode = currentNode.next;
    }
    return result;
  }
}

module.exports = {
  Node,
  LinkedList,
};
