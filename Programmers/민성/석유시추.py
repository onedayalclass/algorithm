from collections import deque

def solution(land):
    answer = [0 for _ in range(len(land[0]))]
    visited = [[0 for _ in range(len(land[0]))] for _ in range(len(land))]
    
    def bfs(row, col):
        dy = [1, 0, -1, 0]
        dx = [0, 1, 0, -1]
        queue = deque()
        queue.append([row, col])
        oil = 1
        visited[row][col] = 1
        visitedX = {col}
        
        while queue:
            curY, curX = queue.popleft()
            for i in range(4):
                nextY = curY + dy[i]
                nextX = curX + dx[i]
                if (0 <= nextY < len(land) and 0 <= nextX < len(land[0])):
                    if (visited[nextY][nextX] == 0 and land[nextY][nextX] == 1):
                        visited[nextY][nextX] = 1
                        queue.append([nextY, nextX])
                        oil += 1
                        visitedX.add(nextX)
        
        for v in visitedX:
            answer[v] += oil
    
    for i in range(len(land[0])):
        for j in range(len(land)):
            if (land[j][i] == 1 and visited[j][i] == 0):
                bfs(j, i)
    return max(answer)
