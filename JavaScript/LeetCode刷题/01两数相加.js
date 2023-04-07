function ListNode(val, next) {
  this.val = (val === undefined ? 0 : val)
  this.next = (next === undefined ? null : next)
}



let l1 = new ListNode(2)
l1.next = new ListNode(4)
l1.next.next = new ListNode(3)
let l2 = new ListNode(5)
l2.next = new ListNode(6)
l2.next.next = new ListNode(4)


/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
  let root = new ListNode(0);//存储头节点
  let cursor = root;//指向头节点，做指针移动的操作，初始指向头结点
  let curry = 0;//进位标志

  while (l1 || l2 || curry) {
    let l1Val = l1?.val ?? 0;//本来想直接用??,但是在结点后移到最后的时候l1是undefined.所以使用可选链
    let l2Val = l2?.val ?? 0;
    let sum = l1Val + l2Val + curry;
    curry = parseInt(sum / 10);//得到进位数
    //留下加操作后的各位数，移动指针，注意，由于是引用类型，故此时cursor.next会作用于root.next
    cursor.next = new ListNode(sum % 10);
    //移动指针
    cursor = cursor.next;
    //判断链表是否为空，节点后移
    if (l1) l1 = l1.next;
    if (l2) l2 = l2.next;
  }

  return root.next;
};

console.log(addTwoNumbers(l1, l2))
