
sub MAIN($file) {
    my $input = slurp $file;
    my $level = 0;

    my $i = 0;
    repeat {
	given $input.substr($i, 1) {
	    when "(" { $level++; }
	    when ")" { $level--; }
	}
	$i++;
    } until $level == -1 or $i == $input.chars;
    
    say $i;
}
