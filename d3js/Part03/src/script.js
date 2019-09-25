const [svgWidth, svgHeight] = [800, 600];
const svg = d3.select('svg')
  .attr('width', svgWidth)
  .attr('height', svgHeight);
const circleGroup = svg.append('g');
const path = svg.append('path')
  .attr('stroke', '#000')
  .attr('fill', 'none');
const xAxisGroup = svg.append('g');
const yAxisGroup = svg.append('g');
const posInfoGroup = svg.append('g');
const rect = posInfoGroup.append('rect')
  .attr('stroke', '#000')
  .attr('fill', 'white');
const text = posInfoGroup.append('text')
  .attr('text-anchor', 'middle')
  .attr('dominant-baseline', 'central');
const pad = 20;

const testcase = [[0, 0], [1, 10], [2, 5], [3, 7], [4, 2], [5, 1]];

const update = (data) => {
  const dataWithO = [...data, [0, 0]];
  const xScale = d3.scaleLinear()
    .domain(d3.extent(dataWithO, d => d[0]))
    .range([pad, svgWidth-pad]);
  const yScale = d3.scaleLinear()
    .domain(d3.extent(dataWithO, d => d[1]))
    .range([svgHeight-pad, pad]);

  const circle = circleGroup.selectAll('circle')
    .data(data);
  circle.exit().remove();
  circle.enter()
    .append('circle')
    .merge(circle)
    .attr('fill', 'black')
    .attr('stroke', 'none')
    .attr('r', 3)
    .attr('cx', d => xScale(d[0]))
    .attr('cy', d => yScale(d[1]))
    .on('mouseover', d => {
      posInfoGroup.attr('transform', `translate(${d3.event.offsetX}, ${d3.event.offsetY-20})`);
      text.text(`(${d[0]},${d[1]})`);
      const bbox = text.node().getBBox();
      rect.attr('width', bbox.width)
        .attr('height', bbox.height)
        .attr('x', -bbox.width/2)
        .attr('y', -bbox.height/2);
    })
    .on('mouseout', () => {
      rect.attr('width', 0)
        .attr('height', 0);
      text.text('');
    });

  const line = d3.line()
    .x(d => xScale(d[0]))
    .y(d => yScale(d[1]));
  path.datum(data)
    .attr('d', line);

  const [xMax, xMin] = d3.extent(dataWithO, d => d[0]);
  const xAxis = d3.axisBottom()
    .scale(xScale)
  xAxisGroup.attr('transform', `translate(0, ${yScale(0)})`)
    .call(xAxis);

  const [yMax, yMin] = d3.extent(dataWithO, d => d[1]);
  const yAxis = d3.axisLeft()
    .scale(yScale)
  yAxisGroup.attr('transform', `translate(${xScale(0)}, 0)`)
    .call(yAxis);

}

const generatePoints = (start, end, step, f) =>
  d3.range(start, end, step)
    .map(d => [d, f(d)]);

const sinc = x => x === 0 ? 1 : Math.sin(x)/x;
const digSum = n => String(n).split('')
  .reduce((acc, e) => acc + Number(e), 0);
const sumDiv = n => n / digSum(n);

