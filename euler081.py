#!/usr/bin/python

def min_path(grid, cache, x, y):
    if cache[y][x] != -1:
        return cache[y][x]
    left = None
    bot = None
    if x < len(grid) - 1:
        left = min_path(grid, cache, x + 1, y)
    if y < len(grid[y]) - 1:
        bot = min_path(grid, cache, x, y + 1)
    result = 0
    if left:
        if bot and bot < left:
            result = bot
        else:
            result = left
    elif bot:
        result = bot
    result += grid[y][x]
    cache[y][x] = result
    return result

if __name__ == "__main__":
    import httplib
    con = httplib.HTTPConnection("projecteuler.net")
    con.request("GET", "/project/matrix.txt")
    resp = con.getresponse()
    print "%s %s" % (resp.status, resp.reason)
    grid = []
    cache = []
    for _line in resp.read().strip().split("\n"):
        arr = []
        _cache_arr = []
        for _num in _line.split(","):
            arr.append(int(_num))
            _cache_arr.append(-1)
        grid.append(arr)
        cache.append(_cache_arr)
    print min_path(grid, cache, 0, 0)
