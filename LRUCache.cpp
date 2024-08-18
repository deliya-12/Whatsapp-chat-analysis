#include "LRUCache.h"

LRUCache::LRUCache(size_t capacity) : capacity_(capacity) {}

void LRUCache::put(const std::string& contact, int messages) {
    auto it = map_.find(contact);

    if (it != map_.end()) {
        // Contact already in cache, update messages and move to front
        it->second->second = messages;
        moveToFront(it->second);
    } else {
        // New contact, check if cache is full
        if (cache_.size() == capacity_) {
            removeLRU();
        }
        // Insert new contact
        cache_.emplace_front(contact, messages);
        map_[contact] = cache_.begin();
    }
}

int LRUCache::get(const std::string& contact) {
    auto it = map_.find(contact);
    if (it == map_.end()) {
        return -1; // Contact not found
    }
    moveToFront(it->second);
    return it->second->second;
}

void LRUCache::moveToFront(std::list<std::pair<std::string, int>>::iterator it) {
    cache_.splice(cache_.begin(), cache_, it);
}

void LRUCache::removeLRU() {
    auto last = cache_.end();
    --last;
    map_.erase(last->first);
    cache_.pop_back();
}

void LRUCache::printCache() const {
    for (const auto& entry : cache_) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}
