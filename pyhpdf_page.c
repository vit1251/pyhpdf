
#include <stdio.h>

#include "hpdf.h"

#include <Python.h>

#include "pyhpdf_doc.h"
#include "pyhpdf_page.h"
#include "pyhpdf_page_internal.h"


PyObject *hpdf_DocumentPage_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    hpdf_DocumentPageObject *self;
    HPDF_STATUS status;

#ifndef _NDEBUG
    fprintf(stderr, "debug: hpdf_DocumentPage_new\n");
#endif

    self = (hpdf_DocumentPageObject *)type->tp_alloc(type, 0);
    if (self != NULL) {
    }

    return (PyObject *)self;
}


PyObject *hpdf_DocumentPage_TextOut(hpdf_DocumentPageObject *self, PyObject *args)
{
    HPDF_Font def_font;
    const char *text;
    HPDF_REAL tw;
    HPDF_REAL height;
    HPDF_REAL width;
    int rc = 0;

    if (!PyArg_ParseTuple(args, "s", &text)) {
        return NULL;
    }


    def_font = HPDF_GetFont (self->pdf, "Helvetica", NULL);
    HPDF_Page_SetFontAndSize (self->page, def_font, 24);


    height = HPDF_Page_GetHeight (self->page);
    width = HPDF_Page_GetWidth (self->page);

    tw = HPDF_Page_TextWidth (self->page, text);
    HPDF_Page_BeginText (self->page);
    HPDF_Page_TextOut (self->page, (width - tw) / 2, height - 50, text);
    HPDF_Page_EndText (self->page);

    return Py_BuildValue("i", rc);
}


PyObject *hpdf_DocumentPage_Line(hpdf_DocumentPageObject *self, PyObject *args)
{
    int x1, y1;
    int x2, y2;
    int rc = 0;

    if (!PyArg_ParseTuple(args, "iiii", &x1, &y1, &x2, &y2)) {
        return NULL;
    }

    HPDF_Page_SetLineWidth (self->page, 1.0);
    HPDF_Page_SetRGBStroke (self->page, 0.0, 0.0, 0.0);

    HPDF_Page_MoveTo (self->page, x1, y1);
    HPDF_Page_LineTo (self->page, x2, y2);
    HPDF_Page_Stroke (self->page);

    return Py_BuildValue("i", rc);
}
