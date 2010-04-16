#!/usr/bin/perl -w
use strict;
use warnings;
use Math::BigInt;

my $num = Math::BigInt->new(2);
$num = $num ** 1000;
my $sum = 0;
for (my $i = 0;$i < length($num);$i++) {
	$sum += int(substr($num, $i, 1));
}
print $sum . "\n";
