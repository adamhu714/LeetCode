class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        
        # Breadth first search of [Node, last colour taken]
        
        answer = [-1] * n
        adjR = [[] for i in range(n)]
        adjB = [[] for i in range(n)]
        # Need an adjacency lists
        for i in redEdges:
            adjR[i[0]].append(i[1])
        
        for i in blueEdges:
            adjB[i[0]].append(i[1])
            
        # Populate queue with initial nodes
        
        queue = deque()
        
        queue.append((0, "r"))
        queue.append((0, "b"))
        
        reached = set(queue)
        
        lengthOfPath = 0
        
        answer[0] = 0
        current = (0,"")
        
        # Loop while edges left to traverse
        
        while queue:
            
            lengthOfPath += 1
            
            for i in range(len(queue)):
                
                current = queue.popleft()
                
                match current[1]:
                    
                    case "r":
                        for i in adjB[current[0]]:
                            nxt = (i, "b")
                            if nxt not in reached:
                                queue.append(nxt)
                                reached.add(nxt)
                                if answer[i] == -1:
                                    answer[i] = lengthOfPath
                    
                    case "b":
                        for i in adjR[current[0]]:
                            nxt = (i, "r")
                            if nxt not in reached:
                                queue.append(nxt)
                                reached.add(nxt)
                                if answer[i] == -1:
                                    answer[i] = lengthOfPath
        return answer
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            