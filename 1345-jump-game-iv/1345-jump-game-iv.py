class Solution:
    def minJumps(self, arr: List[int]) -> int:
        graph=[[] for i in range(len(arr))]
        ele = {}
        for idx,i in enumerate(arr):
            if i not in ele.keys():
                ele[i]=[]
            ele[i].append(idx)
        for i in range(len(arr)-1):
            graph[i].append(i+1)
            graph[i+1].append(i)
        ###################################################    
        #bfs
        vals = [0 for i in range(len(arr))]
        visited = vals[:]
        visited_ = {}
        queue = []
        queue.append(0)
        visited[0]=1
        while len(queue):
            x = queue.pop(0)
            for i in graph[x]:
                if not visited[i]:
                    visited[i]=1
                    vals[i]=vals[x]+1
                    queue.append(i)
            if arr[x] not in visited_.keys():
                visited_[arr[x]]=1
                for i in ele[arr[x]]:
                    if not visited[i]:
                        visited[i]=1
                        vals[i]=vals[x]+1
                        queue.append(i)
                    
        ###################################################
        return vals[-1]