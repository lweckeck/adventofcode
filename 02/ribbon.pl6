
sub MAIN($file) {
    my $input = slurp $file;
    my $ribbon = 0;
    for $input.split("\n") {
	my $sides = $_.split("x").sort: *.Int;
	$ribbon +=  2 * $sides[0] + 2 * $sides[1];
	$ribbon +=  $sides[0] * $sides[1] * $sides[2];
    }
    say $ribbon
}
