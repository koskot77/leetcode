import math

class Solution(object):
    def numPoints(self, points, r):
        """
        :type points: List[List[int]]
        :type r: int
        :rtype: int
        """
        dist2 = lambda p1,p2: (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1])
        def center(p1,p2,r):
            # in a system where p1.x=0 and p1.y=0 and p2.y = 0:
            _x = math.sqrt(dist2(p1,p2))/2.
            if( r < _x ): raise Exception("Not possible to satisfy")  # error #2: don't forget obvious edge case
            _y = math.sqrt(r*r - _x*_x)
            # rotate and shift back to normal coordinates:
            rot = math.atan2(p2[1]-p1[1], p2[0]-p1[0])
            x1 = math.cos(rot)*_x - math.sin(rot)*_y
            y1 = math.sin(rot)*_x + math.cos(rot)*_y
            x2 = math.cos(rot)*_x - math.sin(rot)*(-_y) # +-sqrt # error #1: keep it simple
            y2 = math.sin(rot)*_x + math.cos(rot)*(-_y) # +-sqrt
            return ([x1+p1[0],y1+p1[1]],[x2+p1[0],y2+p1[1]])

        scores = []
        for i in range(len(points)):
            for j in range(i+1,len(points)):
                try:
                  c1, c2 = center(points[i], points[j], r)
                except Exception as e:
                  continue
                score1 = 0
                score2 = 0
                for k in range(len(points)):
                    if( dist2(points[k],c1)<=r*r+0.00000001 ): score1 += 1 # error #3: floating point is not precise
                    if( dist2(points[k],c2)<=r*r+0.00000001 ): score2 += 1
                scores += [(score1,c1)]
                scores += [(score2,c2)]

        print(scores)                
        return len(scores)>0 and max([x for x,y in scores]) or 1

s = Solution()
print(s.numPoints([[4,5],[-4,1],[-3,2],[-4,0],[0,2]],5))
