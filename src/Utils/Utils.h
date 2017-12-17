#ifndef UTILS_HPP
#define UTILS_HPP
#define MAX_STRING_SIZE 16

/**
 * @brief Concatenate a string and a float
 * @details This function concatenates a char array and a float. The in/out
 * buffer shall be allocated before calling the function
 *
 * @param header const har array at the beginning
 * @param value [description]
 * @param buffer Input/Output char buffer array. Must be large enough to contain
 * the concatenated string
 */
void concatenate(const char* header, float value, char* buffer);

#endif