#!/usr/bin/perl
use strict;
use warnings;

sub get_number_of_diagonals {
	my ($len) = @_ or die $!;
	return $len * 2 - 1;
}

# width of the spiral
my ($len) = @ARGV or die $!;
my $sum = 1;
# current number
my $n = 3;
# delta sum
my $d = 2;
# count for increasing $d periodically.
my $c = 1;
foreach(2..&get_number_of_diagonals($len)) {
	$sum += $n;
	$n += $d;
	$c++;
	if ($c > 3) {
		$c = 0;
		$d += 2;
	}
}
print "$sum\n";
