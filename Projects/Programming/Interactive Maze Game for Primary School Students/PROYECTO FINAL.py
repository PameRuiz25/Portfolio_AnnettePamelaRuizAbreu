from pygame import*
import sys,funcionesfinal, random, simpleaudio

def pintar_boton(screen, boton, palabra):
  if boton.collidepoint(mouse.get_pos()):
    draw.rect(screen, (140,134,133), boton, 0)
  else:
    draw.rect(screen, (74, 70, 70), boton, 0)
  texto = myFontbotons.render(palabra, True, (255, 255, 255))
  screen.blit(texto, (boton.x + (boton.width-texto.get_width())/2,boton.y + (boton.height-texto.get_height())/2))  

def pintar_boton_2(screen,boton,palabra):
  if boton.collidepoint(mouse.get_pos()):
    draw.rect(screen, (179,179,179), boton, 0)
  else:
    draw.rect(screen, (255, 255, 255), boton, 0)
  texto = myFontbotons.render(palabra, True, (0, 0, 0))
  screen.blit(texto, (boton.x + (boton.width-texto.get_width())/2,boton.y + (boton.height-texto.get_height())/2))

def poner_imagen(prefijo, sufijo, n):
    images = []
    for i in range(1, n+1):
        name = prefijo + str(i) + sufijo
        images.append(image.load(name))
    return images

clock = time.Clock()
pantalla = 0
init()
inicio = display.set_mode((550,530))
myFontTitulo = font.SysFont('Calíbri',40)
myFont = font.SysFont('Calíbri',30)
fondo = image.load("fondo.jpeg")
fondo = transform.scale(fondo, (550,530))
myFontbotons = font.SysFont("Bahnschrift SemiBold Condensed", 35)
Fonttitulo = font.SysFont("Bahnschrift SemiBold Condensed", 60)
pantcreditos = display.set_mode((550,530))
instrucciones = display.set_mode((550,530))
laberinto = display.set_mode((550,530))
preguntas = display.set_mode((550,530))
ganar = display.set_mode((550,530))
perder = display.set_mode((550,530))
introduccion = display.set_mode((550,530))

reiniciar = Rect(205,495,130,30)

Fontacertijos = font.SysFont("Calíbri", 15)
resp_acertijos = [
                    [4,"Cactus","Estanque","Lago","Arroyo"],
                    [2,"Zombies","H Lobo","Vampiro"],
                    [2,"1","2","3"],
                    [2,"1","2","3"],
                    [4,"Agujero","Volcán","Montaña","Lago"],
                ]

lista_acertijos = poner_imagen("acertijo_",".jpeg",5)

botac1 = Rect(25,470,110,50)
botac2 = Rect(155,470,110,50)
botac3 = Rect(285,470,110,50)
botac4 = Rect(405,470,110,50)

intro = image.load('introduccion.jpg')
intro = transform.scale(intro, (550, 530))
intro1 = image.load('introduccion1.jpg')
intro1 = transform.scale(intro1, (550, 530))
intro2 = image.load('introduccion2.jpg')
intro2 = transform.scale(intro2, (550, 530))
ganaste = image.load('ganaste.jpg')
ganaste = transform.scale(ganaste, (550, 530))
perdiste = image.load('perdiste.jpg')
perdiste = transform.scale(perdiste, (550, 530))
imgcreditos = image.load('creditos.jpeg')
imgcreditos = transform.scale(imgcreditos, (550, 530))
aceptar = Rect(200,420,150,50)
textoperdiste = myFontTitulo.render('Para reiniciar presiona "R"', True, (222, 129, 0))

instruc_acertijos = image.load('instruccion_acertijos.png')
instruc_acertijos = transform.scale(instruc_acertijos, (550, 530))

