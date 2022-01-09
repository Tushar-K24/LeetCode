class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x,y = 0,0
        d = 'N'
        left = {'N':'W', 'S':'E', 'E':'N', 'W':'S'}
        right = {'N':'E', 'S':'W', 'E':'S', 'W':'N'}
        direction = {'N':[0,1], 'S':[0,-1], 'E':[1,0], 
                    'W':[-1,0]}
        for i in range(4):
            for step in instructions:
                if step == 'G':
                    dx, dy = direction[d]
                    x+=dx
                    y+=dy
                elif step == 'L':
                    d = left[d]
                else:
                    d = right[d]
                    
            if x==0 and y==0:
                return True
            
        return False