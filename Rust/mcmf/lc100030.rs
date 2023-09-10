// https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/description/
// #[warn(unused_imports)]
use mincostflow::*;
pub mod mincostflow {
    use crate::internal_type_traits::Integral;

    pub struct MinCostFlowEdge<T> {
        pub from: usize,
        pub to: usize,
        pub cap: T,
        pub flow: T,
        pub cost: T,
    }

    pub struct MinCostFlowGraph<T> {
        pos: Vec<(usize, usize)>,
        g: Vec<Vec<_Edge<T>>>,
    }

    impl<T> MinCostFlowGraph<T>
    where
        T: Integral + std::ops::Neg<Output = T>,
    {
        pub fn new(n: usize) -> Self {
            Self {
                pos: vec![],
                g: (0..n).map(|_| vec![]).collect(),
            }
        }

        pub fn get_edge(&self, i: usize) -> MinCostFlowEdge<T> {
            assert!(i < self.pos.len());
            let e = &self.g[self.pos[i].0][self.pos[i].1];
            let re = &self.g[e.to][e.rev];
            MinCostFlowEdge {
                from: self.pos[i].0,
                to: e.to,
                cap: e.cap + re.cap,
                flow: re.cap,
                cost: e.cost,
            }
        }

        pub fn edges(&self) -> Vec<MinCostFlowEdge<T>> {
            let m = self.pos.len();
            let mut result = vec![];
            for i in 0..m {
                result.push(self.get_edge(i));
            }
            result
        }

        pub fn add_edge(&mut self, from: usize, to: usize, cap: T, cost: T) -> usize {
            assert!(from < self.g.len());
            assert!(to < self.g.len());
            assert_ne!(from, to);
            assert!(cap >= T::zero());
            assert!(cost >= T::zero());

            self.pos.push((from, self.g[from].len()));

            let rev = self.g[to].len();
            self.g[from].push(_Edge { to, rev, cap, cost });

            let rev = self.g[from].len() - 1;
            self.g[to].push(_Edge {
                to: from,
                rev,
                cap: T::zero(),
                cost: -cost,
            });

            self.pos.len() - 1
        }

        /// Returns (maximum flow, cost)
        pub fn flow(&mut self, source: usize, sink: usize, flow_limit: T) -> (T, T) {
            self.slope(source, sink, flow_limit).pop().unwrap()
        }

        pub fn slope(&mut self, source: usize, sink: usize, flow_limit: T) -> Vec<(T, T)> {
            let n = self.g.len();
            assert!(source < n);
            assert!(sink < n);
            assert_ne!(source, sink);

            let mut dual = vec![T::zero(); n];
            let mut prev_v = vec![0; n];
            let mut prev_e = vec![0; n];
            let mut flow = T::zero();
            let mut cost = T::zero();
            let mut prev_cost_per_flow: Option<T> = None;
            let mut result = vec![(flow, cost)];
            while flow < flow_limit {
                if !self.refine_dual(source, sink, &mut dual, &mut prev_v, &mut prev_e) {
                    break;
                }

                let mut c = flow_limit - flow;
                let mut v = sink;
                while v != source {
                    c = std::cmp::min(c, self.g[prev_v[v]][prev_e[v]].cap);
                    v = prev_v[v];
                }

                let mut v = sink;
                while v != source {
                    self.g[prev_v[v]][prev_e[v]].cap -= c;
                    let rev = self.g[prev_v[v]][prev_e[v]].rev;
                    self.g[v][rev].cap += c;
                    v = prev_v[v];
                }

                let d = -dual[source];
                flow += c;
                cost += d * c;
                if prev_cost_per_flow == Some(d) {
                    assert!(result.pop().is_some());
                }
                result.push((flow, cost));
                prev_cost_per_flow = Some(d);
            }
            result
        }

        fn refine_dual(
            &self,
            source: usize,
            sink: usize,
            dual: &mut [T],
            pv: &mut [usize],
            pe: &mut [usize],
        ) -> bool {
            let n = self.g.len();
            let mut dist = vec![T::max_value(); n];
            let mut vis = vec![false; n];

            let mut que = std::collections::BinaryHeap::new();
            dist[source] = T::zero();
            que.push((std::cmp::Reverse(T::zero()), source));
            while let Some((_, v)) = que.pop() {
                if vis[v] {
                    continue;
                }
                vis[v] = true;
                if v == sink {
                    break;
                }

                for (i, e) in self.g[v].iter().enumerate() {
                    if vis[e.to] || e.cap == T::zero() {
                        continue;
                    }

                    let cost = e.cost - dual[e.to] + dual[v];
                    if dist[e.to] - dist[v] > cost {
                        dist[e.to] = dist[v] + cost;
                        pv[e.to] = v;
                        pe[e.to] = i;
                        que.push((std::cmp::Reverse(dist[e.to]), e.to));
                    }
                }
            }

            if !vis[sink] {
                return false;
            }

            for v in 0..n {
                if !vis[v] {
                    continue;
                }
                dual[v] -= dist[sink] - dist[v];
            }
            true
        }
    }

    struct _Edge<T> {
        to: usize,
        rev: usize,
        cap: T,
        cost: T,
    }

    #[cfg(test)]
    mod tests {
        use super::*;

