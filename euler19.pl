#!/usr/bin/perl -w
use strict;
use warnings;

# defines number of days in each month in a non leap-year.
my @months = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
# a simple function, that checks if a year is a leapyear.
sub isleapyear{
	my ($year) = @_ or die "bad args" . $!;
	if ($year % 4 == 0) {
		if ($year % 100 == 0) {
			if ($year % 400 == 0) {
				return 1;
			} else {
				return 0;
			}
		} else {
			return 1;
		}
	} else {
		return 0;
	}
}
# 1. jan 1900 is a monday.
my $weekday = 0;
# let's move forward 1 year, to 1. jan 1901.
for (my $month = 0;$month < 12;$month++) {
	$weekday = ($weekday + $months[$month]) % 7;
}
# let's start counting.
my $count = 0;
# we loop until the end of dec 2000.
for (my $year = 1901;$year <= 2000;$year++) {
	for (my $month = 0;$month < 12;$month++) {
		# if we're at a sunday, increment.
		if ($weekday % 7 == 6) {
			$count++;
		}
		if ($month == 1 && &isleapyear($year)) {
			# if we're in a leap year, and in februar.
			$weekday = ($weekday + $months[$month] + 1) % 7;
		} else {
			$weekday = ($weekday + $months[$month]) % 7;
		}
	}
}
# the result.
print $count . "\n";