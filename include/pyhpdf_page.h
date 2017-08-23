#ifndef PYHPDF_PAGE_H
#define PYHPDF_PAGE_H


typedef struct {
    PyObject_HEAD

    HPDF_Doc pdf;
    HPDF_Page page;


} hpdf_DocumentPageObject;

/* Methods delcaration */

PyObject *hpdf_DocumentPage_TextOut(hpdf_DocumentPageObject *self, PyObject *args);
PyObject *hpdf_DocumentPage_Line(hpdf_DocumentPageObject *self, PyObject *args);

static PyMethodDef hpdf_DocumentPage_methods[] = {
    {
        "TextOut", (PyCFunction)hpdf_DocumentPage_TextOut, METH_VARARGS,
        "Write on page some text"
    },
    {
        "Line", (PyCFunction)hpdf_DocumentPage_Line, METH_VARARGS,
        "Draw line on page"
    },

    {NULL}  /* Sentinel */
};

/* Type declaration */

PyObject *hpdf_DocumentPage_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

extern PyTypeObject hpdf_DocumentPageType;

#endif /* PYHPDF_PAGE_H */
