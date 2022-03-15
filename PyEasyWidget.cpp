#include <pybind11/pybind11.h>
#include "EasyWidget.h"

namespace py = pybind11;
using namespace pybind11::literals;

py::object WrapQtObject(void *instance, const char *qobject_name,
                        bool is_borrow = true)
{
    PyObject *module = PyImport_ImportModule("shiboken2");
    PyObject *dict = PyModule_GetDict(module);
    PyObject *func = PyMapping_GetItemString(dict, "wrapInstance");
    PyObject *args = PyTuple_New(2);
    PyTuple_SetItem(args, 0, PyLong_FromVoidPtr(instance));
    module = PyImport_ImportModule("PySide2.QtWidgets");
    dict = PyModule_GetDict(module);
    PyTuple_SetItem(args, 1, PyMapping_GetItemString(dict, qobject_name));
    PyObject *obj = PyObject_CallObject(func, args);
    py::handle h(obj);
    return is_borrow ? py::reinterpret_borrow<py::object>(h)
                     : py::reinterpret_steal<py::object>(h);
}

using namespace EW;
PYBIND11_MODULE(PyEasyWidget, m)
{
    py::class_<EasyWidget>(m, "EasyWidget")
        .def(py::init<>())
        .def("show", &EasyWidget::show)
        .def("GetLabel",
             [](EasyWidget &self) {
                 return WrapQtObject(self.GetLabel(), "QLabel");
             })
        .def("Widget", [](EasyWidget &self) {
            return WrapQtObject(&self, "QWidget", true);
        });
}