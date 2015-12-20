
sub MAIN($file) {
    my $input = slurp $file;
    my $sqft = 0;

    for $input.split("\n") -> $line {
	my $dims = $line.split("x");
	my @sides = [$dims[0] * $dims[1],
		     $dims[1] * $dims[2],
		     $dims[0] * $dims[2]];
	$sqft += (2 * sum(@sides) + min(@sides));
    }
    say "paper = $sqft";
}
