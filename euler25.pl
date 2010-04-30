#!/usr/bin/perl -w
use strict;
use warnings;
use Math::BigInt;

my ($i, $fn, $fn1, $fn2) = (1, Math::BigInt->new(1), Math::BigInt->new(1), Math::BigInt->new(0));
my @count;
while (@count < 1000) {
	$fn = $fn1 + $fn2;
	$fn2 = $fn1;
	$fn1 = $fn;
	$i++;
	@count = split(//, $fn);
}
print $fn . "\n" . $i . "\n";
