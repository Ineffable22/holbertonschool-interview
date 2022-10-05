#!/usr/bin/python3
"""Test with unittest"""
import unittest
import pycodestyle
valid = __import__('0-validate_utf8')


class TestDocs(unittest.TestCase):
    """
    A Class to check the documentation and style of 0-validate_utf8
    """
    def test_pep8_validateUTF8(self):
        """Test PEP-8"""
        style = pycodestyle.StyleGuide(quite=True)
        result = style.check_files(['0-validate_utf8.py'])
        self.assertEqual(result.total_errors, 0,
                         "Found code style errors (and warnings).")

    def test_pep8_main(self):
        """Test PEP-8"""
        style = pycodestyle.StyleGuide(quite=True)
        result = style.check_files(['0-main.py'])
        self.assertEqual(result.total_errors, 0,
                         "Found code style errors (and warnings).")

    def test_document(self):
        """Test Docstring of file"""
        self.assertIsNot(valid.__doc__, None,
                         "0-validate_utf8 needs a docstring")
        self.assertTrue(len(valid.__doc__) >= 1,
                        "0-validate_utf8 needs a docstring")

    def test_function(self):
        """Test Docstring of function"""
        self.assertIsNot(valid.validUTF8.__doc__, None,
                         "validUTF8 needs a docstring")
        self.assertTrue(len(valid.validUTF8.__doc__) >= 1,
                        "validUTF8 needs a docstring")


class TestCases(unittest.TestCase):
    """Test 0-validate_utf8"""
    def test_data(self):
        """Test type of data"""
        func = valid.validUTF8
        self.assertEqual(func([65]), True)
        self.assertEqual(func([
            80, 121, 116, 104, 111, 110, 32, 105,
            115, 32, 99, 111, 111, 108, 33]), True)
        self.assertEqual(func([229, 65, 127, 256]), False)
        self.assertEqual(func([0, -1, -2, -255, -256]), False)
        self.assertEqual(func([-257]), False)
        self.assertEqual(func([260]), True)

    def test_empty_type_error(self):
        """Empty test type error"""
        func = valid.validUTF8
        with self.assertRaises(TypeError) as Error:
            func()
        self.assertEqual(
            "validUTF8() missing 1 required positional argument: 'data'",
            str(Error.exception)
        )

    def test_type_error(self):
        """Type test type error"""
        func = valid.validUTF8
        self.assertEqual(func(2), False)
        self.assertEqual(func({"2": 3}), False)
        self.assertEqual(func(2.3), False)
        self.assertEqual(func('NaN'), False)
        self.assertEqual(func("Hallo"), False)
        self.assertEqual(func(True), False)
        self.assertEqual(func(__name__), False)

    def test_list_error(self):
        """list test type error"""
        func = valid.validUTF8
        with self.assertRaises(TypeError) as Error:
            func(list(2))
        self.assertEqual(
            "'int' object is not iterable",
            str(Error.exception)
        )
