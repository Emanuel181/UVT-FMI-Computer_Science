import random

from skimage import io
import matplotlib.pyplot as plt
import time


def load_image_from_file(path):
    """
    load the image from a file located at path
    """

    img = io.imread(path)
    # find information about image dimension
    print(type(img))
    print(img.shape)
    # for i in range(img.shape[0]):
       # for j in range(img.shape[1]):
           # print(i, j, "-->", img[i][j])
    # print(img)

    return img


def inverse_image(img):
    """
    transformam imaginea [[[r,g,b], [r,g,b], 0],
                          [0, 0, 0]]
    """
    lines = img.shape[0]
    columns = img.shape[1]
    a = [[0 for j in range(columns)]  for i in range(lines)]
    # print(a[0])
    for i in range(lines):
        for j in range(columns):
            r, g, b = img[i][j]
            a[i][j] = [(255 - r), (255 - g), (255 - b)]
    return a


def show_image(n, m, i, img):
    # display the image
    plt.subplot(n, m, i)
    plt.imshow(img)



# def blur_image(img, radius):
#     a = [[0 for j in range(img.shape[1])] for i in range(img.shape[0])]
#     for i in range(img.shape[0]):
#         for j in range(img.shape[1]):
#             avg = [0, 0, 0]
#             count = (radius*2)**2
#             for k in range(-radius, radius+1):
#                 for k2 in range(-radius, radius+1):
#                     if k == 0 and k == k2:
#                         continue
#                     if i+k < 0 or i + k >= img.shape[0]:
#                         continue
#                     if j+k2 < 0 or j + k2 >= img.shape[1]:
#                         continue
#                     for color in range(3):
#                         avg[color] += img[i+k][j+k2][color]
#             for color in range(3):
#                 avg[color] = int(avg[color] / count)
#             a[i][j] = avg
#     return  a

# [[[r,g,b], [r,g,b], [r,g,b]]
#  [[r,g,b], [r,g,b], [r,g,b]]
#  [[r,g,b], [r,g,b], [r,g,b]]]


def blur_pixel(img, i, j, radius):
    avg = [0,0,0]
    count = 0
    for x in range(-radius, radius+1):
        for y in range(-radius, radius+1):
            if i + x >= img.shape[0] or i + x < 0:
                continue
            if j + y >= img.shape[1] or j + y < 0:
                continue
            avg[0] += img[i+x][j+y][0]
            avg[1] += img[i+x][j+y][1]
            avg[2] += img[i+x][j+y][2]
            count += 1
    for color in range(3):
        avg[color] = avg[color] // count
    return avg




def blur_image2(img, radius):
    linii = img.shape[0]
    cols = img.shape[1]
    a = [[[0,0,0] for j in range(cols)] for i in range(linii)]
    for i in range(linii):
        for j in range(cols):
            a[i][j] = blur_pixel(img, i, j, radius)
    return a



def apply_filter(i, j, color, img, flt):
    n = len(flt)
    m = len(flt[0])
    i_start = i - n // 2  # coltul stanga sus din imagine
    j_start = j - m // 2
    val = 0
    sum_flt = 0
    for k in range(n):
        for t in range(m):
            val += flt[k][t] * img[i_start + k][j_start + t][color]
            sum_flt += flt[k][t]
    return (val // sum_flt) % 256


def filter_image(img, flt):
    """
    adaugam cate o constanta la fiecare pixel
    """
    linii = img.shape[0]
    coloane = img.shape[1]
    a = [[[0, 0, 0]] * coloane for i in range(linii)]
    for i in range(1, linii - 1):

        for j in range(1, coloane - 1):
            a[i][j] = list(img[i][j])
            # for c in range(3):
            a[i][j][0] = apply_filter(i, j, 0, img, flt)
            # print(img[i][j], a[i][j])
    return a


def transform_image(img, r, g, b):
    """
    adaugam cate o constanta la fiecare pixel
    """
    linii = img.shape[0]
    coloane = img.shape[1]
    a = [[[0,0,0] for j in range(coloane)] for i in range(linii)]
    for i in range(linii):
        for j in range(coloane):
            pixel = img[i][j]
            if list(pixel) == [0,0,0]:
                a[i][j] = pixel
                continue
            if pixel[0] == pixel[1] == pixel[2]:
                a[i][j] = pixel
                continue
            if pixel[0] > 90 and pixel[1] > 70 and pixel[2] < 10:
                a[i][j] = [(img[i][j][0] + r) % 256, (img[i][j][1] + g) % 256, (img[i][j][2] + b) % 256]



    return a


if __name__ == '__main__':
    plt.figure(figsize=(10, 6))
    # display the image

    # bee = load_image_from_file("fisiere/bee.bmp")
    # plt.subplot(2, 5, 1)
    # plt.imshow(bee)
    # inverse_bee = inverse_image(bee)
    # plt.subplot(2, 5, 2)
    # plt.imshow(inverse_bee)
    # start = time.time()
    # blurred_bee = blur_image(bee, 1)
    # end = time.time()
    # print("Blur with radius 3: ", end-start)
    # plt.subplot(2, 5, 3)
    # plt.imshow(blurred_bee)
    #
    # for i in range(6):
    #     transformed_bee = transform_image(bee, i*10, i*20, i*50)
    #     plt.subplot(2, 5, 4+i)
    #     plt.imshow(transformed_bee)

    # width = 250
    # height= 500
    # img = [[[255,255,255] for j in range(width)] for i in range(height)]
    # mid = width//2
    #
    # for i in range(50):
    #     line = random.randrange(0, i+1)
    #     print(line)
    #     for j in range(line):
    #         if j+mid >= width:
    #             continue
    #         img[i][j+mid] = [50, 200, 20]
    #         img[i][mid-j] = [50, 200, 20]
    #
    # for i in range(25, 125):
    #     line = random.randrange(0, i-20)
    #     print(line)
    #     for j in range(line):
    #         if j+mid >= width:
    #             continue
    #         img[i][j+mid] = [50, 200, 20]
    #         img[i][mid-j] = [50, 200, 20]
    #
    # plt.subplot(2,5,10)
    # plt.imshow(img)
    bee = load_image_from_file("fisiere/bee.bmp")

    start = time.time()
    blurata = blur_image2(bee, 3)
    end = time.time()
    print("Blue cu radius 3: ", end-start)
    plt.subplot(1,3,1)
    plt.imshow(bee)
    plt.subplot(1, 3, 2)
    plt.imshow(blurata)
    start = time.time()
    blurata10 = blur_image2(bee, 10)
    plt.subplot(1,3,3)
    plt.imshow(blurata10)
    end = time.time()
    print("Blue cu radius 10: ", end - start)

    plt.show()

    '''black_bee = transform_image(bee, 100, 50, 0)
    plt.subplot(1, 2, 2)
    plt.imshow(black_bee)

    # display the image

    plt.subplot(1, 3, 2)
    plt.imshow(black_bee)
    a = bee + black_bee
    plt.subplot(1, 3, 3)
    plt.imshow(a)
    '''
    # flt = [[1, 1, 1],
    #        [2, 4, 2],
    #        [1, 1, 1]]
    # bee2 = filter_image(bee, flt)
    # plt.subplot(2, 2, 2)
    # plt.imshow(bee2)
    #
    # diff = bee2 - bee
    # plt.subplot(2, 2, 3)
    # plt.imshow(diff)
    #
    # diff1 = inverse_image(diff)
    # plt.subplot(2, 2, 4)
    # plt.imshow(diff1)
    # plt.show()