        #[test]
        fn test_min_cost_flow() {
            let mut graph = MinCostFlowGraph::new(4);
            graph.add_edge(0, 1, 2, 1);
            graph.add_edge(0, 2, 1, 2);
            graph.add_edge(1, 2, 1, 1);
            graph.add_edge(1, 3, 1, 3);
            graph.add_edge(2, 3, 2, 1);
            let (flow, cost) = graph.flow(0, 3, 2);
            assert_eq!(flow, 2);
            assert_eq!(cost, 6);
        }

        #[test]
        fn same_cost_paths() {
            // https://github.com/atcoder/ac-library/blob/300e66a7d73efe27d02f38133239711148092030/test/unittest/mincostflow_test.cpp#L83-L90
            let mut graph = MinCostFlowGraph::new(3);
            assert_eq!(0, graph.add_edge(0, 1, 1, 1));
            assert_eq!(1, graph.add_edge(1, 2, 1, 0));
            assert_eq!(2, graph.add_edge(0, 2, 2, 1));
            let expected = [(0, 0), (3, 3)];
            assert_eq!(expected[..], *graph.slope(0, 2, i32::max_value()));
        }

        #[test]
        fn only_one_nonzero_cost_edge() {
            let mut graph = MinCostFlowGraph::new(3);
            assert_eq!(0, graph.add_edge(0, 1, 1, 1));
            assert_eq!(1, graph.add_edge(1, 2, 1, 0));
            let expected = [(0, 0), (1, 1)];
            assert_eq!(expected[..], *graph.slope(0, 2, i32::max_value()));
        }
    }
}
pub mod internal_type_traits {
    use std::{
        fmt,
        iter::{Product, Sum},
        ops::{
            Add, AddAssign, BitAnd, BitAndAssign, BitOr, BitOrAssign, BitXor, BitXorAssign, Div,
            DivAssign, Mul, MulAssign, Not, Rem, RemAssign, Shl, ShlAssign, Shr, ShrAssign, Sub,
            SubAssign,
        },
    };

    // Skipped:
    //
    // - `is_signed_int_t<T>`   (probably won't be used directly in `modint.rs`)
    // - `is_unsigned_int_t<T>` (probably won't be used directly in `modint.rs`)
    // - `to_unsigned_t<T>`     (not used in `fenwicktree.rs`)

    /// Corresponds to `std::is_integral` in C++.
    // We will remove unnecessary bounds later.
    //
    // Maybe we should rename this to `PrimitiveInteger` or something, as it probably won't be used in the
    // same way as the original ACL.
    pub trait Integral:
        'static
        + Send
        + Sync
        + Copy
        + Ord
        + Not<Output = Self>
        + Add<Output = Self>
        + Sub<Output = Self>
        + Mul<Output = Self>
        + Div<Output = Self>
        + Rem<Output = Self>
        + AddAssign
        + SubAssign
        + MulAssign
        + DivAssign
        + RemAssign
        + Sum
        + Product
        + BitOr<Output = Self>
        + BitAnd<Output = Self>
        + BitXor<Output = Self>
        + BitOrAssign
        + BitAndAssign
        + BitXorAssign
        + Shl<Output = Self>
        + Shr<Output = Self>
        + ShlAssign
        + ShrAssign
        + fmt::Display
        + fmt::Debug
        + fmt::Binary
        + fmt::Octal
        + Zero
        + One
        + BoundedBelow
        + BoundedAbove
    {
    }

    /// Class that has additive identity element
    pub trait Zero {
        /// The additive identity element
        fn zero() -> Self;
    }

    /// Class that has multiplicative identity element
    pub trait One {
        /// The multiplicative identity element
        fn one() -> Self;
    }

    pub trait BoundedBelow {
        fn min_value() -> Self;
    }

    pub trait BoundedAbove {
        fn max_value() -> Self;
    }

    macro_rules! impl_integral {
    ($($ty:ty),*) => {
        $(
            impl Zero for $ty {
                #[inline]
                fn zero() -> Self {
                    0
                }
            }

            impl One for $ty {
                #[inline]
                fn one() -> Self {
                    1
                }
            }

            impl BoundedBelow for $ty {
                #[inline]
                fn min_value() -> Self {
                    Self::min_value()
                }
            }

            impl BoundedAbove for $ty {
                #[inline]
                fn max_value() -> Self {
                    Self::max_value()
                }
            }

            impl Integral for $ty {}
        )*
    };
}

impl_integral!(i8, i16, i32, i64, i128, isize, u8, u16, u32, u64, u128, usize);
}

impl Solution {
    pub fn minimum_moves(g: Vec<Vec<i32>>) -> i32 {
        let mut mcf = MinCostFlowGraph::new(11);
        for i in 0..3 {
            for j in 0..3 {
                if g[i][j] > 1 {
                    // println!("{} {} {} {}", 9, i * 3 + j, g[i][j] - 1, 0);
                    mcf.add_edge(9, i * 3 + j, g[i][j] - 1, 0);
                    for k in 0..3 {
                        for d in 0..3 {
                            if g[k][d] == 0 {
                                mcf.add_edge(i * 3 + j, k * 3 + d, 1, (k as i32 - i as i32).abs() + (j as i32 - d as i32).abs());
                                // println!("{} {} {} {}", i * 3 + j, k * 3 + d, 1, (k as i32 - i as i32).abs() + (j as i32 - d as i32).abs());
                            }
                        }
                    }
                } else if g[i][j] == 0 {
                    mcf.add_edge(i * 3 + j, 10, 1, 0);
                    // println!("{} {} {} {}", i * 3 + j, 10, 1, 0);
                }
            }
        }
        mcf.flow(9, 10, 100000).1
    }
}
