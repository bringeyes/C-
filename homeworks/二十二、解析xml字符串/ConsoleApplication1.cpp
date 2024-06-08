/*
函数原型：
 解析 xml 字符串。
xmlbuffer:待解析的 xml字符串。
 fieldname:字段名。
 value:字段的值。
 ilen:字段值的最大长度，超出ilen 的内容将会被丢弃，缺省取值 0，表示不限长度。
 注意，调用该函数的时候，必须保证 value 足够大，否则可会造成内存泄漏。
<bh>3</bh><name>西施</name><sex>女</sex><age>18</age><yz>漂亮</yz>
 bool xmlbuffer(const char* xmlbuffer, const char* fieldname, char* value, const size_t ilen =0);
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
using namespace std;

bool xmlbuffer(const char* xmlbuf, const char* fieldname, char* value, const size_t ilen = 0);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, char& value);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, unsigned char& value);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, int& value);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, unsigned int& value);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, long& value);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, unsigned long& value);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, long long& value);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, unsigned long long& value);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, float& value);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, double& value);
bool xmlbuffer(const char* xmlbuf, const char* fieldname, bool& value);

int main()
{
    //chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    //chrono::nanoseconds dt;     // 时间差
    //start = chrono::steady_clock::now();        // 开始计时
    //for (int i = 0; i < 1000000; i++) {             // 执行一百万次
    //    // 填入要测时的代码

    //}
    //end = chrono::steady_clock::now();          // 计时完成
    //dt = end - start;                                       // 计算时间差
    //cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    char xml[81] = "<bh>3</bh><name>西施</name><sex>X</sex><age>18.2</age><yz>true</yz>";
    cout << '=' << xml << '=' << endl;
    char value[21] = { 0 };
    xmlbuffer(xml, "name", value);
    cout << "name=" << value << '=' << endl;

    char value1 = 0;
    xmlbuffer(xml, "sex", value1);
    cout << "sex=" << value1 << '=' << endl;

    int value2 = 0;
    xmlbuffer(xml, "bh", value2);
    cout << "bh=" << value2 << '=' << endl;

    double value3 = 0;
    xmlbuffer(xml, "age", value3);
    cout << "age=" << value3 << '=' << endl;

    bool value4 = false;
    xmlbuffer(xml, "age", value4);
    cout << "yz=" << value4 << '=' << endl;
}

// <bh>3</bh><name>西施</name><sex>女</sex><age>18</age><yz>漂亮</yz>
bool xmlbuffer(const char* xmlbuf, const char* fieldname, char* value, const size_t ilen) {
    if (xmlbuf == 0 || fieldname == 0 || value == 0) return 0;       // 对形参进行合法性检查

    size_t f_len = strlen(fieldname);
    char* sfieldname = new char[f_len + 3];
    memset(sfieldname, 0, f_len + 3);
    strcpy(sfieldname,"<"); strcat(sfieldname, fieldname); strcat(sfieldname, ">");        // 拼接为<fieldname>
    char* p1 = (char*)strstr(xmlbuf, sfieldname) + f_len + 2;                    // 找到字段值的起始位置

    char* efieldname = new char[f_len + 4];
    memset(efieldname, 0, f_len + 4);
    strcpy(efieldname, "</"); strcat(efieldname, fieldname); strcat(efieldname, ">");           // 拼接为</fieldname>
    char* p2 = (char*)strstr(xmlbuf, efieldname);                                      // 找到字段值的结束位置

    if (p1 && p2) {
        if (ilen < p2 - p1 && ilen != 0) strncpy(value, p1, ilen);
        else strncpy(value, p1, p2 - p1);
        delete[] sfieldname; delete[] efieldname;
        return 1;
    }
    delete[] sfieldname; delete[] efieldname;
    return 0;       // 未找到字段
}

bool xmlbuffer(const char* xmlbuf, const char* fieldname, char& value) {    // 传递单个字符
    char tmpvalue[2];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 1) == true) {
        value = tmpvalue[0]; return true;
    }
    return false;
}

bool xmlbuffer(const char* xmlbuf, const char* fieldname, unsigned char& value) {   // 只是换了value，其他同上
    char tmpvalue[2];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 1) == true) {
        value = tmpvalue[0]; return true;
    }
    return false;
}

bool xmlbuffer(const char* xmlbuf, const char* fieldname, int& value) {
    char tmpvalue[21];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 20) == true) {
        value = atoi(tmpvalue); return true;
    }
    return false;
}

bool xmlbuffer(const char* xmlbuf, const char* fieldname, unsigned int& value) {
    char tmpvalue[21];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 20) == true) {
        value = atoi(tmpvalue); return true;
    }
    return false;
}

bool xmlbuffer(const char* xmlbuf, const char* fieldname, long& value) {
    char tmpvalue[21];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 20) == true) {
        value = atol(tmpvalue); return true;        // 改为atol()
    }
    return false;
}

bool xmlbuffer(const char* xmlbuf, const char* fieldname, unsigned long& value) {
    char tmpvalue[21];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 20) == true) {
        value = atol(tmpvalue); return true;        // 改为atol()
    }
    return false;
}

bool xmlbuffer(const char* xmlbuf, const char* fieldname, long long& value) {
    char tmpvalue[21];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 20) == true) {
        value = atoll(tmpvalue); return true;        // 改为atoll()
    }
    return false;
}

bool xmlbuffer(const char* xmlbuf, const char* fieldname, unsigned long long& value) {
    char tmpvalue[21];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 20) == true) {
        value = atoll(tmpvalue); return true;        // 改为atoll()
    }
    return false;
}

bool xmlbuffer(const char* xmlbuf, const char* fieldname, float& value) {
    char tmpvalue[21];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 20) == true) {
        value = atof(tmpvalue); return true;        // 改为atof()
    }
    return false;
}

bool xmlbuffer(const char* xmlbuf, const char* fieldname, double& value) {
    char tmpvalue[21];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 20) == true) {
        value = atof(tmpvalue); return true;        // 也改为atof()
    }
    return false;
}

// <yz>1</yz>       1-漂亮；      2-不漂亮
// <yz>true</yz>   true-漂亮； false-不漂亮
bool xmlbuffer(const char* xmlbuf, const char* fieldname, bool& value) {
    char tmpvalue[6];
    if (xmlbuffer(xmlbuf, fieldname, tmpvalue, 5) == true) {
        if (strcmp(tmpvalue, "1") == 0 || strcmp(tmpvalue, "true") == 0) value = true;      // strcmp() 返回两个字符串差值
        else value = false;
    }
    return false;
}