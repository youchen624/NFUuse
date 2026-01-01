import os
from openai import OpenAI
from dotenv import load_dotenv
import requests
from PIL import Image
from io import BytesIO

load_dotenv()

open_api_key = os.getenv("OPEN_API_KEY")

client = OpenAI(api_key=open_api_key)

response = client.images.generate(
    model="dall-e-3",
    prompt="遊戲王軍貫壽司牌組牌組，軍貫是一個把壽司還有軍艦組合再一起的牌組，比如說海膽壽司軍艦或是鮭魚軟軍艦，或是銀魚航母",
    size="1024x1024",
    quality="standard",
    n=1
)

#取得圖片 URL
image_url =response.data[0].url
print(f"圖片生成成功:{image_url}")

#下載圖片內容
image_data = requests.get(image_url).content

#儲存圖片
image_path = "output.png"
with open(image_path,"wb") as f:
    f.write(image_data)

#顯示圖片
img = Image.open(BytesIO(image_data))
img.show()
