#!/usr/bin/ruby
# -*- coding: utf-8 -*-

puts (1..999).find_all{|i| i % 3 == 0 or i%5 == 0}.inject(0){|s,i| s+i}
