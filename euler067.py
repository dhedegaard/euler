#!/usr/bin/python

class Node():
    def __init__(self, value, top_left=None, top_right=None, bot_left=None, bot_right=None):
        self.value = value
        self.top_left = top_left
        self.top_right = top_right
        self.bot_left = bot_left
        self.bot_right = bot_right
        self._cached = None
        
    def max_total(self):
        if self._cached:
            return self._cached
        _max = self.value
        if self.bot_left:
            if self.bot_right and self.bot_right.max_total() > self.bot_left.max_total():
                _max += self.bot_right.max_total()
            else:
                _max += self.bot_left.max_total()
        elif self.bot_right:
            _max += self.bot_right.max_total()
        self._cached = _max
        return _max

    def __str__(self):
        return "%s" % self.value
    
    def __unicode(self):
        return self.__str__()

def parse_tree_from_text(text):
    _top = None
    for line in text.split("\n"):
        if not line:
            continue
        _nums = line.strip().split(" ")
        _prev_node = None
        for _e in _nums:
            if not _e.isdigit():
                continue
            _node = Node(int(_e))
            if not _top:
                _top = _node
            else:
                if not _prev_node:
                    _above_right = _top
                    while _above_right.bot_left:
                        _above_right = _above_right.bot_left
                    _above_right.bot_left = _node
                    _node.top_right = _above_right
                else:
                    _above_left = _prev_node.top_right
                    _node.top_left = _above_left
                    _above_left.bot_right = _node
                    if _above_left and _above_left.top_right and _above_left.top_right.bot_right:
                        _above_right = _node.top_left.top_right.bot_right
                        _node.top_right = _above_right
                        _above_right.bot_left = _node
            _prev_node = _node
    return _top
        

if __name__ == "__main__":
    import httplib
    con = httplib.HTTPConnection("projecteuler.net")
    con.request("GET", "/project/triangle.txt")
    resp = con.getresponse()
    print "%s %s" % (resp.status, resp.reason)
    tree = parse_tree_from_text(resp.read().strip())
    print tree.max_total()
    
    
