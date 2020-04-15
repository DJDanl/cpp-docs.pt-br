---
title: _pipe
ms.date: 4/2/2020
api_name:
- _pipe
- _o__pipe
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- pipe
- _pipe
helpviewer_keywords:
- pipes, creating
- _pipe function
- pipes
- pipe function
ms.assetid: 8d3e9800-4041-44b5-9e93-2df0b0354a75
ms.openlocfilehash: 5bac435bed26decee0069f5814d1f3d25a54470a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338491"
---
# <a name="_pipe"></a>_pipe

Cria um pipe para leitura e gravação.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _pipe(
   int *pfds,
   unsigned int psize,
   int textmode
);
```

### <a name="parameters"></a>Parâmetros

*Pfds*<br/>
Ponteiro para uma matriz de dois **int** para segurar descritores de arquivo de leitura e gravação.

*Psize*<br/>
Quantidade de memória a ser reservada.

*Textmode*<br/>
Modo de arquivo.

## <a name="return-value"></a>Valor retornado

Retorna 0 se for bem-sucedido. Retorna -1 para indicar um erro. No erro, **errno** é definido como um desses valores:

- **EMFILE**, o que indica que não há mais descritores de arquivos disponíveis.

- **ENFILE**, que indica um estouro de tabela de arquivo do sistema.

- **EINVAL**, o que indica que ou o *array pfds* é um ponteiro nulo ou que um valor inválido para *modo de texto* foi passado.

Para obter mais informações sobre esses e outros códigos de devolução, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_pipe** cria um *tubo*, que é um canal artificial de I/O que um programa usa para passar informações para outros programas. Um pipe lembra um arquivo, pois ele tem um ponteiro de arquivo, um descritor de arquivo ou ambos e pode ser lido ou gravado usando as funções de entrada e saída da Biblioteca Padrão. No entanto, um pipe não representa um arquivo ou dispositivo específico. Em vez disso, ele representa o armazenamento temporário na memória que é independente da memória do próprio programa e é controlada totalmente pelo sistema operacional.

**_pipe** se assemelha **a _open,** mas abre o tubo para leitura e escrita e retorna dois descritores de arquivo em vez de um. O programa pode usar ambos os lados do pipe ou fechar um que não é necessário. Por exemplo, o processador de comando no Windows cria um tubo quando executa um comando como **PROGRAM1** | **PROGRAM2**.

O descritor de saída padrão do **PROGRAM1** está ligado ao descritor de gravação do tubo. O descritor de entrada padrão do **PROGRAM2** é anexado ao descritor de leitura do tubo. Isso elimina a necessidade de criar arquivos temporários para passar informações para outros programas.

A função **_pipe** retorna dois descritores de arquivo para o tubo no argumento *pfds.* O elemento *pfds*[0] contém o descritor de leitura, e o elemento *pfds*[1] contém o descritor de gravação. Descritores de arquivo de pipe são usados da mesma maneira que outros descritores de arquivo. (As funções de entrada e saída de baixo nível **_read** e **_write** podem ler e gravar para um tubo.) Para detectar a condição de fim da tubulação, verifique se há uma **solicitação de _read** que retorna 0 conforme o número de bytes lido.

O *argumento psize* especifica a quantidade de memória, em bytes, para reservar para o tubo. O argumento *textmode* especifica o modo de tradução para o tubo. A constante manifesto **_O_TEXT** especifica uma tradução de texto, e a **constante _O_BINARY** especifica tradução binária. (Consulte [fopen, _wfopen](fopen-wfopen.md) para uma descrição dos modos de texto e binário.) Se o argumento *textmode* for 0, **_pipe** usar o modo de tradução padrão especificado pela variável de modo padrão [_fmode](../../c-runtime-library/fmode.md).

Em programas multithread, nenhum bloqueio é executado. Os descritores de arquivo que são retornados são recém-abertos e não devem ser referenciados por qualquer segmento até que a **chamada _pipe** esteja concluída.

Para usar a função **_pipe** para se comunicar entre um processo pai e um processo filho, cada processo deve ter apenas um descritor aberto no tubo. Os descritores de deverão ser opostos: se o pai tiver um descritor de leitura aberto, o filho deve ter um descritor de gravação aberto. A maneira mais fácil de fazer isso**|** é bitwise ou ( ) a **bandeira _O_NOINHERIT** com *modo de texto*. Em seguida, use **_dup** ou **_dup2** para criar uma cópia herdada do descritor de tubulação que você deseja passar para a criança. Feche o descritor original e gere o processo filho. No retorno da chamada de geração, feche o descritor duplicado no processo pai. Para obter mais informações, consulte o exemplo 2 mais adiante neste artigo.

No sistema operacional Windows, um pipe é destruído quando todos os seus descritores foram fechados. (Se todos os descritores de leitura no tubo foram fechados, então escrever para o tubo causa um erro.) Todas as operações de leitura e gravação no tubo esperam até que haja dados suficientes ou espaço de buffer suficiente para concluir a solicitação de I/O.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|Cabeçalho opcional|
|-------------|---------------------|---------------------|
|**_pipe**|\<io.h>|\<fcntl.h>,1 \<errno.h>2|

1 Para **definições de _O_BINARY** e **_O_TEXT.**

2 **definições errno.**

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example-1"></a>Exemplo 1

```C
// crt_pipe.c
/* This program uses the _pipe function to pass streams of
* text to spawned processes.
*/

#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <process.h>
#include <math.h>

enum PIPES { READ, WRITE }; /* Constants 0 and 1 for READ and WRITE */
#define NUMPROBLEM 8

