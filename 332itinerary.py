class Solution(object):
    hash = {}
    explored = []
    result   = []

    def dfs(self,pos):

        if pos in self.hash.keys():
            while len(self.hash[pos]):
                dest = self.hash[pos].pop(0)
                self.dfs(dest)

        self.result.append(pos)


    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        for edge in tickets:
            fr = edge[0]
            to = edge[1]
            if fr not in self.hash:
                self.hash[fr] = [to]
            else:
                self.hash[fr].append(to)

        for fr in self.hash.keys():
            self.hash[fr].sort();

        self.dfs("JFK")

        self.result.reverse()

        return self.result


q = Solution()

print( q.findItinerary([["LST","TBI"],["AXA","ELH"],["ASD","CBR"],["AUA","ELH"],["VIE","NAS"],["BAK","BIM"],["MHH","TCB"],["TIA","JFK"],["MHH","ASD"],["HBA","TIA"],["MHH","OOL"],["AUA","TIA"],["TIA","VIE"],["BNE","ADL"],["ASD","BIM"],["PER","GGT"],["MHH","SYD"],["ELH","MEL"],["EZE","OOL"],["TBI","PER"],["ANU","BNE"],["BAK","JFK"],["DAC","CBR"],["HBA","MHH"],["CBR","TIA"],["INN","TIA"],["DAC","MHH"],["CBR","BAK"],["TCB","PER"],["ASD","TIA"],["LST","TIA"],["VIE","TCB"],["OOL","TBI"],["AUA","PER"],["TIA","LST"],["BAK","TBI"],["MHH","LST"],["MEL","ASD"],["ASD","PER"],["BIM","ASD"],["BNE","BIM"],["BAK","INN"],["TCB","AUA"],["ADL","TIA"],["SYD","HBA"],["TIA","AUA"],["DAC","NAS"],["CBR","AXA"],["VIE","MHH"],["AXA","VIE"],["CBR","VIE"],["BIM","EZE"],["BIM","INN"],["TCB","MEL"],["TBI","CBR"],["FPO","LST"],["PER","INN"],["INN","VIE"],["NAS","OOL"],["MEL","HBA"],["TIA","CNS"],["NAS","ADL"],["DAC","LST"],["GGT","HBA"],["NAS","ASD"],["CBR","AXA"],["BAK","CBR"],["BNE","BAK"],["JFK","AXA"],["BIM","AUA"],["NAS","BNE"],["PER","INN"],["EZE","DAC"],["TBI","DAC"],["BNE","BIM"],["MHH","PER"],["TCB","OOL"],["CNS","TIA"],["BAK","TCB"],["ADL","BAK"],["LST","INN"],["ASD","TIA"],["PER","LST"],["HBA","BAK"],["CNS","TCB"],["BIM","AUA"],["OOL","SYD"],["VIE","BNE"],["VIE","TIA"],["ASD","DAC"],["BAH","BNE"],["PER","CBR"],["ANU","ASD"],["AXA","MHH"],["ELH","VIE"],["JFK","DAC"],["LST","BAK"],["BIM","ANU"],["AUA","BIM"],["BAK","ASD"],["TBI","TIA"],["MHH","PER"],["VIE","DAC"],["OOL","BNE"],["BAH","FPO"],["CNS","VIE"],["PER","NAS"],["TIA","BAH"],["OOL","DRW"],["CBR","GGT"],["DRW","AUA"],["SYD","CBR"],["AUA","ELH"],["ASD","GGT"],["DAC","HBA"],["VIE","AXA"],["TIA","LST"],["AXA","TCB"],["GGT","BAH"],["INN","BIM"],["TIA","ASD"],["PER","OOL"],["LST","ANU"],["TIA","BIM"],["INN","CBR"],["BNE","MHH"],["TCB","VIE"],["GGT","TBI"],["AXA","CNS"],["LST","EZE"],["BNE","CNS"],["SYD","BNE"],["CBR","SYD"],["CNS","BIM"],["JFK","CNS"],["BIM","BAK"],["HBA","MHH"],["ELH","BAK"],["INN","AXA"],["BIM","ANU"],["ANU","PER"],["TIA","MHH"],["TIA","NAS"]]) )


