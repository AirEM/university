from tkinter import *


class MainFrame(Tk):

    def __init__(self):
        super().__init__()

        self.width = 700
        self.height = 700

        # Перенос

        self.dx = None
        self.dy = None

        # Масштабирование

        self.xm = None
        self.ym = None
        self.kx = None
        self.ky = None

        # Поворот

        self.xc = None
        self.yc = None
        self.fi = None

        # other

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

        self.create_carry_frame(right_frame).pack(side=TOP, pady=15)
        self.create_scaling_frame(right_frame).pack(side=TOP, pady=15)
        self.create_rotation_frame(right_frame).pack(side=TOP, pady=15)

        self.canvas.pack(fill=BOTH, side=LEFT, expand=True)

    def create_carry_frame(self, right_frame):
        carry_frame = Frame(right_frame)

        self.dx = Entry(carry_frame, width=5)
        self.dy = Entry(carry_frame, width=5)

        carry_label = Label(carry_frame, text="Перенос", anchor="center")
        carry_label.grid(row=0, column=0, columnspan=4, pady=7)

        Label(carry_frame, text="dx = ").grid(row=1, column=0, sticky=E)
        self.dx.grid(row=1, column=1, sticky=W)

        Label(carry_frame, text="dy = ").grid(row=1, column=2, sticky=E)
        self.dy.grid(row=1, column=3, sticky=W)

        btn_carry = Button(carry_frame, text="Выполнить")
        btn_carry.grid(row=2, column=0, columnspan=4, ipadx=50, padx=2, pady=5)

        return carry_frame

    def create_scaling_frame(self, right_frame):
        scaling_frame = Frame(right_frame)

        self.xm = Entry(scaling_frame, width=5)
        self.ym = Entry(scaling_frame, width=5)
        self.kx = Entry(scaling_frame, width=5)
        self.ky = Entry(scaling_frame, width=5)

        point_label = Label(scaling_frame, text="Масштабирование", anchor="center")
        point_label.grid(row=0, column=0, columnspan=4, pady=7)

        # Центр масштабирования

        centre_label = Label(scaling_frame, text="Центр масштабирования", anchor="center")
        centre_label.grid(row=1, column=0, columnspan=4)

        Label(scaling_frame, text="x = ").grid(row=2, column=0, sticky=E)
        self.xm.grid(row=2, column=1, sticky=W)

        Label(scaling_frame, text="y = ").grid(row=2, column=2, sticky=E)
        self.ym.grid(row=2, column=3, sticky=W)

        # Коэф-ты масштабирования

        coeff_label = Label(scaling_frame, text="Коэф-ты масштабирования", anchor="center")
        coeff_label.grid(row=3, column=0, columnspan=4)

        Label(scaling_frame, text="kx = ").grid(row=4, column=0, sticky=E)
        self.kx.grid(row=4, column=1, sticky=W)

        Label(scaling_frame, text="ky = ").grid(row=4, column=2, sticky=E)
        self.ky.grid(row=4, column=3, sticky=W)

        btn_carry = Button(scaling_frame, text="Выполнить")
        btn_carry.grid(row=5, column=0, columnspan=4, ipadx=50, padx=2, pady=5)

        return scaling_frame

    def create_rotation_frame(self, frame):
        rotation_frame = Frame(frame)

        self.xc = Entry(rotation_frame, width=5)
        self.yc = Entry(rotation_frame, width=5)
        self.fi = Entry(rotation_frame, width=5)

        point_label = Label(rotation_frame, text="Поворот", anchor="center")
        point_label.grid(row=0, column=0, columnspan=4, pady=7)

        centre_label = Label(rotation_frame, text="Центр поворота", anchor="center")
        centre_label.grid(row=1, column=0, columnspan=4)

        Label(rotation_frame, text="x = ").grid(row=2, column=0, sticky=E)
        self.xc.grid(row=2, column=1, sticky=W)

        Label(rotation_frame, text="y = ").grid(row=2, column=2, sticky=E)
        self.yc.grid(row=2, column=3, sticky=W)

        Label(rotation_frame, text="Угол = ").grid(row=3, column=0, columnspan=2, sticky=E)
        self.fi.grid(row=3, column=2, sticky=W)

        btn_carry = Button(rotation_frame, text="Выполнить")
        btn_carry.grid(row=4, column=0, columnspan=4, ipadx=50, padx=2, pady=5)

        return rotation_frame
