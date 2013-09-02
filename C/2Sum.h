/** 
 * Header file for 2Sum problem.
 * 
 * @author      Bogdan Constantinescu <bog_con@yahoo.com>
 * @since       2013.08.14
 * @version     1.0
 * @link        GitHub    https://github.com/z3ppelin/2Sum
 * @licence     The MIT License (http://opensource.org/licenses/MIT); see LICENCE.txt
 */

#ifndef _2_SUM_H_
#define _2_SUM_H_

/* function prototypes */
void quickSort(long long*, const int, const int);
int partition(long long*, const int, const int);
void err(const char*);
int readVectorFromFile(long long**, int*, long long*, char*, char*);
void printVector(const long long*, const int);
int binarySearch(const long long*, const int, const int, const long long);

#endif /* _2_SUM_H_ */