fondocodigo = image.load('codigo_secreto.png')
estrella = image.load('estrella.png')
estrella = transform.scale(estrella,(20,20))
llave = image.load('llave.png')
llave = transform.scale(llave,(35,35))
llavepeque = transform.scale(llave,(20,20))
vidasextra = image.load('vidaextra.png')
vidasextra = transform.scale(vidasextra,(20,20))
wrong = image.load('wrong.png')
wrong = transform.scale(wrong,(550,530))
correct = image.load('correct.png')
correct = transform.scale(correct,(550,530))
puertas = image.load('puertas.png')
puertas = transform.scale(puertas,(550,530))

introresp = False
jugar = Rect(200, 200, 140, 50)
creditos = Rect(200, 300, 140, 50)
back = Rect(160,470,140,50)
enter = Rect(10,470,140,50)

rep = 0
cuadrores = Rect(70,380,160,50)
rep1 = 0
res = ""
num1 = Rect(25,10,70,70)
num2 = Rect(105,10,70,70)
num3 = Rect(185,10,70,70)
num4 = Rect(25,90,70,70)
num5 = Rect(105,90,70,70)
num6 = Rect(185,90,70,70)
num7 = Rect(25,170,70,70)
num8 = Rect(105,170,70,70)
num9 = Rect(185,170,70,70)
num0 = Rect(105,250,70,70)
borrar = Rect(185,250,70,70)
menos = Rect(25,250,70,70)

res1 = Rect(30,200,120,50)
res2 = Rect(215,200,120,50)
res3 = Rect(405,200,120,50)

ops = [
        ["35-(4x2)","26","27","28",2],
        ["-9+10-(8/2)","3","15","-3",3],
        ["45-6+8","46","44","47",3],
        ["3x2x6","24","36","11",2],
        ["12/6+3","5","12/9","13",1],
        ["9x4/4x2","18","4.5","36",1],
        ["32-9+9","14","50","32",3],
        ["7+7x2-4","17","24","-28",1],
      ]

sures = -1
conti = 0


incorrecto = simpleaudio.WaveObject.from_wave_file('incorrecto.wav')
correcto = simpleaudio.WaveObject.from_wave_file('correcto.wav')
agregar = simpleaudio.WaveObject.from_wave_file('agregar.wav')
click = simpleaudio.WaveObject.from_wave_file('click.wav')

mostrarPared = True


