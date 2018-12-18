importScripts('webtest-core.js')

const prefix = '/data';

var rtnval={};

onmessage = function (msg) {
    var e = msg.data;
    var test = Module.cwrap('run_webtest', 'number', ['string', 'string', 'string', 'string', 'string', 'number']);
    
    rtnval['seq_count'] = [];
    rtnval['info'] = [];

    try {
        FS.unmount(prefix);
    } catch(err) {}
    try {
        FS.rmdir(prefix);
    } catch(err) {}
    FS.mkdir(prefix);

    FS.mount(WORKERFS, {
        files: [e[0], e[1], e[2], e[3]]
    }, prefix);
    test(e[0].name, e[1].name, e[2].name, e[3].name, e[4], e[5]);
    postMessage([1, rtnval]);
};

console.log("Worker loaded!");
