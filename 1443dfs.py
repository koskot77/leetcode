# comment: somehow only managed to focus on this problem only when running:
#   don't double-count the shared paths to the apples
class Solution(object):
    def DFS(self, node, graph, explored, path):
        explored.add(node)
        for child in graph[node]:
            if child not in explored:
                path[child] = path[node] + [node] # error #2: outline the basics frist and build on top
                self.DFS(child, graph, explored, path)
        
    def minTime(self, n, edges, hasApple):
        """
        :type n: int
        :type edges: List[List[int]]
        :type hasApple: List[bool]
        :rtype: int
        """
        # idea:
        #  0) turn edge list into adjacency list  # error #1: know what you will work with!
        #  1) DFS-explore the whole graph and store paths from 0 to each apple
        #  2) make a union of all these paths and count each one twise
        graph = {}
        for edge in edges:
            if edge[0] not in graph: graph[edge[0]] = []
            if edge[1] not in graph: graph[edge[1]] = [] # error #3: think of details in your adjacency list!
            graph[edge[0]] += [edge[1]]
            graph[edge[1]] += [edge[0]]

        explored = set()
        path = {0:[]} # error #4: build iteratively on top of something!
        
        self.DFS(0, graph, explored, path)

        final = set()
        for i in range(n):
            if hasApple[i]: final.update(path[i] + [i]) # error #5: remember organization of your data!

        return len(final)>0 and (len(final)-1)*2 or 0


s = Solution()

s.minTime(7, [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], [True,False,False,False,False,False,False])
