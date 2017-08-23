
#include <stdio.h>

#include "hpdf.h"

#include <Python.h>

#include "pyhpdf.h"
#include "pyhpdf_doc.h"
#include "pyhpdf_page.h"




PyMODINIT_FUNC
init_hpdf(void)
{
    PyObject *m;

    if (PyType_Ready(&hpdf_DocumentType) < 0) {
        return;
    }

    if (PyType_Ready(&hpdf_DocumentPageType) < 0) {
        return;
    }

    m = Py_InitModule("_hpdf", hpdf_Methods);
    if (m == NULL) {
        return;
    }

    Py_INCREF(&hpdf_DocumentType);
    PyModule_AddObject(m, "Document", (PyObject *)&hpdf_DocumentType);
}
