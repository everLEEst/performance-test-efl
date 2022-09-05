edje_cc_exe = find_program('edje_cc')

custom_target('edje_cc',
  input : 'performance-test-efl.edc',
  depfile: '@BASENAME@.edj.d',
  output : '@BASENAME@.edj',
  command : [edje_cc_exe, '-beta', '-fastdecomp',
            '-deps', '@DEPFILE@',
            '-id', join_paths(meson.current_source_dir(), 'img'),
            '@INPUT@', '@OUTPUT@'],
  install : true,
  install_dir:  join_paths(get_option('tzapp_path'), 'performance-test-efl', 'res'),
)
