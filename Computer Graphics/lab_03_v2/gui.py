from tkinter import *
from tkinter import ttk
from tkinter import Canvas
from math import fabs


def sign(x):

    if x > 0:
        return 1
    elif x < 0:
        return -1
    else:
        return 0


class MainFrame(Tk):

    def __init__(self):
        super().__init__()

        self.width = 700
        self.height = 700

        self.xb = None
        self.yb = None
        self.xe = None
        self.ye = None

        self.color_box = None
        self.algorithm_box = None

        self.display_text = None

        self.canvas = None
        self.border = 15

        self.d_color = {'Красный': 'red1',
                        'Зеленый': 'green4',
                        'Синий': 'blue2',
                        'Желтый': 'yellow',
                        'Фиолетовый': 'magenta4'}

        self.d_algorithm = {'С целыми числами.': 0,
                            'С действительными числами.': 1,
                            'С устранением ступенчатости.': 2,
                            'CDA': 3,
                            'Стандартный алгоритм.': 4}

        self.cords = list()

        self.initUI()

    def initUI(self):
        self.geometry("870x790+40+80")
        self.resizable(False, False)
        self.title("Lab 3")

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
        self.create_rect_frame(right_frame).pack(side=TOP, pady=15)
        self.canvas.pack(fill=BOTH, side=LEFT, expand=True)

    def create_rect_frame(self, right_frame):
        rect_frame = Frame(right_frame)

        self.xb = Entry(rect_frame, width=5)
        self.yb = Entry(rect_frame, width=5)
        self.xe = Entry(rect_frame, width=5)
        self.ye = Entry(rect_frame, width=5)

        self.color_box = ttk.Combobox(rect_frame)
        self.color_box['values'] = ('Красный',
                                    'Зеленый',
                                    'Синий',
                                    'Желтый',
                                    'Фиолетовый')
        self.color_box.current(0)

        self.algorithm_box = ttk.Combobox(rect_frame)
        self.algorithm_box['values'] = ('С целыми числами.',
                                        'С действительными числами.',
                                        'С устранением ступенчатости.',
                                        'CDA',
                                        'Стандартный алгоритм.')
        self.algorithm_box.current(0)

        action_btn = Button(rect_frame, text="Отрисовать", command=self.action)
        clean_btn = Button(rect_frame, text="Очистить", command=self.clean)

        rect_label = Label(rect_frame, text="Линия\n\nКоординаты начала линии.", anchor="center")
        rect_label.grid(row=0, column=0, columnspan=4)

        Label(rect_frame, text="x =").grid(row=1, column=0, sticky=E)
        self.xb.grid(row=1, column=1, sticky=W)
        Label(rect_frame, text="y =").grid(row=1, column=2, sticky=E)
        self.yb.grid(row=1, column=3, sticky=W)

        rect_label = Label(rect_frame, text="\nКоординаты конца линии.", anchor="center")
        rect_label.grid(row=2, column=0, columnspan=4)

        Label(rect_frame, text="x =").grid(row=3, column=0, sticky=E)
        self.xe.grid(row=3, column=1, sticky=W)
        Label(rect_frame, text="y =").grid(row=3, column=2, sticky=E)
        self.ye.grid(row=3, column=3, sticky=W)

        Label(rect_frame, text="Цвет", anchor=CENTER).grid(row=4, column=0, columnspan=4, pady=2)
        self.color_box.grid(row=5, column=0, columnspan=4, padx=2, pady=2)

        Label(rect_frame, text="Алгоритм", anchor=CENTER).grid(row=6, column=0, columnspan=4, pady=0)
        self.algorithm_box.grid(row=7, column=0, columnspan=4, padx=2, pady=6)

        action_btn.grid(row=8, column=0, columnspan=2, padx=2)
        clean_btn.grid(row=8, column=2, columnspan=2, padx=2, ipadx=3)

        return rect_frame

    def b_simple(self, xn, yn, xk, yk, col):

        x = xn
        y = yn

        dx = xk - xn
        dy = yk - yn

        sx = sign(dx)
        sy = sign(dy)

        dx = abs(dx)
        dy = abs(dy)

        flag = 0

        if not (dx > dy):
            flag = 1
            dx, dy = dy, dx

        e = 2 * dy - dx

        for i in range(dx):
            self.canvas.create_rectangle(x, y, x, y, outline=col)

            if e >= 0:
                if flag == 0:
                    y += sy
                else:
                    x += sx

                e -= 2 * dx

            else:
                if flag == 0:
                    x += sx
                else:
                    y += sy

                e += 2 * dy

    def b_norm(self, xn, yn, xk, yk, col):

        x = xn
        y = yn

        dx = xk - xn
        dy = yk - yn

        sx = sign(dx)
        sy = sign(dy)

        dx = abs(dx)
        dy = abs(dy)

        flag = 0

        if not (dx > dy):
            flag = 1
            dx, dy = dy, dx

        m = dy/dx
        e = m - 0.5

        for i in range(dx):
            self.canvas.create_rectangle(x, y, x, y, outline=col)

            if e >= 0:
                if flag == 0:
                    y += sy
                else:
                    x += sx

                e -= 1

            else:
                if flag == 0:
                    x += sx
                else:
                    y += sy

                e += m

    def b_2(self, xn, yn, xk, yk, col):

        x = xn
        y = yn

        dx = xk - xn
        dy = yk - yn

        sx = sign(dx)
        sy = sign(dy)

        dx = abs(dx)
        dy = abs(dy)

        flag = 0

        if not (dx > dy):
            flag = 1
            dx, dy = dy, dx

        m = dy/dx
        e = m - 0.5

        for i in range(dx):
            self.canvas.create_rectangle(x, y, x, y, outline=col)

            if e >= 0:
                if flag == 0:
                    y += sy
                else:
                    x += sx

                e -= 1

            else:
                if flag == 0:
                    x += sx
                else:
                    y += sy

                e += m

    def action(self):

        alg = self.algorithm_box.get()
        col = self.color_box.get()

        xb = float(self.xb.get())
        yb = self.canvas.winfo_height() - float(self.yb.get())
        xe = float(self.xe.get())
        ye = self.canvas.winfo_height() - float(self.ye.get())

        if self.d_algorithm[alg] == 0:
            self.b_simple(round(xb), round(yb), round(xe), round(ye), self.d_color[col])
        elif self.d_algorithm[alg] == 1:
            self.b_norm(round(xb), round(yb), round(xe), round(ye), self.d_color[col])
        elif self.d_algorithm[alg] == 4:
            pass
        self.canvas.create_line(xb, yb, xe, ye, fill='#{:02x}{:02x}{:02x}{:02x}'.format(0, 0, 255, 100))

    def clean(self):
        self.canvas.delete("all")
