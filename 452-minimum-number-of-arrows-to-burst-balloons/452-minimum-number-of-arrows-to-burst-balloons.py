class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        cnt=1
        points.sort(key=lambda x: x[0])
        intersection = points[0]
        for pt in points:
            if pt[0]>intersection[1]:
                cnt+=1
                intersection=pt
            else:
                intersection = [pt[0], min(intersection[1], pt[1])]
        return cnt