const d3 = require('d3');
const jsdom = require('jsdom');
const { JSDOM } = jsdom;

let data = [1, 5, 10];

const document = new JSDOM().window.document;
const size = {
  width: 100,
  height: 20 
};
const svg = d3.select(document.body)
              .append('svg')
              .attr("xmlns",'http://www.w3.org/2000/svg')
              .attr('width', size.width)
              .attr('height', size.height)
              .style('background-color', "#363b44");
svg.selectAll('circle')
  .data(data)
  .enter()
  .append('circle')
  .attr('r', d => d + 5)
  .attr('fill', 'white')
  .attr('stroke', 'black')
  .attr('cx', (d, i) => 50*i)
  .attr('cy', 10);

console.log(document.body.innerHTML)