while True:
#pantalla de inicio (portada)
  while pantalla==0:
      repetidos2=[]
      repetidos = []
      x,y=65,95
      mostrarvidas1 = True
      mostrarvidas2 = True
      mostrarllave1 = True
      mostrarllave2 = True
      mostrarllave3 = True
      mostrarllave4 = True
      mostrarllave5 = True
      mostrarllave6 = True
      mostrarllave7 = True
      mostrarllave8 = True
      vidas = 3
      llaves = 0
      inicio.blit(fondo, (0,0))
      titulo = Fonttitulo.render("THE MAZE", True, (255, 255, 255))
      inicio.blit(titulo, (((550-titulo.get_width())/2,40)))
      for e in event.get():
        if e.type == QUIT:sys.exit()
      if e.type == MOUSEBUTTONDOWN and e.button == 1:
            if jugar.collidepoint(mouse.get_pos()):
              click.play()
              pantalla = 1
      if e.type == MOUSEBUTTONDOWN and e.button == 1:
            if creditos.collidepoint(mouse.get_pos()):
              click.play()
              pantalla = 0.1
      pintar_boton(inicio, jugar, "Play")
      pintar_boton(inicio, creditos, "Credits")
      display.flip()

  while pantalla==0.1:
      pantcreditos.blit(imgcreditos,(0,0))
      for e in event.get():
        if e.type == QUIT:sys.exit()
      if e.type == MOUSEBUTTONDOWN and e.button == 1:
            if back.collidepoint(mouse.get_pos()):
              click.play()
              pantalla = 0
      pintar_boton(pantcreditos, back, "BACK")
      display.flip()

    #pantalla de instrucciones
  while pantalla==1:
      import time
      introduccion.blit(intro,(0,0))
      for e in event.get():
        if e.type == QUIT:sys.exit()
      if e.type == MOUSEBUTTONDOWN and e.button==1:
        if aceptar.collidepoint(mouse.get_pos()):
            click.play()
            time.sleep(0.3)
            pantalla=1.1
      pintar_boton(introduccion, aceptar, "Continuar")
      display.flip()
      
  while pantalla==1.1:
      import time
      instrucciones.blit(intro1,(0,0))
      for e in event.get():
        if e.type == QUIT:sys.exit()
      if e.type == MOUSEBUTTONDOWN and e.button==1:
        if aceptar.collidepoint(mouse.get_pos()):
            click.play()
            time.sleep(0.3)
            pantalla=2
      pintar_boton(instrucciones, aceptar, "Continuar")
      display.flip()
  
  while pantalla==2:
      import time
      instrucciones.blit(intro2,(0,0))
      for e in event.get():
        if e.type == QUIT:sys.exit()
      if e.type == MOUSEBUTTONDOWN and e.button==1:
            if aceptar.collidepoint(mouse.get_pos()):
                click.play()
                time.sleep(0.3)
                pantalla=3
      pintar_boton(instrucciones, aceptar, "Continuar")
      display.flip()

    #pantalla de juego
  while pantalla==3:
    clock.tick(90)
    randomization = True
    rep = 0
    conti = 0
    res = ""
    rep1 = 0
    introresp = False
    import time
    laberinto.fill((30,150,26))
    for e in event.get():
        if e.type == QUIT:sys.exit()
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
      if reiniciar.collidepoint(mouse.get_pos()):
          click.play()
          time.sleep(0.3)
          pantalla = 0
    #Atajo para moverte con el mouse
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
      x,y=mouse.get_pos()
    if key.get_pressed()[K_d] or key.get_pressed()[K_RIGHT]:
          x += 0.5
    if key.get_pressed()[K_a] or key.get_pressed()[K_LEFT]:
          x -= 0.5
    if key.get_pressed()[K_w] or key.get_pressed()[K_UP]:
          y -= 0.5
    if key.get_pressed()[K_s] or key.get_pressed()[K_DOWN]:
          y += 0.5
    if key.get_pressed()[K_i]:
          pantalla = 2
    titulo = myFontTitulo.render('THE MAZE', True, (0,0,0))
    laberinto.blit(titulo,((550-titulo.get_width())/2,10))
    textvidas = myFont.render('Vidas: '+str(vidas), True, (0,0,0))
    laberinto.blit(textvidas,(10,10))
    textllaves = myFont.render(": "+str(llaves),True,(0,0,0))
    laberinto.blit(textllaves,(510,10))
    funcionesfinal.dibujar(laberinto)
    if llaves>=5:
        mostrarPared=False
    
    pintar_boton(laberinto,reiniciar,"Reiniciar")
    
    if mostrarPared:
        draw.line(laberinto, (255,233,36), (405,428),(405,448), 3)
        if x+6>=405 and x-6<=405 and y-6>=428 and y+6<=448:
            incorrect = incorrecto.play()
            incorrect.wait_done()
            vidas -= 1
            x,y=65,95     
    
    if mostrarvidas1:
      vida1 = laberinto.blit(vidasextra, (85,375))
      if mostrarvidas1 and vida1.collidepoint(x,y):
        agregar.play()
        vidas = vidas + 1
        mostrarvidas1 = False
    if mostrarvidas2:
      vida2 = laberinto.blit(vidasextra, (409,166))
      if mostrarvidas2 and vida2.collidepoint(x,y):
        agregar.play()
        vidas = vidas + 1
        mostrarvidas2 = False
    
    if mostrarllave1:
      llave1 = laberinto.blit(llavepeque, (58,110))
      if mostrarllave1 and llave1.collidepoint(x,y):
        time.sleep(0.2)
        pantalla = 3.1
        mostrarllave1 = False
    if mostrarllave2:
      llave2 = laberinto.blit(llavepeque, (195,428))
      if mostrarllave2 and llave2.collidepoint(x,y):
        time.sleep(0.2)
        pantalla = 3.2
        mostrarllave2 = False
    if mostrarllave3:
      llave3 = laberinto.blit(llavepeque, (250,108))
      if mostrarllave3 and llave3.collidepoint(x,y):
        time.sleep(0.2)
        pantalla = 3.3
        mostrarllave3 = False
    if mostrarllave4:
      llave4 = laberinto.blit(llavepeque, (475,61))
      if mostrarllave4 and llave4.collidepoint(x,y):
        time.sleep(0.2)
        pantalla = 3.4
        mostrarllave4 = False
    if mostrarllave5:
      llave5 = laberinto.blit(llavepeque, (460,458))
      if mostrarllave5 and llave5.collidepoint(x,y):
        time.sleep(0.2)
        pantalla = 3.5
        mostrarllave5 = False
    if mostrarllave6:
      llave6 = laberinto.blit(llavepeque, (276,240))
      if mostrarllave6 and llave6.collidepoint(x,y):
        time.sleep(0.2)
        pantalla = 3.6
        mostrarllave6 = False
    if mostrarllave7:
      llave7 = laberinto.blit(llavepeque, (410,300))
      if mostrarllave7 and llave7.collidepoint(x,y):
        time.sleep(0.2)
        pantalla = 3.7
        mostrarllave7 = False
    if mostrarllave8:
      llave8 = laberinto.blit(llavepeque, (85,273))
      if mostrarllave8 and llave8.collidepoint(x,y):
        time.sleep(0.2)
        pantalla = 3.8
        mostrarllave8 = False

    draw.circle(laberinto,(255,255,255),(x,y),5,0)
    laberinto.blit(estrella,(480,428))
    laberinto.blit(llave,(480,10))
      
    if funcionesfinal.chocar_horizontal(x,y) or funcionesfinal.chocar_vertical(x,y):
        incorrect = incorrecto.play()
        incorrect.wait_done()
        vidas -= 1
        x,y=65,95
        
    if x>=480 and x<=500 and y>=428 and y<=450:
      pantalla = 4

    if vidas<0:
        pantalla = -1
        
    display.flip()

