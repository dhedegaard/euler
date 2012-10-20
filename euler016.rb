#!/usr/bin/ruby
# -*- coding: utf-8 -*-

puts ((2**1000).to_s.scan(/\d/).inject{|sum,c|sum=sum.to_i+c.to_i})
