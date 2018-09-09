const Transform = require('./index.js');
const fs = require('fs');

const trans = new Transform();

if(process.argv[2] === undefined || process.argv[3] === undefined ){
    throw 'Usage "node example.js infile outfile"'
} 

var rs = fs.createReadStream(process.argv[2]);
var ws = fs.createWriteStream(process.argv[3]);


trans.on('pipe', () => {
    console.log('PIPE Event')
});
trans.on('unpipe', () => {
    console.log('UNPIPE Event')
});
trans.on('finish', () => {
    console.log('FINISH Event')
});
trans.on('error', () => {
    console.log('ERROR Event')
});
trans.on('end', () => {
    console.log('END Event')
});


rs.pipe(trans).pipe(ws);

