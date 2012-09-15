#!/usr/bin/python
# -*- coding: utf-8 -*-
'''
A simple script for listing euler problems solved, and the
languages used for solving them.

Put the script in the directory with the euler sollutions and
run it.

@author: Dennis Hedegaard
'''

import os
import os.path
import re

# Regex for valid filename (eg euler067.cpp), capture euler number.
EULER_MATCH = re.compile('^euler(\d+)\.\w+$')

# File extensions to identify
FILETYPES = {
    '.c'    : 'C',
    '.cpp'  : 'C++',
    '.py'   : 'Python',
    '.rb'   : 'Ruby',
    '.pl'   : 'Perl',
    '.java' : 'Java',
    '.cs'   : 'C#',
}

def main():
    '''
    Aggregates all euler problems in the folder, showing what
    languages they were done in, up and to the highest problem you've solved.
    '''

    # the languages for each euler problem.
    eulers = {}
    # the number of times a language is used.
    languages = {}

    for f in sorted(os.listdir(os.path.dirname(os.path.realpath(__file__)))):
        ext = os.path.splitext(f)[1]
        match = EULER_MATCH.match(f)

        if not match or ext not in FILETYPES:
            continue

        eulernumber = int(match.groups()[0])
        language = FILETYPES[ext]

        if not eulers.has_key(eulernumber):
            eulers[eulernumber] = [language]
        else:
            eulers[eulernumber].append(language)

        if not languages.has_key(language):
            languages[language] = 1
        else:
            languages[language] += 1

    count_problems = len(eulers.keys())

    # append empty (unsolved) problems to the dict.
    for i in xrange(1, max(eulers)):
        if not eulers.has_key(i):
            eulers[i] = []

    # print the aggregated output
    for k,v in sorted(eulers.items()):
        print '%3s:\t%s' % (k, ', '.join(v))

    string_languages = ', '.join(['%s(%d)' % (k,v) for k,v in sorted(languages.items(), key=lambda x: x[1], reverse=True)],)

    print '\nNumber of problems with code: %d' % count_problems
    print 'Programming languages used: %s' % string_languages

if __name__ == '__main__':
    main()
