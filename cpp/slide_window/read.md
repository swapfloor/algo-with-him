关于固定窗口大小的最值`min`，解决方法

- 单调队列 $O(n)$
- zkw $O(n \log n)$
- 懒堆 $O(n \log n)$

## Code

### 单调队列

```Rust
use std::collections::VecDeque;

fn main() {
    let n: usize = 6;
    let m: usize = 2;
    let a = vec![7, 8, 1, 4, 3, 2];
    let mut q = VecDeque::new();
    let mut r: Vec<usize> = vec![0; n];
    for i in 0..n {
        while !q.is_empty() && i == m + q.front().unwrap() {
            q.pop_front();
        }
        while !q.is_empty() && a[*q.back().unwrap()] >= a[i]  {
            q.pop_back();
        }
        q.push_back(i);
        r[i] = *q.front().unwrap();
    }
    println!("{:?}", r);
}
```

### zkw

```Rust
fn main() {
    let n: usize = 6;
    let m: usize = 2;
    let a: Vec<usize> = vec![7, 8, 1, 4, 3, 2];
    let mut tr = vec![0; 2 * n + 5];
    for i in 1..=n {
        tr[i + n] = a[i - 1];
    }
    tr[2 * n + 1] = 1e9 as usize; // inf
    for i in (1..=n).rev() {
        tr[i] = tr[i * 2].min(tr[i * 2 + 1]);
    }
    let mut p = vec![0usize; n];
    for i in 1..=n {
        let mut l = if i > m {i - m + 1 + n} else {1 + n}; // 左闭
        let mut r = i + n + 1; // 右开
        let mut ans = tr[l]; // inf
        while l < r {
            if (l & 1) != 0 {
                ans = ans.min(tr[l]);
                l += 1;
            }
            if (r & 1) != 0 {
                ans = ans.min(tr[r - 1]);
                r -= 1;
            }
            l /= 2;
            r /= 2;
        }
        p[i - 1] = ans;
    }
    println!("{:?}", p);
}
```

### 懒堆

```Rust
fn main() {
    let n: usize = 6;
    let m: usize = 2;
    let a: Vec<usize> = vec![7, 8, 1, 4, 3, 2];
    use std::collections::BinaryHeap;
    let mut h = BinaryHeap::new();
    let mut p = vec![0; n];
    for i in 0..n {
        h.push((-(a[i] as i64), i));
        while h.peek().unwrap().1 + m <= i {
            h.pop();
        }
        p[i] = -h.peek().unwrap().0;
    }
    println!("{:?}", p);
}
```
