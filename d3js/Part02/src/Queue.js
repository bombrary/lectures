class Queue {
  constructor() {
    this.inStack = [];
    this.outStack = [];
  }
  enqueue(datum) {
    this.inStack.push(datum);    
  }
  dequeue() {
    if (this.outStack.length === 0) {
      this.outStack = this.inStack.reverse();
      this.inStack = [];
    }
    return this.outStack.pop();
  }
  empty() {
    return this.inStack.length === 0 && this.outStack.length === 0;
  }
  toArray() {
    const ret = this.outStack.concat(this.inStack.reverse());  
    return ret;
  }
  copy() {
    const ret = new Queue();
    ret.inStack = this.inStack.slice();
    ret.outStack = this.outStack.slice();
    return ret;
  }
}

/*class ListNode {
  constructor(datum) {
    this.datum = datum;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.tail = null;
    this.head = null;
  }
  enqueue(datum) {
    const node = new ListNode(datum);
    if (this.head == null) {
      this.head = node;
      this.tail = this.head
    } else {
      this.tail.next = node;
      this.tail = node;
    }
  }
  dequeue() {
    const node = this.head;
    this.head = this.head.next;
    return node.datum;
  }
  empty() {
    return this.head === null;
  }
  toArray() {
    const ret = [];
    for (let node = this.head; node !== null; node = node.next) {
      ret.push(node.datum);
    }
    return ret;
  }
  copy() {
    const ret = new Queue();
    for (let node = this.head; node !== null; node = node.next) {
      ret.enqueue(node.datum);
    }
    return ret;
  }
}*/

/*class Queue {
  constructor() {
    this.buf = [];
  }
  enqueue(datum) {
    this.buf.push(datum);
  }
  dequeue() {
    return this.buf.shift(); 
  }
  empty() {
    return this.buf.length === 0;
  }
  toArray() {
    return this.buf;
  }
  copy() {
    const ret = new Queue();
    ret.buf = this.buf.slice();
    return ret;
  }
}*/

