const data = [100, 1, 2, 3, 14, 15, 58, 58, 58, 29];
data.sort((a, b) => a - b);

const svg = d3.select('body')
  .append('svg')
  .attr('width', 800)
  .attr('heght', 800)

const circle = svg.append('g')
  .attr('transform', 'translate(100, 100)')
  .selectAll('g')
  .data(data);

circle.enter()
  .append('circle')
  .attr('r', d => Math.log(d) + 15)
  .attr('cx', (d, i) => 45*i)
  .attr('fill', 'white')
  .attr('stroke', 'black');

circle.enter()
  .append('text')
  .attr('x', (d, i) => 45*i)
  .attr('dy', 5)
  .attr('text-anchor', 'middle')
  .attr('dominant-baseline', 'center')
  .text(d => d);
