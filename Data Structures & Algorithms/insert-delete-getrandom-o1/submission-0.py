class RandomizedSet:

    def __init__(self):
        self.numMap = {}
        self.numArr = []

    def insert(self, val: int) -> bool:
        if val in self.numMap:
            return False
        self.numMap[val] = len(self.numArr)
        self.numArr.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.numMap:
            return False
        i = self.numMap[val]
        last = self.numArr[-1]
        self.numArr[i] = last
        self.numMap[last] = i
        self.numArr.pop()
        self.numMap.pop(val)
        return True

    def getRandom(self) -> int:
        return random.choice(self.numArr)
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()