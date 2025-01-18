#!/usr/bin/python3
"""
This is some documentation
"""
from collections import Counter
import re


def count_words(subreddit, word_list, after=None, counts=None):
    """Recursively queries the Reddit API and counts occurrences of keywords in hot article titles."""
    if counts is None:
        counts = Counter()

    # Define the API endpoint
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {'User -Agent': 'Mozilla/5.0'}

    # Set parameters for the API request
    params = {'limit': 100}
    if after:
        params['after'] = after

    # Make the API request
    response = requests.get(url, headers=headers, params=params)

    # Check for valid subreddit
    if response.status_code != 200:
        return

    # Parse the JSON response
    data = response.json()
    articles = data.get('data', {}).get('children', [])
    after = data.get('data', {}).get('after', None)

    # Process each article
    for article in articles:
        title = article['data']['title'].lower()  # Convert title to lowercase
        for word in word_list:
            # Create a regex pattern for the word
            pattern = r'\b' + re.escape(word.lower()) + r'\b'
            matches = re.findall(pattern, title)
            counts[word.lower()] += len(matches)

    # If there are more articles, recurse
    if after:
        count_words(subreddit, word_list, after, counts)

    # Print the results after all recursive calls
    if after is None:  # Only print once after the final call
        print_results(counts)

def print_results(counts):
    """Prints the sorted results of keyword counts."""
    # Filter out words with zero counts
    filtered_counts = {word: count for word, count in counts.items() if count > 0}
    
    # Sort by count (descending) and then alphabetically (ascending)
    sorted_counts = sorted(filtered_counts.items(), key=lambda x: (-x[1], x[0]))

    for word, count in sorted_counts:
        print(f"{word}: {count}")
