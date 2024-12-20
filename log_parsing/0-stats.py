#!/usr/bin/python3
import sys
import signal
import re
from collections import defaultdict

# Initialize counters
total_size = 0
status_code_count = defaultdict(int)
line_count = 0

# Regex to match the required input format
log_line_pattern = re.compile(
    r'^([\d\.]+) - \[(.*?)\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
)

# Status codes of interest
valid_status_codes = {200, 301, 400, 401, 403, 404, 405, 500}

def print_statistics():
    """Print accumulated statistics."""
    print(f"File size: {total_size}")
    for code in sorted(status_code_count.keys()):
        if status_code_count[code] > 0:
            print(f"{code}: {status_code_count[code]}")

def signal_handler(sig, frame):
    """Handle keyboard interrupt (Ctrl + C) to print statistics."""
    print_statistics()
    sys.exit(0)

# Bind signal handler
signal.signal(signal.SIGINT, signal_handler)

try:
    for line in sys.stdin:
        line = line.strip()
        match = log_line_pattern.match(line)
        if match:
            ip, date, status_code, file_size = match.groups()
            status_code = int(status_code)
            file_size = int(file_size)

            # Update metrics
            total_size += file_size
            if status_code in valid_status_codes:
                status_code_count[status_code] += 1
        
        line_count += 1

        # Print statistics every 10 lines
        if line_count % 10 == 0:
            print_statistics()
except KeyboardInterrupt:
    # Catch keyboard interruption
    print_statistics()
    sys.exit(0)
