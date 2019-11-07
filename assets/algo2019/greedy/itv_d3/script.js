const [width, height] = [600, 400];

const div = d3.select('body')
  .append('div')
  .attr('class', 'flex-container');

const inputarea = div.append('div')
  .attr('class', 'input-container')
const textarea = inputarea.append('textarea')
  .style('width', '200px')
  .style('height', `${height}px`);
const button = inputarea.append('input')
  .attr('type', 'button')
  .attr('value', 'click')
  .on('click', () => {
    let input = textarea.property('value')
      .split('\n')
      .map(d => d.split(' '))
      .map(d0 => d0.map(d1 => Number(d1)));
    input = input.slice(1, input.length)
      .map(d => Object({"color": 'green', "pos": d}));
    update(input);
  });

const svg = div.append('svg')
  .attr('width', width)
  .attr('height', height);
let g_axis = svg.append('g')
    .attr('class', 'axis')
    .attr('transform', `translate(${0}, ${50})`)
let itv = svg.append('g')
  .attr('class', 'intervals');

function update(data) {
  let xScale = d3.scaleLinear()
    .domain([0, d3.max(data, d => d.pos[1]) + 1])
    .range([50, width - 50]);

  let axisx = d3.axisBottom(xScale).ticks(d3.max(data, d => d.pos[1]) + 1);

  g_axis.call(axisx);

  itv = svg.select('g.intervals')
    .selectAll('g')
    .data(data);
  let itv_enter = itv.enter()
    .append('g')
    .attr('transform', (d, i) => `translate(0, ${10*i + 80})`);
  itv_enter.append('path')
    .attr("stroke-width", 1.5);
  itv_enter.merge(itv)
    .selectAll('circle')
    .data(d => d.pos)
    .enter()
    .append('circle')
    .attr('r', 2);

  itv_enter.merge(itv)
    .select('path')
    .attr('d', d => {
      let x0 = xScale(d.pos[0]);
      let x1 = xScale(d.pos[1]);
      return `M${x0},${0} L${x1},${0}`;
    })
    .attr("stroke", d => d.color)
    .on('click', function(d) {
      d3.select(this)
        .attr('stroke', 'red');
    });
  itv_enter.merge(itv)
    .selectAll('circle')
    .attr('cx', d => xScale(d));
  
  itv.exit().remove()
}


