#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <tuple>
#include <vector>

namespace std {
// Overloading for easier display pairs of ints and strings
ostream& operator<<(ostream& os, const pair<int, string>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
}
int main() {
    std::vector<std::pair<int, std::string>> v {
        {1, "one"}, {2, "two"}, {3, "three"},
        {4, "four"}, {5, "five"}, {6, "six"}
    };

    std::map<int, std::string> m;

    std::copy_n(std::begin(v), 3, std::inserter(m, std::begin(m)));

    auto shell_it = std::ostream_iterator<std::pair<int, std::string>>(std::cout, ", ");

    std::copy(std::begin(m), std::end(m), shell_it);
    std::cout << '\n';
}