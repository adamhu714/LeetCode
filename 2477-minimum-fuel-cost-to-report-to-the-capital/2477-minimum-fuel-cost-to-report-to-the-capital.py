class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        
        # Global adjacency list
        
        
        adj = [[] for i in range(len(roads)+1)]
        
        for i in range(len(roads)):
            
            adj[roads[i][0]].append(roads[i][1])
            adj[roads[i][1]].append(roads[i][0])
        
        # Global variable to hold minimum fuel
        fuel = 0
        
        # # Global variable to hold number of members in subtrees
        # members = 0
        
        def dfs(node, parent, fuel, adj, seats):
            
            members = 1
            
            for i in adj[node]:
                
                if i != parent:
                    
                    result = dfs(i, node, fuel, adj, seats)
                    members += result[0]
                    fuel = result[1]
                    
            if node != 0:
                fuel += ceil((members) / seats)
            
            return members, fuel
        
        fuel = dfs(0, None, fuel, adj, seats)[1]
        
        return fuel