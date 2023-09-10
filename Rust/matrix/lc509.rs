// https://leetcode.cn/problems/fibonacci-number/description/
#[derive(Debug, Clone, Copy)]
// 0 1
// 2 3
pub struct Mat {
    x: (i64, i64, i64, i64)
}

impl std::ops::Mul for Mat {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        Mat { x: (
                self.x.0 * rhs.x.0 + self.x.1 * rhs.x.2,
                self.x.0 * rhs.x.1 + self.x.1 * rhs.x.3,
                self.x.2 * rhs.x.0 + self.x.3 * rhs.x.2,
                self.x.2 * rhs.x.1 + self.x.3 * rhs.x.3
            )
        }
    }
}

impl Solution {
    /// ```
    /// f(x) = f(x - 1) + f(x - 2)
    /// ```
    /// ```
    /// [ f(x + 1) ] = [ 1 1 ] [   f(x)   ]
    /// [   f(x)   ] = [ 1 0 ] [ f(x - 1) ]
    /// ```
    /// ```
    /// [ f(x + 1) ] = [ 1 1 ] ^ x [ f(1) ]
    /// [   f(x)   ] = [ 1 0 ]     [ f(0) ]
    /// ```
    pub fn fib(mut n: i32) -> i32 {
        let mut a = Mat{ x: (1, 1, 1, 0) };
        let mut r = Mat{ x: (1, 0, 0, 1) };
        while n > 0 {
            if n % 2 != 0 {
                r = r * a;
            }
            a = a * a;
            n /= 2;
        }
        r.x.2 as i32
    }
}
