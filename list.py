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
EULER_MATCH = re.compile('^euler(\d+)')

# File extensions to identify
FILETYPES = {
    '.c'    : 'C',
    '.cpp'  : 'C++',
    '.py'   : 'Python',
    '.rb'   : 'Ruby',
    '.pl'   : 'Perl',
    '.java' : 'Java',
    '.cs'   : 'C#',
    '.sh'   : '(B)ASH shell script',
}

def find_language_for_directory(dir):
    '''
    Estimates the language used for the directory specified.
    Simply walks through all files and returns languages for
    all types found.

    (dir: string) -> list of languages
    '''
    result = set()
    for root, dirs, files in os.walk(dir):
        for file in files:
            ext = os.path.splitext(file)[1]
            if ext and ext in FILETYPES and not FILETYPES[ext] in result:
                result.add(FILETYPES[ext])
    if len(result) > 0:
        return list(result)
    else:
        return None

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

        match = EULER_MATCH.match(f)

        if not match:
            continue

        if os.path.isdir(f):
            language = find_language_for_directory(f)
            if language == None:
                continue
            
        else:
            ext = os.path.splitext(f)[1]
            if ext not in FILETYPES:
                continue
            language = (FILETYPES[ext],)

        eulernumber = int(match.groups()[0])

        if not eulers.has_key(eulernumber):
            eulers[eulernumber] = set(language)
        else:
            for l in language:
                eulers[eulernumber].add(l)

        for l in language:
            if not languages.has_key(l):
                languages[l] = 1
            else:
                languages[l] += 1

    count_problems = len(eulers.keys())

    # append empty (unsolved) problems to the dict.
    for i in xrange(1, max(eulers)):
        if not eulers.has_key(i):
            eulers[i] = []

    # print the aggregated output
    print 'Euler problems:'
    for k,v in sorted(eulers.items()):
        print '%8s:\t%s' % (k, ', '.join(v))

    print
    # print the languages used
    print 'Languages used:'
    for language, count in sorted(languages.items(), key=lambda x: x[1], reverse=True):
        print '%8s:\t%d' % (language, count)

    print '\nNumber of problems with code: %d' % count_problems

if __name__ == '__main__':
    main()
