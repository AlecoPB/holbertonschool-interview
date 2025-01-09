def rain(walls):
    if not walls or len(walls) < 3:
        return 0  # No water can be retained if list is empty or has less than 3 walls

    left, right = 0, len(walls) - 1
    left_max, right_max = 0, 0
    trapped_water = 0

    while left < right:
        if walls[left] <= walls[right]:
            if walls[left] < left_max:
                trapped_water += left_max - walls[left]
            else:
                left_max = walls[left]
            left += 1
        else:
            if walls[right] < right_max:
                trapped_water += right_max - walls[right]
            else:
                right_max = walls[right]
            right -= 1

    return trapped_water
