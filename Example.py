#! /usr/bin/python3

from PySide2 import QtWidgets
from build.PyEasyWidget import EasyWidget
from IPython import embed

app = QtWidgets.QApplication()
win = QtWidgets.QMainWindow()
w = EasyWidget()
label = w.GetLabel()
print(f"label text: {label.text()}")
label.setText("Hello, change from python!")
widget = w.Widget()
layout = widget.layout()
layout.addWidget(QtWidgets.QLabel("label from python!"))
win.setCentralWidget(widget) # cause segmentation fault, it's maybe double destruction
win.show()
# w.show()
app.exec_()
