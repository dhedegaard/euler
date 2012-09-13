#!/usr/bin/ruby
# -*- coding: utf-8 -*-

def fibo_seq(n)
  result = Array.new
  a, b = 1, 0
  while b < n do
    result << b
    a, b = a + b, a
  end
  return result
end

puts fibo_seq(4*10**6).find_all{|item| item % 2 == 0}.inject(0){|sum,item| sum + item}
