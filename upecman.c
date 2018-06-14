/***************************************************************************
 *   upecman.c                                Version 20160529.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file upecman.c
 * @ingroup GroupUnique
 * @brief Pacman Ncurses
 * @details This program really do a nice job as a template, and template only!
 * @version 20160529.013231
 * @date 2016-05-29
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *      $make
 * ou
 *      $gcc upecman.c -o upecman.x -Wall -lncurses -g -Og
 *          -Wextra -ansi -pedantic-errors -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <assert.h> /* Verify assumptions with assert */
#include <unistd.h> /* UNIX standard function */
#include <time.h>  /* Time and date functions */
#include <math.h>  /* Mathematics functions */
#include "upecman.h" /* To be created for this template if needed */
#define DES 5
#define TPY 10
#define TPX 19
#define TP 0
#define LIFE 3

/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./upecman -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
int main(int argc, char *argv[])
{
    IFDEBUG("main()\n");
    int opt,i,f; /* return from getopt() */
    t_game g; /* the game */
    const char *sready="Are you ready? (y/n)"; /* ready string */
    int kin; /* keyboard input */
    /*time_t tinicio;*/
    IFDEBUG("Starting optarg loop...\n");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright & version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hvc")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'v':
                verb++;
                break;
            case 'c':
                copyr();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* ...and we are done */
    IFDEBUG("Starting the game now...\n");

    g=upecman_init();

    printlab(g);
    while(1)
    {
        kin=getch();
        if(kin == 'y')
            break;
        if(kin == 'n')
        {
            endwin();
            return EXIT_SUCCESS;
        }
        mvprintw(10, 25, "%s", sready);
    }
    for(f=blinky; f<=clyde; f++) /*blinky, pinky, inky and clyde*/ 
        g.ghost[f].tinicio=time(NULL); 

    while(1)
    {
        kin=getch();
        if(kin == 'q')
        
            break;
        
        g.lab[17][9] = ' ';
        g.lab[7][9] = ' ';
        g.lab[9][10] = ' ';
        g.lab[10][10] = ' ';
        g.lab[11][10] = ' ';

        g=moveFantasmas(g, f);
        for(i = 0; i < 3; i++)
        {
            usleep(280000);  /*wait 16666 microseconds to avoid frying the processor (1/60 s) */
            kin=getch();
            flushinp();
            g = andapac(g,kin);
            printlab(g);
            g = morre(g);
            if(g.pacman.life == 0)
            {
                endwin();
                return EXIT_SUCCESS;
            }
        }
        /*printlab(g);*/
    }
    endwin();
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Target do modo afraid
 * @details Funcao criada para determinar o target dos fantasmas no modo afraid
 * @return jogo
 * @author upecman-01-blinky
 * @version 0.1.16029.205452
 * @date 2016-06-29
 *
 */
t_game afraidTarget(t_game jogo, int fantasma)
{
    int direcao = jogo.ghost[fantasma].dir;
    int xAtual = jogo.ghost[fantasma].pos.x;
    int yAtual = jogo.ghost[fantasma].pos.y;
    int proximoX = 0;
    int proximoY = 0;
    int foiPraParede;
    int x = rand()%4;/*faz osorteio de acordo com as posicoes do enum*/

    if(direcao == right)
    {
        if(jogo.ghost[fantasma].pos.x == 19 && jogo.ghost[fantasma].pos.y == 10)
        {
            jogo.ghost[fantasma].pos.x = 0;
            jogo.ghost[fantasma].dir = right;
        }   
        else
        {
            proximoX = xAtual + 1;
            proximoY = yAtual;
            foiPraParede = isParede (  jogo, proximoX, proximoY  );
            if( foiPraParede )
            {
                proximoX = xAtual;
                direcao = down;
                direcao = x;
            }  
        }
    }
    else if(direcao == left)
    {
        if(jogo.ghost[fantasma].pos.x == 0 && jogo.ghost[fantasma].pos.y == 10)
        {
            jogo.ghost[fantasma].pos.x = 19;
            jogo.ghost[fantasma].dir = left;                                       
        }
        else
        {
            proximoX = xAtual - 1;
            proximoY = yAtual;
            foiPraParede = isParede(jogo,proximoX,proximoY);
            if( foiPraParede )
            {
                proximoX = xAtual;
                direcao = up;
                direcao = x;
            }
        }
    }
    else if(direcao == up)
    {
        proximoX = xAtual;
        proximoY = yAtual - 1;
        foiPraParede = isParede(jogo,proximoX,proximoY);
        if( foiPraParede )
        {
            proximoY = yAtual;
            direcao = right;
            direcao = x;
        }
    }
    else if(direcao == down)
    {
        proximoX = xAtual;
        proximoY = yAtual + 1;
        foiPraParede = isParede(jogo,proximoX,proximoY);
        if( foiPraParede )
        {
            proximoY = yAtual;
            direcao = left;
            direcao = x;
        }
    }
    /*Criando nova posicao*/
    t_pos novaPosicao;
    novaPosicao.x = proximoX;
    novaPosicao.y = proximoY;
    /*atribuindo a nova posicao ao fantasma blinky*/
    jogo.ghost[fantasma].dir = direcao;
    jogo.ghost[fantasma].pos = novaPosicao;

    return jogo;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Pacman morrendo pelos fantasmas
 * @details Funcao criada para o Pacman morrer ao ser atingido por algum fantasma e para os fantasmas retornarem para a "caixa inicialâ€ quando sao comidos pelo Pacman.
 * @return g
 * @author upecman-01-blinky
 * @version 0.1.160629.132231
 * @date 2016-06-29
 *
 */
t_game morre(t_game g)
{
    int f,kin=0;

    for(f = blinky; f <= clyde; f++) /*blinky, pinky, inky and clyde*/
    {
        if(g.ghost[f].mode == afraid)/*verificar se o fantasma morreu quando esta no modo afraid*/ 
        {
            if((g.ghost[f].pos.x == g.pacman.pos.x) && (g.ghost[f].pos.y == g.pacman.pos.y))/*ele morre se essas posicoes estiverem iguais*/
            {
                g.ghost[f].mode = dead;
                g.ghost[f].tinicio = time(NULL);
            }
        }
        else
            if((g.ghost[f].pos.x == g.pacman.pos.x) && (g.ghost[f].pos.y == g.pacman.pos.y)&&(g.ghost[f].mode != dead))
            {
                g.pacman.life--;
                g = initPosition(g);/*reinicia somente as posicoes sem alterar o mapa e as vidas*/
                while(1)
                {
                    usleep(480000); /*wait 16666 microseconds to avoid frying the processor (1/60 s) */
                    if(g.pacman.life == 0)/*se a vida der  o ele termina ojogo*/
                    {
                        mvprintw(10, 25, "Pacman dead!!!");
                        mvprintw(11, 25, "GAME OVER!!! ENTER to play again or 'q' to quit the game");
                    }
                    else
                    {
                        mvprintw(10, 25, "Pacman dead!!!");
                        mvprintw(11, 25, "Life: %d", g.pacman.life);
                        mvprintw(12, 25, "ENTER to continue or 'q' to quit the game");
                    }
                    kin = getch();
                    refresh();
                    flushinp();
                    if(kin == KEY_ENTER || kin == '\n')
                    {
                        if(g.pacman.life == 0)
                            g = upecman_init();
                        break;
                    }
                    if(kin == 'q')
                    {
                        g.pacman.life = 0;
                        break;
                    }
                }
        }
        if(kin == 'q')
        {
            g.pacman.life = 0;
            break;
        }
    }
    return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief moveFantasmas e' para os modos scatter, chase, afraid e dead.
 * @details Funcao criada para determinar em qual modo os fantasmas vao estar, com seus respectivos times.
 * @return g
 * @author upecman-01-blinky
 * @version 0.1.160629.205452
 * @date 2016-06-29
 *
 */
t_game moveFantasmas(t_game g, int f) /* funcao que serve para determinar os modos que o fantasmas irao assumir durante a execucao */
{
    for(f = blinky; f <= clyde;f++)/*blinky, pinky, inky and clyde*/
    {
        if((g.ghost[f].pos.x > 7 && g.ghost[f].pos.x < 12)&&(g.ghost[f].pos.y < 12 && g.ghost[f].pos.y >= 8)) /* fantasma na area do respawn */
        {
            if(g.ghost[f].mode == dead )
            {
                g.ghost[f].mode = scatter;
                g = scatterf(g,f);
                g.ghost[f].tinicio = time(NULL);
            }
            else
            {
                g.ghost[f].starget.x = 9; /* target fora do respawn que o fantasma ira chegar*/
                g.ghost[f].starget.y = 7;
                g=procuraTarget(g,f); /* faz chamada da procuratarget para achar o target acima */
            }
                g=procuraTarget(g,f);
        }    
        else
            switch(g.ghost[f].mode)
            {
                case scatter :
                    g.ghost[f].tfim=time(NULL); /* tfim recebe o tempo atual*/
                    g.ghost[f].tempo = difftime(g.ghost[f].tfim, g.ghost[f].tinicio); /*faz o difftime do tfim do tinicial*/
                    if(g.ghost[f].tempo < 7) /*tempo que o fantasma vai se encontrar no modo scatter */
                        g = scatterf(g, f);
                    else
                    {
                        g.ghost[f].mode = chase;
                        g.ghost[f].tinicio = time(NULL); /* zera o cronometro */
                    }
                    g = procuraTarget(g,f);   
                    break; 
                case chase :
                    g.ghost[f].tfim = time(NULL);
                    g.ghost[f].tempo = difftime(g.ghost[f].tfim, g.ghost[f].tinicio);
                    if(g.ghost[f].tempo < 20) /*tempo que o fantasma vai ficar no modo chase*/
                        g = chaseTarget(g,f);
                    else
                    {
                        g.ghost[f].mode = scatter;
                        g.ghost[f].tinicio = time(NULL); /* zera o cronometro */
                    }
                    g = procuraTarget(g,f);
                    break;
                case afraid :

                    g.ghost[f].tfim = time(NULL);
                    g.ghost[f].tempo = difftime(g.ghost[f].tfim, g.ghost[f].tinicio);
                    if(g.ghost[f].tempo < 10 )
                    {
                        if((g.ghost[f].pos.x == g.pacman.pos.x) && (g.ghost[f].pos.y == g.pacman.pos.y))
                        {        
                            g.ghost[f].mode = dead;
                            g.ghost[f].tinicio = time(NULL);
                            g=procuraTarget(g,f);
                            /*chama funcao de movimentacao do dead*/
                        }
                        else 
                            g = afraidTarget(g,f); /*chama funcao de movimentacao no afraid*/
                    }
                    else
                    {
                        g.ghost[f].mode = chase;
                        g = procuraTarget(g,f);
                        g.ghost[f].tinicio = time(NULL);
                    }   

                    break;

                case dead:
                    g.ghost[f].starget.x = 8;
                    g.ghost[f].starget.y = 9;
                    g = procuraTarget(g,f);
                    break;                 

            }
    }
    return g;
}
t_game chaseTarget (t_game g, int f) /* determinar o target no modo chase */
{
    if(f == blinky)
    {
        g.ghost[f].starget.x = g.pacman.pos.x; 
        g.ghost[f].starget.y = g.pacman.pos.y;
    } 
    else if(f == pinky)
        g = andaPinky(g);
    else if(f == inky)
        g = andaInky(g);
    else if(f == clyde)
        g = andaClyde(g);

    return g;
}    
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Quando estiver no modo scatterf, posicoes de cada fantasma.
 * @details Funcao criada para determina os Targets especificos de cada um dos fantasmas, suas zonas de preferencia quando se encontram no modo scatte.
 *
 * @return g
 * @author upecman-01-blinky
 * @version 0.1.160629.205452
 * @date 2016-06-29
 * 
 * */
t_game scatterf(t_game g, int f) /* modo scatter = target fixo no mapa para cada fanstama */
{
    {
        switch(f)
        {
            case blinky:
                g.ghost[f].starget.x = 19;
                g.ghost[f].starget.y = 0;
                break;

            case pinky:
                g.ghost[f].starget.x = 0;
                g.ghost[f].starget.y = 0;
                break;

            case inky:
                g.ghost[f].starget.x = 19;
                g.ghost[f].starget.y = 22;
                break;
            case clyde:
                g.ghost[f].starget.x = 0;
                g.ghost[f].starget.y = 22;
                break;
        }
    }
    return g;
}


t_game andaPinky(t_game g)
{
    switch(g.pacman.dir)
    {
        case right:
            g.ghost[pinky].starget.x = g.ghost[pinky].starget.x+4;
            g.ghost[pinky].starget.y = g.ghost[pinky].starget.y;

            break;
        case left:
            g.ghost[pinky].starget.x = g.ghost[pinky].starget.x-4;
            g.ghost[pinky].starget.y = g.ghost[pinky].starget.y;

            break;
        case up:
            g.ghost[pinky].starget.y = g.ghost[pinky].starget.y-4;
            g.ghost[pinky].starget.x = g.ghost[pinky].starget.x;

            break;
        case down:

            g.ghost[pinky].starget.y = g.ghost[pinky].starget.y+4;
            g.ghost[pinky].starget.x = g.ghost[pinky].starget.x;
            break;
    }
    return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief A IA do Clyde no labirinto do pacman
 * @details funÃ§Ã£o criada com o objetivo de fazer a inteligÃªncia do fantasma Clyde.
 * @return g
 * @author upecman-01-blinky
 * @version 0.1.160629.205452
 * @date 2016-06-29
 *
 */
t_game andaClyde(t_game g)
{
    float vetor1 = 0;
    int f = clyde;

    vetor1=sqrt(pow(g.ghost[clyde].pos.y - g.pacman.pos.y, 2) + pow(g.ghost[clyde].pos.x - g.pacman.pos.x, 2));
    if(vetor1 < 8)
    {
        g.ghost[f].starget.x = g.pacman.pos.x;
        g.ghost[f].starget.y = g.pacman.pos.y;
    }
    else
    {
        g.ghost[f].starget.x = 10;
        g.ghost[f].starget.y = 11;
    }
    return g;
}

t_game andaInky(t_game g)
{
    /*int f=inky;*/
    int x = g.pacman.pos.x;
    int  y = g.pacman.pos.y;
    float  vetor1=0;
    switch(g.pacman.dir)
    {
        case right:
            x = x + 2;/**/
            vetor1 = sqrt(pow(g.ghost[blinky].pos.y - y,2) + pow(g.ghost[blinky].pos.x - x ,2));
            g.ghost[inky].starget.x = x + 2*vetor1;
            g.ghost[inky].starget.y = y;
            break;
        case left :
            x = x - 2;
            vetor1 = sqrt(pow(g.ghost[blinky].pos.y - y,2) + pow(g.ghost[blinky].pos.x - x ,2));
            g.ghost[inky].starget.x = x - 2*vetor1;
            g.ghost[inky].starget.y = y;
            break;
        case up :
            y = y - 2;
            vetor1 = sqrt(pow(g.ghost[blinky].pos.y - y,2) + pow(g.ghost[blinky].pos.x - x ,2));
            g.ghost[inky].starget.x =  g.ghost[blinky].pos.x;
            g.ghost[inky].starget.y = y - 2*vetor1;
            break;
        case down :
            y = y + 2;
            vetor1 = sqrt(pow(g.ghost[blinky].pos.y - y,2) + pow(g.ghost[blinky].pos.x - x ,2));
            g.ghost[inky].starget.x =  g.ghost[blinky].pos.x;
            g.ghost[inky].starget.y = y + 2*vetor1;
            break;
    }
    return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Calculo do vetor para achar a menor distancia do pacman.
 * @details Funcao criada para demarcar os targets (seus objetivos) de cada fantasma.
 * @return g
 * @author upecman-01-blinky
 * @version 0.1.160629.205452
 * @date 2016-06-29
 *
 */
t_game procuraTarget(t_game g, int f)
{
    int var = 0;
    float vetor1 = 0.0, vetor2 = 0.0, vetor3 = 0.0, vetor4 = 0.0;

    /*numeracao pra ver todos os caminhos de tal forma que cada um tenha um resultado diferente*/
    if((g.lab[g.ghost[f].pos.y+1][g.ghost[f].pos.x] != '#'&&'-') && g.ghost[f].dir != up )/*p*/
        var = var +1;
    if((g.lab[g.ghost[f].pos.y-1][g.ghost[f].pos.x] != '#'&&'-') && g.ghost[f].dir != down)
        var = var +2;
    if((g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x +1] != '#'&&'-') && g.ghost[f].dir != left)
        var = var +4;
    if((g.lab[g.ghost[f].pos.y][g.ghost[f].pos.x -1] != '#'&&'-') && g.ghost[f].dir != right)
        var = var +8;
    
    vetor1=sqrt(pow(((g.ghost[f].pos.y) - g.ghost[f].starget.y),2) + pow((g.ghost[f].pos.x+1 - g.ghost[f].starget.x) ,2));
    vetor2=sqrt(pow((g.ghost[f].pos.y - g.ghost[f].starget.y),2) + pow((g.ghost[f].pos.x-1 - g.ghost[f].starget.x) ,2));
    vetor3=sqrt(pow((g.ghost[f].pos.y+1 - g.ghost[f].starget.y),2) + pow((g.ghost[f].pos.x  - g.ghost[f].starget.x) ,2));
    vetor4=sqrt(pow((g.ghost[f].pos.y-1 - g.ghost[f].starget.y),2) + pow((g.ghost[f].pos.x  - g.ghost[f].starget.x) ,2));

    switch(var)
    {
        case 1:
            g.ghost[f].pos.y++;
            g.ghost[f].dir = down;
            break;
        case 2:
            g.ghost[f].pos.y--;
            g.ghost[f].dir = up;
            break;
        case (1+2): /*3*/
            vetor1 = g.ghost[f].pos.y - g.ghost[f].starget.y;
            if(vetor1 > 0)
            {
                g.ghost[f].pos.y--;
                g.ghost[f].dir = up;
            }
            else
            {
                g.ghost[f].pos.y++;
                g.ghost[f].dir = down;
            }
            break;
        case 4:
            if(g.ghost[f].pos.x == 19 && g.ghost[f].pos.y == 10)
            {
                g.ghost[f].pos.x = 0;
                g.ghost[f].dir = right;
            }
            else
            {
                g.ghost[f].pos.x++;
                g.ghost[f].dir = right;
            }
            break;
        case(1+4): /*5*/
            if(vetor3 <= vetor1)
            {
                g.ghost[f].pos.y++;
                g.ghost[f].dir = down;
            }
            else
            {
                g.ghost[f].pos.x++;
                g.ghost[f].dir = right;
            }
            break;
        case(2+4):
            if(vetor4 <= vetor1)
            {
                g.ghost[f].pos.y--;
                g.ghost[f].dir = up;
            }
            else
            {
                g.ghost[f].pos.x++;
                g.ghost[f].dir = right;
            }
            break;
        case (1+2+4):
            if(vetor1 <= vetor3 && vetor1< vetor4)
            {
                g.ghost[f].pos.x++;
                g.ghost[f].dir = right;
            }
            if(vetor3 < vetor1 && vetor3 <= vetor4)
            {
                g.ghost[f].pos.y++;
                g.ghost[f].dir = down;
            }
            if(vetor4 <= vetor1 && vetor4 < vetor3)
            {
                g.ghost[f].pos.y--;
                g.ghost[f].dir = up;
            }
            break;
        case 8:
            if(g.ghost[f].pos.x == 0 && g.ghost[f].pos.y == 10)
            {
                g.ghost[f].pos.x = 19;
                g.ghost[f].dir = left;
            }
            else
            {
                g.ghost[f].pos.x--;
                g.ghost[f].dir = left;
            }
            break;
        case (1+8): /*9*/
            if(vetor3 < vetor2)
            {
                g.ghost[f].pos.y++;
                g.ghost[f].dir=down;
            }
            else
            {
                g.ghost[f].pos.x--;
                g.ghost[f].dir = left;
            }
            break;
        case (2+8):/*10*/
            if(vetor4 < vetor2)
            {
                g.ghost[f].pos.y--;
                g.ghost[f].dir = up;
            }
            else
            {
                g.ghost[f].pos.x--;
                g.ghost[f].dir = left;
            }
            break;
        case(8+4+1):/*13*/
            if(vetor3 <= vetor2 && vetor3 < vetor1)
            {
                g.ghost[f].pos.y++;
                g.ghost[f].dir = down;
            }
            if(vetor1 <= vetor3 && vetor1 < vetor2 )
            {
                g.ghost[f].pos.x++;
                g.ghost[f].dir = right;
            }
            if(vetor2 < vetor3 && vetor2 <= vetor1)
            {
                g.ghost[f].pos.x--;
                g.ghost[f].dir = left;
            }
            break;
        case(8+4+2):/*14*/
            if(vetor4 <= vetor2 && vetor4< vetor1)
            {
                g.ghost[f].pos.y--;
                g.ghost[f].dir = up;
            }
            if(vetor1 < vetor4 && vetor1 <= vetor2)
            {
                g.ghost[f].pos.x++;
                g.ghost[f].dir = right;
            }
            if(vetor2 <= vetor4 && vetor2 < vetor1 )
            {
                g.ghost[f].pos.x--;
                g.ghost[f].dir = left;
            }
            break;
        case(4+8):/*12*/
            if((g.ghost[f].pos.x - g.ghost[f].starget.x) < 0)
        {
            g.ghost[f].pos.x++;
            g.ghost[f].dir = right;
        }
            else
            {
                g.ghost[f].pos.x--;
                g.ghost[f].dir = left;
            }
            break;
        case(8+2+1): /*11*/
            if(vetor3 <= vetor4 && vetor3 < vetor2)
            {
                g.ghost[f].pos.y++;
                g.ghost[f].dir = down;
            }
            if(vetor4 < vetor3 && vetor4 <= vetor2)
            {
                g.ghost[f].pos.y--;
                g.ghost[f].dir = up;
            }
            if(vetor2 <= vetor3 && vetor2 < vetor4 )
            {
                g.ghost[f].pos.x--;
                g.ghost[f].dir = left;
            }
            break;
    }
    return g;
}

/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "upecman", "Pacman Ncurses");
    printf("\nUsage: ./%s [-h|-v|-c]\n", "upecman");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "upecman", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb>3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
t_game upecman_init(void)
{
    IFDEBUG("init()");
    /* initialization */

    t_game g;
    /*int f;*/
    int y;

    for(y = 0; y < LABL; y++)
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.life = 3; /* 3 lifes */
    g.pacman.score = 0; /* 0 points */

    g = initPosition(g);

    initscr(); /* start ncurses mode screen */
    cbreak(); /* stop line buffering */
    keypad(stdscr, TRUE); /* grab extended keys */
    noecho(); /* stop echoing chars */
    timeout(0); /* do not wait */
    start_color(); /* initialize the color functionality */

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK); /* Blinky */
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK); /* Pinky */
    init_pair(3, COLOR_CYAN, COLOR_BLACK); /* Inky */
    init_pair(4, COLOR_GREEN, COLOR_BLACK); /* Clyde doesn't have orange :( */
    init_pair(5, COLOR_BLUE, COLOR_BLACK); /* Afraid mode: blue with A_BLINK */
    init_pair(6, COLOR_YELLOW, COLOR_BLACK); /* Pacman */

    return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Inicializacao das posicoes, que se mantem ao longa das execucoes
 * @details A funcao vai iniciar as posicoes dos fantasmas e do pacman tambem
 * @return g
 * @author upecman-01-blinky
 * @version 0.1.160629.205452
 * @date 2016-06-29
 *
 */
t_game initPosition(t_game g)
{
    int f;

    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.dir = left; /* pacman start direction */

    for(f=blinky; f<=clyde; f++) /* blinky, pinky, inky and clyde */
    {
        switch(f) 
        {
            case blinky:

                g.ghost[f].pos.y=7; /* blinky start position (line) */
                g.ghost[f].pos.x=9; /* blinky start position (column) */
                g.ghost[f].starget.y=0; /* preferred corner (line) */
                g.ghost[f].starget.x=19; /* preferred corner (column) */

                break;

            case pinky:

                g.ghost[f].pos.y=9;/*9;  pinky start position (line) */
                g.ghost[f].pos.x=10;/*=10;  pinky start position (column) */
                g.ghost[f].starget.y=0; /* preferred corner (line) */
                g.ghost[f].starget.x=0; /* preferred corner (column) */

                break;

            case inky:

                g.ghost[f].pos.y= 10;/*10;  inky start position (line) */
                g.ghost[f].pos.x= 10;/*10; * inky start position (column) */
                g.ghost[f].starget.y=22; /* preferred corner (line) */
                g.ghost[f].starget.x=19; /* preferred corner (column) */

                break;

            case clyde:

                g.ghost[f].pos.y=11;/*11; * clyde start position (line) */
                g.ghost[f].pos.x= 10;/*10; * clyde start position (column) */
                g.ghost[f].starget.y=22; /* preferred corner (line) */
                g.ghost[f].starget.x=0; /* preferred corner (column) */

                break;
        }
        g.ghost[f].dir=left; /* start direction and future direction: left */
        g.ghost[f].mode=chase;
    }
    return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
void printlab(t_game g)
{
    IFDEBUG("printlab()");

    int y, f;

    clear(); /* clear the screen */
    for(y=0; y<LABL; y++)
        printw("%s\n", g.lab[y]);

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        if(f == blinky)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x,"B");

        if(f == pinky)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x,"P");
        if(f == clyde)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x,"C");
        if(f == inky)
            mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x,"I");
    
        if(g.ghost[f].mode != afraid && g.ghost[f].mode !=dead)
           mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f+1, NULL);
        else if(g.ghost[f].mode != dead) 
            mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 5, NULL);
    
    
    }
    mvprintw(g.pacman.pos.y, g.pacman.pos.x,"@");
    mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);

    mvprintw(5, 25, "pacman.x: %d", g.pacman.pos.x);
    mvprintw(6, 25, "pacman.y: %d", g.pacman.pos.y);
    mvprintw(7, 25, "score: %d", g.pacman.score);
    mvprintw(8, 25, "life: %d", g.pacman.life);

    refresh();
}

