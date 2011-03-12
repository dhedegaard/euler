#!/usr/bin/perl
use strict;
use warnings;

sub sum_of {
	my ($n) = @_ or die $!;
	my $sum = 0;
	foreach(split //, $n) {
		$sum += $_ ** 5;
	}
	return $n == $sum;
}

my @arr;
foreach (100..999999) {
	push @arr, $_ if &sum_of($_);
}
my $sum = 0;
foreach (@arr) {
	$sum += $_;
	print "$_\n";
}
print "--------------------------\n";
print "$sum\n";
