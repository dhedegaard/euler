#!/usr/bin/perl -w
use strict;
use warnings;
use bigint;

my $sum = 0;
for (my $i = 1;$i <= 1000;$i++) {
	$sum += $i ** $i;
}
# get the last 10 chars, before $ (end of line).
my @result = $sum =~ m/(.{10})$/gs;
print $result[0] . "\n";