void debugPacman(t_game jogo)
{
    int f;
    #ifdef DEBUG
    mvprintw(5, 25, "pacman.x: %d", jogo.pacman.pos.x);
    mvprintw(6, 25, "pacman.y: %d", jogo.pacman.pos.y);
    mvprintw(7, 25, "score: %d", jogo.pacman.score);
    mvprintw(8, 25, "life: %d", jogo.pacman.life);
    for(f=blinky; f<=clyde; f++) /* blinky, pinky, inky and clyde */
    {
        mvprintw(9+f, 25, "fantasma[%d]modo: %d", f,jogo.ghost[f].mode);
        mvprintw(21+f, 25, "fantasma[%d]tempo: %d", f,jogo.ghost[f].tempo);
    }
    mvprintw(13, 25, "blinky.x: %d", jogo.ghost[blinky].pos.x);
    mvprintw(14, 25, "blinky.y: %d", jogo.ghost[blinky].pos.y);
    mvprintw(15, 25, "clyde.x: %d", jogo.ghost[clyde].pos.x);
    mvprintw(16, 25, "clyde.y: %d", jogo.ghost[clyde].pos.y);
    mvprintw(17, 25, "inky.x: %d", jogo.ghost[inky].pos.x);
    mvprintw(18, 25, "inky.y: %d", jogo.ghost[inky].pos.y);
    mvprintw(19, 25, "pinky.x: %d", jogo.ghost[pinky].pos.x);
    mvprintw(20, 25, "pinky.y: %d", jogo.ghost[pinky].pos.y);
    
   #endif
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief usada pra movimentar o pacman de acordo com o que foi lido no teclado
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
t_game andapac(t_game g, int kin)
{
    int xAtual = g.pacman.pos.x;
    int yAtual = g.pacman.pos.y;
    int temParede = 1;
    int proximoX = xAtual;
    int proximoY = yAtual;
    /*analise de cada tecla apertada*/
    switch(kin)
    {
        case KEY_RIGHT:
            if(g.pacman.pos.x == TPX && g.pacman.pos. y == TPY)/*serve para fazer o teletransporte*/
            {
                g.pacman.pos.x = TP;/*se tiver printo do outro lado*/
                g.pacman.dir = right; /*adiciona a direcao right*/
                g.pacman.ultimaDirecao=DES; /*desativa o premove*/
            }
            else
            {
                proximoX = g.pacman.pos.x+1;
                proximoY = yAtual;
                temParede = isParede(g, proximoX, proximoY);/*chama a funcao isParede pra verificar se o caminho esta livre*/
                if(!temParede)
                {
                    g.pacman.pos.x = g.pacman.pos.x + 1; /*soma um a x pra ele ir a direita*/
                    g.pacman.dir = right;
                    g=pegaPellet(g,proximoX ,proximoY);
                    g.pacman.ultimaDirecao = DES;/*se nao tem parede, nao ha premove*/
                }
                else
                    g.pacman.ultimaDirecao=right;/*se tiver parede habilito premove com right */
            }
            break;
        case KEY_LEFT:
            if(g.pacman.pos.x == TP && g.pacman.pos.y == TPY)
            {
                g.pacman.pos.x = TPX;
                g.pacman.dir = left;
                g.pacman.ultimaDirecao = DES;
            }
            else
            {
                proximoX = g.pacman.pos.x-1;
                proximoY = yAtual;
                temParede = isParede(g, proximoX, proximoY);
                if(!temParede)
                {
                    g.pacman.pos.x = g.pacman.pos.x - 1;
                    g.pacman.dir = left;
                    g.pacman.ultimaDirecao=DES;
                    g=pegaPellet(g,proximoX ,proximoY);
                }
                else
                    g.pacman.ultimaDirecao = left;
            }
            break;
        case KEY_UP:
            proximoY = yAtual-1;
            proximoX = xAtual;
            temParede = isParede(g, proximoX, proximoY);
            if(!temParede)
            {
                g.pacman.pos.y = g.pacman.pos.y - 1;
                g.pacman.dir = up;
                g=pegaPellet(g,proximoX ,proximoY);
                g.pacman.ultimaDirecao=DES;
            }
            else
                g.pacman.ultimaDirecao = up;
            break;
        case KEY_DOWN:
            proximoY = yAtual+1;
            proximoX = xAtual;
            temParede = isParede(g, proximoX, proximoY);
            if(!temParede)
            {
                g.pacman.pos.y = g.pacman.pos.y + 1;
                g.pacman.dir = down;
                g=pegaPellet(g,proximoX ,proximoY);
                g.pacman.ultimaDirecao=DES;
            }
            else
                g.pacman.ultimaDirecao = down;
            break;
        default:/*e nao houver entrada de dados  ele ver primeiro se ha premove pra executar*/
            {
                if(g.pacman.ultimaDirecao != DES)
                    g = pmove( g);
                else
                    g=movemento(g);
            }
    }
    return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Funcao criada para delimitar os movimentos do Pacman.
 * @details Com ela o Pacman nÃ£o atravessa os limites do mapa e os caminhos que podem ser seguidos.
 * @return parade
 * @author upecman-01-blinky
 * @version 0.1.160629.205452
 * @date 2016-06-29
 *
 */
int isParede(t_game jogo, int x, int y)
{

    int parede = 0;

    if( jogo.lab[y][x] == '#'|| jogo.lab[y][x] == '-')/*pra ele nao passar da parede*/
    {
        parede = 1;
        mvprintw(1, 25, "verificando (%d ,%d) %c %d", x , y, jogo.lab[y][x], jogo.lab[y][x] == '#'  );
    }

    return parede;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Funcao usada pra  retiar os pellets e adicionar na pontuacao alem de iniciar o modo afraid.
 * @details Funcao que faz o pacman coletar os pellets assim somando no score e caso coma o pellete 'o' ativa o modo afraid.
 * @return Void
 * @author Ruben Carlo Benante & upecman-01-blinky
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
t_game pegaPellet(t_game jogo, int x, int y)
{
    int f=0;
    if(jogo.lab[y][x] == '.')
    {
        jogo.pacman.score = jogo.pacman.score + 10;/* 0 points */
        jogo.lab[y][x] = ' ';
    }
    if(jogo.lab[y][x] == 'o')
    {
        jogo.pacman.score = jogo.pacman.score + 50;/* 0 points */
        jogo.lab[y][x] = ' ';
        for(f=blinky; f<=clyde; f++) /*blinky, pinky, inky and clyde*/
        {
            jogo.ghost[f].mode = afraid;
            jogo.ghost[f].tinicio=time(NULL);
        }
    }
    return jogo;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Funcao que faz com que o pacman execute o preMove.
 * @details Funcao criada para realizar o pre-move do Pacman, que executa o comando do jogador assim que o caminho e possivel.
 * @return g
 * @author upecman-01-blinky
 * @version 0.1.160629.205452
 * @date 2016-06-29
 *
 */
t_game pmove(t_game g)
{
    int temParede = 1;
    int xAtual = g.pacman.pos.x;
    int yAtual = g.pacman.pos.y;
    int proximoX = xAtual, proximoY = yAtual;
    switch(g.pacman.ultimaDirecao)/*ver o que ta colocado com pre move pra ver se executa*/
    {
        case right:
            proximoX = xAtual+1;
            proximoY = yAtual;
            temParede = isParede (g, proximoX, proximoY);
            if(!temParede)
            {
                g.pacman.dir = right;
                g.pacman.pos.x = g.pacman.pos.x + 1;
                g = pegaPellet(g,proximoX,proximoY);
                g.pacman.ultimaDirecao = DES;
            }
            else
                g = movemento(g);
            break;
        case left:
            proximoX = xAtual - 1;
            proximoY = yAtual;
            temParede = isParede(g, proximoX, proximoY);
            if(!temParede)
            {
                g.pacman.dir = left;
                g.pacman.pos.x = g.pacman.pos.x - 1;
                g = pegaPellet(g, proximoX, proximoY);
                g.pacman.ultimaDirecao = DES;
            }
            else
                g=movemento(g);
            break;
        case up:
            proximoX = xAtual ;
            proximoY = yAtual-1;
            temParede = isParede (g , proximoX, proximoY);
            if(!temParede)
            {
                g.pacman.dir = up;
                g.pacman.pos.y = g.pacman.pos.y - 1;
                g = pegaPellet(g,proximoX,proximoY);
                g.pacman.ultimaDirecao = DES;
            }
            else
                g = movemento(g);
            break;
        case down :
            proximoX = xAtual ;
            proximoY = yAtual +1;
            temParede = isParede (g , proximoX, proximoY);
            if(!temParede)
            {
                g.pacman.dir = down;
                g.pacman.pos.y= g.pacman.pos.y +1;
                g= pegaPellet(g,proximoX,proximoY);
                g.pacman.ultimaDirecao = DES;
            }
            else
                g = movemento(g);
            break;
    }
    return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Continuacao do movimento do pacman, obedecendo a ultima seta usada.
 * @details Funcao criada para o caso onde nao ha entrada de dados (comandos do jogador) para ser rodado na funcao andapac e na pmove, ela continua a execucao da ultima entrada de dados. 
 * @return g
 * @author upecman-01-blinky
 * @version 0.1.160629.205452
 * @date 2016-06-29
 *
 */
t_game movemento(t_game g)
{
    int temParede = 1;
    int xAtual = g.pacman.pos.x;
    int yAtual = g.pacman.pos.y;
    int proximoX = xAtual, proximoY = yAtual;
    switch(g.pacman.dir)
    {
        case left:
            if(xAtual == TP && yAtual == TPY)/*as posicoes pra fazer o teletransporte*/
            {
                g.pacman.pos.x = TPX;
            }
            else
            {
                proximoX = xAtual - 1;
                proximoY = yAtual;
                temParede = isParede(g,proximoX,proximoY);
                if(!temParede)
                {
                    g.pacman.pos.x = g.pacman.pos.x -1;
                    g= pegaPellet(g,proximoX,proximoY);
                }
            }
            break;
        case right:
            if(xAtual == TPX &&yAtual == TPY)
            {
                g.pacman.pos.x = TP;

            }
            else
            {
                proximoX = xAtual + 1;
                proximoY = yAtual;
                temParede = isParede (g, proximoX, proximoY);
                if(!temParede)
                {
                    g.pacman.pos.x = g.pacman.pos.x + 1;
                    g = pegaPellet(g,proximoX,proximoY);
                }
            }
            break;
        case up:
            proximoY = yAtual - 1;
            proximoX = xAtual;
            temParede = isParede(g,proximoX,proximoY);
            if(!temParede)
            {
                g.pacman.pos.y = g.pacman.pos.y - 1;
                g = pegaPellet(g,proximoX,proximoY);
            }
            break;
        case down:
            proximoY = yAtual + 1;
            proximoX= xAtual;
            temParede = isParede (g,proximoX,proximoY);
            if(!temParede)
            {
                g.pacman.pos.y = g.pacman.pos.y +1;
                g = pegaPellet(g,proximoX,proximoY);
            }
            break;
    }
    return g;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20150619.231433      */
