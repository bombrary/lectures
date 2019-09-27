class Queue {
  constructor(queueSize) {
    this.buf = new Array(queueSize).fill(0);
    this.head = 0;
    this.tail = 0;
    this.length = 0;
  }
  enqueue(datum) {
    if (this.full()) {
      console.error('Queue is full.');
      return;
    }
    this.buf[this.tail] = datum;
    this.tail = (this.tail + 1) % this.buf.length;
    this.length++;
  }
  dequeue() {
    if (this.empty()) {
      console.error('Queue is empty.');
      return undefined;
    }
    const ret = this.buf[this.head];
    this.head = (this.head + 1) % this.buf.length;
    this.length--;
    return ret;
  }
  full() {
    return this.length >= this.buf.length; 
  }
  empty() {
    return this.length === 0; 
  }
  toArray() {
    return this.buf.slice();
  }
}
