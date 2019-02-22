from math import acos, degrees, tan
from tkinter import *
from tkinter.ttk import *
from tkinter import Canvas, Frame, Button, Label, Entry


def find_point(p1, p2, p3):
    a = ((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2) ** 0.5
    b = ((p3[0] - p2[0]) ** 2 + (p3[1] - p2[1]) ** 2) ** 0.5
    c = ((p1[0] - p3[0]) ** 2 + (p1[1] - p3[1]) ** 2) ** 0.5

    x = (b * p1[0] + c * p2[0] + a * p3[0]) / (a + b + c)
    y = (b * p1[1] + c * p2[1] + a * p3[1]) / (a + b + c)

    return x, y


def find_corner(p1, p2):
    x = p1[0] - p2[0]
    y = p1[1] - p2[1]

    cos_fi = x / ((x * x + y * y) ** 0.5)
    print("cos_fi = ", cos_fi)
    return cos_fi


def is_triangle(p1, p2, p3):
    if (p2[1] - p1[1]) * (p3[0] - p1[0]) != (p3[1] - p1[1]) * (p2[0] - p1[0]):
        return True
    return False


class MainFrame(Tk):

    def __init__(self):
        super().__init__()

        self.ex1 = None
        self.ey1 = None
        self.rect_a = None
        self.rect_b = None
        self.rect_fi = None

        self.ex = None
        self.ey = None

        self.display_text = None

        self.listbox = None

        self.btn_do = None
        self.btn_add = None
        self.btn_cls = None

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

        self.ex1 = Entry(rect_frame, width=5)
        self.ey1 = Entry(rect_frame, width=5)
        self.rect_a = Entry(rect_frame, width=5)
        self.rect_b = Entry(rect_frame, width=5)
        self.rect_fi = Entry(rect_frame, width=5)

        rect_label = Label(rect_frame, text="Прямоугольник\nЛевая нижняя точка.", anchor="center")

        rect_label.grid(row=0, column=0, columnspan=4)

        Label(rect_frame, text="x =").grid(row=1, column=0, sticky=E)
        self.ex1.grid(row=1, column=1, sticky=W)
        Label(rect_frame, text="y =").grid(row=1, column=2, sticky=E)
        self.ey1.grid(row=1, column=3, sticky=W)

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

        self.btn_add = Button(point_frame, text="Add", command=self.add_point)
        self.btn_add.grid(row=3, column=0, columnspan=2, ipadx=15, padx=2, pady=2)
        self.btn_cls = Button(point_frame, text="Clean", command=self.clean)
        self.btn_cls.grid(row=3, column=2, columnspan=2, ipadx=15, padx=2, pady=2)

        self.btn_do = Button(point_frame, text="DO", command=self.do_it)
        self.btn_do.grid(row=4, column=0, columnspan=4, ipadx=55, padx=2, pady=2)

        return point_frame

    def add_point(self):
        if len(self.ex.get()) != 0 and len(self.ey.get()) != 0:
            self.cords.append((float(self.ex.get()), float(self.ey.get())))
            self.listbox.insert(0, "  ({} ; {})".format(self.ex.get(), self.ey.get()))
            self.ex.delete(0, END)
            self.ey.delete(0, END)

    def clean(self):
        self.ex.delete(0, END)
        self.ey.delete(0, END)

        self.ex1.delete(0, END)
        self.ey1.delete(0, END)
        self.ex2.delete(0, END)
        self.ey2.delete(0, END)
        self.ex3.delete(0, END)
        self.ey3.delete(0, END)
        self.ex4.delete(0, END)
        self.ey4.delete(0, END)

        self.canvas.delete("all")

        self.display_text.set("")

        self.listbox.delete(0, END)

        self.cords.clear()

    def do_it(self):

        if len(self.cords) > 2:

            rect_centre, rect = self.get_rect()

            if (rect[1][0] - rect[0][0]) * (rect[1][1] - rect[0][1]) != 0:
                triangle, cos_fi, b_point = self.get_triangle_point(rect_centre)

                if b_point is not None:

                    # scale

                    k, mins = self.get_scale(rect, triangle, b_point)

                    # draw graph

                    self.draw_rect(rect, mins, k)
                    self.draw_triangle(triangle, b_point, mins, k)
                    self.draw_lines(rect_centre, b_point, mins, k)

                    self.display_text.set("Минимальный угол = {:.3f} градуса.".format(degrees(acos(cos_fi))))

                else:
                    self.display_text.set("Выражденный треугольник")
            else:
                self.display_text.set("Прямоугольник задан неправильно.")
        else:
            self.display_text.set("Мало точек")

    # helper function

    def get_rect(self):
        xl = float(self.ex1.get())
        yl = float(self.ey1.get())
        xr = float(self.ex3.get())
        yr = float(self.ey3.get())

        return ((xl + xr) / 2, (yl + yr) / 2), ((xl, yl), (xr, yr))

    def get_triangle_point(self, rect_centre):
        cords_len = len(self.cords)
        min_fi = -2.0
        triangle = None
        point = None

        for p1 in range(cords_len):
            for p2 in range(p1 + 1, cords_len):
                for p3 in range(p2 + 1, cords_len):

                    if is_triangle(self.cords[p1], self.cords[p2], self.cords[p3]):

                        res_point = find_point(self.cords[p1], self.cords[p2], self.cords[p3])
                        fi = find_corner(res_point, rect_centre)

                        if fi > min_fi:
                            min_fi = fi
                            triangle = (p1, p2, p3)
                            point = res_point

        return triangle, min_fi, point

    def get_scale(self, rect, triangle, b_point):
        width = 700
        height = 700

        min_x = min(rect[0][0], rect[1][0], self.cords[triangle[0]][0],
                    self.cords[triangle[1]][0], self.cords[triangle[2]][0], b_point[0])
        max_x = max(rect[0][0], rect[1][0], self.cords[triangle[0]][0],
                    self.cords[triangle[1]][0], self.cords[triangle[2]][0], b_point[0])
        min_y = min(rect[0][1], rect[1][1], self.cords[triangle[0]][1],
                    self.cords[triangle[1]][1], self.cords[triangle[2]][1], b_point[1])
        print("min y = ", min_y)
        max_y = max(rect[0][1], rect[1][1], self.cords[triangle[0]][1],
                    self.cords[triangle[1]][1], self.cords[triangle[2]][1], b_point[1])

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
        print("k = ", k)
        return k, (min_x, min_y)

    # draw functions

    def draw_rect(self, rect, mins, k):
        my = 700#self.canvas.winfo_height()
        min_x = mins[0]# fabs(mins[0])
        min_y = mins[1]# fabs(mins[1])

        xl = (rect[0][0] - min_x) * k + self.border
        yl = my - (rect[0][1] - min_y) * k - self.border
        xr = (rect[1][0] - min_x) * k + self.border
        yr = my - (rect[1][1] - min_y) * k - self.border

        self.canvas.create_rectangle(xl, yl, xr, yr, outline="blue")
        self.canvas.create_oval((xl + xr) / 2 - 2, (yl + yr) / 2 - 2,
                                (xl + xr) / 2 + 2, (yl + yr) / 2 + 2,
                                fill="red", outline="red")
        self.canvas.create_text((xl + xr) / 2 + 18, (yl + yr) / 2 + 18,
                                text="({:.1f}, {:.1f})".format((rect[1][0] + rect[0][0]) / 2,
                                                               (rect[1][1] + rect[0][1]) / 2),
                                font="Verdana 8", justify=CENTER)

    def draw_triangle(self, triangle, b_point, mins, k):

        my = 700#self.canvas.winfo_height()
        # min_x = fabs(mins[0])
        # min_y = fabs(mins[1])
        min_x = mins[0]
        min_y = mins[1]

        self.canvas.create_line((self.cords[triangle[0]][0] - min_x) * k + self.border,
                                my - (self.cords[triangle[0]][1] - min_y) * k - self.border,
                                (self.cords[triangle[1]][0] - min_x) * k + self.border,
                                my - (self.cords[triangle[1]][1] - min_y) * k - self.border, fill="green")

        self.canvas.create_line((self.cords[triangle[1]][0] - min_x) * k + self.border,
                                my - (self.cords[triangle[1]][1] - min_y) * k - self.border,
                                (self.cords[triangle[2]][0] - min_x) * k + self.border,
                                my - (self.cords[triangle[2]][1] - min_y) * k - self.border, fill="green")

        self.canvas.create_line((self.cords[triangle[2]][0] - min_x) * k + self.border,
                                my - (self.cords[triangle[2]][1] - min_y) * k - self.border,
                                (self.cords[triangle[0]][0] - min_x) * k + self.border,
                                my - (self.cords[triangle[0]][1] - min_y) * k - self.border, fill="green")

        self.canvas.create_oval((b_point[0] - min_x) * k + self.border - 2,
                                my - (b_point[1] - min_y) * k - self.border - 2,
                                (b_point[0] - min_x) * k + self.border + 2,
                                my - (b_point[1] - min_y) * k - self.border + 2,
                                fill="red", outline="red")

        self.canvas.create_text((b_point[0] - min_x) * k + self.border + 18,
                                my - (b_point[1] - min_y) * k - self.border + 18,
                                text="({:.1f}, {:.1f})".format(b_point[0], b_point[1]),
                                font="Verdana 8", justify=CENTER)

    def draw_lines(self, p1, p2, mins, k):

        my = 700#self.canvas.winfo_height()
        # min_x = fabs(mins[0])
        # min_y = fabs(mins[1])
        min_x = mins[0]
        min_y = mins[1]

        self.canvas.create_line((p1[0] - min_x) * k + self.border,
                                my - (p1[1] - min_y) * k - self.border,
                                (p2[0] - min_x) * k + self.border,
                                my - (p2[1] - min_y) * k - self.border, fill="maroon")

        x0 = (p1[0] + p2[0]) / 2
        y0 = (p1[1] + p2[1]) / 2

        x0 = (x0 - min_x) * k + self.border
        y0 = my - (y0 - min_y) * k - self.border

        self.canvas.create_line(x0 - 200, y0, x0 + 200, y0, arrow=LAST)
        self.canvas.create_text(x0 + 190, y0 - 18, text="Параллельная оси X",
        font="Verdana 8", justify=CENTER)



def main():
    app = MainFrame()
    app.mainloop()


if __name__ == '__main__':
    main()
