def maxNum(nums, k):
        if k <= 0 :
            return []

        retval = [ ]
        for i in range(len(nums)-1,-1,-1):
            if k > len(retval):
                retval.append( nums[i] )
            else:
                if nums[i] >= retval[ len(retval)-1 ]:
                    j = len(retval)-1
                    while j > 0:
                        if retval[j] < retval[j-1]:
                            break
                        j = j - 1
                    del retval[j]
                    retval.append( nums[i] )

        return list(reversed(retval))


def maxNumber(nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k == 0:
            return []

#        print nums1, nums2, k

        if len(nums2) == 0 :
            return maxNum(nums1,k)

        if len(nums1) == 0 :
            return maxNum(nums2,k)

        if len(nums1) + len(nums2) == k :

            if nums1[0] > nums2[0] :
                return [ nums1[0] ] + maxNumber(nums1[1:],nums2,k-1)

            if nums1[0] < nums2[0] :
                return [ nums2[0] ] + maxNumber(nums1,nums2[1:],k-1)

            pos1 = 0
            while pos1 < len(nums1) and nums1[pos1] == nums2[0] :
                pos1 = pos1 + 1

            pos2 = 0
            while pos2 < len(nums2) and nums2[pos2] == nums1[0] :
                pos2 = pos2 + 1

            posMin = pos1 if pos1 < pos2 else pos2

#            print len(nums1)," ",len(nums2)," ",posMin

            if posMin == len(nums1) and posMin == len(nums2) :
                return nums1 + nums2

            if posMin != len(nums1) and posMin == len(nums2) :
                return nums1[0:posMin] + maxNumber(nums1[posMin:],nums2,k-posMin)
 
            if posMin == len(nums1) and posMin != len(nums2) :
                return nums2[0:posMin] + maxNumber(nums1,nums2[posMin:],k-posMin)

            if nums1[posMin] >  nums2[posMin] :
                return nums1[0:posMin] + maxNumber(nums1[posMin:],nums2,k-posMin)

            if nums1[posMin] <  nums2[posMin] :
                return nums2[0:posMin] + maxNumber(nums1,nums2[posMin:],k-posMin)

            if nums1[posMin] == nums2[posMin] :
                pos = posMin
                while pos < len(nums1) and pos < len(nums2) and nums1[pos] == nums2[pos] :
                    pos = pos + 1

                if pos == len(nums1) and pos == len(nums2) :
                    return nums1[0:posMin] + maxNumber(nums1[posMin:],nums2,k-posMin)

                if pos != len(nums1) and pos == len(nums2) :
                    return nums1[0:posMin] + maxNumber(nums1[posMin:],nums2,k-posMin)
               
                if pos == len(nums1) and pos != len(nums2) :
                    return nums2[0:posMin] + maxNumber(nums1,nums2[posMin:],k-posMin)

                if nums1[pos] > nums2[pos] :
                    return nums1[0:posMin] + maxNumber(nums1[posMin:],nums2,k-posMin)

                if nums1[pos] < nums2[pos] :
                    return nums2[0:posMin] + maxNumber(nums1,nums2[posMin:],k-posMin)

#            combination = nums1[0:posMin] + nums2[0:posMin] + maxNumber(nums1[posMin:],nums2[posMin:],m-posMin-posMin) 
#            return combination if m == k else maxNum(combination,k)
#                return [ nums1[i] if j == 0 else nums2[i] for i in range(0,pos) for j in range(0,2) ] + maxNumber(nums1[pos:],nums2[pos:],k-pos)

        a = zip(nums1, range(len(nums1)))
        b = zip(nums2, range(len(nums2)))
        a.sort(key=lambda tup: (tup[0],-tup[1]))
        b.sort(key=lambda tup: (tup[0],-tup[1]))

        indexedNums1 = list( reversed(a) )
        indexedNums2 = list( reversed(b) )

#        print indexedNums1, indexedNums2

        best1 = 0
        best2 = 0
        while True :
            if indexedNums1[best1][0] > indexedNums2[best2][0] :
                if len(nums1) - indexedNums1[best1][1] + len(nums2) >= k :
                    best2 = -1
                    break
                else :
                    best1 = best1 + 1
                    continue
 
            if indexedNums1[best1][0] < indexedNums2[best2][0] :
                if len(nums2) - indexedNums2[best2][1] + len(nums1) >= k :
                    best1 = -1
                    break
                else :
                    best2 = best2 + 1
                    continue
            
            if indexedNums1[best1][0] == indexedNums2[best2][0] :
                if len(nums1) - indexedNums1[best1][1] + len(nums2) >= k and len(nums2) - indexedNums2[best2][1] + len(nums1) <  k :
                    best2 = -1
                    break
                if len(nums1) - indexedNums1[best1][1] + len(nums2) <  k and len(nums2) - indexedNums2[best2][1] + len(nums1) >= k :
                    best1 = -1
                    break
                if len(nums1) - indexedNums1[best1][1] + len(nums2) <  k and len(nums2) - indexedNums2[best2][1] + len(nums1) <  k :
                    best1 = best1 + 1
                    best2 = best2 + 1
                    continue
                if len(nums1) - indexedNums1[best1][1] + len(nums2) >= k and len(nums2) - indexedNums2[best2][1] + len(nums1) >= k :
                    dismissed1 = list( reversed( sorted( nums1[ 0:indexedNums1[best1][1] ] ) ) )
                    dismissed2 = list( reversed( sorted( nums2[ 0:indexedNums2[best2][1] ] ) ) )
                    pos = 0
                    while pos < len(dismissed1) and pos < len(dismissed2) and dismissed1[pos] == dismissed2[pos] :
                       pos = pos + 1
                    print dismissed1," ",dismissed2," ",pos
#                    if pos < len(dismissed1) and pos < len(dismissed2) :
#                       if dismissed1[pos] < dismissed2[pos] :
#                           best2 = -1
#                           break
#                       else :
#                           best1 = -1
#                           break
#                    if pos <  len(dismissed1) and pos == len(dismissed2) :
#                           best1 = -1
#                           break
#                    if pos == len(dismissed1) and pos <  len(dismissed2) :
#                           best2 = -1
#                           break
                    print "tie"
                    break

        print best1," ",best2

        if best1 >= 0 and best2 <  0 :
            return [ indexedNums1[best1][0] ] + maxNumber( nums1[indexedNums1[best1][1]+1:], nums2, k-1 )

        if best1 <  0 and best2 >= 0 :
            return [ indexedNums2[best2][0] ] + maxNumber( nums1, nums2[indexedNums2[best2][1]+1:], k-1 )

        if best1 >= 0 and best2 >= 0 :
            res1 = [ indexedNums2[best2][0] ] + maxNumber( nums1, nums2[indexedNums2[best2][1]+1:], k-1 )
            res2 = [ indexedNums1[best1][0] ] + maxNumber( nums1[indexedNums1[best1][1]+1:], nums2, k-1 )
            if len(res1) > len(res2) :
                 return res1
            pos = 0
            while pos < len(res1) and res1[pos] == res2[pos]:
                pos = pos + 1

            if pos == len(res1):
                print "same"
                return res1
            else :
                print res1[pos] > res2[pos] 
                return res1 if res1[pos] > res2[pos] else res2
        

#print maxNumber( [9, 1, 2, 5, 8, 3], [3, 4, 6, 5], 6 )
#print maxNumber( [6, 7], [6, 0, 4], 0 )
#print maxNumber( [3, 9], [8, 9], 4 )
#print maxNumber([6,6,8], [5,0,9], 3)
#print maxNumber([5,6,8], [6,4,0], 3,)
#print maxNum([9, 1, 2, 5, 8, 3, 3, 4, 6, 5],6)
#print maxNum([5,6,8],2)
#print maxNumber( [2,1,7,8,0,1,7,3,5,8,9,0,0,7,0,2,2,7,3,5,5], [2,6,2,0,1,0,5,4,5,5,3,3,3,4], 35 )
mn = maxNumber( [9,3,9,4,3,6,6,1,8,3,6,5,8,9,0,4,0,7,6,6,5,6,2,8,6,7,1,5,0,3,2,3,9,2,1,4,8,8,1,6,3,9,5,4,3,5,9,5,4,9,3,7,9,9,1,9,9,5,6,2,4,8,1,4,0,3,0,4,2,3,2,7,6,4,8,2,1,9,4,6,0,6,0,5,2,8,6,5,9,8,2,6,1,2,1,0,6,0,1,8,8,8,7,3,1,4,9,7,0,7,7,3,8,2,8,0,5,4,7,6,1,9,8,3,5,0,4,6,2,2,5,4,9,7,4,9,1,6,7,2,0,1,2,5,8,1,1,3,2,9,9,2,1,2,3,3,6,1,8,7],
[5,0,1,5,1,0,8,8,7,3,8,9,2,8,9,8,1,5,6,4,5,7,2,0,6,8,8,0,9,4,5,7],
160 )
print mn
if [9,9,9,9,9,8,7,8,8,0,9,4,5,7,0,4,0,7,6,6,5,6,2,8,6,7,1,5,0,3,2,3,9,2,1,4,8,8,1,6,3,9,5,4,3,5,9,5,4,9,3,7,9,9,1,9,9,5,6,2,4,8,1,4,0,3,0,4,2,3,2,7,6,4,8,2,1,9,4,6,0,6,0,5,2,8,6,5,9,8,2,6,1,2,1,0,6,0,1,8,8,8,7,3,1,4,9,7,0,7,7,3,8,2,8,0,5,4,7,6,1,9,8,3,5,0,4,6,2,2,5,4,9,7,4,9,1,6,7,2,0,1,2,5,8,1,1,3,2,9,9,2,1,2,3,3,6,1,8,7] != mn: 
    print "Bad"
