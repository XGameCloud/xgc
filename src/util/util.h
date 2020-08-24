/// 2020/08/24 zhangzhong
/// util.h

#include <type_traits>

namespace xgc
{
    /// enumeration cast 
    template <typename Enumeration>
    auto enumeration_cast(Enumeration enumerator)
    {
        return static_cast<std::underlying_type_t<Enumeration>>(enumerator);
    }
}