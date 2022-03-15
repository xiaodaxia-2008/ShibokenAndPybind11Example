#include <pybind11/pybind11.h>
#include "EasyWidget.h"

namespace py = pybind11;
using namespace pybind11::literals;

using namespace EW;
using namespace RVS;
PYBIND11_MODULE(PyEasyWidget, m)
{
    py::class_<EasyWidget>(m, "EasyWidget")
        .def(py::init<>())
        .def("show", &EasyWidget::show)
        .def("GetLabel", [](EasyWidget &self) {
            PyObject *module = PyImport_ImportModule("shiboken2");
            PyObject *dict = PyModule_GetDict(module);
            PyObject *func = PyMapping_GetItemString(dict, "wrapInstance");
            PyObject *args = PyTuple_New(2);
            QLabel *label = self.GetLabel();
            PyTuple_SetItem(args, 0, PyLong_FromVoidPtr((void *)label));
            module = PyImport_ImportModule("PySide2.QtWidgets");
            dict = PyModule_GetDict(module);
            PyTuple_SetItem(args, 1, PyMapping_GetItemString(dict, "QLabel"));
            PyObject *obj = PyObject_CallObject(func, args);
            py::handle h(obj);
            std::cout << "end\n";
            return py::reinterpret_borrow<py::object>(h);
        });
}