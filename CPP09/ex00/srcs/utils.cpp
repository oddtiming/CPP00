#include "bitcoin.hpp"

template<typename T>
std::string ft_to_string(T const & value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}
template string ft_to_string<int>(int const& value);
template string ft_to_string<uint>(uint const& value);
template string ft_to_string<long>(long const& value);

float ft_stof(string s) {
    float i;
    std::istringstream(s) >> i;
    return i;
}
