#pragma once
#define ALL		\033[0m		// ��� �������� �� ���������
#define BOLD	\033[1m		// ������ �����(����������� ����)
#define HALF	\033[2m		// ���� ����� ���� (����-�����, ���������� �� �����)
#define ULNE	\033[4m		// �������������
#define FLSH	\033[5m		// ��������
#define REV		\033[7m		// ��������(����� ����������� ���� ����, � ��� -- ���� ������)
#define NORM	\033[22m    // ���������� ���������� �������������
#define NULN	\033[24m    // �������� �������������
#define NFLS	\033[25m    // �������� �������
#define NREV	\033[27m    // �������� ��������

#define BLAK	\033[30    // ������ ���� ������
#define RED		\033[31    // ������� ���� ������
#define GREE	\033[32    // ������ ���� ������
#define YELL	\033[33    // ������ ���� ������
#define BLUE	\033[34    // ����� ���� ������
#define MAGE	\033[35    // ���������� ���� ������
#define CYAN	\033[36    // ���� ������� ����� ������
#define GREY	\033[37    // ����� ���� ������

#define FBLAK	\033[40    // ������ ���� ����
#define FRED	\033[41    // ������� ���� ����
#define FGREE	\033[42    // ������ ���� ����
#define FYELL	\033[43    // ������ ���� ����
#define FBLUE	\033[44    // ����� ���� ����
#define FMAGE	\033[45    // ���������� ���� ����
#define FCYAN	\033[46    // ���� ������� ����� ����
#define FGREY	\033[47    // ����� ���� ����

