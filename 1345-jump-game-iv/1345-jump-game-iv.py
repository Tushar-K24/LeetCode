from collections import deque
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        if len(arr)==1: return 0
        graph = {}
        for i in range(len(arr)):
            if arr[i] not in graph.keys():
                graph[arr[i]]=[]
            graph[arr[i]].append(i)
        queue = deque([])
        queue.append(0)
        visited = [0 for i in range(len(arr))]
        ans = visited[:]
        visited[0]=1
        visited_ = {}
        while len(queue):
            x = queue.popleft()
            if arr[x] not in visited_.keys():
                visited_[arr[x]]=1
                for i in graph[arr[x]]:
                    if not visited[i]:
                        visited[i]=1
                        ans[i]=ans[x]+1
                        queue.append(i)
                        if i==len(arr)-1:
                            return ans[i]
            if x-1>=0:
                if not visited[x-1]:
                    visited[x-1]=1
                    ans[x-1]=ans[x]+1
                    queue.append(x-1)
            if x+1<len(arr):
                if not visited[x+1]:
                    visited[x+1]=1
                    ans[x+1]=ans[x]+1
                    queue.append(x+1)
                    if i==len(arr)-1:
                        return ans[i]
        return ans[-1]