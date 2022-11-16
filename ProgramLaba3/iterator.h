#include "map.h"

template<class T>
class Iteratorclass {
private:
    const T* obj;
    size_t ind;
public:;
    Iteratorclass(const T&) noexcept;
    Iteratorclass<T>& operator++();
    Iteratorclass<T>& operator--();
    const auto& first() const noexcept;
    const auto& second() const noexcept;
    void advanceIt(int izm) noexcept;
};

template<class T>
Iteratorclass<T>::Iteratorclass(const T& obj) noexcept
    : obj(&obj), ind(0) {
}

template<class T>
Iteratorclass<T>& Iteratorclass<T>::operator++(){
    if (ind+1 > obj->key.size()) throw -1;
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
const auto& Iteratorclass<T>::first() const noexcept{
    return obj->key[ind];
}

template<class T>
const auto& Iteratorclass<T>::second() const noexcept{
    return obj->value[ind];
}

template<class T>
void Iteratorclass<T>::advanceIt(int izm) noexcept{
    ind += izm;
}