#!/usr/bin/env ruby
# -*- coding: utf-8 -*-

def fibo
  a, b, n = 1, 0, 0
  while b.to_s.length < 1000
    a, b, n = a + b, a, n + 1
  end
  n
end

puts fibo
