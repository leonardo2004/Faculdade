#Nome: Leonardo Tomasela Leal RA:170291
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        m, n = len(image), len(image[0])
        visited = set()
        dirs = [(0, -1), (0, 1), (1, 0), (-1, 0)]
        oc = image[sr][sc]

        def valid(row, col):
            return 0 <= row < m and 0 <= col < n and image[row][col] == oc
        
        def dfs(row, col):
            if (row, col) not in visited:
                visited.add((row, col))
                for drow, dcol in dirs:
                    next_row, next_col = row + drow, col + dcol
                    if valid(next_row, next_col):
                        image[next_row][next_col] = color
                        dfs(next_row, next_col)
        
        image[sr][sc] = color
        dfs(sr, sc)
        return image