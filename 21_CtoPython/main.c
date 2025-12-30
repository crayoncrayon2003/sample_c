#include <Python.h>
#include <stdio.h>

int main() {
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('.')");

    PyObject *pName = PyUnicode_FromString("mymodule");
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (!pModule) {
        PyErr_Print();
        return 1;
    }

    /* =========================
     * 1. C → Python（入力1つ）
     * ========================= */
    {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "func_input_one");
        PyObject *args = PyTuple_Pack(1, PyLong_FromLong(10));
        PyObject_CallObject(pFunc, args);
        Py_DECREF(args);
        Py_DECREF(pFunc);
    }

    /* =========================
     * 2. C → Python（入力複数）
     * ========================= */
    {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "func_input_multi");
        PyObject *args = PyTuple_Pack(
            2,
            PyLong_FromLong(3),
            PyLong_FromLong(4)
        );
        PyObject_CallObject(pFunc, args);
        Py_DECREF(args);
        Py_DECREF(pFunc);
    }

    /* =========================
     * 3. Python → C（戻り値1つ）
     * ========================= */
    {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "func_return_one");
        PyObject *args = PyTuple_Pack(1, PyLong_FromLong(5));
        PyObject *ret = PyObject_CallObject(pFunc, args);

        long value = PyLong_AsLong(ret);
        printf("Returned one value: %ld\n", value);

        Py_DECREF(ret);
        Py_DECREF(args);
        Py_DECREF(pFunc);
    }

    /* =========================
     * 4. Python → C（戻り値複数）
     * ========================= */
    {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "func_return_multi");
        PyObject *args = PyTuple_Pack(
            2,
            PyLong_FromLong(6),
            PyLong_FromLong(7)
        );
        PyObject *ret = PyObject_CallObject(pFunc, args);

        long a = PyLong_AsLong(PyTuple_GetItem(ret, 0));
        long b = PyLong_AsLong(PyTuple_GetItem(ret, 1));
        printf("Returned multi values: %ld, %ld\n", a, b);

        Py_DECREF(ret);
        Py_DECREF(args);
        Py_DECREF(pFunc);
    }

    Py_DECREF(pModule);
    Py_Finalize();
    return 0;
}
