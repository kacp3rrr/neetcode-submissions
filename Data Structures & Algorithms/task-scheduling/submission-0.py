class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # greedy approach: make n empty blocks serparated by the most frequent task
        # ((max frequency - 1) * n). then iterate through the rest of the task frequencies
        # in descending order, and subtract its frequency from the available empty slots
        freqCounts = Counter(tasks)
        sortedCounts = [c for _, c in freqCounts.most_common()]
        # our initial minimum bound restricted by the need to seperate the most frequent task by
        # a gap of n
        emptySlots = (sortedCounts[0] - 1) * n

        # for the rest of the counts in descending sorted order, subtract from the empty slots
        # by min(max frequency - 1, f) (i.e., minimum out of the frequency of the current task,
        # or the frequency of the current task being dealt with. if the latter, then not all of
        # the blocks set by the most frequent task will be filled, which is good. otherwise, they
        # will naturally fill the spots after the empty slot blocks we've made)
        for i in range(1, len(sortedCounts)):
            emptySlots -= min(sortedCounts[0] - 1, sortedCounts[i])

        return len(tasks) if emptySlots <= 0 else len(tasks) + emptySlots
