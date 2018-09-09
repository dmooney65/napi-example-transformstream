
const { Transform } = require('stream');
const TransformStream = require('bindings')('napi-transformstream').TransformStream;
const inherits = require('util').inherits;

let defaultOpts = {
    optionNum: 1
}

inherits(TransformStream, Transform)

class TransformWrapper extends Transform {

    constructor(opts) {
        opts = opts || defaultOpts;
        super(opts);
        this._transform = new TransformStream(opts);
    }

    write(chunk) {
        var data = this._transform.transform(chunk);
        this.push(data);
    }
}

module.exports = TransformWrapper;

