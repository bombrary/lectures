class MazeHistories {
  constructor(mp) {
    this.data = [];
    this.mp = mp;
  }
  push(_queue, _dist, pos) {
    const queue = _queue.copy();
    const dist = _dist.map(arr => arr.slice());
    this.data.push({ queue, dist, pos });
  }
}

class MazeHistoriesIterator {
  constructor(mazeHistories, format) {
    this.histories = mazeHistories;
    this.format = format;
    this.cnt = 0;
  }
  hasNext() {
    return this.cnt < this.histories.data.length;
  }
  next() {
    this.cnt++;
  }
  toFormatted() {
    const mp = this.histories.mp;
    const {queue, dist, pos} = this.histories.data[this.cnt];
    return this.format(mp, queue, dist, pos);
  }
}
