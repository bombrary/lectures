const [svgWidth, svgHeight] = [800, 600];
const rectLen = 30;
const svg = d3.select('svg')
  .attr('width', svgWidth)
  .attr('height', svgHeight);
const pieChart = svg.append('g')
  .attr('transform', `translate(${svgWidth/2}, ${svgHeight/2})`);
const arrGroup = svg.append('g')
  .attr('transform', `translate(${svgWidth/2}, ${svgHeight - rectLen})`);

const formatData = (queue) => {
  const pieData = queue.toArray()
    .map(d => Object({ text: String(d), color: 'gray', opacity: 0 }));
  const { head, length, buf} = queue;
  for (let i = 0; i < length; i++) {
    const k = (head + i) % buf.length;
    pieData[k].color = 'white';
    pieData[k].opacity = 1;
  }
  const alignedData = [];
  for (let i = buf.length - 1; i >= 0; i--) {
    const k = (head + i) % buf.length;
    alignedData.push({...pieData[k], idx: k});
  }
  return {pieData, alignedData};
}

const update = (data) => {
  const { pieData, alignedData } = data;
  const pie = d3.pie()
    .value(d => 1)
    .sort(null);
  const arc = d3.arc()
    .outerRadius(200)
    .innerRadius(100);

  const pieGroup = pieChart.selectAll('g')
    .data(pie(pieData));
  pieGroup.exit().remove();
  const pieGroupEnter = pieGroup.enter()
    .append('g');
  pieGroupEnter.append('path');
  pieGroupEnter.append('text');

  const t = d3.transition()
    .duration(500);
  const pieGroupMerge = pieGroupEnter.merge(pieGroup);
  pieGroupMerge.select('path')
    .attr('d', arc)
    .transition(t)
    .attr('fill', d => d.data.color)
    .attr('stroke', 'black');
  pieGroupMerge.select('text')
    .attr('transform', d => `translate(${arc.centroid(d)})`)
    .attr('text-anchor', 'middle')
    .attr('dominant-baseline', 'central')
    .transition(t)
    .attr('opacity', d => d.data.opacity)
    .text(d => d.data.text);

  
  const arrElem = arrGroup.selectAll('g')
    .data(alignedData, d => d.idx);
  arrElem.exit().remove();
  const arrElemEnter = arrElem.enter()
    .append('g');
  arrElemEnter.append('rect');
  arrElemEnter.append('text');

  const arrLen = alignedData.length * rectLen;
  const xScale = d3.scaleLinear()
    .domain([0, alignedData.length])
    .range([-arrLen/2, arrLen/2]);
  const arrElemMerge = arrElemEnter.merge(arrElem)
    .transition(t);
  arrElemMerge.attr('transform', (d, i) => `translate(${xScale(i)}, 0)`);
  arrElemMerge.select('rect')
    .attr('fill', d => d.color)
    .attr('stroke', 'black')
    .attr('width', rectLen)
    .attr('height', rectLen);
  arrElemMerge.select('text')
    .attr('text-anchor', 'middle')
    .attr('dominant-baseline', 'central')
    .attr('x', rectLen/2)
    .attr('y', rectLen/2)
    .attr('opacity', d => d.opacity)
    .text(d => d.text);
};

const ul = d3.select('#loaded_data');
const updateInfo = (data) => {
  const li = ul.selectAll('li')
    .data(data);
  li.exit().remove();
  li.enter()
    .append('li')
    .merge(li)
    .text(d => d);
};

let itr = new Iterator([]);
d3.select('#load_btn')
  .on('click', () => {
    const input = d3.select('textarea')
      .property('value')
      .split('\n')
      .map(d => d.split(' '));
    const data = d3.merge(input)
      .map(d => Number(d));
    itr = new Iterator(data);
    updateInfo(itr.remainder());
  });

d3.select('#clear_btn')
  .on('click', () => {
    itr = new Iterator([]);
    updateInfo(itr.remainder());
  });

const q = new Queue(20);
d3.select('#enqueue_btn')
  .on('click', () => {
    if (itr.hasNext() && !q.full()) {
      q.enqueue(itr.now());
      update(formatData(q));
      itr.next();
      updateInfo(itr.remainder());
    }
  });
d3.select('#dequeue_btn')
  .on('click', () => {
    if (!q.empty()) {
      q.dequeue(itr.now());
      update(formatData(q));
    }
  });

const randomInt = (m, M) => {
    const randUniform = d3.randomUniform(m, M);
    return () => Math.floor(randUniform());
  };
const rand = randomInt(0, 100);
const testcase = [...Array(30)].map(() => rand());
d3.select('textarea').property('value', testcase.join(' '));
