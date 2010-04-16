#!/usr/bin/perl -w
use strict;

sub countcollatzchain {
	my $count = 1;
	(my $num) = @_ or die $!;
	while ($num != 1) {
		if ($num % 2 == 0) {
			$num /= 2;
		} else {
			$num = 3 * $num + 1;
		}
		$count++;
	}
	return $count;
}
my $max = 0;
my $maxi = 0;
for (my $i = 1;$i < 1000000;$i++) {
	my $newcount = &countcollatzchain($i);
	if ($newcount > $max) {
		print "newmax: $newcount - oldmax: $max - i: $i\n";
		$max = $newcount;
		$maxi = $i;
	}
}
print $maxi . "\n";
