import tkinter as tk
import webbrowser

def open_selected_websites():
    selected_indices = website_listbox.curselection()
        # curselection() 返回一个元组，包含了选中项的索引

    if selected_indices:  # 选择非空
        selected_websites = [websites[index] for index in selected_indices]
            # 得到选中项的键值
        for selected_website_name in selected_websites:
            selected_website = website_urls.get(selected_website_name, "")
            if selected_website:  # URL非空
                webbrowser.open(selected_website)

# 创建主窗口
root = tk.Tk()
root.title("学习网站")

# 定义学习网站字典
website_urls = {
    "C++学习": "https://www.bilibili.com/cheese/play/ep174133",
    "01大学C++基础": "https://appprle8wl84197.pc.xiaoe-tech.com/p/t_pc/course_pc_detail/video/v_6379959fe4b01126eaa87b42?product_id=p_634d4c64e4b0a51fef2a2803&content_app_id=&type=8&parent_pro_id=p_666e463be4b0694c98293ce7",
    "韦东山嵌入式Linux": "https://www.bilibili.com/video/BV1w4411B7a4/?spm_id_from=333.999.0.0&vd_source=e97b51705159b1891c4873b3974ff702",
    "GitHub": "https://github.com/",
    "Git学习": "https://www.bilibili.com/video/BV1HM411377j?p=16&spm_id_from=pageDriver&vd_source=e97b51705159b1891c4873b3974ff702",
    # "数据结构": "https://www.bilibili.com/video/BV13b411t7LF/?spm_id_from=333.999.0.0&vd_source=e97b51705159b1891c4873b3974ff702",
    # "左程云算法": "https://space.bilibili.com/8888480/video?tid=0&pn=5&keyword=&order=pubdate",
    # "C++实现数据结构": "https://blog.csdn.net/qq_41696018?type=lately&spm=1001.2014.3001.5348",
    # "Python学习": "https://www.bilibili.com/video/BV1c4411e77t/?p=21",
    # "动手学深度学习": "https://space.bilibili.com/1567748478/channel/seriesdetail?sid=358497",
    # "许志钦_统计计算与机器学习": "https://space.bilibili.com/95975441/channel/seriesdetail?sid=1586092",
    # "统计学习方法 第二版_监督学习": "https://www.bilibili.com/video/BV1W7411N7Ag/?vd_source=e97b51705159b1891c4873b3974ff702",
    # "机器学习": "https://www.bilibili.com/video/BV1Pa411X76s?p=106",
    "ChatGPT": "https://chat.openai.com",
    "梯子": "https://w1.v2free.top/user",
    "知网": "https://www.cnki.net",
    "图书馆": "https://lib.cumt.edu.cn/wxzy/sjkdh/zwsjk.htm",
    "培养管理系统": "http://yjsxt.cumt.edu.cn/Gstudent/Default.aspx?UID=TS23120050A31LD",
    # 添加更多网站...
}

# 获取学习网站名称列表
websites = list(website_urls.keys())

# 创建 Listbox 并添加学习网站名称
website_listbox = tk.Listbox(root, selectmode=tk.MULTIPLE, height=len(websites))  # selectmode=tk.SINGLE单一选择
for website_name in websites:
    website_listbox.insert(tk.END, website_name)  # tk.END在末尾插入
website_listbox.pack(side=tk.LEFT, fill=tk.Y, pady=10)  # fill=tk.Y纵向填充，pady=10与主窗口上下边距10像素

# 创建垂直滚动条
scrollbar = tk.Scrollbar(root, orient=tk.VERTICAL, command=website_listbox.yview)  
    # orient=tk.VERTICAL创建垂直滚动条
    # command=website_listbox.yview使我们能通过拖动滚动条来显示website_listbox纵向视角
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
website_listbox.config(yscrollcommand=scrollbar.set)
    # 将 Listbox 与滚动条关联
    # 当用户在 Listbox 中滚动时，yscrollcommand 会调用 scrollbar.set 方法，告诉滚动条更新其位置

# 设置窗口大小和位置
window_width = 300
window_height = 200
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
x_position = (screen_width - window_width) // 2
y_position = (screen_height - window_height) // 2

root.geometry(f"{window_width}x{window_height}+{x_position}+{y_position}")
    # {宽度}x{高度}+{横坐标}+{纵坐标} 左上角坐标

# 创建按钮
open_button = tk.Button(root, text="Link Start!", command=open_selected_websites)
open_button.pack(padx=5, pady=(window_height // 2 - 20, 0))  # 按钮高40

# 运行主循环
root.mainloop()
