// https://leetcode.cn/problems/n-th-tribonacci-number/description/
#[derive(Debug, Clone, Copy)]
pub struct Mat {
    x: [[i64; 3]; 3]
}

impl std::ops::Mul for Mat {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        let mut res = [[0; 3]; 3];
        for i in 0..3 {
            for j in 0..3 {
                for k in 0..3 {
                    res[i][j] += self.x[i][k] * rhs.x[k][j];
                }
            }
        }
        Mat { x: res }
    }
}

impl Solution {
    /// ```
    /// f(x) = f(x - 1) + f(x - 2) + f(x - 3)
    /// ```
    /// ```
    /// [ f(x + 2) ] = [ 1 1 1 ] [ f(x + 1) ]
    /// [ f(x + 1) ] = [ 1 0 0 ] [   f(x)   ]
    /// [   f(x)   ] = [ 0 1 0 ] [ f(x - 1) ]
    /// ```
    /// ```
    /// [ f(x + 2) ] = [ 1 1 1 ] ^ x [ f(2) ]
    /// [ f(x + 1) ] = [ 1 0 0 ]     [ f(1) ]
    /// [   f(x)   ] = [ 0 1 0 ]     [ f(0) ]
    /// ```
    pub fn tribonacci(mut n: i32) -> i32 {
        let mut a = Mat{x: [[1, 1, 1], [1, 0, 0], [0, 1, 0]]};
        let mut r = Mat{x: [[1, 0, 0], [0, 1, 0], [0, 0, 1]]};
        while n > 0 {
            if n % 2 != 0 {
                r = r * a;
            }
            a = a * a;
            n /= 2;
        }
        (r.x[2][0] + r.x[2][1]) as i32
    }
}
