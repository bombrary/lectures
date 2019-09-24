
const update = (data) => {
  const table = d3.select('table');
  const tr = table.selectAll('tr')
    .data(data);
  tr.exit().remove();
  const td = tr.enter()
    .append('tr')
    .merge(tr)
    .selectAll('td')
    .data(d => d);
  td.exit().remove();
  td.enter()
    .append('td')
    .merge(td)
    .text(d => d.text)
    .style('background-color', d => d.color);
}
const formatData = (mp, queue, dist, pos) => {
  const [H, W] = [mp.length, mp[0].length];
  const ret = [];
  for (let i = 0; i < H; i++) {
    ret.push([]);
    for (let j = 0; j < W; j++) {
      const obj = { };
      if (dist[i][j] === Infinity) {
        obj.text = '∞';
      } else {
        obj.text = String(dist[i][j]);
      }

      if (i == pos[0] && j == pos[1]) {
        obj.color = 'yellow';
      } else if (mp[i][j] === '#') {
        obj.color = 'black';
      } else if (dist[i][j] === Infinity) {
        obj.color = 'lightgray';
      } else {
        obj.color = 'orangered';
      }
      ret[i].push(obj);
    }
  }
  for (const p of queue.toArray()) {
    const [i, j] = p;
    ret[i][j].color = 'lightgreen';
  }
  return ret;
}

const solveMaze = (mp, sy, sx) => {
  const ret = new MazeHistories(mp);

  const dy = [-1, 0, 1, 0];
  const dx = [0, 1, 0, -1];

  const [H, W] = [mp.length, mp[0].length];
  const dist = Array.from(new Array(H), () => new Array(W).fill(Infinity));
  const q = new Queue();
  dist[sy][sx] = 0;
  q.enqueue([sy, sx]);

  while (!q.empty()) {
    const [y, x] = q.dequeue();
    for (let i = 0; i < 4; i++) {
      const [ny, nx] = [y + dy[i], x + dx[i]];
      if (ny < 0 || ny >= H) continue;
      if (nx < 0 || nx >= W) continue;

      ret.push(q, dist, [ny, nx]);
      if (mp[ny][nx] === '#') continue;
      if (dist[ny][nx] > dist[y][x] + 1) {
        dist[ny][nx] = dist[y][x] + 1;
        q.enqueue([ny, nx]);
      }
    }
  }

  return ret;
}

let itr;
d3.select('#gen_btn')
  .on('click', () => {
    const input = d3.select('textarea')
      .property('value')
      .split('\n');
    const start = input[0].split(' ')
      .map(d => Number(d));
    const mp = input.slice(1);

    const [H, W] = [mp.length, mp[0].length];
    itr = new MazeHistoriesIterator(solveMaze(mp, start[0], start[1]), formatData);

    update(itr.toFormatted());

    d3.select('#step_btn').property('disabled', false);
    d3.select('#play_btn').property('disabled', false);
  });

const testcase = 
`1 1
########
#......#
#.######
#..#...#
#..##..#
##.....#
########`;
d3.select('textarea')
  .property('value', testcase);

d3.select('#step_btn')
  .on('click', () => {
    if (itr.hasNext()) {
      update(itr.toFormatted());
      itr.next();
    }
  });

let timer;
d3.select('#play_btn')
  .on('click', () => {
  d3.select('#play_btn').property('disabled', true);
  d3.select('#stop_btn').property('disabled', false);
  timer = d3.interval(() => {
    if (itr.hasNext()) {
      update(itr.toFormatted());
      itr.next();
    } else {
      timer.stop();
    }
  }, 200);
});
d3.select('#stop_btn')
  .on('click', () => {
  timer.stop();
  d3.select('#play_btn').property('disabled', false);
  d3.select('#stop_btn').property('disabled', true);
});
