#!/usr/bin/python

import sys

data = """
131,673,234,103,18
201,96,342,965,150
630,803,746,422,111
537,699,497,121,956
805,732,524,37,331
""".strip()

class From:
    class LEFT: pass
    class ABOVE: pass
    class BELOW: pass

def min_path(grid, cache_above, cache_below, cache_left, x=0, y=0, _from=From.LEFT):
    if _from == From.ABOVE and cache_above[y][x] != -1:
        return cache_above[y][x]
    elif _from == From.LEFT and cache_left[y][x] != -1:
        return cache_left[y][x]
    elif _from == From.BELOW and cache_below[y][x] != -1:
        return cache_below[y][x]
    _right = None
    _bot = None
    _top = None
    # recurse to the left
    if x < len(grid) - 1:
        _right = min_path(grid, cache_above, cache_below, cache_left, x + 1, y, From.LEFT)
    # recurse up
    if _from != From.ABOVE and y > 0:
        _top = min_path(grid, cache_above, cache_below, cache_left, x, y - 1, From.BELOW)
    # recurse down
    if _from != From.BELOW and y < len(grid[y]) - 1:
        _bot = min_path(grid, cache_above, cache_below, cache_left, x, y + 1, From.ABOVE)

    # find the lowest
    _result = sys.maxint
    if _top and _top < _result:
        _result = _top
    if _bot and _bot < _result:
        _result = _bot
    if _right and  _right < _result:
        _result = _right
    # add currenct position to the value
    _result += grid[y][x]
    # save to cache_above for the position
    if _from == From.LEFT:
        cache_left[y][x] = _result
    elif _from == From.ABOVE:
        cache_above[y][x] = _result
    elif _from == From.BELOW:
        cache_below[y][x] = _result
    if _result == 1457:
        print "top: %s, right: %s, bot: %s, from: %s" % (_top, _right, _bot, _from)
    return _result

def get_grid_data():
    import httplib
    con = httplib.HTTPConnection("projecteuler.net")
    con.request("GET", "/project/matrix.txt")
    resp = con.getresponse()
    if resp.status != httplib.OK:
        print "error getting data, server returned: %s %s" % (resp.status, resp.reason)
        return None
    else:
        data = resp.read()
        resp.close()
        con.close()
        return data.strip()

if __name__ == "__main__":
    grid = []
    cache_above = []
    cache_below = []
    cache_left = []
    for _line in get_grid_data().strip().split("\n"):
        arr = []
        cache_arr_above = []
        cache_arr_below = []
        cache_arr_left = []
        for _num in _line.split(","):
            arr.append(int(_num))
            cache_arr_above.append(-1)
            cache_arr_below.append(-1)
            cache_arr_left.append(-1)
        grid.append(arr)
        cache_above.append(cache_arr_above)
        cache_below.append(cache_arr_below)
        cache_left.append(cache_arr_left)
    # put cache_above in for endpoints.
    for _y in xrange(len(grid)):
        cache_above[_y][-1] = grid[_y][-1]
        cache_below[_y][-1] = grid[_y][-1]
        cache_left[_y][-1] = grid[_y][-1]
    _min = sys.maxint
    for y in xrange(len(grid)):
        _rc = min_path(grid, cache_above, cache_below, cache_left, y=y)
        if _rc < _min:
            _min = _rc
    print _min
