py_test(
    name = "JSON_parser_test",
    srcs = ["JSON_parser_test.py"],
    deps = [":JSON_parser"],
    data = [
        ":test_files_true_case",
        ":test_files_false_case"
    ]
)

py_library(
    name = "JSON_parser",
    srcs = ["JSON_parser.py"],
    deps = ["@requests//:srcs"]
)

filegroup(
    name = "test_files_true_case",
    srcs = ["output_true.json"]
)

filegroup(
    name = "test_files_false_case",
    srcs = ["output_false.json"]
)