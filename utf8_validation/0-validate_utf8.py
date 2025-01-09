#!/usr/bin/python3
def validUTF8(data):
    """
    Determine if a given data set represents a valid UTF-8 encoding.

    :param data: List[int] - The input data set where each integer represents 1 byte
    :return: bool - True if the data set is a valid UTF-8 encoding, False otherwise
    """
    def is_valid_byte(byte):
        # Checks if the byte starts with '10'
        return (byte & 0b11000000) == 0b10000000

    # Number of bytes left in the current character
    remaining_bytes = 0

    for byte in data:
        # Mask to only consider the 8 least significant bits
        byte &= 0xFF

        if remaining_bytes == 0:
            # Determine the number of bytes in the current character
            if (byte & 0b10000000) == 0:  # 1-byte character
                continue
            elif (byte & 0b11100000) == 0b11000000:  # 2-byte character
                remaining_bytes = 1
            elif (byte & 0b11110000) == 0b11100000:  # 3-byte character
                remaining_bytes = 2
            elif (byte & 0b11111000) == 0b11110000:  # 4-byte character
                remaining_bytes = 3
            else:
                return False  # Invalid starting byte
        else:
            # Check if the byte is a valid continuation byte
            if not is_valid_byte(byte):
                return False
            remaining_bytes -= 1

    # If there are no remaining bytes expected, the data is valid
    return remaining_bytes == 0
