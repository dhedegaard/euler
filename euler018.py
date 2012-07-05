#!/usr/bin/python

data = """
75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
""".strip()

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
    tree = parse_tree_from_text(data)
    print tree.max_total()
    
    
