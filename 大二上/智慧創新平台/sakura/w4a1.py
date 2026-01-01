from dotenv import load_dotenv
import os

# 載入 dot env config
load_dotenv()

# 取得環境變數
debug_mode = os.getenv("DEBUG")

if (debug_mode):
    print("on")
else:
    print("off")


# 取得環境變數
openai_api_key = os.getenv("OPENAI_API_KEY")
serp_api_key = os.getenv("SERP_API_KEY")

# 載入 langchain hub
from langchain import hub

# hub得到React的提示字
prompt = hub.pull("hwchase17/react")
print(prompt)

# 匯入 openAI
from langchain_openai import OpenAI
llm = OpenAI()

# 匯入 SearchAPIWrapper

from langchain_community.utilities import SerpAPIWrapper
from langchain.tools import Tool

# 建立 SearchAPIWrapper 物件
search = SerpAPIWrapper(serpapi_api_key = serp_api_key)

# 準備工具清單
tools = [
    Tool(
        name= "Search",
        func = search.run,
        description = "當LLM沒有相關知識時，用於搜尋知識"
    )
]

# 匯入代理功能
from langchain.agents import create_react_agent
# 建議ReAct物件
agent = create_react_agent(llm, tools, prompt)

# 匯入執行器
from langchain.agents import AgentExecutor

# 建立執行檔
agent_executor = AgentExecutor(agent = agent, tools = tools, verbose= True)

# 執行
a = input("請輸入內容\n")
str = f"題目是\"住\"，請在\"增加一些花火歡愉的創意\"以該口吻及修飾回答以下問題: {a}"
print("執行結果:")
result = agent_executor.invoke({"input": str})
final_answer = result.get("output", "無法取得結果")
print(final_answer)