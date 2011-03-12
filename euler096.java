import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import sudoku.lib.Solver;

/**
 * An implementation to solve the euler96 problem.
 * 
 * @author Dennis Hedegaard
 * 
 */
public final class euler96 {
	private euler96() {
	}

	private static int[] parse_line(String line) {
		if (line.startsWith("Grid"))
			return null;
		else {
			int[] arr = new int[9];
			for (int i = 0; i < 9; i++)
				arr[i] = line.charAt(i) - '0';
			return arr;
		}
	}

	/**
	 * Parses the data and returns a list of boards.
	 * 
	 * @return
	 */
	private static List<int[][]> parse() throws IOException {
		List<int[][]> result = new ArrayList<int[][]>();
		Scanner input = new Scanner(new File("euler96-data"));
		int[][] buffer = null;
		int ypos = 0;
		while (input.hasNextLine()) {
			String line = input.nextLine();
			int[] parsed = parse_line(line);
			if (parsed == null) {
				if (buffer != null)
					result.add(buffer);
				buffer = new int[][] { new int[9], new int[9], new int[9],
						new int[9], new int[9], new int[9], new int[9],
						new int[9], new int[9] };
				ypos = 0;
			} else {
				buffer[ypos++] = parsed;
			}
		}
		if (buffer != null)
			result.add(buffer);
		return result;
	}

	public static void main(String[] args) {
		List<int[][]> boards = null;
		try {
			boards = parse();
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
		int sum = 0;
		for (int[][] board : boards) {
			int[][] solved = Solver.solve(board);
			sum += solved[0][0] * 100 + solved[0][1] * 10 + solved[0][2];
		}
		System.out.println(sum);
	}
}
