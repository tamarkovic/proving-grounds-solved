def permute(int_list):
    if len(int_list) == 1:
        return [int_list]

    permutation = []

    for i in range(len(int_list)):
        for j in permute(int_list[:i] + int_list[i+1:]):
            permutation.append([int_list[i]] + j)

    return permutation