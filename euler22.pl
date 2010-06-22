#!/usr/bin/perl -w
use strict;
use warnings;

my $a = ord('A') - 1;
sub namevalue {
	# gets the value of a name, takes a name and a hashtable for args.
	my $result = 0;
	my ($name) = @_ or die "bad args" . $!;
	foreach ($name =~ m/(.)/g) {
		$result += ord($_) - $a;
	}
	return $result;
}
open FILE, "<euler22-data" or die "unable to find euler22-data in wordir\n" . $!;
# the following regex takes a match of anything not a ',' between a " and a ".
my @lines = sort <FILE> =~ m/"([^,]*)"/sg;
close FILE;
my $count = 1;
my $result = 0;
foreach my $line (@lines) {
	my $value = &namevalue($line);
	$result += $value * $count++;
}
print $result . "\n";
