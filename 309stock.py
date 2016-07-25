# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) < 2:
           return 0

        # Typical DP approach: create arrays of current balance if at this step we buy/sell/wait{after_buy,after_sell}
        profitBuy   = [0]*len(prices)
        profitSell  = [0]*len(prices)
        profitWaitWith = [0]*len(prices)
        profitWaitWO   = [0]*len(prices)

        profitBuy[0]      = -prices[0]
        profitWaitWith[0] = -1000000000

        for curPos in range(1,len(prices)):
            # code in the "buy-before-sell" limitation: 
            profitWaitWith[curPos] = max(profitWaitWith[curPos-1], profitBuy[curPos-1])
            profitWaitWO  [curPos] = max(profitSell[curPos-1], profitWaitWO[curPos-1])
            profitBuy  [curPos] = profitWaitWO[curPos-1] - prices[curPos]
            profitSell [curPos] = max(profitWaitWith[curPos-1], profitBuy[curPos-1]) + prices[curPos]

        print profitSell
        print profitBuy
        print profitWaitWith
        print profitWaitWO

        return max([profitSell[-1],profitWaitWO[-1],profitBuy[-1]])

stock = [1,2,3,0,2]

s = Solution()

print s.maxProfit(stock)

