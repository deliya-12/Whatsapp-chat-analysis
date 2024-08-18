#include "LRUCache.h"
#include <iostream>

int main() {
    LRUCache cache(5); // Capacity of 5 contacts

    // Example chat data processing
    cache.put("Alice", 10);
    cache.put("Bob", 20);
    cache.put("Charlie", 30);
    cache.put("David", 40);
    cache.put("Eve", 50);

    // Update message count for Alice and add a new contact
    cache.put("Alice", 15);
    cache.put("Frank", 25);

    // Retrieve and print message counts
    std::cout << "Alice: " << cache.get("Alice") << std::endl;
    std::cout << "Bob: " << cache.get("Bob") << std::endl;
    std::cout << "Charlie: " << cache.get("Charlie") << std::endl;
    std::cout << "David: " << cache.get("David") << std::endl;
    std::cout << "Eve: " << cache.get("Eve") << std::endl;
    std::cout << "Frank: " << cache.get("Frank") << std::endl;

    std::cout << "Cache content:" << std::endl;
    cache.printCache();

    return 0;
}
