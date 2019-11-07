const width = 800, height = 500;
const svg = d3.select('body')
  .append('svg')
  .attr('width', width)
  .attr('height', height);

let data = {
  "name": ["Exponentation by squaring", "繰り返し二乗法"],
  "color": "salmon",
  "children": [
    { 
      "name": ["Power of Matrix", "行列累乗"] ,
      "color": "steelblue"
    },
    { 
      "name": ["Modular Division", "modによる割り算"],
      "color": "salmon",
      "children": [{ "name": ["Combination", "組み合わせ計算"], "color": "salmon"}]
    },
  ]
};

root = d3.hierarchy(data)

let tree = d3.tree()
  .size([width, height-160]);
tree(root);

let g = d3.select('svg')
  .append('g')
  .attr('transform', 'translate(0, 80)');
let link = g.selectAll('.link')
  .data(root.descendants().slice(1))
  .enter()
  .append('path')
  .attr('class', 'link')
  .attr('d', (d) => 
    `M${d.x},${d.y} C${d.x},${d.y-100} ${d.parent.x},${d.parent.y+100} ${d.parent.x},${d.parent.y}`);
let node = g.selectAll('.node')
  .data(root.descendants())
  .enter()
  .append('g')
  .attr('class', 'node')
  .attr('transform', d => `translate(${d.x}, ${d.y})`);

let text_g = node.append('g');
text_g.selectAll('text')
  .data(d => d.data.name)
  .enter()
  .append('text')
  .attr('y', (d, i) => `${1.5*i}em`)
  .attr('font-size', '1.5em')
  .attr('fill-opacity', 0)
  .text(d => d);
text_g.each(function(d) {
  let bbox = this.getBBox();
  d.data.width = bbox.width + 25;
  d.data.height = bbox.height + 5;
});

node.append('rect')
  .attr('x', d => -d.data.width/2)
  .attr('y', d => -d.data.height)
  .attr('width', d => d.data.width)
  .attr('height', d => d.data.height)
  .attr('fill', d => d.data.color);
node.append('g')
  .attr('transform', d => `translate(0, ${-d.data.height/2 - 15})`)
  .selectAll('text')
  .data(d => d.data.name)
  .enter()
  .append('text')
  .attr('y', (d, i) => `${1.5*i}em`)
  .attr('font-size', '1.5em')
  .text(d => d);
