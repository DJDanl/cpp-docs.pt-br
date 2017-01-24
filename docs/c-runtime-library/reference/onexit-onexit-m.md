---
title: "_onexit, _onexit_m | Microsoft Docs"
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
  - "_onexit"
  - "_onexit_m"
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
apitype: "DLLExport"
f1_keywords: 
  - "_onexit"
  - "onexit_m"
  - "onexit"
  - "_onexit_m"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função onexit"
  - "Registro, registrando rotinas de saída"
  - "Função _onexit_m"
  - "Função onexit_m"
  - "Função _onexit"
  - "registrando rotinas de saída"
  - "registrando para ser chamado na saída"
ms.assetid: 45743298-0e2f-46cf-966d-1ca44babb443
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _onexit, _onexit_m
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Registra uma rotina a ser chamada no momento da saída.  
  
## Sintaxe  
  
```  
_onexit_t _onexit(  
   _onexit_t function  
);  
_onexit_t_m _onexit_m(  
   _onexit_t_m function  
);  
```  
  
#### Parâmetros  
 `function`  
 Ponteiro para uma função a ser chamada na saída.  
  
## Valor de retorno  
 `_onexit` retorna um ponteiro para a função se com êxito ou a `NULL` se não houver nenhum espaço para armazenar o ponteiro de função.  
  
## Comentários  
 A função de `_onexit` é transmitida o endereço de uma função \(\)`function`a ser chamada quando o programa será encerrado normalmente.  As chamadas sucessivas a `_onexit` criam um registro das funções que são executadas em último\-em\- primeiro em expansão ordem de LIFO \(\).  As funções transmitidas a `_onexit` não podem ter parâmetros.  
  
 Nos casos em `_onexit` é chamado de dentro de uma DLL, as rotinas registradas com `_onexit` são executados em uma DLL que descarrega depois que `DllMain` é chamado com DLL\_PROCESS\_DETACH.  
  
 `_onexit` é uma extensão da Microsoft.  Para a portabilidade de ANSI, use [atexit](../../c-runtime-library/reference/atexit.md).  A versão de `_onexit_m` da função é para uso no modo misto.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_onexit`|\<stdlib.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_onexit.c  
  
#include <stdlib.h>  
#include <stdio.h>  
  
/* Prototypes */  
int fn1(void), fn2(void), fn3(void), fn4 (void);  
  
int main( void )  
{  
   _onexit( fn1 );  
   _onexit( fn2 );  
   _onexit( fn3 );  
   _onexit( fn4 );  
   printf( "This is executed first.\n" );  
}  
  
int fn1()  
{  
   printf( "next.\n" );  
   return 0;  
}  
  
int fn2()  
{  
   printf( "executed " );  
   return 0;  
}  
  
int fn3()  
{  
   printf( "is " );  
   return 0;  
}  
  
int fn4()  
{  
   printf( "This " );  
   return 0;  
}  
```  
  
## Saída  
  
```  
This is executed first.  
This is executed next.  
```  
  
## Equivalência do .NET Framework  
 [System::Diagnostics::Process::Exited](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.exited.aspx)  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [sair, Exit, Exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [\_\_dllonexit](../../c-runtime-library/dllonexit.md)