#![allow(dead_code, mutable_transmutes, non_camel_case_types, non_snake_case,
         non_upper_case_globals, unused_assignments, unused_mut)]
#![register_tool(c2rust)]
#![feature(const_raw_ptr_to_usize_cast, extern_types, main, register_tool)]
extern "C" {
    pub type _IO_wide_data;
    pub type _IO_codecvt;
    pub type _IO_marker;
    #[no_mangle]
    static mut stdin: *mut FILE;
    #[no_mangle]
    static mut stdout: *mut FILE;
    #[no_mangle]
    static mut stderr: *mut FILE;
    #[no_mangle]
    fn fclose(__stream: *mut FILE) -> libc::c_int;
    #[no_mangle]
    fn freopen(__filename: *const libc::c_char, __modes: *const libc::c_char,
               __stream: *mut FILE) -> *mut FILE;
    #[no_mangle]
    fn fprintf(_: *mut FILE, _: *const libc::c_char, _: ...) -> libc::c_int;
    #[no_mangle]
    fn printf(_: *const libc::c_char, _: ...) -> libc::c_int;
    #[no_mangle]
    fn scanf(_: *const libc::c_char, _: ...) -> libc::c_int;
    #[no_mangle]
    fn feof(__stream: *mut FILE) -> libc::c_int;
    #[no_mangle]
    fn malloc(_: libc::c_ulong) -> *mut libc::c_void;
    #[no_mangle]
    fn free(__ptr: *mut libc::c_void);
    #[no_mangle]
    fn memcpy(_: *mut libc::c_void, _: *const libc::c_void, _: libc::c_ulong)
     -> *mut libc::c_void;
    #[no_mangle]
    fn strcat(_: *mut libc::c_char, _: *const libc::c_char)
     -> *mut libc::c_char;
    #[no_mangle]
    fn strcmp(_: *const libc::c_char, _: *const libc::c_char) -> libc::c_int;
    #[no_mangle]
    fn strlen(_: *const libc::c_char) -> libc::c_ulong;
    #[no_mangle]
    fn bvInitialize();
    // 初始化BV_codec。
// 可以多次调用。
    #[no_mangle]
    fn bvDec(x: *mut libc::c_char) -> int64_t;
    // 把BV号转换为av号。
// eg bvDec("BV1xx411c7XW")
    #[no_mangle]
    fn bvEnc(x: int64_t) -> *mut libc::c_char;
}
pub type size_t = libc::c_ulong;
pub type __int64_t = libc::c_long;
pub type __off_t = libc::c_long;
pub type __off64_t = libc::c_long;
#[derive(Copy, Clone)]
#[repr(C)]
pub struct _IO_FILE {
    pub _flags: libc::c_int,
    pub _IO_read_ptr: *mut libc::c_char,
    pub _IO_read_end: *mut libc::c_char,
    pub _IO_read_base: *mut libc::c_char,
    pub _IO_write_base: *mut libc::c_char,
    pub _IO_write_ptr: *mut libc::c_char,
    pub _IO_write_end: *mut libc::c_char,
    pub _IO_buf_base: *mut libc::c_char,
    pub _IO_buf_end: *mut libc::c_char,
    pub _IO_save_base: *mut libc::c_char,
    pub _IO_backup_base: *mut libc::c_char,
    pub _IO_save_end: *mut libc::c_char,
    pub _markers: *mut _IO_marker,
    pub _chain: *mut _IO_FILE,
    pub _fileno: libc::c_int,
    pub _flags2: libc::c_int,
    pub _old_offset: __off_t,
    pub _cur_column: libc::c_ushort,
    pub _vtable_offset: libc::c_schar,
    pub _shortbuf: [libc::c_char; 1],
    pub _lock: *mut libc::c_void,
    pub _offset: __off64_t,
    pub _codecvt: *mut _IO_codecvt,
    pub _wide_data: *mut _IO_wide_data,
    pub _freeres_list: *mut _IO_FILE,
    pub _freeres_buf: *mut libc::c_void,
    pub __pad5: size_t,
    pub _mode: libc::c_int,
    pub _unused2: [libc::c_char; 20],
}
pub type _IO_lock_t = ();
pub type FILE = _IO_FILE;
pub type int64_t = __int64_t;
unsafe fn main_0(mut argc: libc::c_int, mut argv: *mut *mut libc::c_char)
 -> libc::c_int {
    let mut fi: *mut FILE = 0 as *mut FILE;
    let mut fo: *mut FILE = 0 as *mut FILE;
    let mut fe: *mut FILE = 0 as *mut FILE;
    let mut file: bool = 0 as libc::c_int != 0;
    if argc == 2 as libc::c_int {
        let mut q: *mut libc::c_char = 0 as *mut libc::c_char;
        let p: *const libc::c_char = *argv.offset(1 as libc::c_int as isize);
        if strcmp(b"-h\x00" as *const u8 as *const libc::c_char, p) == 0 ||
               strcmp(b"--help\x00" as *const u8 as *const libc::c_char, p) ==
                   0 {
            fprintf(stderr,
                    b"-h, --help\tshow this help.\n[filename]\tconvert the file and write into [filename].txt .\n\nWARNING: this Program will overwrite ./latest.log!\n\n\x00"
                        as *const u8 as *const libc::c_char);
            return 0 as libc::c_int
        } else {
            let mut len: size_t =
                strlen(p).wrapping_add(1 as libc::c_int as libc::c_ulong);
            q =
                malloc(len.wrapping_add(4 as libc::c_int as
                                            libc::c_ulong).wrapping_mul(::std::mem::size_of::<libc::c_char>()
                                                                            as
                                                                            libc::c_ulong))
                    as *mut libc::c_char;
            if q.is_null() {
                fprintf(stderr,
                        b"Error while eating memory!\n\n\x00" as *const u8 as
                            *const libc::c_char);
                return 0 as libc::c_int
            }
            memcpy(q as *mut libc::c_void, p as *const libc::c_void, len);
            strcat(q, b".txt\x00" as *const u8 as *const libc::c_char);
            fi =
                freopen(p, b"r\x00" as *const u8 as *const libc::c_char,
                        stdin);
            if fi.is_null() {
                fprintf(stderr,
                        b"File redirecting failed!\nDo you have the permissions needed?\n\n\x00"
                            as *const u8 as *const libc::c_char);
                free(q as *mut libc::c_void);
                return 0 as libc::c_int
            } else {
                fo =
                    freopen(q, b"w\x00" as *const u8 as *const libc::c_char,
                            stdout);
                if fo.is_null() {
                    fprintf(stderr,
                            b"File redirecting failed!\nDo you have the permissions needed?\n\n\x00"
                                as *const u8 as *const libc::c_char);
                    free(q as *mut libc::c_void);
                    fclose(fi);
                    return 0 as libc::c_int
                } else {
                    fe =
                        freopen(b"latest.log\x00" as *const u8 as
                                    *const libc::c_char,
                                b"w\x00" as *const u8 as *const libc::c_char,
                                stderr);
                    if fe.is_null() {
                        fprintf(stderr,
                                b"File redirecting failed!\nDo you have the permissions needed?\n\n\x00"
                                    as *const u8 as *const libc::c_char);
                        free(q as *mut libc::c_void);
                        fclose(fi);
                        fclose(fo);
                        return 0 as libc::c_int
                    } else { file = 1 as libc::c_int != 0 }
                }
            }
            free(q as *mut libc::c_void);
        }
    }
    let mut stat: libc::c_int = 0;
    let mut num: int64_t = 0;
    let mut p_0: [libc::c_char; 13] =
        [0 as libc::c_int as libc::c_char, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0];
    bvInitialize();
    loop  {
        stat =
            scanf(b"%ld\x00" as *const u8 as *const libc::c_char,
                  &mut num as *mut int64_t);
        if !(1 as libc::c_int != 0) { break ; }
        if feof(stdin) != 0 { break ; }
        if stat != 0 {
            printf(b"%s\n\x00" as *const u8 as *const libc::c_char,
                   bvEnc(num));
        } else {
            scanf(b"%s\x00" as *const u8 as *const libc::c_char,
                  p_0.as_mut_ptr());
            printf(b"av%ld\n\x00" as *const u8 as *const libc::c_char,
                   bvDec(p_0.as_mut_ptr()));
            p_0[0 as libc::c_int as usize] = 0 as libc::c_int as libc::c_char
        }
    }
    if file {
        if fclose(fi) != 0 || fclose(fo) != 0 || fclose(fe) != 0 {
            fprintf(stderr,
                    b"Error while closing files!\n\n\x00" as *const u8 as
                        *const libc::c_char);
        }
    }
    return stat;
}
#[main]
pub fn main() {
    let mut args: Vec<*mut libc::c_char> = Vec::new();
    for arg in ::std::env::args() {
        args.push(::std::ffi::CString::new(arg).expect("Failed to convert argument into CString.").into_raw());
    };
    args.push(::std::ptr::null_mut());
    unsafe {
        ::std::process::exit(main_0((args.len() - 1) as libc::c_int,
                                    args.as_mut_ptr() as
                                        *mut *mut libc::c_char) as i32)
    }
}
