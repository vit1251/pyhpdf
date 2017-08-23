
#include <stdio.h>

#include "hpdf.h"

#include <Python.h>

#include "pyhpdf_doc.h"
#include "pyhpdf_doc_internal.h"
#include "pyhpdf_page.h"


PyObject *hpdf_Document_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    hpdf_DocumentObject *self;
    HPDF_STATUS status;

    fprintf(stderr, "debug: hello\n");

    self = (hpdf_DocumentObject *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->pdf = HPDF_New (NULL, NULL);
        if (!self->pdf) {
            fprintf(stderr, "error: can not create new PDF instance\n");
        }
    }

    return (PyObject *)self;
}


PyObject *hpdf_Document_AddPage(hpdf_DocumentObject *self, PyObject *args)
{
    HPDF_Page page_1;
    hpdf_DocumentPageObject *obj;
    int rc = 0;
    HPDF_STATUS status;


    if (!PyArg_ParseTuple(args, "")) {
        return NULL;
    }

    page_1 = HPDF_AddPage(self->pdf);

    status = HPDF_Page_SetSize (page_1, HPDF_PAGE_SIZE_A4, HPDF_PAGE_LANDSCAPE);


    /*** Create new Python object ***/

    /* Pass arguments */
    PyObject *argList = NULL; //Py_BuildValue("");

    /* Call the class object. */
    obj = (hpdf_DocumentPageObject *)PyObject_CallObject((PyObject *) &hpdf_DocumentPageType, argList);

    /* Release the argument list. */
    if (argList) {
        Py_DECREF(argList);
    }

    obj->pdf = self->pdf;
    obj->page = page_1;

    return (PyObject *)obj;
}


PyObject *hpdf_Document_SaveToFile(hpdf_DocumentObject *self, PyObject *args)
{
    const char *path;
    HPDF_STATUS status;
    int rc = 0;

    if (!PyArg_ParseTuple(args, "s", &path)) {
        return NULL;
    }

    fprintf(stdout, "debug: write file %s\n", path);

    status = HPDF_SaveToFile (self->pdf, path);
    if (status != HPDF_OK) {
        rc = 1;
    }

    return Py_BuildValue("i", rc);
}
