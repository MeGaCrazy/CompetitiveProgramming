import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author MeGaCrazy
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        UVA_10058 solver = new UVA_10058();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVA_10058 {
        private static final String VERB = "(hate|love|know|like)s*";
        private static final String NOUN = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
        private static final String ARTICLE = "(a|the)";
        private static final String ACTOR = "(" + NOUN + "|" + ARTICLE + " " + NOUN + ")";
        private static final String ACTIVE_LIST = "(" + ACTOR + " and )*" + ACTOR;
        private static final String ACTION = ACTIVE_LIST + " " + VERB + " " + ACTIVE_LIST;
        private static final String STATEMENT = ACTION + "( , " + ACTION + ")*";

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String str;
            while (in.hasNextLine()) {
                str = in.nextLine();
                String s = "             bla     bla     ";
                out.println(s.trim());
                if (str.replaceAll(" +", " ").trim().matches(STATEMENT)) {
                    out.println("YES I WILL");
                } else {
                    out.println("NO I WON'T");
                }
            }
        }

    }
}

