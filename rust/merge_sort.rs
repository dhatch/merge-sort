use std::env;

/// Sorts the values using merge sort.
fn msort(values: &[i64]) -> Vec<i64> {
    let lc = values.len() / 2;
    let lvec;
    let rvec;
    let (mut l, mut r) = values.split_at(lc);

    if !(l.len() <= 1 && r.len() <= 1) {
        lvec = msort(l);
        rvec = msort(r);
        l = &lvec[..];
        r = &rvec[..];
    }

    let mut sorted: Vec<i64> = Vec::with_capacity(values.len());

    let mut l_iter = l.into_iter().peekable();
    let mut r_iter = r.into_iter().peekable();
    while l_iter.peek().is_some() || r_iter.peek().is_some() {
        if l_iter.peek().is_none() {
            sorted.push(*r_iter.next().unwrap());
        } else if r_iter.peek().is_none() {
            sorted.push(*l_iter.next().unwrap());
        } else if *l_iter.peek().unwrap() < *r_iter.peek().unwrap() {
            sorted.push(*l_iter.next().unwrap());
        } else {
            sorted.push(*r_iter.next().unwrap());
        }
    }

    sorted
}

fn main() {
    let values: Vec<i64> =
        env::args().skip(1).map(|x| x.parse::<i64>().unwrap()).collect();

    let sorted = msort(&values);
    for v in sorted {
        print!("{} ", v);
    }

    print!("\n");
}
