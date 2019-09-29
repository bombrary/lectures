const [svgWidth, svgHeight] = [800, 1000];
const svg = d3.select('svg')
  .attr('width', svgWidth)
  .attr('height', svgHeight);
const svgPad = 50;
const rectPad = 10;
const linksGroup = svg.append('g')
  .attr('transform', `translate(${svgPad}, ${svgPad})`);
const nodesGroup = svg.append('g')
  .attr('transform', `translate(${svgPad}, ${svgPad})`);

const update = (data) => {
  const root = d3.hierarchy(data);
  const tree = d3.tree()
    .size([svgWidth-2*svgPad, svgHeight-2*svgPad]);
  tree(root);

  const node = nodesGroup.selectAll('g')
    .data(root.descendants());
  node.exit().remove();
  const nodeEnter = node.enter()
    .append('g');
  nodeEnter.append('rect');
  nodeEnter.append('text');
  
  const nodeMerge = nodeEnter.merge(node)
    .attr('transform', d => `translate(${d.x}, ${d.y})`);
  nodeMerge.select('rect')
    .attr('fill', d => d.data.kind === 'op' ? 'lightgray' : 'white')
    .attr('stroke', 'black');

  const tspan = nodeMerge.select('text')
    .selectAll('tspan')
    .data(d => {
      if (d.data.kind === 'op') return  [d.data.kind, d.data.str]
      else return [d.data.kind, d.data.str, d.data.value];
    });
  tspan.exit().remove();
  tspan.enter()
    .append('tspan')
    .merge(tspan)
    .attr('text-anchor', 'middle')
    .attr('x', 0)
    .attr('dy', '1em')
    .attr('y', (d, i) => `${1.5*i}em`)
    .text(d => d);

  nodeMerge.each((d, i, node) => {
    const bbox = d3.select(node[i])
      .select('text')
      .node()
      .getBBox();
    const width = bbox.width + 2*rectPad;
    const height = bbox.height + 2*rectPad;
    d3.select(node[i])
      .select('text')
      .attr('transform', `translate(0, ${-bbox.height/2})`);
    d3.select(node[i])
      .select('rect')
      .attr('x', -width/2)
      .attr('y', -height/2)
      .attr('width', width)
      .attr('height', height);
  });

  const link = linksGroup.selectAll('path')
    .data(root.links());
  link.exit().remove()
  const linkEnter = link.enter()
    .append('path');
  const linkMerge = linkEnter.merge(link);
  linkMerge.attr('fill', 'none')
    .attr('stroke', 'black')
    .attr('d', d3.linkVertical()
      .x(d => d.x)
      .y(d => d.y));
};

const p = new Parser();
console.log(p.parse('(12/3)+4*(5+2)'));
update(p.parse('(12/3)+4*(5+2)'));

d3.select('#gen_btn')
  .on('click', () => {
    const input = d3.select('textarea').property('value');
    update(p.parse(input));
  });
