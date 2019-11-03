
function makeCombString(r, c) {
  let ret = [];
  for (let i = 0; i < r; i++) {
    ret.push([]);
    for (let j = 0; j <= i; j++) {
      ret[i].push([i, j]);
    }
  }
  return ret;
}

function makeComb(r, c) {
  let ret = [];
  for (let i = 0; i < r; i++) {
    ret.push([]);
    if (i == 0) {
      ret[i].push(1); 
      continue;
    }
    for (let j = 0; j <= i; j++) {
      if (j == 0 || j == i) ret[i].push(1);
      else ret[i].push(ret[i - 1][j - 1] + ret[i - 1][j]);
    }
  }
  return ret;
}

d3.select('body')
  .append('div')
  .attr('class', 'flex-container');

const table2 = d3.select('body')
  .select('div.flex-container')
  .append('table')
table2.append('tbody')
  .selectAll('tr')
  .data(makeComb(10, 10))
  .enter()
  .append('tr')
  .selectAll('td')
  .data(d => d)
  .enter()
  .append('td')
  .text(d => `\\(\\large ${d}\\)`)
  .style('padding', '6px')

const table1 = d3.select('body')
  .select('div.flex-container')
  .append('table')
table1.append('tbody')
  .selectAll('tr')
  .data(makeCombString(10, 10))
  .enter()
  .append('tr')
  .selectAll('td')
  .data(d => d)
  .enter()
  .append('td')
  .text(d => `\\(\\large_${d[0]}C_${d[1]}\\)`)
  .style('padding', '5px')

