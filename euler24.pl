#!/usr/bin/perl
use strict;
use warnings;
# args: 0123456789

my $count = 0;

sub permutate {
	my $a = shift or die $!;
	$count = 0;
	&_permutate($a, []);
}

sub _permutate {
	my $a = shift;
	my $b = shift;
	if (defined $a->[0]) {
		for my $i (0..$#$a) {
			my @a2 = @$a;
			my @b2 = @$b;
			splice @a2, $i, 1;
			push @b2, $$a[$i];
			&_permutate(\@a2, \@b2);
		}
	} else {
		$count++;
		print "$count: " . join("", @$b) . "\n" if $count == 1000000;
	}
}
my $input = sprintf "%s", $ARGV[0] or die $!;
die $! if not $input;
chomp $input;
my $arr = [];
foreach (sort split //, $input) {
	push @$arr, $_;
}
&permutate($arr);