#pantalla de juego de acertijos
  while pantalla==3.3 or pantalla==3.8:
    while randomization:
        a = random.randint(0,4)
        selec_acertijo = lista_acertijos[a]
        if a not in repetidos2:
            repetidos2.append(a)
            randomization = False
    correct_answer = resp_acertijos[a][0]
    if conti==0:
        preguntas.blit(instruc_acertijos,(0,0))
        pintar_boton(preguntas,aceptar,"Continuar")
    else:
        preguntas.blit(selec_acertijo,(0,0))
    for e in event.get():
      if e.type == QUIT:sys.exit()
    if e.type == MOUSEBUTTONDOWN and e.button == 1 and introresp:
      if back.collidepoint(mouse.get_pos()):
        time.sleep(0.5)
        pantalla = 3
        
    if e.type == MOUSEBUTTONDOWN and e.button == 1 and conti==1 and not (introresp):
      if botac1.collidepoint(mouse.get_pos()):
        seleccion = 1
        introresp = True
    if e.type == MOUSEBUTTONDOWN and e.button == 1 and conti==1 and not (introresp):
      if botac2.collidepoint(mouse.get_pos()):
        seleccion = 2
        introresp = True
    if e.type == MOUSEBUTTONDOWN and e.button == 1 and conti==1 and not (introresp):
      if botac3.collidepoint(mouse.get_pos()):
        seleccion = 3
        introresp = True
    if e.type == MOUSEBUTTONDOWN and e.button == 1 and conti==1 and not (introresp) and (len(resp_acertijos[a])>4):
      if botac4.collidepoint(mouse.get_pos()):
        seleccion = 4
        introresp = True

    if e.type == MOUSEBUTTONDOWN and e.button == 1 and conti==0:
      if aceptar.collidepoint(mouse.get_pos()):
        time.sleep(0.3)
        conti = 1
    if introresp:
        if seleccion==correct_answer and rep1==0:
            correcto.play()
            preguntas.blit(correct,(0,0))
            textfinal = myFontTitulo.render("CORRECTO", True, (0, 255, 10))
            display.flip()
            time.sleep(0.8)
            llaves += 1
            rep1 = 1
        elif rep1==0:
            incorrecto.play()
            preguntas.blit(wrong,(0,0))
            display.flip()
            time.sleep(0.8)
            vidas = vidas - 1
            textfinal = myFontTitulo.render("INCORRECTO", True, (255, 0, 0))
            rep1=1
        pintar_boton(preguntas,back,"BACK")
    if conti==1 and rep1==0:    
        pintar_boton(preguntas,botac1,resp_acertijos[a][1])
        pintar_boton(preguntas,botac2,resp_acertijos[a][2])
        pintar_boton(preguntas,botac3,resp_acertijos[a][3])
        if len(resp_acertijos[a]) > 4:
            pintar_boton(preguntas,botac4,resp_acertijos[a][4])
    display.flip()    
    
    
