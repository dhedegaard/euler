#!/usr/bin/perl
use strict;
use warnings;
use Bit::Vector;

# converts a decimal to binary.
sub dec2bin {
	my ($num) = @_ or die $!;
	my $str = Bit::Vector->new_Dec(32, $num)->to_Bin();
	$str =~ s/^0+(?=\d)//;
	return $str;
}

# check for palindrome in the input.
sub palindromic {
	my ($num) = @_ or die $!;
	my @str = $num =~ /(\d)/g;
	for (my $i = 0;$i < @str / 2;$i++) {
		return 0 if ($str[$i] ne $str[@str - 1 - $i]);
	}
	return 1;
}

my $sum = 0;
# we can skip even numbers, since they don't have 1's in both ends.
for (my $i = 1; $i < 1000000; $i += 2) {
	if (&palindromic($i) && &palindromic(&dec2bin($i))) {
		$sum += $i;
		print "$i\n";
	}
}
print "---------------------\n"
print $sum . "\n";
