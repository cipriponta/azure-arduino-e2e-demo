This repo contains an implementation of an end-to-end communication between an Arduino UNO and a Python app deployed in Azure.

How to make an Azure for Students account: https://azure.microsoft.com/en-us/free/students.

How to deploy the web app in Azure (Follow the VSCode instructions): https://learn.microsoft.com/en-us/azure/app-service/quickstart-python?tabs=flask%2Cwindows%2Cvscode-aztools%2Cvscode-deploy%2Cdeploy-instructions-azportal%2Cterminal-bash%2Cdeploy-instructions-zip-azcli.

How to run this demo:
- Upload the code inside smart-controller on an Arduino Uno. Check the defines in order to figure out how to wire the setup. 
- Install the python requirements: __python -m pip install -r requirements.txt__.
- Deploy the web-app folder to Azure following the tutorial above.
- Change the URL inside wifi-module/wifi_module.py. Add __/post__ at the end of the URL since this is the address of the POST API.
- Run: __python wifi-module/wifi_module.py__.

