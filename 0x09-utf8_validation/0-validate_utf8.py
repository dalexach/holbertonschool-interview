#!/usr/bin/python3
"""
UTF-8 Validation
"""

def validUTF8(data):
    """
    Method that determines if a given data set represents a valid UTF-8 encoding

    Arguments:
     - data: can contain multiple characters

    Returns:
     True if data is a valid UTF-8 encoding, else return False
    """

    nbytes = 0

    for n in data:
        byte = format(n, '#010b')[-8:]
        if nbytes == 0:
            if byte[0] == '1':
                nbytes = len(byte.split('0')[0])
            if nbytes > 4 or nbytes == 1:
                return False
            if nbytes == 0:
                continue
        else:
            if not byte.startswith('10'):
                return False
        nbytes -= 1
    if nbytes != 0:
        return False
    return True