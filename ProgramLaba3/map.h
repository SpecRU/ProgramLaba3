#include <vector>
#include <algorithm>
#include <list>

template <class T>
class Iteratorclass;
template <class K, class V>
class Map {
private:
    std::vector<K> key;
    std::vector<V> value;

    template<class T>
    size_t findind(const std::vector<T>& vec,const T& A) const noexcept;
public:
    Map() noexcept;
    Map(const Map& item) noexcept;
    Map(Map&& item) noexcept;
    ~Map() noexcept;
    const V& at(const K& key) const;
    void push(const K& key, const V& value);
    std::list<K> keys() noexcept;
    size_t size() const noexcept;
    template <class K, class V>
    friend bool operator==(Map<K, V> A, Map<K, V> B);
    template <class K, class V>
    friend bool operator!=(Map<K, V> A, Map<K, V> B);
    const V& operator[](const K& key) const noexcept;
    void clear() noexcept;
    void delElem(const K& key);
    V& valueMap(const K& key,const V& defvalue) const noexcept;
    std::string toJSON() const;

    friend class Iteratorclass<Map<K, V>>;
};

template<class K, class V>
template<typename T>
size_t Map<K, V>::findind(const std::vector<T>& vec,const T& A) const noexcept{
    for (int i = 0; i != vec.size(); i++){
        if (vec[i] == A) return i;
    }
    return vec.size();
}

template <class K, class V>
Map<K, V>::Map() noexcept{
}

template <class K, class V>
Map<K, V>::Map(const Map<K, V>& item) noexcept{
    key = item.key;
    value = item.value;
}

template<class K, class V>
Map<K, V>::Map(Map<K, V> &&item) noexcept {
    key = item.key;
    value = item.value;
}

template <class K, class V>
Map<K, V>::~Map() noexcept{
    key.clear();
    value.clear();
}

template<class K, class V>
const V& Map<K, V>::at(const K& key) const {
    auto ind = std::find(this->key.begin(), this->key.end(), key);
    if (ind == this->key.end()){
        throw -1;
    }
    return this->value[findind(this->key, key)];
}
template <class K, class V>
void Map<K, V>::push(const K& key,const V& value){
    auto ind = std::find(this->key.begin(), this->key.end(), key);
    if (ind != this->key.end()){
        this->value[findind<K>(this->key, key)] = value;
    } 
    else {
        this->value.push_back(value);
        this->key.push_back(key);
    }
}
template <class K, class V>
std::list<K> Map<K, V>::keys() noexcept{
    std::list<K> l(key.begin(), key.end());
    return l;
}
template<class K, class V>
size_t Map<K, V>::size() const noexcept{
    return value.size();
}

template<class K, class V>
const V& Map<K, V>::operator[](const K& key) const noexcept{
    return at(key);
}

template<class K, class V>
void Map<K, V>::clear() noexcept {
    value.clear();
    key.clear();
}

template<class K, class V>
inline bool operator==(Map<K, V> A, Map<K, V> B) {
    std::list<K> result;
    std::list<K> Avec = A.keys();
    std::list<K> Bvec = B.keys();
    std::set_difference(Avec.begin(), Avec.end(), Bvec.begin(), Bvec.end(), std::inserter(result, result.end()));

    if (A.size() != B.size() || result.size() > 0)
        return false;
    for (auto it : Avec) {
        if (A[it] != B[it]) return false;
    }
    return true;
}

template<class K, class V>
inline bool operator!=(Map<K, V> A, Map<K, V> B)
{
    return !operator==(A, B);
}

template<class K, class V>
void Map<K, V>::delElem(const K& key){
    auto ind = std::find(this->key.begin(), this->key.end(), key);
    if (ind == this->key.end()) throw -1;
    else {
        int indk = findind(this->key, key);
        this->key.erase(this->key.begin() + indk);
        this->value.erase(this->value.begin() + indk);
    }
}

template<class K, class V>
V& Map<K, V>::valueMap(const K& key, const V& defvalue) const noexcept {
    if(std::find(this->key.begin(), this->key.end(), key) != this->key.end()) return value[findind(this->key, key)];
    return defvalue;
}

template<class V, class K>
std::string Map<V, K>::toJSON() const {
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