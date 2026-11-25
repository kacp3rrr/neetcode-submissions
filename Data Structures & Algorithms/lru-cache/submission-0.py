# using pythons OrderedDict which gives us the order of insertions/updates
# needed to maintain LRU cachce. Effectively saves the work of setting up a 
# doubly linked list but works almost the same
class LRUCache:

    def __init__(self, capacity: int):
        self.MAX = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        # move to end if it exists, since a put call is considered as a use
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value

        # pop least recently used key if overfill
        if len(self.cache) > self.MAX:
            self.cache.popitem(last=False) # since we move recently used to the back