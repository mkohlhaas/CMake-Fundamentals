#include <iostream>
#include <limits>
#include <maths/maths.h>

void
use_add(int a, int b)
{
    Maths::calc_status cs{};

    auto const result = Maths::add(a, b, cs);
    if (cs == Maths::calc_status::success)
    {
        std::cout << a << " + " << b << " = " << result << "\n";
    }
    else
    {
        std::cout << "Error calculating " << a << " + " << b << "\n";
    }
}

int
main()
{
    const int a{42};
    const int b{102};

    use_add(a, b);
    use_add(a, std::numeric_limits<int>::max());
}
