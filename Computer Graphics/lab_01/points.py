from math import cos, sin, radians


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


def is_number(string):
    try:
        float(string)
        return True
    except ValueError:
        return False


def get_rect_centre(rect):
    xl = rect[0][0]
    yl = rect[0][1]
    xr = xl + rect[1]
    yr = yl + rect[2]

    xr = xr * cos(radians(rect[3])) - yr * sin(radians(rect[3]))
    yr = xr * sin(radians(rect[3])) + yr * cos(radians(rect[3]))

    return (xl + xr) / 2, (yl + yr) / 2


def get_triangle_point(cords, rect_centre):
    cords_len = len(cords)
    min_fi = -2.0
    triangle = None
    point = None

    for p1 in range(cords_len):
        for p2 in range(p1 + 1, cords_len):
            for p3 in range(p2 + 1, cords_len):

                if is_triangle(cords[p1], cords[p2], cords[p3]):

                    res_point = find_point(cords[p1], cords[p2], cords[p3])
                    fi = find_corner(res_point, rect_centre)

                    if fi > min_fi:
                        min_fi = fi
                        triangle = (cords[p1], cords[p2], cords[p3])
                        point = res_point

    return triangle, min_fi, point


def get_rect_points(rect):
    xl = rect[0][0]
    yl = rect[0][1]

    xr = rect[1] * cos(radians(rect[3])) - rect[2] * sin(radians(rect[3]))
    yr = rect[1] * sin(radians(rect[3])) + rect[2] * cos(radians(rect[3]))

    xr += rect[0][0]
    yr += rect[0][1]

    xl2 = 0 * cos(radians(rect[3])) - rect[2] * sin(radians(rect[3]))
    yl2 = 0 * sin(radians(rect[3])) + rect[2] * cos(radians(rect[3]))

    xl2 += rect[0][0]
    yl2 += rect[0][1]

    xr2 = rect[1] * cos(radians(rect[3])) - 0 * sin(radians(rect[3]))
    yr2 = rect[1] * sin(radians(rect[3])) + 0 * cos(radians(rect[3]))

    xr2 += rect[0][0]
    yr2 += rect[0][1]

    return (xl, yl), (xl2, yl2), (xr, yr), (xr2, yr2)
