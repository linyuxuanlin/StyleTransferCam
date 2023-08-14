from flask import Flask, request
import subprocess

app = Flask(__name__)

@app.route('/upload', methods=['POST'])
def upload():
    try:
        image = request.data

        # 保存照片到指定目录
        with open('base.png', 'wb') as f:
            f.write(image)
        print("照片已保存，正在渲染中……")
        # 启动风格迁移的 python 脚本
        subprocess.run(['python', './style_transfer.py'])

        return "照片上传成功", 200
    except Exception as e:
        print("照片上传失败：", str(e))
        return "照片上传失败", 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=9000)

