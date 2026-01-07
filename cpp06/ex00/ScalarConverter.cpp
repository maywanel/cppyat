#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & other) {
	if (this != &other) {}
	return (*this);
}
ScalarConverter::~ScalarConverter() {}


static int ft_stoi(const std::string& str) {
    char* end;
    long val = std::strtol(str.c_str(), &end, 10);
    if (end == str.c_str()) throw std::invalid_argument("invalid_argument");
    if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min()) throw std::out_of_range("out_of_range");
    return static_cast<int>(val);
}

static float ft_stof(const std::string& str, size_t* pos = NULL) {
    char* end;
    errno = 0;
    double val = std::strtod(str.c_str(), &end);
    if (end == str.c_str()) throw std::invalid_argument("invalid_argument");
    if (errno == ERANGE) throw std::out_of_range("out_of_range");
    if (pos) *pos = end - str.c_str();
    return static_cast<float>(val);
}

static double ft_stod(const std::string& str, size_t* pos = NULL) {
    char* end;
    errno = 0;
    double val = std::strtod(str.c_str(), &end);
    if (end == str.c_str()) throw std::invalid_argument("invalid_argument");
    if (errno == ERANGE) throw std::out_of_range("out_of_range");
    if (pos) *pos = end - str.c_str();
    return val;
}

static std::string ft_to_string(int val) {
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

static std::string ft_to_string(float val) {
    std::ostringstream oss;
    oss << std::fixed << val;
    return oss.str();
}

static std::string ft_to_string(double val) {
    std::ostringstream oss;
    oss << std::fixed << val;
    return oss.str();
}

std::string isPrintableChar(std::string input) {
	int i = 0;
	try {
		i = ft_stoi(input);
	} catch (std::out_of_range &e) {
		return ("oof");
	} catch(const std::exception& e){
		std::cerr << e.what() << '\n';
		return ("Nan");
	}
	char c = static_cast<char>(i);
	if (std::isprint(c))
		return (std::string("'") + c + std::string("'"));
	else
		return ("Non displayable");
}

std::string isInt(std::string input) {
	try {
		int num = ft_stoi(input);
		return ft_to_string(num);
		} catch (...) {
			return "Nan";
	}
}

std::string isFloat(std::string input) {
	try {
		float fl = ft_stof(input);
		return (ft_to_string(fl).substr(0, ft_to_string(fl).find('.') + 2) + "f");
	} catch (...) {
		return "Nan";
	}
}

std::string isDouble(std::string input) {
	try {
		double dbl = ft_stod(input);
		return (ft_to_string(dbl).substr(0, ft_to_string(dbl).find('.') + 2));
	} catch (...) {
		return "Nan";
	}
}

void ScalarConverter::convert(std::string input) {
	try
	{
		size_t pos;
		ft_stof(input, &pos);
		if ((pos != input.length() && pos != input.length() - 1)
			|| (pos == input.length() - 1
			&& input[pos] != 'f'
			&& input[pos] != 'F')) {
				return (std::cout << "This is not a valid input" << std::endl, void());
		}
	}
	catch(const std::exception& e)
	{
		return (std::cout << "This is not a valid input" << std::endl, void());
	}

	if (input.compare("nan") == 0 || input.compare("nanf") == 0
		|| input.compare("inf") == 0 || input.compare("inff") == 0
		|| input.compare("+inf") == 0 || input.compare("+inff") == 0
		|| input.compare("-inf") == 0 || input.compare("-inff") == 0) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << input << std::endl;
			std::cout << "double: " << input << std::endl;
			return;
	}

	std::cout << "Input: " << input << std::endl;
	std::cout << "char: " << isPrintableChar(input) << std::endl;
	std::cout << "int: " << isInt(input) << std::endl;
	std::cout << "float: " << isFloat(input)<< std::endl;
	std::cout << "double: " << isDouble(input)<< std::endl;
}