#!/usr/bin/python
# -*- coding: utf-8 -*-

from __future__ import print_function

from _hpdf import Document


class Application(object):
    def run(self):
        doc = Document()
        page_1 = doc.AddPage()
        page_1.TextOut("Test Page1")
        #page_1.Line(0,0,100,100)
        page_2 = doc.AddPage()
        page_2.TextOut("Page2")
        rc = doc.SaveToFile("123.pdf")
        print(rc)


if __name__ == "__main__":
    app = Application()
    app.run()
