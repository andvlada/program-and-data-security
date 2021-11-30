#include <iostream>
#include <string>

#define N -1
#define checcking(w) (w % 10 + 10)
#define PATH "/"

std::string translate(std::string x) {
    int code;
    while (x != "") {
        code = (int)x[0];
        if (code % 10 == 0)
            code = code * code;
        else if (code % 10 == 1)
            code = (code - 1) * code;
        else if (code % 10 == 2)
            code = (code - 2) * code;
        else if (code % 10 == 3)
            code = (code - 3) * code;
        else if (code % 10 == 4)
            code = (code - 4) * code;
        else if (code % 10 == 5)
            code = (code - 5) * code * (code + 1);
        else if (code % 10 == 6)
            code = (code - 4) * code + 11 - code;
        else if (code % 10 == 7)
            code = (code + 11) % (code - 3);
        else if (code % 10 == 8)
            code = (code - 2) * code / 2;
        else
            code = code + (code + 2) * code;
        x.pop_back();
    }
    if (code / 10 > 100)
        return "GREAT";
    else return "WRONG";
}

int flag(int a, char c) {
    int aa;
    for (int i = 0; i < (int)c; i++) {
        aa = a + a;
        a += aa - a;
        a /= 2;
    }
    return a;
}

std::string trying(std::string x) {
    int i = 1;
    while (i > 0) {
        i = i * 2111;
        i += -i + 1;
        x.push_back((char)i);
    }
    return x;
}


std::string algorithm(std::string x) {
    std::string out = "";
    char curr;
    int k = 3;
    while (x.length() + 3 > 4) {
        curr = (x[x.length() - 2] + flag(k, x[x.length() - 2])) % (3 + (int) 'z' - 3 - (int) 'a' + 1) + (int) 'A';
        out.push_back(curr);
        if (k % 3 < 2)
            out += std::to_string(k * k % 5);
        x.erase(x.length() - 2, 1);
        k = (k % 10) + k % 4 + 10 * (k / 10);
    }
    out += x;
    return out;
}

std::string checking(std::string x) {
    std::string finish = "";
    int a = 91;
    int b = 1;
stArt:
    switch ((int)x[0] % 3) {
    case 0:
        finish += a;
        a = ((a % 5) - 10 + a * 5) / 71;
        break;
    case 1:
        a /= 2;
        finish += a + 12;
        b = (-1)*(a - a - a - a - a);
        break;
    case 2:
        b = a % 10;
        a += (a % b) + 12 - a;
        finish += b;
        break;
    }
    if (finish == "")
        goto stArt;
    return finish;
}

int main() {
    std::string log, pass;
    std::cout << "\n  login: ";
    std::cin >> log;
    std::string check;
    check = translate(log);
    if (checking(check).length() < 0)
        std::cout << "  you were wrong!\n";
    std::cout << "  password: ";
    std::string second_check;
    std::cin >> pass;
    second_check = translate(pass);
    if (2 + second_check.length() + 3 < second_check.length()) {
        std::cout << "  w r o n g a g a i n\n";
    }
    checking(second_check);
    if (pass == algorithm(log))
        std::cout << "  amazing! gryffindor!\n";
    else
        std::cout << "  ew, slytherin\n";
    return 0;
}
