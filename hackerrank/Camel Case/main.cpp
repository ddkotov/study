#include <iostream>
#include <string>
#include <cassert>
#include <locale>

void processSplit(std::string data)
{
    std::string ret;

    for (auto& d : data)
    {
        if (d == '\r')
            continue;
        if (d == '(')
            break;
        if (isupper(d))
        {
            if (!ret.empty())
                ret += ' ';
            ret += tolower(d, std::locale());
        }
        else
        {
            ret += d;
        }
    }
    std::cout << ret << "\n";
}

void processCombine(std::string data, char data_type)
{
    std::string ret;
    bool is_need_toupper = false;
    for (auto& d : data)
    {
        if (d == '\r')
            continue;
        if (is_need_toupper)
        {
            ret += toupper(d, std::locale());
            is_need_toupper = false;
        }
        else
            if (d == ' ')
            {
                is_need_toupper = true;
            }
            else
            {
                ret += d;
            }
    }
    if (data_type == 'M')
        ret += "()";
    if (data_type == 'C')
    {
        char temp = ret.at(0);
        ret.at(0) = toupper(temp, std::locale());
    }

    std::cout << ret << "\n";
}

int main()
{
    std::string input_line;

    while (std::getline(std::cin, input_line))
    {
        assert(input_line.size() > 5 && "bad input line size");

        char operation_type = input_line.at(0);
        char words = input_line.at(2);

        assert(words == 'C' || words == 'M' || words == 'V' && "bad input type");

        operation_type == 'S' ?
            processSplit(std::string(input_line.begin() + 4, input_line.end())) :
            operation_type == 'C' ?
            processCombine(std::string(input_line.begin() + 4, input_line.end()), words) :
            assert(false && "bad input command");
        input_line.clear();
    }
}