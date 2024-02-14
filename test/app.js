const http = require('http');

const server = http.createServer((req,res) => {
    console.log('Server request');
    console.log(req.url,req.method);
    res.setHeader('Content-Type','application/json');
    const data = JSON.stringify ([
        {name: 'Bob', id : 1},
        {name: 'Mark', id : 2},
    ])
    res.end(data);
});

const Port = 3000;

server.listen(Port,(error) => {
    error ? console.log(error) : console.log(`listening port ${Port}`);
});


