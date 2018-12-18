#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <set>
#include <functional>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "webtest.h"
#include "be_fastq-lib.h"

using namespace std;


WebTest::WebTest(const char* file_name) {
    int linecnt;
    
    struct fq * entry;
    meminit(entry);

    FILE* fp;
    fp = fopen(file_name, "r");
    setvbuf(fp, NULL, _IOFBF, 4194304);
    struct stat * st;
    stat(file_name, st);
    double total_size = (double)st->st_size;
    while (read_fq(fp, linecnt++, entry)) {
        string strseq=entry->seq.s;
        if (m_seq_count.find(strseq) == m_seq_count.end()) {
            m_seq_count[strseq] = 1;
            m_seq.push_back(strseq);
        } else {
            m_seq_count[strseq] ++;
        }
    }
    fclose(fp);
}

WebTest::~WebTest() {
}
