"""
Question:
https://leetcode.com/problems/satisfiability-of-equality-equations/

Medium
"""
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        arr=[set()]
        for equation in equations:
            if equation[1]=='=':
                operator='=='
            else:
                operator='!='
            
            if operator=='==':
                var1 = equation[0]
                var2 = equation[3]
                var1_index = -1
                var2_index = -2
                for index, row in enumerate(arr):
                    if var1 in row:
                        var1_index = index
                    if var2 in row:
                        var2_index = index
                if var1_index==-1 and var2_index!=-2:
                    arr[var2_index].add(var1)
                elif var1_index!=-1 and var2_index==-2:
                    arr[var1_index].add(var2)
                elif var1_index==-1 and var2_index==-2:
                    arr.append(set())
                    arr[len(arr)-1].add(var1)
                    arr[len(arr)-1].add(var2)
                else:
                    if var1_index==var2_index:
                        continue
                    else:
                        arr[var1_index] = arr[var1_index].union(arr[var2_index])
                        del arr[var2_index]
            else:
                continue

        for equation in equations:
            if equation[1]=='=':
                operator='=='
            else:
                operator='!='
            
            if operator=='==':
                continue
            else:
                var1 = equation[0]
                var2 = equation[3]
                var1_index = -1
                var2_index = -2
                for index, row in enumerate(arr):
                    if var1 in row:
                        var1_index = index
                    if var2 in row:
                        var2_index = index
                if var1_index == var2_index:
                    return False
                elif var1==var2: # like: ["a!=a"]
                    return False
                elif var1_index != var2_index:
                    continue
        return True