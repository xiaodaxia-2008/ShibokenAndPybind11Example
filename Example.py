#! /usr/bin/python3

from PySide2 import QtWidgets
from build.PyEasyWidget import EasyWidget
from IPython import embed

app = QtWidgets.QApplication()
w = EasyWidget()
label = w.GetLabel()
print(f"label text: {label.text()}")
label.setText("Hello, change from python!")
w.show()
app.exec_()
