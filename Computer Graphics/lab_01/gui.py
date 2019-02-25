from math import acos, degrees
from tkinter import *
# from tkinter.ttk import *
from tkinter import messagebox as mb
# from tkinter import Canvas, Frame, Button, Label, Entry
from points import *


class MainFrame(Tk):

    def __init__(self):
        super().__init__()

        self.width = 700
        self.height = 700

        self.rect_x = None
        self.rect_y = None
        self.rect_a = None
        self.rect_b = None
        self.rect_fi = None

        self.ex = None
        self.ey = None

        self.display_text = None

        self.listbox = None

        self.canvas = None
        self.border = 15

        self.cords = list()

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
        self.create_rect_frame(right_frame).pack(side=TOP, pady=15)
        self.create_point_frame(right_frame).pack(side=TOP)

        self.canvas.pack(fill=BOTH, side=LEFT, expand=True)

    def create_rect_frame(self, right_frame):
        rect_frame = Frame(right_frame)

        self.rect_x = Entry(rect_frame, width=5)
        self.rect_y = Entry(rect_frame, width=5)
        self.rect_a = Entry(rect_frame, width=5)
        self.rect_b = Entry(rect_frame, width=5)
        self.rect_fi = Entry(rect_frame, width=5)

        rect_label = Label(rect_frame, text="Прямоугольник\nЛевая нижняя точка.", anchor="center")

        rect_label.grid(row=0, column=0, columnspan=4)

        Label(rect_frame, text="x =").grid(row=1, column=0, sticky=E)
        self.rect_x.grid(row=1, column=1, sticky=W)
        Label(rect_frame, text="y =").grid(row=1, column=2, sticky=E)
        self.rect_y.grid(row=1, column=3, sticky=W)

        Label(rect_frame, text="Длинна : ").grid(row=2, column=0, columnspan=3, sticky=E)
        self.rect_a.grid(row=2, column=3, sticky=W)

        Label(rect_frame, text="Ширина : ").grid(row=3, column=0, columnspan=3, sticky=E)
        self.rect_b.grid(row=3, column=3, sticky=W)

        Label(rect_frame, text="Угол поворота : ").grid(row=4, column=0, columnspan=3, sticky=E)
        self.rect_fi.grid(row=4, column=3, sticky=W)

        return rect_frame

    def create_point_frame(self, right_frame):
        point_frame = Frame(right_frame)

        self.ex = Entry(point_frame, width=5)
        self.ey = Entry(point_frame, width=5)

        point_label = Label(point_frame, text="Точки", anchor="center")

        point_label.grid(row=0, column=0, columnspan=4)

        Label(point_frame, text="x =").grid(row=2, column=0, sticky=E)
        self.ex.grid(row=2, column=1, sticky=W)
        Label(point_frame, text="y =").grid(row=2, column=2, sticky=E)
        self.ey.grid(row=2, column=3, sticky=W)

        scrollbar = Scrollbar(point_frame)
        scrollbar.grid(row=1, column=1)

        self.listbox = Listbox(point_frame, yscrollcommand=scrollbar.set, height=17)

        self.listbox.grid(row=1, column=0, columnspan=4, ipadx=2, ipady=2, padx=10, pady=5)
        scrollbar.config(command=self.listbox.yview)

        btn_add = Button(point_frame, text="Add", command=self.add_point)
        btn_add.grid(row=3, column=0, columnspan=2, ipadx=15, padx=2, pady=2)
        btn_del = Button(point_frame, text="Delete", command=self.delete_point)
        btn_del.grid(row=3, column=2, columnspan=2, ipadx=13, padx=2, pady=2)

        btn_cls = Button(point_frame, text="Clean", command=self.clean)
        btn_cls.grid(row=4, column=0, columnspan=4, ipadx=49, padx=2, pady=2)

        btn_do = Button(point_frame, text="DO", command=self.do_it)
        btn_do.grid(row=5, column=0, columnspan=4, ipadx=55, padx=2, pady=2)

        return point_frame

    def add_point(self):
        if len(self.ex.get()) != 0 and len(self.ey.get()) != 0:
            self.cords.append((float(self.ex.get()), float(self.ey.get())))
            self.listbox.insert(0, "  ({} ; {})".format(self.ex.get(), self.ey.get()))
            self.ex.delete(0, END)
            self.ey.delete(0, END)

    def delete_point(self):
        selection = self.listbox.curselection()
        # мы можем получить удаляемый элемент по индексу
        # selected_language = languages_listbox.get(selection[0])
        self.listbox.delete(selection[0])

    def clean(self):
        self.ex.delete(0, END)
        self.ey.delete(0, END)

        self.rect_x.delete(0, END)
        self.rect_y.delete(0, END)
        self.rect_a.delete(0, END)
        self.rect_b.delete(0, END)
        self.rect_fi.delete(0, END)

        self.canvas.delete("all")

        self.display_text.set("")

        self.listbox.delete(0, END)

        self.cords.clear()

    def do_it(self):

        self.canvas.delete("all")

        if len(self.cords) > 2:

            rect = self.get_rect()

            if rect is not None:

                rect_centre = get_rect_centre(rect)
                rect_points = get_rect_points(rect)

                triangle, cos_fi, b_point = get_triangle_point(self.cords, rect_centre)

                if b_point is not None:

                    # scale

                    k, mins = self.get_scale(rect_points, triangle, b_point)

                    # draw graph

                    self.draw_rect(rect_points, mins, k)
                    self.draw_triangle(triangle, b_point, mins, k)
                    self.draw_lines(rect_points, b_point, mins, k)

                    self.display_text.set("Минимальный угол = {:.3f} градуса.".format(degrees(acos(cos_fi))))

                else:
                    self.display_text.set("Выражденный треугольники")
                    mb.showerror("Ошибка", "Выражденный треугольники")
            else:
                self.display_text.set("Прямоугольник задан некорректно.")
                mb.showerror("Ошибка", "Прямоугольник задан некорректно.")
        else:
            self.display_text.set("Требуется не менее трех точек.")
            mb.showerror("Ошибка", "Требуется не менее трех точек.")

    # helper function

    def get_rect(self):

        if is_number(self.rect_x.get()) and is_number(self.rect_y.get()) \
                and is_number(self.rect_a.get()) and is_number(self.rect_b.get()) \
                and is_number(self.rect_fi.get()):

            x = float(self.rect_x.get())
            y = float(self.rect_y.get())
            a = float(self.rect_a.get())
            b = float(self.rect_b.get())
            fi = float(self.rect_fi.get())

            if a > 0 and b > 0 and 0 <= fi < 180:
                return (x, y), a, b, fi

        return None

    def get_scale(self, rect_points, triangle, b_point):
        width = self.width
        height = self.height

        k = None

        min_x = min(rect_points[0][0], rect_points[1][0], rect_points[2][0], rect_points[3][0],
                    triangle[0][0], triangle[1][0], triangle[2][0], b_point[0])
        max_x = max(rect_points[0][0], rect_points[1][0], rect_points[2][0], rect_points[3][0],
                    triangle[0][0], triangle[1][0], triangle[2][0], b_point[0])
        min_y = min(rect_points[0][1], rect_points[1][1], rect_points[2][1], rect_points[3][1],
                    triangle[0][1], triangle[1][1], triangle[2][1], b_point[1])
        max_y = max(rect_points[0][1], rect_points[1][1], rect_points[2][1], rect_points[3][1],
                    triangle[0][1], triangle[1][1], triangle[2][1], b_point[1])

        k_x = (width - 2 * self.border) / (max_x - min_x)
        k_y = (height - 2 * self.border) / (max_y - min_y)

        if k_x >= 1 and k_y >= 1:
            k = min(k_x, k_y)
        elif k_x < 1 and k_y >= 1:
            k = k_x
        elif k_x >= 1 and k_y < 1:
            k = k_y
        elif k_x < 1 and k_y < 1:
            k = min(k_x, k_y)

        return k, (min_x, min_y)

    # draw functions

    def draw_rect(self, rect_points, mins, k):
        my = self.height
        min_x = mins[0]
        min_y = mins[1]

        xl = rect_points[0][0]
        yl = rect_points[0][1]

        xr = rect_points[2][0]
        yr = rect_points[2][1]

        xl2 = rect_points[1][0]
        yl2 = rect_points[1][1]

        xr2 = rect_points[3][0]
        yr2 = rect_points[3][1]

        tx = (xl + xr) / 2
        ty = (yl + yr) / 2

        # other

        xl = (xl - min_x) * k + self.border
        yl = my - (yl - min_y) * k - self.border

        xr = (xr - min_x) * k + self.border
        yr = my - (yr - min_y) * k - self.border

        xl2 = (xl2 - min_x) * k + self.border
        yl2 = my - (yl2 - min_y) * k - self.border

        xr2 = (xr2 - min_x) * k + self.border
        yr2 = my - (yr2 - min_y) * k - self.border

        # drawing

        self.canvas.create_line(xl, yl, xr2, yr2, xr, yr, xl2, yl2, xl, yl, fill="blue")

        self.canvas.create_oval((xl + xr) / 2 - 2, (yl + yr) / 2 - 2,
                                (xl + xr) / 2 + 2, (yl + yr) / 2 + 2,
                                fill="red", outline="red")
        self.canvas.create_text((xl + xr) / 2 + 18, (yl + yr) / 2 + 18,
                                text="({:.1f}, {:.1f})".format(tx, ty),
                                font="Verdana 8", justify=CENTER)

    def draw_triangle(self, triangle, b_point, mins, k):

        my = self.height
        min_x = mins[0]
        min_y = mins[1]

        self.canvas.create_line((triangle[0][0] - min_x) * k + self.border,
                                my - (triangle[0][1] - min_y) * k - self.border,
                                (triangle[1][0] - min_x) * k + self.border,
                                my - (triangle[1][1] - min_y) * k - self.border, fill="green")

        self.canvas.create_line((triangle[1][0] - min_x) * k + self.border,
                                my - (triangle[1][1] - min_y) * k - self.border,
                                (triangle[2][0] - min_x) * k + self.border,
                                my - (triangle[2][1] - min_y) * k - self.border, fill="green")

        self.canvas.create_line((triangle[2][0] - min_x) * k + self.border,
                                my - (triangle[2][1] - min_y) * k - self.border,
                                (triangle[0][0] - min_x) * k + self.border,
                                my - (triangle[0][1] - min_y) * k - self.border, fill="green")

        self.canvas.create_oval((b_point[0] - min_x) * k + self.border - 2,
                                my - (b_point[1] - min_y) * k - self.border - 2,
                                (b_point[0] - min_x) * k + self.border + 2,
                                my - (b_point[1] - min_y) * k - self.border + 2,
                                fill="red", outline="red")

        self.canvas.create_text((b_point[0] - min_x) * k + self.border + 18,
                                my - (b_point[1] - min_y) * k - self.border + 18,
                                text="({:.1f}, {:.1f})".format(b_point[0], b_point[1]),
                                font="Verdana 8", justify=CENTER)

    def draw_lines(self, rect_points, b_point, mins, k):

        my = self.height
        min_x = mins[0]
        min_y = mins[1]

        xl = rect_points[0][0]
        yl = rect_points[0][1]

        xr = rect_points[2][0]
        yr = rect_points[2][1]

        x1 = (xl + xr) / 2
        y1 = (yl + yr) / 2

        self.canvas.create_line((x1 - min_x) * k + self.border,
                                my - (y1 - min_y) * k - self.border,
                                (b_point[0] - min_x) * k + self.border,
                                my - (b_point[1] - min_y) * k - self.border, fill="maroon")

        x0 = (x1 + b_point[0]) / 2
        y0 = (y1 + b_point[1]) / 2

        x0 = (x0 - min_x) * k + self.border
        y0 = my - (y0 - min_y) * k - self.border

        self.canvas.create_line(x0 - 200, y0, x0 + 200, y0, arrow=LAST)
        self.canvas.create_text(x0 + 190, y0 - 18, text="Параллельная оси X",
        font="Verdana 8", justify=CENTER)

