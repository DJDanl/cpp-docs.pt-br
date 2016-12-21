---
title: "ftell, _ftelli64 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_ftelli64"
  - "ftell"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_ftelli64"
  - "ftell"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ftelli64"
  - "ponteiros de arquivo [C++]"
  - "ponteiros de arquivo [C++], obtendo posição atual"
  - "Função ftell"
  - "Função ftelli64"
ms.assetid: 40149cd8-65f2-42ff-b70c-68e3e918cdd7
caps.latest.revision: 19
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ftell, _ftelli64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém a posição atual de um ponteiro de arquivo.  
  
## Sintaxe  
  
```  
long ftell(   
   FILE *stream   
);  
__int64 _ftelli64(   
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `stream`  
 Estrutura de `FILE` de destino.  
  
## Valor de retorno  
 `ftell` e `_ftelli64` retorna a posição atual do arquivo.  O valor retornado por `ftell` e por `_ftelli64` não reflita o deslocamento físico de byte para os fluxos abertos no modo de texto, como o modo de texto faz com que a conversão de retorno\- avanço de linha de carro.  Use `ftell` com `fseek`ou`_ftelli64`com`_fseeki64` para retornar para arquivar corretamente locais.  Em erro, `ftell`e`_ftelli64` invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, essas funções retornam – 1L e `errno` defina como uma das constantes, definido em. ERRNO.H.  A constante de `EBADF` significa que o argumento de `stream` não é um valor de ponteiro válido do arquivo ou não se refere a um arquivo aberto.  `EINVAL` significa que um argumento inválido de `stream` esteve passada para a função.  Dispositivos pôde buscar \(como os terminais e impressoras\), ou quando `stream` não se refere a um arquivo aberto, o valor de retorno será indefinido.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 As funções de `ftell` ede `_ftelli64`recuperam a posição atual do ponteiro de arquivo \(se houver\) associado a `stream`*.* A posição é expressa como um desvio relativo ao início do fluxo.  
  
 Observe que quando um arquivo é aberto com dados, a posição atual do arquivo é determinada pela última operação de E\/S, não por onde a gravação seguinte ocorrerá.  Por exemplo, se um arquivo é aberto para anexar e a última operação era uma leitura, a posição do arquivo é onde a operação de leitura seguir não teria iniciado, onde a seguir começaria gravação. \(Quando um arquivo é aberto com, a posição do arquivo é movida para um fim de arquivo antes de qualquer operação de gravação.\) Se nenhuma operação de E\/S ocorreu ainda em um arquivo aberto, anexando a posição do arquivo é o início do arquivo.  
  
 No modo de texto, CTRL\+Z é interpretado como um caractere de participante de Arquivo na entrada.  Em arquivos abertos leitura\/gravação, `fopen` e qualquer verificação de rotinas relacionada para um CTRL\+Z no final do arquivo e solte\-o se possível.  Isso é feito como usar a combinação de `ftell` e `fseek` ou `_ftelli64` e `_fseeki64`, para se mover dentro de um arquivo que termina com um CTRL\+Z pode fazer com que `ftell` ou `_ftelli64` se comportem de forma incorreta próximo do fim do arquivo.  
  
 Essa função bloqueia o thread de chamada durante a execução e em virtude disso é seguro para threads.  Para uma versão sem bloqueio, consulte `_ftell_nolock`.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalhos opcionais|  
|------------|--------------------------|--------------------------|  
|`ftell`|\<stdio.h\>|\<errno.h\>|  
|`_ftelli64`|\<stdio.h\>|\<errno.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_ftell.c  
// This program opens a file named CRT_FTELL.C  
// for reading and tries to read 100 characters. It  
// then uses ftell to determine the position of the  
// file pointer and displays this position.  
  
#include <stdio.h>  
  
FILE *stream;  
  
int main( void )  
{  
   long position;  
   char list[100];  
   if( fopen_s( &stream, "crt_ftell.c", "rb" ) == 0 )  
   {  
      // Move the pointer by reading data:   
      fread( list, sizeof( char ), 100, stream );  
      // Get position after read:   
      position = ftell( stream );  
      printf( "Position after trying to read 100 bytes: %ld\n",  
              position );  
      fclose( stream );  
   }  
}  
```  
  
  **Posição depois de tentar ler 100 bytes: 100**   
## Equivalência do .NET Framework  
 [System::IO::FileStream::Position](https://msdn.microsoft.com/en-us/library/system.io.filestream.position.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [fgetpos](../../c-runtime-library/reference/fgetpos.md)   
 [fseek, \_fseeki64](../../c-runtime-library/reference/fseek-fseeki64.md)   
 [\_lseek, \_lseeki64](../../c-runtime-library/reference/lseek-lseeki64.md)