---
title: "_eof | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_eof"
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
  - "_eof"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _eof"
  - "final do arquivo"
  - "final do arquivo, testando para"
  - "Função eof"
  - "Arquivos  [C++], final de"
  - "testando, para final do arquivo"
ms.assetid: 265703f4-d07e-4005-abf3-b1d0cdd9e0b0
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _eof
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Testando a fim de arquivo \(EOF\).  
  
## Sintaxe  
  
```  
int _eof(   
   int fd   
);  
```  
  
#### Parâmetros  
 `fd`  
 O descritor de Arquivo que faz referência ao arquivo aberto.  
  
## Valor de retorno  
 `_eof` retornará 1 se a posição atual é o final do arquivo, ou 0 se não for.  Um valor de retorno – 1 indica um erro; nesse caso, o manipulador inválido do parâmetro é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, `errno` está definido como `EBADF`, que indica um descritor de arquivo inválido.  
  
## Comentários  
 A função de `_eof` determina se a extremidade do arquivo associado com `fd` esteve atingida.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_eof`|\<io.h\>|\<errno.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_eof.c  
// This program reads data from a file  
// ten bytes at a time until the end of the  
// file is reached or an error is encountered.  
//  
#include <io.h>  
#include <fcntl.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <share.h>  
  
int main( void )  
{  
   int  fh, count, total = 0;  
   char buf[10];  
   if( _sopen_s( &fh, "crt_eof.txt", _O_RDONLY, _SH_DENYNO, 0 ) )  
   {  
        perror( "Open failed");  
        exit( 1 );  
   }  
   // Cycle until end of file reached:   
   while( !_eof( fh ) )  
   {  
      // Attempt to read in 10 bytes:   
      if( (count = _read( fh, buf, 10 )) == -1 )  
      {  
         perror( "Read error" );  
         break;  
      }  
      // Total actual bytes read   
      total += count;  
   }  
   printf( "Number of bytes read = %d\n", total );  
   _close( fh );  
}  
```  
  
## Entrada: crt\_eof.txt  
  
```  
This file contains some text.  
```  
  
### Saída  
  
```  
Number of bytes read = 29  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Tratamento de erros](../../c-runtime-library/error-handling-crt.md)   
 [E\/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [clearerr](../../c-runtime-library/reference/clearerr.md)   
 [feof](../../c-runtime-library/reference/feof.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [perror, \_wperror](../../c-runtime-library/reference/perror-wperror.md)