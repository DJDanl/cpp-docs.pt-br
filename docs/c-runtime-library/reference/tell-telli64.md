---
title: "_tell, _telli64 | Microsoft Docs"
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
  - "_telli64"
  - "_tell"
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
  - "tell"
  - "telli64"
  - "_telli64"
  - "_tell"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tell"
  - "Função _telli64"
  - "ponteiros de arquivo [C++]"
  - "ponteiros de arquivo [C++], obtendo"
  - "Função tell"
  - "Função telli64"
ms.assetid: 1500e8f9-8fec-4253-9eec-ec66125dfc9b
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _tell, _telli64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obter a posição do ponteiro de arquivo.  
  
## Sintaxe  
  
```  
long _tell(  
   int handle  
);  
__int64 _telli64(  
   int handle   
);  
```  
  
#### Parâmetros  
 `handle`  
 O descritor de Arquivo que faz referência ao arquivo aberto.  
  
## Valor de retorno  
 A posição atual do ponteiro de arquivo.  Dispositivos pôde buscar, o valor de retorno será indefinido.  
  
 Um valor de retorno 1L – indica um erro.  Se `handle` é um descritor de arquivo inválido, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, esse `errno` definido funções a `EBADF` e a ser retornado \-1L.  
  
 Consulte [\_doserrno, errno, \_sys\_errlist, e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para obter mais informações sobre esse, e outras, códigos de retorno.  
  
## Comentários  
 A função de `_tell` obtém a posição atual do ponteiro de arquivo \(se houver\) associado com o argumento de `handle` .  A posição é expresso como o número de bytes do início do arquivo.  Para a função de `_telli64` , esse valor é expresso como um inteiro de 64 bits.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_tell`, `_telli64`|\<io.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_tell.c  
// This program uses _tell to tell the  
// file pointer position after a file read.  
//  
  
#include <io.h>  
#include <stdio.h>  
#include <fcntl.h>  
#include <share.h>  
#include <string.h>  
  
int main( void )  
{  
   int  fh;  
   char buffer[500];  
  
   if ( _sopen_s( &fh, "crt_tell.txt", _O_RDONLY, _SH_DENYNO, 0) )  
   {  
      char buff[50];  
      _strerror_s( buff, sizeof(buff), NULL );  
      printf( buff );  
      exit( -1 );  
   }  
  
   if( _read( fh, buffer, 500 ) > 0 )  
      printf( "Current file position is: %d\n", _tell( fh ) );  
   _close( fh );  
}  
```  
  
## Entrada: crt\_tell.txt  
  
```  
Line one.  
Line two.  
```  
  
### Saída  
  
```  
Current file position is: 20  
```  
  
## Consulte também  
 [E\/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [ftell, \_ftelli64](../../c-runtime-library/reference/ftell-ftelli64.md)   
 [\_lseek, \_lseeki64](../../c-runtime-library/reference/lseek-lseeki64.md)