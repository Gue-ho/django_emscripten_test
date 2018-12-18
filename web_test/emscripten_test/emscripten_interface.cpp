#include <emscripten.h>
#include <string>
#include <vector>
#include "webtest.h"

extern "C" {
    void report_result(WebTest $wt, string wtseq, int wtcnt) {
        int i, j;
        for (i = 0; i < $wt.m_seq.size(); i++) {
            EM_ASM_({
                rtnval['seq_count'].push([Pointer_stringify($0), $1]);
            }, $wt.m_seq[i].c_str(), $wt.m_seq_count[$wt.m_seq[i]]);
        }
        EM_ASM_({
            rtnval['info'].push([Pointer_stringify($0), $1]);
        }, wtseq.c_str(), wtcnt);
    }

    void run_webtest(char* file_name1, char* file_name2, char* file_name3, char* file_name4, char* wtseq, int wtcnt) {
        
        WebTest wt = WebTest((string("/data/")+string(file_name1)).c_str());
        report_result(wt, wtseq, wtcnt);

    }
};
