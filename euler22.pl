#!/usr/bin/perl -w
use strict;
use warnings;

my $a = ord('A') - 1;
sub namevalue {
	# gets the value of a name, takes a name and a hashtable for args.
	my $value = 0;
	my ($name) = @_ or die "bad args" . $!;
	my @chars = split(//, $name);
	foreach my $c (@chars) {
		$value += ord($c) - $a;
	}
	return $value;
}
open FILE, "<euler22-data";
my @lines = sort <FILE> =~ m/"([^,]*)"/sg;
my $count = 1;
my $result = 0;
foreach my $line (@lines) {
	my $value = &namevalue($line);
	$result += $value * $count;
	print $count++ . ": " . $line . ": " . &namevalue($line) . "\n";
}
close FILE;
print $result . "\n";
