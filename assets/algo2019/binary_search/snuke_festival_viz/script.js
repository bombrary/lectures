const container = d3.select('svg')
                  .append('g')
                  .attr('transform', 'translate(30, 30)');

const createArrSVG = (a, name, y) => {
  const [w, h] = [50, 50];
  const arr = container.append('g')
  arr.append('text')
       .attr('transform', `translate(0, ${y})`)
       .text(`${name}: `);
  const elems = arr.append('g')
                      .attr('transform', `translate(30, ${y})`)
                      .selectAll('g')
                      .data(a)
                      .enter()
                      .append('g')
                      .attr('transform', (d, i) => `translate(${w*i}, 0)`);
  elems.append('rect')
        .attr('width', w)
        .attr('height', h)
        .attr('fill', 'white')
        .attr('stroke', 'black')
  elems.append('text')
        .attr('x', w/2)
        .attr('y', h/2)
        .attr('text-anchor', 'middle')
        .attr('dominant-baseline', 'central')
        .text((d) => d);
};

const textarea = d3.select('body').select('textarea');
d3.select('input#btn')
  .on('click', () => {
    //const arrs = textarea.property('value')
    //               .split('\n')
    //               .map((e1) => 
    //                 e1.split(' ')
    //                  .map((e2) => Number(e2))
    //               );
    //createArrSVG(arrs[1], 'A', 0);
    //createArrSVG(arrs[2], 'B', 100);
    //createArrSVG(arrs[3], 'C', 200);
    const rand20 = d3.randomUniform(1, 21);
    const arrs = [[], [], []];
    for (let i = 0; i < 15; i++) {
      arrs[0].push(Math.floor(rand20()));
      arrs[1].push(Math.floor(rand20()));
      arrs[2].push(Math.floor(rand20()));
    }
    arrs[0].sort((a, b)=>a-b);
    arrs[2].sort((a, b)=>a-b);
    createArrSVG(arrs[0], 'A', 0);
    createArrSVG(arrs[1], 'B', 200);
    createArrSVG(arrs[2], 'C', 400);
  });
