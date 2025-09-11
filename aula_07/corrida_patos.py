import pygame
import sys
import random

# Inicializar Pygame
pygame.init()

# Tamanho da tela
WIDTH, HEIGHT = 800, 400
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Corrida de Patos - Obstáculos")

# Cores
WHITE = (255, 255, 255)
GREEN = (50, 205, 50)
YELLOW = (255, 255, 0)
GRAY = (100, 100, 100)

# Relógio (FPS)
clock = pygame.time.Clock()

# Parâmetros do pato
pato_width = 40
pato_height = 40
pato_x = 100
pato_y = HEIGHT - pato_height - 40  # chão
vel_y = 0
gravidade = 1
pulo = -15
no_chao = True

# Velocidade dos blocos (velocidade do jogo)
velocidade_do_jogo = 7

# Obstáculos (blocos)
blocos = [
    pygame.Rect(WIDTH + 200, HEIGHT - 60, 30, 30),
    pygame.Rect(WIDTH + 500, HEIGHT - 60, 30, 30),
    pygame.Rect(WIDTH + 800, HEIGHT - 60, 30, 30),
]

# Loop principal
running = True
while running:
    screen.fill(GREEN)  # fundo = pista

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        # Pulo
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and no_chao:
                vel_y = pulo
                no_chao = False

    # Física do pulo
    pato_y += vel_y
    vel_y += gravidade

    # Verifica se está no chão
    if pato_y >= HEIGHT - pato_height - 40:
        pato_y = HEIGHT - pato_height - 40
        vel_y = 0
        no_chao = True

    # Desenhar pato
    pato = pygame.Rect(pato_x, pato_y, pato_width, pato_height)
    pygame.draw.rect(screen, YELLOW, pato)

    # Mover e desenhar blocos
    for bloco in blocos:
        bloco.x -= velocidade_do_jogo
        # Se saiu da tela, reposiciona para a direita com espaço aleatório
        if bloco.x < -bloco.width:
            bloco.x = WIDTH + random.randint(200, 600)
        pygame.draw.rect(screen, GRAY, bloco)

        # Verifica colisão
        if pato.colliderect(bloco):
            print("💥 Colidiu com obstáculo! Fim de jogo.")
            running = False

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()