//������� ������ � ����� :
//����        ���       ��� ����
/*
black       30  40    \033[30m  \033[40m
red			31  41    \033[31m  \033[41m
green		32  42    \033[32m  \033[42m
yellow      33  43    \033[33m  \033[43m
blue        34  44    \033[34m  \033[44m
magenta     35  45    \033[35m  \033[45m
cyan        36  46    \033[36m  \033[46m
grey        37  47    \033[37m  \033[47m

����������� ����������� ���� ����������� �������������������.
��������: 
\033[1m\033[5m\033[36m ����� ���� �������� ������������� ������������������� 
\033[1;5;36m.

#�������, ������� ������ � �����
#����           ���       ��� ����

#black		30  40    \033[30m  \033[40m
#red		31  41    \033[31m  \033[41m
#green		32  42    \033[32m  \033[42m
#yellow		33  43    \033[33m  \033[43m
#blue		34  44    \033[34m  \033[44m
#magenta    35  45    \033[35m  \033[45m
#cyan		36  46    \033[36m  \033[46m
#white		37  47    \033[37m  \033[47m

# �������������� �������� ��� �����:
BOLD='\033[1m'			#  ${BOLD}			# ������ ����� (����������� ����)
DBOLD='\033[2m'			#  ${DBOLD}			# ���� ����� ���� (����-�����, ���������� �� �����)
NBOLD='\033[22m'		#  ${NBOLD}			# ���������� ���������� �������������
UNDERLINE='\033[4m'		#  ${UNDERLINE}		# �������������
NUNDERLINE='\033[4m'	#  ${NUNDERLINE}	# �������� �������������
BLINK='\033[5m'			#  ${BLINK}			# ��������
NBLINK='\033[5m'		#  ${NBLINK}		# �������� �������
INVERSE='\033[7m'		#  ${INVERSE}		# �������� (����� ����������� ���� ����, � ��� -- ���� ������)
NINVERSE='\033[7m'		#  ${NINVERSE}		# �������� ��������
BREAK='\033[m'			#  ${BREAK}			# ��� �������� �� ���������
NORMAL='\033[0m'		#  ${NORMAL}		# ��� �������� �� ���������

# ���� ������:
BLACK='\033[0;30m'		#  ${BLACK}		# ������ ���� ������
RED='\033[0;31m'		#  ${RED}		# ������� ���� ������
GREEN='\033[0;32m'		#  ${GREEN}		# ������ ���� ������
YELLOW='\033[0;33m'     #  ${YELLOW}    # ������ ���� ������
BLUE='\033[0;34m'       #  ${BLUE}      # ����� ���� ������
MAGENTA='\033[0;35m'	#  ${MAGENTA}	# ���������� ���� ������
CYAN='\033[0;36m'       #  ${CYAN}      # ���� ������� ����� ������
GRAY='\033[0;37m'       #  ${GRAY}      # ����� ���� ������

# ������ ������ (������) (bold) :
DEF='\033[0;39m'		#  ${DEF}
DGRAY='\033[1;30m'		#  ${DGRAY}
LRED='\033[1;31m'       #  ${LRED}
LGREEN='\033[1;32m'     #  ${LGREEN}
LYELLOW='\033[1;33m'	#  ${LYELLOW}
LBLUE='\033[1;34m'		#  ${LBLUE}
LMAGENTA='\033[1;35m'   #  ${LMAGENTA}
LCYAN='\033[1;36m'		#  ${LCYAN}
WHITE='\033[1;37m'		#  ${WHITE}

# ���� ����
BGBLACK='\033[40m'		#  ${BGBLACK}
BGRED='\033[41m'		#  ${BGRED}
BGGREEN='\033[42m'		#  ${BGGREEN}
BGBROWN='\033[43m'		#  ${BGBROWN}
BGBLUE='\033[44m'		#  ${BGBLUE}
BGMAGENTA='\033[45m'	#  ${BGMAGENTA}
BGCYAN='\033[46m'		#  ${BGCYAN}
BGGRAY='\033[47m'		#  ${BGGRAY}
BGDEF='\033[49m'		#  ${BGDEF}

tput sgr0     # ������� ����� � "����������" ���������

#������ ����
echo ""
echo -n "     "
echo -e "${BOLD}${BGMAGENTA}${LGREEN} ���� DNS323 ${NORMAL}"
echo ""
echo -en "${LYELLOW} 1 ${LGREEN} �������� ��� ������� ������ � telnet ${GRAY}(���������?)${NORMAL}\n"
echo ""
echo -en "${LYELLOW} 2 ${LGREEN} ���� � ������ & ��������� ���� ������� ${GRAY}(��������)${NORMAL}\n"
echo ""
echo -en "${LYELLOW} 3 ${LGREEN} Transmission (${GREEN}Start${NORMAL}, ${LRED}Stop${NORMAL}, ${CYAN}Upgrade${NORMAL}) ${GRAY}(����)${NORMAL}\n"
echo ""
echo -en "${LYELLOW} 4 ${LGREEN} ����������� (cp & rsync) ${GRAY}(��������)${NORMAL}\n"
echo ""
echo -en "${LYELLOW} 5 ${LGREEN} �������� ������ �� ���� ��� ����� ${GRAY}(��������)${NORMAL}\n"
echo ""
echo -en "${LYELLOW} 6 ${LGREEN} ��������� �� fun-plug & IPKG ${GRAY}(��������)${NORMAL}\n"
echo ""
echo -en "${LYELLOW} 7 ${LGREEN} �������� ������ (${LYELLOW} n${LGREEN}load) ${GRAY}(���������?)${NORMAL}\n"
echo ""
echo -en "${LYELLOW} 8 ${LGREEN} ��������� ����� (${LYELLOW} h${LGREEN}top) ${GRAY}(���������?)${NORMAL}\n"
echo ""
echo -en "${LYELLOW} 9 ${LGREEN} Midnight Commander (${LYELLOW} m${LGREEN}c) ${GRAY}(���������?)${NORMAL}\n"
echo ""
echo -en "${LMAGENTA} q ${LGREEN} ����� ${NORMAL}\n"
echo ""
echo "(������� ��������� ����� ������, ����� ��������� �������� ����� ������, ����� ������ ����, �����)"
echo ""
tput sgr0

*/