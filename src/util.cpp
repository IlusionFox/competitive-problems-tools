#include "util.h"

std::vector<std::string> split(const std::string& s, char delim)
{
    enum State { NONE, ESCAPED, TOKEN };
    enum State state = NONE;

    std::string temp = s + delim;
    int start = -1, count = 0;
    std::vector<std::string> tokens;

    for (size_t i = 0; i < temp.size(); ++i)
    {
        auto c = temp[i];

        switch (state) {
        case NONE:
            if (c == '\"')
            {
                state = ESCAPED;
                start = i + 1;
                count = 0;
            } else if (c != delim)
            {
                state = TOKEN;
                start = i;
                count = 1;
            }

        break;

        case ESCAPED:
            if (c == '\"')
                state = TOKEN;
            else 
                ++count;

        break;

        case TOKEN:
            if (c == delim)
            {
                if (count)
                    tokens.push_back(temp.substr(start, count));
                else
                    tokens.push_back("");

                count = 0;
                state = NONE;
            } else
                ++count;

        break;
        }
    }

    return tokens;
}

std::string strip(const std::string& s)
{
    int size = s.size();

    if (size < 1)
        return "";

    int i = -1, j = size;

    while (i < size and isspace(s[++i]));
    while (j > 0 and isspace(s[--j]));

    return j < i ? "" : s.substr(i, j - i + 1);
}

std::string strip(const std::string& s, char c)
{
    int size = s.size();

    if (size < 1)
        return "";

    int i = -1, j = size;

    while (i < size and s[++i] == c);
    while (j > 0 and s[--j] == c);

    return j < i ? "" : s.substr(i, j - i + 1);
}
