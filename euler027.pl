#!/usr/bin/perl
use strict;
use warnings;

my %prime_hash;

sub is_prime {
	my ($n) = @_ or die $!;
	return 0 if $n < 0;
	return $prime_hash{$n} if defined $prime_hash{$n};
	for my $m(2..$n-1) {
		if ($n % $m == 0) {
			$prime_hash{$n} = 0;
			return 0;
		}
	}
	$prime_hash{$n} = 1;
	return 1;
}

my $maxn = 1;
my ($maxa, $maxb);
print "a:\tb:\tn:\n";
foreach my $a(-1000..1000) {
	foreach my $b(-1000..1000) {
		my $n = 0;
		while (&is_prime($n**2 + $a * $n + $b)) {
			$n++;
		}
		if ($n > $maxn) {
			print "$a\t$b\t$n\n";
			$maxn = $n;
			$maxa = $a;
			$maxb = $b;
		}
	}
}
print "$maxa * $maxb = " . $maxa * $maxb . "\n";
