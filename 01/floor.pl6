
sub MAIN($file) {
    my $input = slurp $file;
    my $level = 0;

    loop (my $i=0; $i < $input.chars; $i++) {
	given $input.substr($i, 1) {
	    when "(" { $level++; }
	    when ")" { $level--; }
	}
    }

    say $level;
}
