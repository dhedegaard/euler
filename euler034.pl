#!/usr/bin/perl
# since the amount of these numbers decrease fast, we only have to run to ~50k
use strict;
use warnings;
use bigint;

# hash of factorials for 0..9
our @factorials = (
	1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880
);

# checks a number, to see if we should include it in the sum.
sub is_valid {
	my ($n) = @_ or die $!;
	my $sum = 0;
	foreach($n =~ /(\d)/g) {
		$sum += $factorials[$_];
	}
	return 1 if ($sum == $n);
	return 0;
}

my $sum = 0;
my $before = time;
foreach (10..50000) {
	if (&is_valid($_)) {
		print "found: $_\n";
		$sum += $_;
	}
}
print "-----------------------\n";
print "sum: $sum\n";
print "memory contains " . @factorials . " keys.\n";
print "took " . (time - $before) . " seconds\n";
