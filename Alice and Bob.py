class Solution:
    def divisorGame(self, N: int) -> bool:
        # 1. 创建一个数组 target, 长度 N+1
        # target[i] 表示: 当前数字是 i 时, **当前玩家能不能赢**
        # 0 = 必输, 1 = 必赢
        target = [0 for i in range(N + 1)]

        # 2. 初始条件: 数字是 1 时, 当前玩家必输
        target[1] = 0

        # 3. 如果 N <= 1, 直接返回 False
        if N <= 1:
            return False

        # 4. 初始条件: 数字是 2 时, 当前玩家必胜
        target[2] = 1

        # 5. 从 3 遍历到 N, 计算每个数字的胜负状态
        for i in range(3, N + 1):
            # 遍历所有可能的约数 j (1 到 i//2)
            for j in range(1, i // 2 + 1):
                # 如果 j 是 i 的约数，且 i-j 状态为必输（0）
                if i % j == 0 and target[i - j] == 0:
                    target[i] = 1
                    break

        # 6. 返回 N 对应的胜负状态
        return target[N] == 1