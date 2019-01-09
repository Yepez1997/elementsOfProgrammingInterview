# Problem 5.18 Python Version 
import math 

"""
Outputs a Spiral Array 
"""

#first thing -> determain size want to create an n * n matrix 
# n x n matricies are perfect squares
# key to this problem is to keep trasck of your cordinates 
def spiralOrder(matrix):
        def spiral_coords(r1, c1, r2, c2):
            ## first do the colums left to right on top
            for c in range(c1, c2 + 1):
                print("top")
                yield r1, c
            ## next do the rigth colums from  topn right + 1 to bottom  rigth
            for r in range(r1 + 1, r2 + 1):
                print("right")
                yield r, c2
            if r1 < r2 and c1 < c2:
                ## third do the bottom column first IN REVERSE 
                for c in range(c2 - 1, c1, -1):
                    print("bottom")
                    yield r2, c
                ## fourth do the left side i.e r2 - r1 IN REVERSE 
                for r in range(r2, r1, -1):
                    print("left")
                    yield r, c1

        if not matrix: return []
        ans = []
        # subtact -1 since adding 1 in generator 
        row1, row2 = 0, len(matrix) - 1
        col1, col2 = 0, len(matrix[0]) - 1
        while row1 <= row2 and col1 <= col2:
            for r, c in spiral_coords(row1, col1, row2, col2):
                ans.append(matrix[r][c])
                print(r) 
                print(c)
                print("enter matrix")
                print(matrix[r][c])
                print("distinguish")
            # once we are done with the first clock cycle, want to reduce the size 
            # of the matrix to keep values in order 
            row1 += 1; row2 -= 1
            col1 += 1; col2 -= 1
        return ans

"""
Thinking :  fill up the first row 0 with i to n
            fill up the second row 1 with the last spot filleed 
            fill up the n row row n with the last spot filled 
            once the last spots are filled fill up the bottome 
            fill up the nth row with vals in reverse 

            2 * 2 matrix -> 1,2,3,6 -> [[1,2],[3,6]] 
            3 * 3 matrix ->  look at example 
            4 * 4 matrix  -> 16 elts -> too much 

Actual Logic ->  Want to iterate 
                1. n - 1 of the first row    <------------------ +   
                2. n - 1 of the last column                      |
                3. n - 1 of the last row -> IN REVERSED          |
                4. n - 1 of the first column -> IN REVERSED ---- + 
                5. Repeat 4 for all n - 2

                Definition 
                In other words, want to iterate elts clockwiswe 
                let r1, c1 be the top left  coord and let r2, c2 be the bottom right coord
                let the first row be from c ... c2 (top)
                let the last column be r1 + 1... r2 (right)
                let the bottom colum be from c2 + 1 ... c1 + 1  (bottom)
                let the first column be r2 + 1  ... r1 + 1 (left)



"""

"""
Test Cases:
Outpur 1: <1,2,3,6,9,8,7,4,5>
Input 1:   [[1,2,3]
            [6,9,8]
            [7,4,5]] 3 x 3 array 
"""
def tests():

    input_one = [[1,2,3],[6,9,8],[7,4,5]]
    output_one = [1,2,3,8,5,4,7,6,9] 

    assert(spiralOrder(input_one) == output_one)
    print("Passed test case")
    return 0


tests()


