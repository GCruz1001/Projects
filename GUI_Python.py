import PySimpleGUI as sg

#sg.Window(title = "Hellow World", layout = [[]], margins = (300, 100)).read()



layout = [[sg.Text("PYTHON GUI")], [sg.Button("Next")]]

#This part of code creates the window 

window = sg.Window("GUI Prototype", layout, margins = (300, 100)).read()

#Event Loop so the user can interact with the GUI

while True:
    event, values = window.read()
    #End program if the user closes window
    if event == "Next" or event == sg.WIN_CLOSED:
        break
    #IF the user presses next button

window.close()
