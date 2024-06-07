#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <random>

template<typename K, typename T>
class HashTable {
private:
    struct HashNode {
        K key;
        T value;
        HashNode(K k, T v) : key(k), value(v) {}
    };

    size_t _size;
    std::vector<std::list<HashNode>> table;

    size_t hash(const K& key) const {
        const double A = (std::sqrt(5) - 1) / 2;
        return static_cast<size_t>(_size * (key * A - static_cast<size_t>(key * A)));
    }

public:
    HashTable(size_t tableSize) : _size(tableSize), table(tableSize) {}
    HashTable(size_t tableSize, const K& min_k, const K& max_k, const T& min_v, const T& max_v) : _size(tableSize), table(tableSize) {
        if (tableSize == 0)
            throw std::invalid_argument("Size = 0");

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<K> key_dist(min_k, max_k);
        std::uniform_int_distribution<size_t> value_dist(min_v, max_v);

        for (size_t i = 0; i < tableSize; ++i) {
            K random_key = key_dist(gen);
            T random_value = value_dist(gen);

            insert(random_key, random_value);
        }
    }
    HashTable(const HashTable& other) : _size(other._size), table(other.table) {}
    ~HashTable() = default;






