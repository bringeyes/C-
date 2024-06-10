from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait, Select
from selenium.webdriver.support import expected_conditions as EC
# from selenium.common.exceptions import TimeoutException, NoSuchElementException
from tkinter import messagebox
import subprocess
import tkinter as tk
import chardet
# import requests

def show_warning(message):
    root = tk.Tk()
    root.withdraw()  # 隐藏主窗口
    messagebox.showwarning("错误", message)

def decode_bytes(data):
    result = chardet.detect(data)
    encoding = result.get('encoding', 'utf-8')
    if encoding:
        return data.decode(encoding, errors='replace')
    else:
        # 如果无法检测到编码，使用默认的 utf-8 编码
        return data.decode('utf-8', errors='replace')

def connect_to_wifi_and_login(wifi_name, wifi_password, student_id, password, operator_index):
    # 连接到指定的 Wi-Fi 网络
    cmd = f'netsh wlan connect name="{wifi_name}"'
    if wifi_password:
        cmd += f' keyMaterial="{wifi_password}"'
    
    # 使用 subprocess.run 执行命令，将 stdout 和 stderr 设置为 subprocess.PIPE
    result = subprocess.run(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # 检查命令执行是否成功，非零状态码表示有错误
    if result.returncode != 0:
        error_message = decode_bytes(result.stderr).strip() or decode_bytes(result.stdout).strip()
        error_message = f"无法连接到 Wi-Fi {wifi_name}:\n{error_message}"
        show_warning(error_message)

    print(f"连接到 Wi-Fi {wifi_name}")
    # 设置 Microsoft Edge WebDriver 的路径，根据你的实际路径修改
    # edge_driver_path = r"D:\a我的文件\任务计划程序\Edge网页驱动\msedgedriver.exe"

    # 可能的登录网址列表
    login_urls = [
        # 10.52.170.110 是佩佩的
        "http://10.2.5.251/a79.htm?wlanuserip=10.27.26.210&wlanacname=Backup-RSR7716&ssid=Ruijie&nasip=10.2.4.129&mac=c85ea91e50cd&t=wireless-v2-plain&url=http://10.2.251.1/",   # 文昌宿舍
        "http://10.2.5.251/a79.htm?wlanuserip=10.6.168.166&wlanacname=NAS&ssid=Ruijie&nasip=10.2.4.1&mac=c85ea91e50cd&t=wireless-v2-plain&url=http://10.2.251.1/",   # 南湖图书馆二层公共区域
        "http://10.2.5.251/a79.htm?wlanuserip=10.52.157.21&wlanacname=BRAS&url=http://10.2.251.1/&mac=C8-5E-A9-1E-50-CD",   # 图书馆
    ]
    execute_login(login_urls[0], student_id, password, operator_index)

def execute_login(login_url, student_id, password, operator_index):
    # 创建 Edge WebDriver 实例
    # driver = webdriver.Edge(EdgeChromiumDriverManager().install())
    driver = webdriver.Edge()
    driver.implicitly_wait(3)  # 设置隐式等待时间为10秒
    driver.get(login_url)
    print(login_url)
    wait = WebDriverWait(driver, 10)  # 设置最长等待时间为10秒

    # 使用XPath找到学号输入框
    student_id_input = wait.until(EC.presence_of_element_located((By.XPATH, '//*[@id="edit_body"]/div[3]/div[1]/form/input[2]')))
    student_id_input.send_keys(student_id)

    # 使用XPath找到密码输入框
    password_input = wait.until(EC.presence_of_element_located((By.XPATH, '//*[@id="edit_body"]/div[3]/div[1]/form/input[3]')))
    password_input.send_keys(password)

    # 使用XPath找到选择运营商的下拉框
    operator_select = wait.until(EC.presence_of_element_located((By.XPATH, '//*[@id="edit_body"]/div[3]/div[1]/select')))
    # 选择指定索引的选项
    operator_select = Select(operator_select)
    operator_select.select_by_index(operator_index)     

    # 使用XPath找到登录按钮并点击
    login_button = wait.until(EC.element_to_be_clickable((By.XPATH, '//*[@id="edit_body"]/div[3]/div[1]/form/input[1]')))
    driver.execute_script("arguments[0].click();", login_button)
        
# 使用方式
connect_to_wifi_and_login(wifi_name="CUMT_Stu", wifi_password=None, student_id="04191404", password="clxyq0826", operator_index=2)