#pantalla de juego de puertas
  while pantalla==3.1 or pantalla==3.7 or pantalla==3.6:
    preguntas.blit(puertas,(0,0))
    for e in event.get():
      if e.type == QUIT:sys.exit()
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
      if back.collidepoint(mouse.get_pos()):
        time.sleep(0.5)
        pantalla = 3
    if e.type == MOUSEBUTTONDOWN and e.button == 1 and not (introresp):
      if res1.collidepoint(mouse.get_pos()):
        sures = ops[numpreg][1]
        introresp = True
      if res2.collidepoint(mouse.get_pos()):
        sures = ops[numpreg][2]
        introresp = True
      if res3.collidepoint(mouse.get_pos()):
        sures = ops[numpreg][3]
        introresp = True
    while rep==0:
        numpreg = random.randint(0,7)
        if numpreg not in repetidos:
          repetidos.append(numpreg)
          rep = 1
    ops_puertas = ops[numpreg][0]
    pos_respuesta_correcta = ops[numpreg][4]
    respuesta_correcta = ops[numpreg][pos_respuesta_correcta]
    textops = myFontTitulo.render(ops_puertas, True, (255, 255, 255))
    preguntas.blit(textops,(210,150))
    pintar_boton_2(preguntas,res1,ops[numpreg][1])
    pintar_boton_2(preguntas,res2,ops[numpreg][2])
    pintar_boton_2(preguntas,res3,ops[numpreg][3])

    if sures==respuesta_correcta and introresp and rep1==0:
        correcto.play()
        preguntas.blit(correct,(0,0))
        textfinal = myFontTitulo.render("CORRECTO", True, (0, 255, 10))
        display.flip()
        time.sleep(0.8)
        llaves += 1
        rep1=1
    elif introresp and rep1==0:
        incorrecto.play()
        preguntas.blit(wrong,(0,0))
        display.flip()
        time.sleep(0.8)
        vidas = vidas - 1
        textfinal = myFontTitulo.render("INCORRECTO", True, (255, 0, 0))
        rep1 = 1
    if introresp:
        preguntas.blit(textfinal, ((cuadrores.x + (cuadrores.width-textfinal.get_width())/2),430))
        pintar_boton(preguntas, back, "BACK")
    display.flip()      

