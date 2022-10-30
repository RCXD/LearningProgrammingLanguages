# importing libraries
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import * 
from PyQt5.QtGui import * 
from PyQt5.QtCore import * 
import sys
import time
  
class Window(QMainWindow):
    def __init__(self):
        super().__init__()
  
        # setting title
        self.setWindowTitle("TvGame")
  
        # setting geometry
        self.setGeometry(650, 250, 641, 362)

        self.screen("C:/GitHub/LearningProgrammingLanguages/Python/PyQt/firstscreen1.gif",641, 362)
        self.start_btn()
        self.show()
        # self.screen("firstscreen1.gif",641, 362)

    # setting start btn
    def start_btn(self):
        start_btn = QPushButton("", self)
        start_btn.setGeometry(210,300,200,56)
        start_btn.setStyleSheet("border-width: 0px;"
                                "border-style: solid;"
                                "background-image : url(C:/GitHub/LearningProgrammingLanguages/Python/PyQt/start_btn.png);")
        start_btn.clicked.connect(self.start_screen)
    # setting back_main btn
    def back_main(self):
        back_main = QPushButton("",self)
        back_main.setGeometry(210,300,100,39)
        back_main.setStyleSheet("border-width: 0px;"
                                "border-style: solid;"
                                "background-image : url(C:/GitHub/LearningProgrammingLanguages/Python/PyQt/Back_Button.png);")
        back_main.clicked.connect(self.start_screen)

    def start_screen(self):
        self.stopAnimation()
        # self.screen('C:/GitHub/LearningProgrammingLanguages/Python/PyQt/firstscreen.gif',490, 368, 'self.UiComponents()')
        self.screen('C:/GitHub/LearningProgrammingLanguages/Python/PyQt/firstscreen.gif',490, 368)
        # while self.movie.state()==self.movie.Running:
        print(self.movie.loopCount())
        if self.movie.loopCount() == -1:
            self.stopAnimation()
        # self.stopAnimation()
        self.UiComponents()
        self.show()
        #self.show()
       
    # background Gif function
    def screen(self, background,x,y,btn=None):
    # def screen(self, background,x,y):
        # setting geometry
        self.setGeometry(650, 250, x, y)
        self.centralwidget = QtWidgets.QWidget(self)
        self.centralwidget.setObjectName("main-widget")
        # Label Create
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(0, 0, x, y))
        self.label.setMinimumSize(QtCore.QSize(x, y))
        self.label.setMaximumSize(QtCore.QSize(x, y))
        self.label.setObjectName("lb1")
        self.setCentralWidget(self.centralwidget)

        # Loading the GIF
        self.movie = QMovie(background)
        self.label.setMovie(self.movie)
        
        # calling method
        self.startAnimation()

        # calling method
        if btn != None:
            exec(btn)
        # self.start_btn()
  
        # showing all the widgets
        #self.show()

     # background Gif function
    def screen2(self, background,x,y, btn):
        # setting geometry
        self.centralwidget = QtWidgets.QWidget(self)
        self.centralwidget.setObjectName("main-widget")
        # Label Create
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(0, 0, x, y))
        self.label.setMinimumSize(QtCore.QSize(x, y))
        self.label.setMaximumSize(QtCore.QSize(x, y))
        self.label.setObjectName("lb1")
        self.setCentralWidget(self.centralwidget)

        # Loading the GIF
        self.movie = QMovie(background)
        self.label.setMovie(self.movie)
        
        # calling method
        self.startAnimation()

        # calling method
        exec(btn)
  
        # showing all the widgets
        self.show()
        
  
    # Start Animation
    def startAnimation(self):
        self.movie.start()
  
    # Stop Animation(According to need)
    def stopAnimation(self):
        self.movie.stop()
        
    # method for widgets
    def UiComponents(self):
#----------------pokemon btn-------------------------------------------------
        # pokemon = ['(C:/GitHub/LearningProgrammingLanguages/Python/PyQt/pikachu1.png);',
        pokemon = [#'(C:/GitHub/LearningProgrammingLanguages/Python/PyQt/pikachubtn.gif);',
                   '(C:/GitHub/LearningProgrammingLanguages/Python/PyQt/fire.png);',
                   '(C:/GitHub/LearningProgrammingLanguages/Python/PyQt/water.png);', 
                   '(C:/GitHub/LearningProgrammingLanguages/Python/PyQt/wiredo.png);']
        pBtnPosiSize = {0: [350, 230, 131, 139],1:[250, 250, 128, 121], 2: [150, 250, 123, 127], 3:[50, 250, 111, 121] }
        connects = [self.quit, self.aboutme,self.howto, self.start]

        button=QPushButton("", self)
        button.setGeometry(pBtnPosiSize[0][0],pBtnPosiSize[1][1],pBtnPosiSize[2][2],pBtnPosiSize[3][3])
        button.setStyleSheet("border-width: 0px;"
                                  "border-style: solid;"
                                  "background-image : url(C:/GitHub/LearningProgrammingLanguages/Python/PyQt/start_btn.png)")
        button.clicked.connect(self.start)
        
        # UiComponents=dict()
        # for i in range(len(pokemon)):
        #     btnName = 'btn' + str(i)
        #     # creating a push button
        #     UiComponents={btnName: QPushButton("", self)}
        #     # btnName = QPushButton("", self)
        #     # setting geometry of button
        #     UiComponents[btnName].setGeometry(pBtnPosiSize[i][0],pBtnPosiSize[i][1],pBtnPosiSize[i][2],pBtnPosiSize[i][3])
        #     # btnName.setGeometry(pBtnPosiSize[i][0],pBtnPosiSize[i][1],pBtnPosiSize[i][2],pBtnPosiSize[i][3])
        #     # setting image to the button
        #     # btnName.setStyleSheet("border-width: 0px;"
        #     UiComponents[btnName].setStyleSheet("border-width: 0px;"
        #                           "border-style: solid;"
        #                           "background-image : url"+pokemon[i])
        #     # adding action to a button
        #     UiComponents[btnName].clicked.connect(connect[i])
            # btnName.clicked.connect(connect[i])
#----------------pokemon btn-------------------------------------------------                
  
    # action method
    def start(self):
        self.screen('C:/GitHub/LearningProgrammingLanguages/Python/PyQt/channel1.gif',498,298,'self.back_main()')
        print('channel1')
    def howto(self):
        self.screen('C:/GitHub/LearningProgrammingLanguages/Python/PyQt/channel4.gif',400,279,'self.back_main()')
        print('channel2')
    def aboutme(self):
        self.screen('C:/GitHub/LearningProgrammingLanguages/Python/PyQt/PokemonDoKam3.png',389,484,'self.back_main()')
        print('channel3')
    def quit(self):
        self.quit()
            
if __name__ == '__main__':
    
    
    # create pyqt5 app
    App = QApplication(sys.argv)
  
    # create the instance of our Window
    window = Window()
    
    
    # start the app
    sys.exit(App.exec())