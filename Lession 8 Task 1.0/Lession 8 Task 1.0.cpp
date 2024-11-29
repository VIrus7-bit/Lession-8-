#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix {
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;

    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {
    };

    ~tridiagonal_matrix() {
        std::cout << "destructor called\n";
    }

    std::unique_ptr<tridiagonal_matrix> clone() const {
        return std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
    }
};

int main() {

    using namespace std;
    setlocale(LC_ALL, "Rus");

    auto down = vector<double>{ -4.0, 5.0 };
    auto upper = vector<double>{ 14.0, 8.0 };
    auto middle = vector<double>{ 3.0, 1.0, 7.0 };

    auto matrix = make_unique<tridiagonal_matrix>(down, upper, middle);

    auto matrix_clone = matrix->clone();

    std::cout << "matrix_clone created successfully\n";

    return EXIT_SUCCESS;
}