#include "strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utf8_byte_count(char ch) {
  unsigned char byte = (unsigned char)ch;

  if (byte <= 0x7F) {
    return 1; // ASCII
  } else if ((byte & 0xE0) == 0xC0) {
    return 2; // 2-byte UTF-8 character
  } else if ((byte & 0xF0) == 0xE0) {
    return 3; // 3-byte UTF-8 character
  } else if ((byte & 0xF8) == 0xF0) {
    return 4; // 4-byte UTF-8 character
  } else {
    return -1; // Invalid byte
  }
}

uint32_t utf8_to_codepoint(const string_t str, int *char_len) {
  unsigned char byte1 = (unsigned char)str[0];
  int num_bytes = utf8_byte_count(byte1);

  if (num_bytes == 1) {
    *char_len = 1;
    return byte1;
  } else if (num_bytes == 2) {
    *char_len = 2;
    return ((byte1 & 0x1F) << 6) | ((unsigned char)str[1] & 0x3F);
  } else if (num_bytes == 3) {
    *char_len = 3;
    return ((byte1 & 0x0F) << 12) | (((unsigned char)str[1] & 0x3F) << 6) |
           ((unsigned char)str[2] & 0x3F);
  } else if (num_bytes == 4) {
    *char_len = 4;
    return ((byte1 & 0x07) << 18) | (((unsigned char)str[1] & 0x3F) << 12) |
           (((unsigned char)str[2] & 0x3F) << 6) |
           ((unsigned char)str[3] & 0x3F);
  } else {
    *char_len = -1; // Invalid UTF-8 sequence
    return 0;
  }
}

utf8arr_t parse_utf8_string(const string_t str) {
  int index = 0;
  int char_len = 0;
  int codepoint_count = 0;

  // First pass: count the number of UTF-8 characters in the string
  while (str[index] != '\0') {
    int bytes = utf8_byte_count(str[index]);
    if (bytes > 0) {
      codepoint_count++;
      index += bytes;
    } else {
      index++; // Skip invalid byte
    }
  }

  // Allocate memory for storing Unicode code points
  uint32_t *codepoints = (uint32_t *)malloc(codepoint_count * sizeof(uint32_t));
  if (!codepoints) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  // Second pass: extract and store the code points
  index = 0;
  int current = 0;
  while (str[index] != '\0') {
    uint32_t codepoint = utf8_to_codepoint(&str[index], &char_len);
    if (char_len > 0) {
      codepoints[current++] = codepoint;
      index += char_len;
    } else {
      index++; // Skip invalid byte
    }
  }

  // Return the result as a struct
  utf8arr_t result;
  result.codepoints = codepoints;
  result.length = codepoint_count;
  return result;
}

void free_utf8_arr(utf8arr_t *result) {
  if (result->codepoints) {
    free(result->codepoints);
    result->codepoints = NULL;
  }
}
