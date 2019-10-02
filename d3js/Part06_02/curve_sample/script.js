const [svgWidth, svgHeight] = [600, 600];
const svg = d3.select('svg')
  .attr('xmlns', d3.namespaces.svg)
  .attr('xmlns:xlink', d3.namespaces.xlink)
  .attr('width', svgWidth)
  .attr('height', svgHeight);

const [sx, lx, l1, l2] = [100, 300, 400, 200];
const pointsTemplate = [
  [sx, -l2/(2*lx)*sx], [lx, -l2/2], [l1, 0],
  [lx, l2/2], [sx, l2/(2*lx)*sx]
];

const [px, py] = [(svgWidth - l1)/2, svgHeight/2];

const points = pointsTemplate.map(d => [d[0] + px, d[1] + py]);
const line = d3.line()
  .curve(d3.curveBasis);

/*svg.selectAll('circle')
  .data([...points, [px, py]])
  .enter()
  .append('circle')
  .attr('fill', 'black')
  .attr('stroke', 'black')
  .attr('r', 2)
  .attr('cx', d => d[0])
  .attr('cy', d => d[1]);

const f = d3.format('.0f');
svg.selectAll('text')
  .data([...points, [px, py]])
  .enter()
  .append('text')
  .text(d => `(${f(d[0])},${f(d[1])})`)
  .attr('x', d => d[0])
  .attr('y', d => d[1]);

svg.append('path')
  .datum(points)
  .attr('fill', 'none')
  .attr('stroke', 'black')
  .attr('d', d3.line()
    .curve(d3.curveBasis));

svg.append('path')
  .datum([[px, py], ...points, [px, py]])
  .attr('fill', 'none')
  .attr('stroke', 'black')
  .attr('d', d3.line())
  .attr('stroke-dasharray', '2 2');
*/

const path = svg.append('path')
    .attr('fill', 'none')
    .attr('stroke', 'black');
const dottedPath = svg.append('path')
  .attr('fill', 'none')
  .attr('stroke', 'black')
  .attr('stroke-dasharray', '2 2');
const update = (data) => {
  const circle = svg.selectAll('circle')
    .data(data);
  circle.exit().remove()
  circle.enter()
    .append('circle')
    .attr('fill', 'black')
    .attr('stroke', 'black')
    .attr('r', 2)
    .merge(circle)
    .attr('cx', d => d[0])
    .attr('cy', d => d[1]);

  path.datum(data)
    .attr('d', d3.line()
      .curve(d3.curveBasis));
  dottedPath.datum(data)
    .attr('d', d3.line())
};

const data = [];
svg.on('click', () => {
  const [x, y] = [d3.event.offsetX, d3.event.offsetY];
  data.push([x, y]);
  update(data);
});
