class Iterator {
  constructor(array) {
    this.buf = array;
    this.cnt = 0;
  }
  hasNext() {
    return this.cnt < this.buf.length;
  }
  next() {
    this.cnt++;
  }
  now() {
    return this.buf[this.cnt];
  }
  remainder() {
    return this.buf.slice(this.cnt);
  }
}

