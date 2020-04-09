#![allow(dead_code, mutable_transmutes, non_camel_case_types, non_snake_case,
         non_upper_case_globals, unused_assignments, unused_mut)]
#![register_tool(c2rust)]
#![feature(register_tool)]
pub type size_t = libc::c_ulong;
pub type __int64_t = libc::c_long;
pub type int64_t = __int64_t;
static mut table: [libc::c_char; 59] =
    [102, 90, 111, 100, 82, 57, 88, 81, 68, 83, 85, 109, 50, 49, 121, 67, 107,
     114, 54, 122, 66, 113, 105, 118, 101, 89, 97, 104, 56, 98, 116, 52, 120,
     115, 87, 112, 72, 110, 74, 69, 55, 106, 76, 53, 86, 71, 51, 103, 117, 77,
     84, 75, 78, 80, 65, 119, 99, 70, 0];
static mut tr: [int64_t; 256] =
    [0 as libc::c_int as int64_t, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
static mut r: [libc::c_char; 13] =
    [66, 86, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 0];
static mut s: [int64_t; 10] =
    [11 as libc::c_int as int64_t, 10 as libc::c_int as int64_t,
     3 as libc::c_int as int64_t, 8 as libc::c_int as int64_t,
     4 as libc::c_int as int64_t, 6 as libc::c_int as int64_t,
     2 as libc::c_int as int64_t, 9 as libc::c_int as int64_t,
     5 as libc::c_int as int64_t, 7 as libc::c_int as int64_t];
static mut xor: int64_t = 177451812 as libc::c_long;
static mut add: int64_t = 100618342136696320 as libc::c_long;
#[no_mangle]
pub unsafe extern "C" fn bvInitialize() {
    let mut i: libc::c_uint = 0 as libc::c_int as libc::c_uint;
    while i < 58 as libc::c_int as libc::c_uint {
        tr[table[i as usize] as size_t as usize] = i as int64_t;
        i = i.wrapping_add(1)
    };
}
#[inline]
unsafe extern "C" fn bvi64Pow(mut x: int64_t, mut a: libc::c_uint)
 -> int64_t {
    let mut aa: libc::c_uint = a;
    let mut s_0: int64_t = 1 as libc::c_int as int64_t;
    let mut i: libc::c_uint = 0 as libc::c_int as libc::c_uint;
    while i < aa { s_0 *= x; i = i.wrapping_add(1) }
    return s_0;
}
#[no_mangle]
pub unsafe extern "C" fn bvDec(mut x: *mut libc::c_char) -> int64_t {
    let mut r_0: int64_t = 0 as libc::c_int as int64_t;
    let mut i: libc::c_uint = 0 as libc::c_int as libc::c_uint;
    while i < 10 as libc::c_int as libc::c_uint {
        r_0 +=
            tr[(*x.offset(s[i as usize] as isize) as
                    size_t).wrapping_mul(bvi64Pow(58 as libc::c_int as
                                                      int64_t, i) as
                                             libc::c_ulong) as usize];
        i = i.wrapping_add(1)
    }
    return r_0 - add ^ xor;
}
// 初始化BV_codec。
// 可以多次调用。
// 把BV号转换为av号。
// eg bvDec("BV1xx411c7XW")
#[no_mangle]
pub unsafe extern "C" fn bvEnc(mut x: int64_t) -> *mut libc::c_char {
    x = (x ^ xor) + add;
    let mut i: libc::c_uint = 0 as libc::c_int as libc::c_uint;
    while i < 10 as libc::c_int as libc::c_uint {
        r[s[i as usize] as usize] =
            table[(x / bvi64Pow(58 as libc::c_int as int64_t, i) %
                       58 as libc::c_int as libc::c_long) as usize];
        i = i.wrapping_add(1)
    }
    return r.as_mut_ptr();
}
