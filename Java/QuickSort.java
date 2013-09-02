/**
 * Sorting a vector via QuickSort algorithm in O(n * log n) on average.
 *
 * @author      Bogdan Constantinescu <bog_con@yahoo.com>
 * @since       2013.07.08
 * @version     1.0
 * @link        GitHub  https://github.com/z3ppelin/2Sum
 * @licence     The MIT License (http://opensource.org/licenses/MIT); see LICENCE.txt
 */

public class QuickSort {
    /**
     * Recursive function (based on Divide and Conquer algorithm) that sorts a
     * vector (via Quick Sort algorithm).
     *
     * @param   <T>       Any comarable object.
     * @param   v         The vector to sort.
     * @param   left      The left margin of the vector.
     * @param   right     The right margin of the vector.
     */
    public static <T extends Comparable<T>> void quickSort(T[] v, int left, int right) {
        if (left < right) {
            int i = partition(v, left, right);
            quickSort(v, left, i - 1);
            quickSort(v, i + 1, right);
        }
    }

    /**
     * Partition the vector, choose a pivot and arrange all elements lower than
     * it to the left, elements bigger than it to the right.
     *
     * @param   <T>     Any comarable object
     * @param   v       The vector to sort.
     * @param   left    The left margin of the vector.
     * @param   right   The right margin of the vector.
     * @return          The pivot position.
     */
    public static <T extends Comparable<T>> int partition(T[] v, int left, int right) {
        int i = left + 1, j, pivotPos;
        pivotPos = left + (int) (Math.random() * ((right - left) + 1));
        T pivot = v[pivotPos], aux;

        /* make pivot the first element */
        v[pivotPos] = v[left];
        v[left] = pivot;

        for (j = left + 1; j <= right; j++) {
            if (pivot.compareTo(v[j]) > 0) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
            }
        }

        /* move pivot between elements < pivot and elements > pivot */
        v[left] = v[i - 1];
        v[i - 1] = pivot;

        return i - 1; // pivot pos
    }
}
