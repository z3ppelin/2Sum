/**
 * Check if there are distinct numbers x,y in the input file that satisfy x + y = sum.
 *
 * @author      Bogdan Constantinescu <bog_con@yahoo.com>
 * @since       2013.07.08
 * @version     1.0
 * @link        GitHub   https://github.com/z3ppelin/2Sum
 * @licence     The MIT License (http://opensource.org/licenses/MIT); see LICENCE.txt
 */

import java.io.FileInputStream;
import java.util.*;

public class TwoSum {

    public static Long sum;

    /**
     * Main function. Reads vector, sorts it, and prints it.
     *
     * @param args Command line arguments.
     */
    public static void main(String[] args) {
        System.out.println("------ Begin TwoSum ------");
        Long[] vector = null;
        long start, end;
        boolean found = false;
        Long x = null, y = null;

        /* read vector */
        try {
            if (args.length == 0) {
                throw new Exception("The input file must be given as an argument.");
            }
            vector = readVectorFromFile(args[0]);
        } catch (Exception ex) {
            System.out.println("ERR. " + ex.getMessage());
            System.out.println("------- End TwoSum -------");
            System.exit(-1);
        }

        /* print read vector */
        //System.out.print("The read vector is: ");
        //printVector(vector);
        //System.out.println();

        /* start searching for x,y, x != y, so x + y = sum */
        start = System.currentTimeMillis();
        QuickSort.quickSort(vector, 0, vector.length - 1);
        for (int i = 0; i < vector.length; i++) {
            if (vector[i] != sum - vector[i] && -1 != BinarySearch.binarySearch(vector, 0, vector.length - 1, sum - vector[i])) {
                found = true;
                x = vector[i];
                y = sum - vector[i];
                break;
            }
        }
        end = System.currentTimeMillis();

        /* print results */
        if (found) {
            System.out.println("Found " + x + " + " + y + " = " + sum);
        } else {
            System.out.println("Found no elements with sum " + sum);
        }

        System.out.println("Elapsed: " + ((double) (end - start) / 100) + " seconds.");
        System.out.println("------- End TwoSum -------");
    }

    /**
     * Prints an array 's elements.
     *
     * @param v The vector to print.
     */
    public static void printVector(Long[] v) {
        for (int i = 0; i < v.length; i++) {
            System.out.print(v[i] + " ");
        }
    }

    /**
     * Reads array from file.
     *
     * @param   file The file where to read array from.
     * @return      The read vector.
     * @throws Exception
     */
    public static Long[] readVectorFromFile(String file) throws Exception {
        Scanner sc;
        FileInputStream fis = null;
        int n;
        Long[] v;
        try {
            fis = new FileInputStream(file);
            sc = new Scanner(fis);
            if (sc.hasNextInt()) {
                n = sc.nextInt();
            } else {
                throw new Exception("Could not read the number of elements vector has.");
            }
            if (sc.hasNextLong()) {
                sum = sc.nextLong();
            } else {
                throw new Exception("Could not read target sum to search for if there are 2 values x + y = sum.");
            }
            v = new Long[n];
            for (int i = 0; i < n; i++) {
                if (sc.hasNextLong()) {
                    v[i] = sc.nextLong();
                } else {
                    throw new Exception("Number of declared elements does not match with the one found in file.");
                }
            }
            fis.close();
        } catch (Exception ex) {
            if (fis != null) {
                try {
                    fis.close();
                } catch (Exception e) {
                }
            }
            throw ex;
        }
        return v;
    }
}
