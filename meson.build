project('performance-test-efl',                                                                                                                                                                                                'c',
        license : 'Apache')

sample_deps = [
    dependency('elementary'),
    dependency('appcore-efl'),
    dependency('dlog'),
]

sample_inc = [
   include_directories('inc'),
]

executable('performance-test-efl', 'src/main.c',
           dependencies: sample_deps,
           include_directories: sample_inc,
           install : true,
		   install_dir:  join_paths(get_option('tzapp_path'), 'performance-test-efl', 'bin'),
		   )

install_data('performance-test-efl.xml', install_dir: get_option('tzpackage_path'))
