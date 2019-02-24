from tkinter import *
from tkinter.ttk import *
from tkinter import Canvas, Frame, Button, Label, Entry


class MainFrame(Tk):

    def __init__(self):
        super().__init__()

        self.width = 700
        self.height = 700

        self.a = None
        self.b = None
        self.r = None
        self.c = None

        self.display_text = None

        self.canvas = None
        self.border = 15

        self.initUI()

    def initUI(self):
        self.geometry("870x790+40+80")
        self.resizable(False, False)
        self.title("Lab 1")

        right_frame = Frame(self, bd=1, relief=SUNKEN)
        down_frame = Frame(self, bd=1, relief=SUNKEN)
        self.canvas = Canvas(self)

        self.display_text = StringVar()
        info_label_0 = Label(down_frame, text="", anchor="center")
        info_label_1 = Label(down_frame, text="", anchor="center")
        info_label_2 = Label(down_frame, text="", anchor="center", textvariable=self.display_text)

        info_label_0.pack(side=TOP)
        info_label_1.pack(side=TOP)
        info_label_2.pack(side=TOP)

        down_frame.pack(fill=X, side=BOTTOM)

        right_frame.pack(fill=Y, side=RIGHT)
        self.create_paint_frame(right_frame).pack(side=TOP, pady=15)
        # self.create_hyperbola_frame(right_frame).pack(side=TOP)

        self.canvas.pack(fill=BOTH, side=LEFT, expand=True)

    def create_paint_frame(self, right_frame):
        paint_frame = Frame(right_frame)

        self.a = Entry(paint_frame, width=5)
        self.b = Entry(paint_frame, width=5)
        self.r = Entry(paint_frame, width=5)
        self.c = Entry(paint_frame, width=5)

        rect_label = Label(paint_frame, text="Окружность\n\n(x-a)^2 + (y-b)^2 = r^2\n", anchor="center")

        rect_label.grid(row=0, column=0, columnspan=4)

        Label(paint_frame, text="a = ").grid(row=1, column=0, sticky=E)
        self.a.grid(row=1, column=1, sticky=W)

        Label(paint_frame, text="b = ").grid(row=2, column=0, sticky=E)
        self.b.grid(row=2, column=1, sticky=W)

        Label(paint_frame, text="r = ").grid(row=3, column=0, sticky=E)
        self.r.grid(row=3, column=1, sticky=W)

        point_label = Label(paint_frame, text="\n\nГипербола\n\ny = c / x", anchor="center")
        point_label.grid(row=4, column=0, columnspan=4)

        Label(paint_frame, text="c = ").grid(row=5, column=0, sticky=E, pady=5)
        self.c.grid(row=5, column=1, sticky=W, pady=2)

        btn_do = Button(paint_frame, text="DO")
        btn_do.grid(row=6, column=0, columnspan=4, ipadx=50, padx=2, pady=2)

        btn_clean = Button(paint_frame, text="Clean")
        btn_clean.grid(row=7, column=0, columnspan=4, ipadx=45, padx=2, pady=2)

        return paint_frame

    def create_hyperbola_frame(self, right_frame):
        hyperbola_frame = Frame(right_frame)

        self.c = Entry(hyperbola_frame, width=5)

        point_label = Label(hyperbola_frame, text="Гипербола\n\ny = c / x\n", anchor="center")
        point_label.grid(row=0, column=0, columnspan=4)

        Label(hyperbola_frame, text="c = ").grid(row=2, column=0, sticky=E)
        self.c.grid(row=2, column=1, sticky=W)

        return hyperbola_frame
