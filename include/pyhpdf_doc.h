#ifndef PYHPDF_DOC_H
#define PYHPDF_DOC_H

/* Instance members */

typedef struct {
    PyObject_HEAD

    HPDF_Doc pdf;


} hpdf_DocumentObject;

/* Methods declaration */

PyObject *hpdf_Document_AddPage(hpdf_DocumentObject *self, PyObject *args);
PyObject *hpdf_Document_SaveToFile(hpdf_DocumentObject *self, PyObject *args);


static PyMethodDef hpdf_Document_methods[] = {
    {
        "AddPage", (PyCFunction)hpdf_Document_AddPage, METH_VARARGS,
        "Add new PDF page"
    },
    {
        "SaveToFile", (PyCFunction)hpdf_Document_SaveToFile, METH_VARARGS,
        "Save PDF document on disk"
    },

    {NULL}  /* Sentinel */
};

/* Type declaration */

PyObject *hpdf_Document_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

extern PyTypeObject hpdf_DocumentType;

#endif /* PYHPDF_DOC_H */
