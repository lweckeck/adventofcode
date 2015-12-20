import java.util.*;
import java.io.*;

public class Combinations {

    static List<Integer> containers = new ArrayList<Integer>();
    static int[][] cache;
    static boolean[][] cached;

    public static int numberOfCombinationsFor(int x, int c) {
	if (cached[x][c]) {
	    return cache[x][c];
	}
	// container not used
	int result = numberOfCombinationsFor(x, c-1);
	if (containers.get(c-1) <= x) {
	    // container used
	    result += numberOfCombinationsFor(x-containers.get(c-1), c-1);
	}
	cache[x][c] = result;
	cached[x][c] = true;
	return result;
    }
    
    public static void main (String[] args) throws IOException {
	if (args.length < 2) {
	    System.err.println("Usage: java Combinations <#items> <container-file>");
	    System.exit(1);
	}
	
	try(BufferedReader br = new BufferedReader(new FileReader(args[1]))) {
	    String line = "";

	    while ((line = br.readLine()) != null) {
		containers.add(Integer.parseInt(line));
	    }
	    int n = Integer.parseInt(args[0]);
	    int m = containers.size();

	    cache = new int[n+1][m+1];
	    cached = new boolean[n+1][m+1];
	    for (int i=1; i<n+1; i++) {
		cache[i][0] = 0;
		cached[i][0] = true;
	    }
	    for (int i=0; i<m+1; i++) {
		cache[0][i] = 1;
		cached[0][i] = true;
	    }
	    int combinations = numberOfCombinationsFor(n, m);
	    System.out.println(combinations);
	}
    }
}
