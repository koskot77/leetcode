import resource, sys

sys.setrecursionlimit(150000)
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))

class Solution(object):
    def coinChangeSlow(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if len(coins) == 0 :
            return -1

        coin   = coins[0]
        nCoins = int(amount / coin)

        if len(coins) == 1 :
            if amount - nCoins * coin != 0 :
                return -1
            else :
                return nCoins

        minNcoins = 100000000
        for i in range(0,nCoins) :

            if i > minNcoins :
                break

            nc = self.coinChangeSlow(coins[1:],amount-coin*i)
            if nc < 0 :
                continue
            if nc + i < minNcoins :
                minNcoins = nc + i

        if minNcoins == 100000000 :
            return -1
        else :
            return minNcoins

    lookUp = {0:0}

    def coinChangeStrange(self, coins, amount):
        minCoins = amount

        if amount == 0:
            return 0

        if amount in coins :
            self.lookUp[amount] = 1
            return 1
        elif amount in self.lookUp.keys() :
            return self.lookUp[amount]
        else :
            for coin in [ c for c in coins if c <= amount ] :
                nc = self.coinChangeStrange(coins,amount-coin)
                if nc < 0 :
                    continue
                if nc + 1 < minCoins :
                    minCoins = nc + 1
                    self.lookUp[amount] = minCoins

        if amount not in self.lookUp.keys() :
            self.lookUp[amount] = -1

        return self.lookUp[amount]

    def coinChangeFinal(self, coins, amount, lookUp):
        minCoins = amount

        if amount == 0:
            return 0

        if amount in coins :
            lookUp[amount] = 1

        elif lookUp[amount] != 0:
            return lookUp[amount]

        else :
            for coin in [ c for c in coins if c <= amount ] :
                nc = self.coinChangeFinal(coins,amount-coin,lookUp)
#                print " ",amount," ",coin," ",nc
                if nc <= 0 :
                    lookUp[amount-coin] = -1
                    continue
                if nc + 1 <= minCoins :
                    minCoins = nc + 1
                    lookUp[amount] = minCoins

        return -1 if lookUp[amount] == 0 else lookUp[amount]

    def coinChange(self, coins, amount):
        lookUp = [-1]*(amount+1)
        lookUp[0] = 0
        for a in range(1,amount+1) :
            minCoins = 10000000
            for coin in [ c for c in coins if c <= a ] :
                if lookUp[a-coin] >= 0 and lookUp[a-coin] + 1 < minCoins :
                    minCoins = lookUp[a-coin] + 1
            lookUp[a] = minCoins if minCoins != 10000000 else -1

        return lookUp[amount]

s = Solution()

#print s.coinChange([186,419,83,408], 6249)
#print s.coinChange([2], 2)

lookUp = [0]*624124
print s.coinChangeFinal([186,419,83,408,213,321,12,3321,23], 624123, lookUp)
print s.coinChange([186,419,83,408,213,321,12,3321,23], 624123)

def recDC(coinValueList,change,knownResults):
   minCoins = change
   if change in coinValueList:
      knownResults[change] = 1
      return 1
   elif knownResults[change] > 0:
      return knownResults[change]
   else:
       for i in [c for c in coinValueList if c <= change]:
         numCoins = 1 + recDC(coinValueList, change-i,
                              knownResults)
         if numCoins < minCoins:
            minCoins = numCoins
            knownResults[change] = minCoins
   return minCoins

#lookUp2 = [-1]*624124
#print(recDC([186,419,83,408,213,321,12,3321,23], 624123, lookUp2))

#print lookUp == lookUp2
