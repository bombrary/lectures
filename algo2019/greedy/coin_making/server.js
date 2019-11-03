let http = require('http');
let server = http.createServer();

server.on('request', (req, res) => {
  res.writeHead('200, {'Content-Type': 'test/plain'});
  res.write('Hello, World\n');
  res.end();
});

server.listen(3000);
