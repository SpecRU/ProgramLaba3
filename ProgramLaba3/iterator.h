#include "map.h"

template<class T>
class Iteratorclass {
private:
    const T* item;
    size_t ind;
public:;
    Iteratorclass(const T&) noexcept;
    Iteratorclass<T>& operator++();
    Iteratorclass<T>& operator--();
    const auto& first() const;
    const auto& second() const;
    void advanceIt(int izm) noexcept;
};

template<class T>
Iteratorclass<T>::Iteratorclass(const T& item) noexcept
    : item(&item), ind(0) {
}

template<class T>
Iteratorclass<T>& Iteratorclass<T>::operator++(){
    if (ind >= item->key.size()) throw -1;
    else ++ind;
    return *this;
}

template<class T>
Iteratorclass<T>& Iteratorclass<T>::operator--(){
    if (ind-1 < 0) throw -1;
    else --ind;
    return *this;
}

template<class T>
const auto& Iteratorclass<T>::first() const{
    if (ind >= item->key.size()) throw -1;
    return item->key[ind];
}

template<class T>
const auto& Iteratorclass<T>::second() const{
    if (ind >= item->value.size()) throw -1;
    return item->value[ind];
}

template<class T>
void Iteratorclass<T>::advanceIt(int izm) noexcept{
    ind += izm;
}