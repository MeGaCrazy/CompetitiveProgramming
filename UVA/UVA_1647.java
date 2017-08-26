import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author MeGaCrazy
 */
/*
* Idea : From Some Test Cases w Got that if number odd is equal sum of all prevoius if even equal all previous+1
*        Happy Solving :)
*
* */


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        UVA_1647 solver = new UVA_1647();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVA_1647 {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            BigInteger dp[] = new BigInteger[1001];
            dp[0] = BigInteger.ZERO;
            BigInteger sum = BigInteger.ZERO;
            for (int i = 1; i <= 1000; i++) {
                dp[i] = ((i & 1) == 1) ? sum : sum.add(BigInteger.ONE);
                sum = sum.add(dp[i]);
            }
            while (in.hasNext()) {
                int n = in.nextInt();
                out.println(dp[n]);
            }
        }

    }
}

