def intersect(nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]

        """

        if len(nums1) < len(nums2):
            nSmall = nums1
            nBig   = nums2
        else :
            nSmall = nums2
            nBig   = nums1

        common = []
        n1 = {}

        for val in nSmall:
            if( val not in n1 ):
                n1[val] = 0
            n1[val] = n1[val] + 1

        for n2 in nBig:
            if n2 in n1:
                if n1[n2] != 0:
                    common.append(n2)
                    n1[n2] = n1[n2] - 1


        return common                    


print intersect([33,30,4,74,28,68,83,76,43,13,79,75,67,28,45,92,75,70,99,24,20,97,52,80,89,52,66,37,71,12,11,44,62,4,51,87,3,10,35],
                [48,9,46,8,98,70,21,98,46,84,27,66,61,40,28,99,75,82,24,40,70,31,40,25,51,13,4,53,86,66,23,69,93,11,91,7])
