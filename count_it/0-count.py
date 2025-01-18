#!/usr/bin/python3
"""
This is some documentation
"""
import requests


def count_words(subreddit, word_list, after=None, counter=None):
    """
    Recursive function to count occurrences of
    keywords in hot posts of a subreddit.

    Args:
        subreddit (str): The subreddit to query.
        word_list (list): List of keywords to count.
        after (str): Pagination parameter for Reddit API (default: None).
        counter (dict): Accumulator for keyword counts (default: None).
    """
    # Initialize the counter dictionary on the first call
    if counter is None:
        counter = {word.lower(): 0 for word in word_list}
    if not word_list:
        return

    # Base API URL
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "keyword-count-bot"}
    params = {"limit": 100, "after": after}

    # Make the request to Reddit
    response = requests.get(url, headers=headers,
                            params=params,
                            allow_redirects=False)

    if response.status_code != 200:
        return  # Exit if subreddit is invalid or unreachable

    # Parse JSON data
    data = response.json()
    posts = data.get("data", {}).get("children", [])
    after = data.get("data", {}).get("after", None)

    # Process titles of the posts
    for post in posts:
        title = post.get("data", {}).get("title", "").lower().split()
        for word in title:
            clean_word = ''.join(filter(str.isalnum, word))
            if clean_word in counter:
                counter[clean_word] += 1

    # Recursively call the function if there are more pages
    if after:
        count_words(subreddit, word_list, after, counter)
    else:
        # Sorting and printing results once recursion ends
        sorted_counts = sorted(
            [(word, count) for word,
             count in counter.items() if count > 0],
            key=lambda x: (-x[1], x[0])
        )
        for word, count in sorted_counts:
            print(f"{word}: {count}")
