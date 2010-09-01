#!/usr/bin/perl
use strict;
use warnings;
use bigint;

sub doit {
	my ($coins) = @_ or die $!;
	my $count = 0;
	for (my $i1 = 0;$i1 <= $coins;$i1++) {
		my $n1 = $i1;
		for (my $i2 = 0;$i2 <= $coins - $n1;$i2 += 2) {
			my $n2 = $n1 + $i2;
			for (my $i5 = 0;$i5 <= $coins - $n2;$i5 += 5) {
				my $n5 = $n2 + $i5;
				for (my $i10 = 0;$i10 <= $coins - $n5;$i10 += 10) {
					my $n10 = $n5 + $i10;
					for (my $i20 = 0;$i20 <= $coins - $n10;$i20 += 20) {
						my $n20 = $n10 + $i20;
						for (my $i50 = 0;$i50 <= $coins - $n20;$i50 += 50) {
							my $n50 = $n20 + $i50;
							for (my $i100 = 0;$i100 <= $coins - $n50;$i100 += 100) {
								my $n100 = $n50 + $i100;
								for (my $i200 = 0;$i200 <= $coins - $n100;$i200 += 200) {
									my $n200 = $n100 + $i200;
									if ($n200 == $coins) {
										$count++;
										if ($count % 50 == 0) {
											printf "%5s\n", $count;
										} elsif ($count % 10 == 0) {
											printf "%5s", $count;
										} else {
											print ".";
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	print "\n";
	return $count;
}

$| = 1;

sub doitnow {
	my ($coins) = @_ or die;
	my $count = 0;
	for (my $i1 = 0;$i1 <= $coins;$i1++) {
		my $n1 = $i1;
		for (my $i2 = 0;$i2 <= $coins - $n1;$i2 += 2) {
			my $n2 = $n1 + $i2;
			if ($n2 == $coins) {
				$count++;
				print "$n1 - $i2\n";
			}
		}
	}
	return $count;
}

print &doitnow(200) . "\n";
print &doit(200) . "\n";
