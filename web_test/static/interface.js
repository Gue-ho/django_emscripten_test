var worker_1;

function main() {
    var file1 = $('#file1')[0].files[0];
    var file2 = $('#file2')[0].files[0];
    var file3 = $('#file3')[0].files[0];
    var file4 = $('#file4')[0].files[0];
    var seq = $('#seq').val();
    var cnt = $('#cnt').val();

    var worker_1 = new Worker("/static/worker.js");

    worker_1.onmessage = function (msg) {
        var e = msg.data;
        var s = '<tr><td>'+e[1].info[0]+'</td><td>'+String(e[1].info[1])+'</td></tr>';
        for (var i = 0; i<e[1].seq_count.length; i++) {
            s+='<tr><td>'+e[1].seq_count[i][0]+'</td><td>'+String(e[1].seq_count[i][1])+'</td></tr>'
        }
        $('.input-output').html(String(s));
        
    }

    worker_1.postMessage([file1, file2, file3, file4, seq, cnt]);

};


