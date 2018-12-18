#ifndef WEBTEST_WEBTEST_H
#define WEBTEST_WEBTEST_H

#include <string>
#include <map>
#include <vector>

using namespace std;

typedef map<string, int> seq_count;

class WebTest {
public:
    ~WebTest();
    WebTest(const char* file_name1);

    vector<string> m_seq;
    seq_count m_seq_count;
};

#endif
