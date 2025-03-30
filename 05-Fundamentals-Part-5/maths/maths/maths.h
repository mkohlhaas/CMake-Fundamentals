#pragma once

#include <add/calc_status.h>

namespace Maths
{
    using Add::calc_status;

    int add(int l, int r, calc_status &cs) noexcept;
    int subtract(int l, int r, calc_status &cs) noexcept;

} // namespace Maths