#pantalla de juego de insertar codigo secreto
  while pantalla==3.2 or pantalla==3.4 or pantalla==3.5:
    clock.tick(5)
    if rep1==0:
        numeros = []
        for i in range(5):
            r = random.randint(0,10)
            numeros.append(r)
        rep1 = 1
    instrucciones.blit(fondocodigo,(0,0))
    for e in event.get():
      if e.type == QUIT:sys.exit()
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if back.collidepoint(mouse.get_pos()):
            time.sleep(0.2)
            pantalla = 3
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if enter.collidepoint(mouse.get_pos()):
            time.sleep(0.1)
            introresp = True
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if borrar.collidepoint(mouse.get_pos()) and rep==0:
            res = ""
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if num1.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "1"
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if num2.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "2"
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if num3.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "3"
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if num4.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "4"
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if num5.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "5"
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if num6.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "6"
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if num7.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "7"
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if num8.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "8"
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if num9.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "9"
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if num0.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "0"
    if e.type == MOUSEBUTTONDOWN and e.button == 1:
        if menos.collidepoint(mouse.get_pos()) and rep==0 and len(res)<10:
            res = res + "-"
    draw.rect(preguntas,(0,0,0),cuadrores,0)
    operacion = str(numeros[0])+"+"+str(numeros[1])+"x"+str(numeros[2])+"+"+str(numeros[3])+"-"+str(numeros[4])
    textcodigo = myFontTitulo.render(operacion, True, (255, 255, 255))
    textres = myFontTitulo.render(res, True, (255, 255, 255))
    preguntas.blit(textcodigo, (cuadrores.x + (cuadrores.width-textcodigo.get_width())/2,340))
    preguntas.blit(textres,(cuadrores.x + (cuadrores.width-textres.get_width())/2,cuadrores.y + (cuadrores.height-textres.get_height())/2))
    pintar_boton(preguntas, num1, "1")
    pintar_boton(preguntas, num2, "2")
    pintar_boton(preguntas, num3, "3")
    pintar_boton(preguntas, num4, "4")
    pintar_boton(preguntas, num5, "5")
    pintar_boton(preguntas, num6, "6")
    pintar_boton(preguntas, num7, "7")
    pintar_boton(preguntas, num8, "8")
    pintar_boton(preguntas, num9, "9")
    pintar_boton(preguntas, num0, "0")
    pintar_boton(preguntas, borrar, "Del")
    pintar_boton(preguntas,menos,"-")

    
    if len(res)>0 and rep==0:
        pintar_boton(preguntas, enter, "ENTER")
    if introresp:
        respuesta = numeros[0] + numeros[1] * numeros[2] + numeros[3] - numeros[4]
        if res==str(respuesta) and rep==0:
          correcto.play()
          preguntas.blit(correct,(0,0))
          display.flip()
          time.sleep(0.8)
          textfinal = myFontTitulo.render("CORRECTO", True, (0, 255, 10))
          llaves += 1
          rep = 1
        elif rep==0:
          incorrecto.play()
          preguntas.blit(wrong,(0,0))
          display.flip()
          time.sleep(0.8)
          textfinal = myFontTitulo.render("INCORRECTO", True, (255, 0, 0))
          vidas = vidas - 1
          rep = 1
        preguntas.blit(textfinal, ((cuadrores.x + (cuadrores.width-textfinal.get_width())/2),430))
        pintar_boton(preguntas, back, "BACK")
    display.flip()
    
#pantalla de ganar
  while pantalla==4:
    ganar.blit(ganaste,(0,0))
    for e in event.get():
      if e.type == QUIT:sys.exit()
    ganar.blit(textoperdiste, (109,300))
    if key.get_pressed()[K_r]:
        pantalla = 0
    display.flip()

    #pantalla de perder
  while pantalla==-1:
    perder.blit(perdiste,(0,0))
    for e in event.get():
      if e.type == QUIT:sys.exit()
    perder.blit(textoperdiste, (109,300))
    if key.get_pressed()[K_r]:
        pantalla = 0
    display.flip()