int main( int argc, char *argv[] )
{

   int fdpipe[2];
   char hstr[20];
   int pid, problem, c;
   int termstat;

   /* If no arguments, this is the spawning process */
   if( argc == 1 )
   {

      setvbuf( stdout, NULL, _IONBF, 0 );

      /* Open a set of pipes */
      if( _pipe( fdpipe, 256, O_BINARY ) == -1 )
          exit( 1 );

      /* Convert pipe read descriptor to string and pass as argument
       * to spawned program. Program spawns itself (argv[0]).
       */
      _itoa_s( fdpipe[READ], hstr, sizeof(hstr), 10 );
      if( ( pid = _spawnl( P_NOWAIT, argv[0], argv[0],
            hstr, NULL ) ) == -1 )
          printf( "Spawn failed" );

      /* Put problem in write pipe. Since spawned program is
       * running simultaneously, first solutions may be done
       * before last problem is given.
       */
      for( problem = 1000; problem <= NUMPROBLEM * 1000; problem += 1000)
      {

         printf( "Son, what is the square root of %d?\n", problem );
         _write( fdpipe[WRITE], (char *)&problem, sizeof( int ) );

      }

      /* Wait until spawned program is done processing. */
      _cwait( &termstat, pid, WAIT_CHILD );
      if( termstat & 0x0 )
         printf( "Child failed\n" );

      _close( fdpipe[READ] );
      _close( fdpipe[WRITE] );

   }

   /* If there is an argument, this must be the spawned process. */
   else
   {

      /* Convert passed string descriptor to integer descriptor. */
      fdpipe[READ] = atoi( argv[1] );

      /* Read problem from pipe and calculate solution. */
      for( c = 0; c < NUMPROBLEM; c++ )
      {

        _read( fdpipe[READ], (char *)&problem, sizeof( int ) );
        printf( "Dad, the square root of %d is %3.2f.\n",
                 problem, sqrt( ( double )problem ) );

      }
   }
}
```

```Output
Son, what is the square root of 1000?
Son, what is the square root of 2000?
Son, what iDad, the square root of 1000 is 31.62.
Dad, the square root of 2000 is 44.72.
s the square root of 3000?
Dad, the square root of 3000 is 54.77.
Son, what is the square root of 4000?
Dad, the square root of 4000 is 63.25.
Son, what is the square root of 5000?
Dad, the square root of 5000 is 70.71.
Son, what is the square root of 6000?
SonDad, the square root of 6000 is 77.46.
, what is the square root of 7000?
Dad, the square root of 7000 is 83.67.
Son, what is the square root of 8000?
Dad, the square root of 8000 is 89.44.
```

## <a name="example-2"></a>Exemplo 2

Este é um aplicativo de filtro básico. Ele gera crt_pipe_beeper do aplicativo após criar um pipe que direciona o stdout do aplicativo gerado para o filtro. O filtro remove caracteres ASCII 7 (bipe).

```C
// crt_pipe_beeper.c

#include <stdio.h>
#include <string.h>

int main()
{
   int   i;
   for(i=0;i<10;++i)
      {
         printf("This is speaker beep number %d...\n\7", i+1);
      }
   return 0;
}
```

O aplicativo de filtro real:

```C
// crt_pipe_BeepFilter.C
// arguments: crt_pipe_beeper.exe

#include <windows.h>
#include <process.h>
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#define   OUT_BUFF_SIZE 512
#define   READ_FD 0
#define   WRITE_FD 1
#define   BEEP_CHAR 7

char szBuffer[OUT_BUFF_SIZE];

int Filter(char* szBuff, ULONG nSize, int nChar)
{
   char* szPos = szBuff + nSize -1;
   char* szEnd = szPos;
   int nRet = nSize;

   while (szPos > szBuff)
   {
      if (*szPos == nChar)
         {
            memmove(szPos, szPos+1, szEnd - szPos);
            --nRet;
         }
      --szPos;
   }
   return nRet;
}

int main(int argc, char** argv)
{
   int nExitCode = STILL_ACTIVE;
   if (argc >= 2)
   {
      HANDLE hProcess;
      int fdStdOut;
      int fdStdOutPipe[2];

      // Create the pipe
      if(_pipe(fdStdOutPipe, 512, O_NOINHERIT) == -1)
         return   1;

      // Duplicate stdout file descriptor (next line will close original)
      fdStdOut = _dup(_fileno(stdout));

      // Duplicate write end of pipe to stdout file descriptor
      if(_dup2(fdStdOutPipe[WRITE_FD], _fileno(stdout)) != 0)
         return   2;

      // Close original write end of pipe
      _close(fdStdOutPipe[WRITE_FD]);

      // Spawn process
      hProcess = (HANDLE)_spawnvp(P_NOWAIT, argv[1],
       (const char* const*)&argv[1]);

      // Duplicate copy of original stdout back into stdout
      if(_dup2(fdStdOut, _fileno(stdout)) != 0)
         return   3;

      // Close duplicate copy of original stdout
      _close(fdStdOut);

      if(hProcess)
      {
         int nOutRead;
         while   (nExitCode == STILL_ACTIVE)
         {
            nOutRead = _read(fdStdOutPipe[READ_FD],
             szBuffer, OUT_BUFF_SIZE);
            if(nOutRead)
            {
               nOutRead = Filter(szBuffer, nOutRead, BEEP_CHAR);
               fwrite(szBuffer, 1, nOutRead, stdout);
            }

            if(!GetExitCodeProcess(hProcess,(unsigned long*)&nExitCode))
               return 4;
         }
      }
   }
   return nExitCode;
}
```

```Output
This is speaker beep number 1...
This is speaker beep number 2...
This is speaker beep number 3...
This is speaker beep number 4...
This is speaker beep number 5...
This is speaker beep number 6...
This is speaker beep number 7...
This is speaker beep number 8...
This is speaker beep number 9...
This is speaker beep number 10...
```

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
