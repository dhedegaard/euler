#!/usr/bin/perl
use strict;
use warnings;
use bigint;

sub digital_sum {
	my ($num) = @_ or die $!;
	my $sum = 0;
	foreach($num =~ /(\d)/g) {
		$sum += $_;
	}
	return $sum;
}

my $max = 0;
for (my $a = 90;$a < 100;$a++) {
	for (my $b = 90;$b < 100;$b++) {
		my $c = &digital_sum($a ** $b);
		$max = $c if ($c > $max);
	}
}
print "$max\n";
