---
title: "_lseek, _lseeki64 | Microsoft Docs"
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
  - "_lseeki64"
  - "_lseek"
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
  - "_lseeki64"
  - "_lseek"
  - "lseeki64"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _lseek"
  - "Função _lseeki64"
  - "ponteiros de arquivo [C++], movendo"
  - "Função lseek"
  - "Função lseeki64"
  - "procurar ponteiros de arquivo"
ms.assetid: aba8a768-d40e-48c3-b38e-473dbd782f93
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _lseek, _lseeki64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Move um ponteiro de arquivo no local especificado.  
  
## Sintaxe  
  
```  
  
      long _lseek(  
   int fd,  
   long offset,  
   int origin   
);  
__int64 _lseeki64(  
   int fd,  
   __int64 offset,  
   int origin   
);  
```  
  
#### Parâmetros  
 `fd`  
 O descritor de Arquivo que faz referência a um arquivo aberto.  
  
 *deslocamento*  
 Número de bytes *de origem*.  
  
 *origem*  
 Posição inicial.  
  
## Valor de retorno  
 `_lseek` retorna o deslocamento, em bytes, da nova posição desde o início do arquivo.  `_lseeki64` retorna o deslocamento em um inteiro de 64 bits.  A função retorna – 1L para indicar um erro.  Se transmitido para um parâmetro inválido, como um descritor de arquivo incorreto, ou o valor da *origem* não são válidos ou a posição especificada pelo *deslocamento* é antes do início do arquivo, o manipulador inválido do parâmetro seja invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, esse `errno` definido funções a `EBADF` e a ser retornado \-1L.  Dispositivos pôde buscar \(como os terminais e impressoras\), o valor de retorno será indefinido.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `_lseek` move o ponteiro de arquivo associado com `fd` para um novo local que *é o deslocamento de* bytes *de origem*.  A próxima operação no arquivo ocorre no novo local.  O argumento *de origem* deve ser uma das seguintes constantes, que são definidas em Stdio.h.  
  
 `SEEK_SET`  
 Início do arquivo.  
  
 `SEEK_CUR`  
 A posição atual do ponteiro de arquivo.  
  
 `SEEK_END`  
 Fim de arquivo.  
  
 Você pode usar para `_lseek` reposicionar o ponteiro em qualquer lugar em um arquivo ou além do final do arquivo.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_lseek`|\<io.h\>|  
|`_lseeki64`|\<io.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_lseek.c  
/* This program first opens a file named lseek.txt.  
 * It then uses _lseek to find the beginning of the file,  
 * to find the current position in the file, and to find  
 * the end of the file.  
 */  
  
#include <io.h>  
#include <fcntl.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <share.h>  
  
int main( void )  
{  
   int fh;  
   long pos;               /* Position of file pointer */  
   char buffer[10];  
  
   _sopen_s( &fh, "crt_lseek.c_input", _O_RDONLY, _SH_DENYNO, 0 );  
  
   /* Seek the beginning of the file: */  
   pos = _lseek( fh, 0L, SEEK_SET );  
   if( pos == -1L )  
      perror( "_lseek to beginning failed" );  
   else  
      printf( "Position for beginning of file seek = %ld\n", pos );  
  
   /* Move file pointer a little */  
    _read( fh, buffer, 10 );  
  
   /* Find current position: */  
   pos = _lseek( fh, 0L, SEEK_CUR );  
   if( pos == -1L )  
      perror( "_lseek to current position failed" );  
   else  
      printf( "Position for current position seek = %ld\n", pos );  
  
   /* Set the end of the file: */  
   pos = _lseek( fh, 0L, SEEK_END );  
   if( pos == -1L )  
      perror( "_lseek to end failed" );  
   else  
      printf( "Position for end of file seek = %ld\n", pos );  
  
   _close( fh );  
}  
```  
  
## Entrada: crt\_lseek.c\_input  
  
```  
Line one.  
Line two.  
Line three.  
Line four.  
Line five.  
```  
  
## Saída  
  
```  
Position for beginning of file seek = 0  
Position for current position seek = 10  
Position for end of file seek = 57  
```  
  
## Consulte também  
 [E\/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [fseek, \_fseeki64](../../c-runtime-library/reference/fseek-fseeki64.md)   
 [\_tell, \_telli64](../../c-runtime-library/reference/tell-telli64.md)