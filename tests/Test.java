package tests;

import solutions.Solution; 
import java.util.*;

public class Test {

    public static void printList(List<Integer> list) {
        System.out.println(list);
    }

    public static void runTestCases() {
        int[][][] testCases = {
                { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } },
                { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } },
                { { 1, 2 }, { 3, 4 } },
                { { 1 } },
                {},
                { { 1 }, { 2 }, { 3 } }
        };
        List<List<Integer>> expectedResults = Arrays.asList(
                Arrays.asList(1, 2, 3, 6, 9, 8, 7, 4, 5),
                Arrays.asList(1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7),
                Arrays.asList(1, 2, 4, 3),
                Arrays.asList(1),
                Arrays.asList(),
                Arrays.asList(1, 2, 3));

        Solution sol = new Solution();
        int passed = 0, failed = 0;
        // stratting loop
        for (int i = 0; i < testCases.length; i++) {
            List<Integer> result = sol.spiralOrder(testCases[i]);

            System.out.println("Test Case " + (i + 1) + ":");
            System.out.print("Expected: ");
            printList(expectedResults.get(i));
            System.out.print("Got:      ");
            printList(result);

            if (result.equals(expectedResults.get(i))) {
                System.out.println("✅ Passed\n");
                passed++;
            } else {
                System.out.println("❌ Failed\n");
                failed++;
            }
        }

        System.out.println("Test Cases Passed: " + passed);
        System.out.println("Test Cases Failed: " + failed);
        System.out.println("Total Test Cases: " + (passed + failed));
    }

    public static void main(String[] args) {
        runTestCases();
    }
}