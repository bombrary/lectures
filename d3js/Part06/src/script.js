const [svgWidth, svgHeight] = [300, 300];
const svg = d3.select('svg')
  .attr('width', svgWidth)
  .attr('height', svgHeight);
svg.append('defs')
  .append('marker')
  .attr('id', 'arr')
  .attr('markerUnits', 'strokeWidth')
  .attr('markerWidth', 10)
  .attr('markerHeight', 10)
  .attr('orient', 'auto')
  .attr('refX', 2.2)
  .attr('refY', 0.5)
  .attr('viewBox', '0 0 1 1')
  .append('path')
  .attr('stroke', 'none')
  .attr('fill', '#000')
  .attr('d', 'M0,0 L1,0.5 0,1');

const nodes = [
  { id: 'A' },
  { id: 'B' },
  { id: 'C' },
];

const links = [
  { source: 'A', target: 'B' },
  { source: 'B', target: 'C' },
  { source: 'C', target: 'A' },
];


const linksGroup = svg.append('g');
const nodesGroup = svg.append('g');
const init = () => {
  const nodeGroup = nodesGroup.selectAll('g')
    .data(nodes);
  nodeGroup.exit().remove();
  const nodeGroupEnter = nodeGroup.enter()
    .append('g');
  nodeGroupEnter.append('circle')
    .attr('r', 10)
    .attr('fill', 'white')
    .attr('stroke', 'black');
  nodeGroupEnter.append('text')
    .attr('text-anchor', 'middle')
    .attr('dominant-baseline', 'central')
    .text(d => d.id);
  nodeGroupEnter.call(d3.drag()
      .on('start', dragstarted)
      .on('drag', dragged)
      .on('end', dragended));

  const linkGroup = linksGroup.selectAll('path')
    .data(links);
  linkGroup.exit().remove();
  linkGroup.enter()
    .append('path')
    .attr('fill', 'none')
    .attr('stroke', 'black')
}

const dragstarted = (d) => {
  if (!d3.event.active) simulation.alphaTarget(0.3).restart();
  d.fx = d.x;
  d.fy = d.y;
};
const dragged = (d) => {
  d.fx = d3.event.x;
  d.fy = d3.event.y;
};
const dragended = (d) => {
  if (!d3.event.active) simulation.alphaTarget(0).restart();
  d.x = d.fx;
  d.y = d.fy;
  d.fx = null
  d.fy = null;
};

const ticked = () => {
  nodesGroup.selectAll('g')
    .attr('transform', d => `translate(${d.x}, ${d.y})`);
  linksGroup.selectAll('path')
    .attr('d', d => {
      return `M${d.source.x},${d.source.y} L${d.target.x},${d.target.y}`;
    })
    .attr('marker-end', 'url(#arr)')
    .attr('stroke-dasharray', d => {
      const R = 10;
      const W = 10;
      const [sx, sy] = [d.source.x, d.source.y];
      const [tx, ty] = [d.target.x, d.target.y];
      const D = Math.sqrt((tx-sx)*(tx-sx) + (ty-sy)*(ty-sy));
      const DD = D - 2*R - W;
      return `0 ${R+3} ${DD-6} ${3+W+R}`;
    });
};

const simulation = d3.forceSimulation(nodes)
  .force('link', d3.forceLink(links).id(d => d.id))
  .force('forceX', d3.forceX(svgWidth/2))
  .force('forceY', d3.forceY(svgHeight/2))
  .force('charge', d3.forceManyBody().strength(-200))
  .on('tick', ticked)
init();

