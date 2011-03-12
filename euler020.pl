#!/usr/bin/perl -w
use strict;
use warnings;
use Math::BigInt;

sub faculty {
	(my $num) = @_ or die $!;
	my $sum = Math::BigInt->new(1);
	while ($num > 1) {
		$sum *= $num--;
	}
	return $sum;
}
my $result = &faculty(100);
my $sum = 0;
for (my $i = 0;$i < length($result);$i++) {
	$sum += int(substr($result, $i, 1));
}
print $result . "\n";
print $sum . "\n";
