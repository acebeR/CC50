import pygame
import sys
import random

# Inicialização e configurações
pygame.init()

WIDTH, HEIGHT = 800, 400
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Corrida de Patos IA")

clock = pygame.time.Clock()

# Cores
GREEN = (34, 139, 34)
YELLOW = (255, 255, 0)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
GRAY = (100, 100, 100)

# Constantes pato
pato_width = 40
pato_height = 30
pato_x = 100
gravidade = 1
pulo = -15

# Classe Pato
class Pato:
    def __init__(self, cor, intervalo_pulo):
        self.cor = cor
        self.x = pato_x
        self.y = HEIGHT - pato_height - 40
        self.vel_y = 0
        self.no_chao = True
        self.rect = pygame.Rect(self.x, self.y, pato_width, pato_height)
        self.ativo = False
        self.intervalo_pulo = intervalo_pulo  # em ms
        self.ultimo_pulo = 0

    def pular(self):
        if self.no_chao and self.ativo:
            self.vel_y = pulo
            self.no_chao = False

    def atualizar(self):
        if not self.ativo:
            return
        self.y += self.vel_y
        self.vel_y += gravidade

        if self.y >= HEIGHT - pato_height - 40:
            self.y = HEIGHT - pato_height - 40
            self.vel_y = 0
            self.no_chao = True

        self.rect.topleft = (self.x, self.y)

    def desenhar(self, tela):
        pygame.draw.rect(tela, self.cor, self.rect)

    def resetar(self):
        self.y = HEIGHT - pato_height - 40
        self.vel_y = 0
        self.no_chao = True
        self.rect.topleft = (self.x, self.y)

# Configura blocos (obstáculos)
bloco_width = 30
bloco_height = 60
velocidade_do_jogo = 7

def criar_blocos():
    blocos = []
    for i in range(3):
        x = WIDTH + i * 300
        y = HEIGHT - bloco_height - 40
        blocos.append(pygame.Rect(x, y, bloco_width, bloco_height))
    return blocos

# Configura patos com intervalos iniciais
patos = [
    Pato(YELLOW, 1000),  # amarelo pula a cada 1s
    Pato(RED, 700),      # vermelho pula a cada 0.7s (depois que entra)
    Pato(BLUE, 400)      # azul pula a cada 0.4s (depois que entra)
]

patos[0].ativo = True  # inicia só o amarelo ativo

blocos = criar_blocos()

running = True
jogo_ativo = True

while running:
    dt = clock.tick(60)
    screen.fill(GREEN)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    if jogo_ativo:
        tempo_agora = pygame.time.get_ticks()

        # Controle pulos dos patos ativos
        for i, pato in enumerate(patos):
            if pato.ativo:
                if tempo_agora - pato.ultimo_pulo > pato.intervalo_pulo:
                    pato.pular()
                    pato.ultimo_pulo = tempo_agora

        # Atualiza e desenha patos
        for pato in patos:
            pato.atualizar()
            pato.desenhar(screen)

        # Move e desenha blocos
        for bloco in blocos:
            bloco.x -= velocidade_do_jogo
            if bloco.x < -bloco.width:
                bloco.x = WIDTH + random.randint(200, 600)
            pygame.draw.rect(screen, GRAY, bloco)

            # Checa colisão só com pato ativo
            for i, pato in enumerate(patos):
                if pato.ativo and pato.rect.colliderect(bloco):
                    print(f"Pato {pato.cor} colidiu!")
                    pato.ativo = False
                    pato.resetar()

                    # Resetar blocos para posição inicial
                    for b in blocos:
                        b.x = WIDTH + random.randint(200, 600)

                    # Ativa próximo pato (se existir)
                    if i + 1 < len(patos):
                        patos[i + 1].ativo = True
                        patos[i + 1].ultimo_pulo = tempo_agora

        # Verifica se algum pato está ativo
        if not any(pato.ativo for pato in patos):
            jogo_ativo = False

    else:
        # Tela de fim do jogo
        font = pygame.font.SysFont(None, 48)
        texto = font.render("Fim do jogo!", True, (255, 255, 255))
        texto_rect = texto.get_rect(center=(WIDTH // 2, HEIGHT // 2))
        screen.blit(texto, texto_rect)

    pygame.display.flip()

pygame.quit()
sys.exit()
