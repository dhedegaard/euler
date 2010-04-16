#!/usr/bin/perl -w
use strict;
use Math::BigInt;

# solved in perl using Math::BigInt and substr for the first 10 integers.
# This is primarily a parser assignment =)

open F, '<euler13-data' or die $!;
my @arr;
@arr = <F>;
my $sum = Math::BigInt->new(0);
foreach my $line (@arr) {
	print $line;
	$sum += $line;
}
print "sum: $sum\n";
my $sumstr = Math::BigInt->new($sum);
print substr($sumstr, 0, 10) . "\n";
close F;
