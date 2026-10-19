class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        parent = {}
        emailToName = {}
        
        # union find helper functions
        def find(email: str) -> str:
            """
            recursively call the find function until we hit the root of
            the tree/the representative of the set, which has the side effect of,
            on the recursive unwinding calls, setting every node in the traversed
            path to become the immediate child of the root. 
            """
            if parent[email] != email:
                parent[email] = find(parent[email])
            return parent[email]

        def union(e1: str, e2: str) -> None:
            """
            union two sets that contain e1 and e2 by calling find on e2 to
            get the representative of that tree, and setting it as the child
            of what we get after calling find on e1
            """
            parent[find(e2)] = find(e1)

        # go through each entry and create a set, then merge it with the 
        # first account. if email exists in another set, it will merge that 
        # set with the first account
        for account in accounts:
            name = account[0]
            firstAccount = account[1]

            # for each email, 
            for email in account[1:]:
                if email not in parent:
                    parent[email] = email
                emailToName[email] = name
                union(firstAccount, email)
        
        # populate the result array by creating buckets of emails keyed by their
        # root in the respective DSU tree. then, iterate through each bucket, get
        # the name associated with the key, and append [name] + buckets[root]
        # as an entry in the output
        res = []
        buckets = defaultdict(list)
        for email in emailToName:
            root = find(email)
            buckets[root].append(email)
        
        for root in buckets:
            name = emailToName[root]
            res.append([name] + sorted(buckets[root]))
        
        return res