/**
 * Binary search. Searches for a value in a sorted vector in O(log n).
 * 
 * @author      Bogdan Constantinescu <bog_con@yahoo.com>
 * @since       2013.07.08
 * @version     1.0
 * @link        GitHub  https://github.com/z3ppelin/2Sum
 * @licence     The MIT License (http://opensource.org/licenses/MIT); see LICENCE.txt
 */

public class BinarySearch {

    /**
     * Binary seaches for a given value in a sorted vector.
     *
     * @param <T>           Any comarable object.
     * @param v             The sorted vector to search in.
     * @param left          The left margin of the vector.
     * @param right         The right margin of the vector.
     * @param searchedValue The searched value.
     * @return              Position in the vector of the searched value, -1 if not found.
     */
    public static <T extends Comparable<T>> int binarySearch(T[] v, int left, int right, T searchedValue) {
        if (right < left) {
            return -1;
        }
        int middle = (right + left) / 2;
        if (v[middle].equals(searchedValue)) {
            return middle;
        } else if (searchedValue.compareTo(v[middle]) > 0) {
            return binarySearch(v, middle + 1, right, searchedValue);
        } else {
            return binarySearch(v, left, middle - 1, searchedValue);
        }
    }
}