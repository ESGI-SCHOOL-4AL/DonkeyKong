#ifndef INSTANCE_OF_HELPER_HPP
#define INSTANCE_OF_HELPER_HPP

#include <type_traits>

template<typename Base, typename T>
inline bool InstanceOf(const T*) {
   return std::is_base_of<Base, T>::value;
}

#endif