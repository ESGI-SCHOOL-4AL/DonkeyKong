#ifndef INSTANCE_OF_HELPER_H
#define INSTANCE_OF_HELPER_H

template<typename Base, typename T>
inline bool instanceof(const T*) {
   return is_base_of<Base, T>::value;
}

#endif