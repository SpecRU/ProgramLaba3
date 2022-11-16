#include <vector>
#include <algorithm>
#include <list>

template <class T>
class Iteratorclass;
template <class L, class R>
class Map{
private:
    std::vector<L> key;
    std::vector<R> value;

    template<class T>
    size_t findind(const std::vector<T>& vec,const T& el) const noexcept;
public:
    Map() noexcept;
    Map(const Map& obj) noexcept;
    Map(Map&& obj) noexcept;
    ~Map() noexcept;
    const R& at(const L& key) const;
    void add(const L& key, const R& value);
    std::list<L> keys() noexcept;
    size_t size() const noexcept;
    template <class Lt, class Rt>
    friend bool operator==(Map<Lt, Rt> A, Map<Lt, Rt> B);
    template <class Lt, class Rt>
    friend bool operator!=(Map<Lt, Rt> A, Map<Lt, Rt> B);
    const R& operator[](const L& key) const noexcept;
    void clear() noexcept;
    void deleteEl(const L& key);
    R& valueMap(const L& key,const R& defvalue) const noexcept;
    std::string toJSON() const;

    friend class Iteratorclass<Map<L, R>>;
};

template<class L, class R>
template<typename T>
size_t Map<L, R>::findind(const std::vector<T>& vec,const T& el) const noexcept{
    for (int i = 0; i != vec.size(); i++){
        if (vec[i] == el) return i;
    }
    return this->size();
}

template <class L, class R>
Map<L, R>::Map() noexcept{
}

template <class L, class R>
Map<L, R>::Map(const Map<L, R>& obj) noexcept{
    key = obj.key;
    value = obj.value;
}

template<class L, class R>
Map<L, R>::Map(Map<L, R> &&obj) noexcept {
    key = obj.key;
    value = obj.value;
}

template <class L, class R>
Map<L, R>::~Map() noexcept{
    key.clear();
    value.clear();
}

template<class L, class R>
const R& Map<L, R>::at(const L& key) const {
    auto ind = std::find(this->key.begin(), this->key.end(), key);
    if (ind == this->key.end()){
        throw -1;
    }
    return this->value[findind(this->key, key)];
}
template <class L, class R>
void Map<L, R>::add(const L& key,const R& value){
    auto ind = std::find(this->key.begin(), this->key.end(), key);
    if (ind != this->key.end()){
        this->value[findind<L>(this->key, key)] = value;
    } 
    else {
        this->value.push_back(value);
        this->key.push_back(key);
    }
}
template <class L, class R>
std::list<L> Map<L, R>::keys() noexcept{
    std::list<L> l(key.begin(), key.end());
    return l;
}
template<class L, class R>
size_t Map<L, R>::size() const noexcept{
    return value.size();
}

template<class L, class R>
const R& Map<L, R>::operator[](const L& key) const noexcept{
    return at(key);
}

template<class L, class R>
void Map<L, R>::clear() noexcept {
    value.clear();
    key.clear();
}


template<class Lt, class Rt>
inline bool operator==(Map<Lt, Rt> A, Map<Lt, Rt> B) {
    std::list<Lt> result;
    std::list<Lt> Al = A.keys();
    std::list<Lt> Bl = B.keys();
    std::set_difference(Al.begin(), Al.end(), Bl.begin(), Bl.end(), std::inserter(result, result.end()));

    if (A.size() != B.size() || result.size() > 0)
        return false;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i])
            return false;
    }
    return true;
}

template<class Lt, class Rt>
inline bool operator!=(Map<Lt, Rt> A, Map<Lt, Rt> B)
{
    return !operator==(A, B);
}


template<class L, class R>
void Map<L, R>::deleteEl(const L& key){
    auto ind = std::find(this->key.begin(), this->key.end(), key);
    if (ind == this->key.end()) throw -1;
    else {
        int indk = findind(this->key, key);
        this->key.erase(this->key.begin() + indk - 1);
        this->value.erase(this->value.begin() + indk - 1);
    }
}

template<class L, class R>
R& Map<L, R>::valueMap(const L& key, const R& defvalue) const noexcept {
    if(std::find(this->key.begin(), this->key.end(), key) != this->key.end()) return value[findind(this->key, key)];
    return defvalue;
}

template<class R, class L>
std::string Map<R, L>::toJSON() const {
    std::string json = "{";
    for (int i=0; i < size(); i++){
        json += "\"";
        json += std::to_string(key[i]);
        json += "\"";
        json += ":";
        json += "\"";
        json += std::to_string(value[i]);
        json += "\"";
        if (i!= size()-1) json += ",";
    }
    json += "}";
    return json;
}