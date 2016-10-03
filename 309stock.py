# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
# https://discuss.leetcode.com/topic/61479/annotated-python-dp-solution-no-optimization
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # On each day, represented by the stock price, we need to choose
        #  between _buy_/_wait_/_sell_ actions. The limitations are that
        #  we cannot
        #   (1) _sell_ until we _buy_
        #   (2) _buy_ until we _sell_ (unless starting),
        #   (3) wait for cooldown between _sell_ and next _buy_
        # A subtle detail is that we can _wait_ with the stock bought and
        #  we can _wait_ without having stock (like in the cooldown phase)
        # DP constituents, (1) optimal subproblem and (2) cache, boil down
        #  to having four "lines" of actions (arrays) to be updated daily:
        #   (1) waitWith[day] - we choose to do nothing on the _day_ while
        #       having the stock because a day before we've either bought
        #       the stock or we've been also waiting already having the stock
        #   (2) waitWO[day] - we choose to do nothing on the _day_ even we
        #       don't have the stock because on the day before we've either
        #       also didn't have it or we've sold it
        #   (3) buy[day] - we buy the stock meaning that we just starting
        #       or we've being waiting with no stock the day before
        #   (4) sell[day] - we sell the stock meaning that on the day before 
        #       we've either bought the stock or we were waiting already
        #       having it
        #  Choosing the "retrospectively optimal" strategy means choosing
        #   the "line" with the maximal profit on the last day
        #  Updating each of the "lines" should use the most optimal of the
        #   choices of what "could have happened" on the day before

        # safety
        if len(prices) < 2:
           return 0

        # the four "lines"
        profitBuy   = [0]*len(prices)
        profitSell  = [0]*len(prices)
        profitWaitWith = [0]*len(prices)
        profitWaitWO   = [0]*len(prices)

        # boundary condition
        profitBuy[0]      = -prices[0]   # bare expenses buying stock
        profitWaitWith[0] = -1000000000  # we start while not holding stock

        # start trading
        for curPos in range(1,len(prices)):
            # do nothing "with"
            profitWaitWith[curPos] = max(profitWaitWith[curPos-1], profitBuy[curPos-1])
            # do nothing "without"
            profitWaitWO  [curPos] = max(profitSell[curPos-1], profitWaitWO[curPos-1])
            # we can buy only if we've waited before, mind "expenses"
            profitBuy  [curPos] = profitWaitWO[curPos-1] - prices[curPos]
            # sell stock with "profit"
            profitSell [curPos] = max(profitWaitWith[curPos-1], profitBuy[curPos-1]) + prices[curPos]

        print profitSell
        print profitBuy
        print profitWaitWith
        print profitWaitWO

        return max([profitSell[-1],profitWaitWO[-1],profitBuy[-1]])

stock = [1,2,3,0,2]

s = Solution()

print s.maxProfit(stock)

