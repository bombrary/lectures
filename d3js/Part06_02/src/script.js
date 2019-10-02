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


const linksGroup = svg.append('g');
const nodesGroup = svg.append('g');
const adjustElements = (nodes, links) => {
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
const simulation = d3.forceSimulation()
  .force('link', d3.forceLink().id(d => d.id).distance(70))
  .force('forceX', d3.forceX(svgWidth/2))
  .force('forceY', d3.forceY(svgHeight/2))
  .force('charge', d3.forceManyBody().strength(-200))
  .on('tick', ticked);

const executeCmd = (c, i, j) => {
  const cmdMsg = d3.select('#cmd_msg');
  if (c === 0) {
    uf.unite(i, j);
    cmdMsg.text(`unite(${i}, ${j})`);
  } else {
    const res = uf.same(i, j);
    cmdMsg.text(`same(${i}, ${j}): ${res}`);
  }
};

const formatData = (uf) => {
  const nodes = [...Array(uf.par.length)].map((_, i) => Object({ id: i }));
  const links = uf.par.map((p, i) => Object({ source: i, target: p }));
  return { nodes, links };
};

const bindToSimulation = (simulation, nodes, links) => {
  const oldNodes = simulation.nodes();
  for (let i = 0; i < nodes.length; i++) {
    if (i < oldNodes.length) {
      nodes[i].x = oldNodes[i].x;
      nodes[i].y = oldNodes[i].y;
    }
  }
  simulation.nodes(nodes);
  simulation.force('link').links(links);
  simulation.alpha(1).restart();
};

const updateCmdInfo = (data) => {
  const li = d3.select('ul')
    .selectAll('li')
    .data(data);
  li.exit().remove();
  li.enter()
    .append('li')
    .merge(li)
    .text(d => d);
};

const displayUnionFind = (uf) => {
    const { nodes, links } = formatData(uf);
    bindToSimulation(simulation, nodes, links);
    adjustElements(nodes, links);
};

let itr = new Iterator([]);
let uf = new UnionFind(0);
d3.select('#load_btn')
  .on('click', () => {
    const input = d3.select('textarea')
      .property('value')
      .split('\n')
      .map(d => d.split(' '))
      .map(d => d.map(e => Number(e)));
    itr = new Iterator(input.slice(1));
    uf = new UnionFind(input[0][0]);

    displayUnionFind(uf);
    updateCmdInfo(itr.rest());
  });


d3.select('#step_btn')
  .on('click', () => {
    if (itr.hasNext()) {
      executeCmd(...itr.now());
      itr.next();
      displayUnionFind(uf);
      updateCmdInfo(itr.rest());
    }
  });

let timer;
const playBtn = d3.select('#play_btn');
const stopBtn = d3.select('#stop_btn')
  .property('disabled', true);
playBtn.on('click', () => {
    playBtn.property('disabled', true);
    stopBtn.property('disabled', false);
    timer = d3.interval(() => {
      if (itr.hasNext()) {
        executeCmd(...itr.now());
        itr.next();
        displayUnionFind(uf);
        updateCmdInfo(itr.rest());
      } else {
        timer.stop();
        playBtn.property('disabled', false);
        stopBtn.property('disabled', true);
      }
    }, 500);
  });
stopBtn.on('click', () => {
  timer.stop();
  playBtn.property('disabled', false);
  stopBtn.property('disabled', true);
});

const testcase = `5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0`;
d3.select('textarea')
  .property('value', testcase);
