add_test( Test.test /home/honolulu/programs/external_libraries/honolulu_audio_engine/build/test/test_run [==[--gtest_filter=Test.test]==] --gtest_also_run_disabled_tests)
set_tests_properties( Test.test PROPERTIES WORKING_DIRECTORY /home/honolulu/programs/external_libraries/honolulu_audio_engine/build/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( test_run_TESTS Test.test)
