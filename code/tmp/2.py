lists = [[] for i in range(0,3)]  # 创建的是多行三列的二维列表
for i in range(3):
    lists[0].append(i)
for i in range(5):
    lists[1].append(i)
for i in range(7):
    lists[2].append(i)
print("lists is:", lists)
