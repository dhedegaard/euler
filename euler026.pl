#!/usr/bin/perl
# http://www.perlmonks.org/?node_id=637880
use strict;
use warnings;

use constant COUNT  => $ARGV[0]||99;
use constant LENGTH => length COUNT;

use bignum a => 3*COUNT; # accuracy ...

my ($i, $len) = (0, 0);
for my $n (1..COUNT) {
  my $f = substr(1/$n, 0, 3*COUNT); # precision too ...
  if ( $f =~ /(\d+?)\1+(?!\d{${\COUNT}})/ ) { # a little leeway ...
    printf " 1/%-*d = %-30.30s -> (%d) %s\n", LENGTH, $n, $f, length $1, $1;
	if (length $1 > $len) {
		$i = $n;
		$len = length $1;
	}
  }
  else {
    # should never happen ...
    die "Insufficient precision/accuracy?  Cannot handle the following
+:\n$f\n";
  }
}
print $i . ": " . $len ."\n";
