---
title: "atexit | Microsoft Docs"
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
  - "atexit"
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
  - "atexit"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função atexit"
  - "processando, na saída"
ms.assetid: 92c156d2-8052-4e58-96dc-00128baac6f9
caps.latest.revision: 12
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# atexit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Processa a função especificada na saída.  
  
## Sintaxe  
  
```  
int atexit(  
   void (__cdecl *func )( void )  
);  
```  
  
#### Parâmetros  
 `func`  
 Função a ser chamada.  
  
## Valor de retorno  
 `atexit` retornará 0 se tiver êxito, ou um valor diferente de zero se ocorrer um erro.  
  
## Comentários  
 A função de `atexit` é transmitida o endereço de uma função \(\)`func`a ser chamada quando o programa será encerrado normalmente.  As chamadas sucessivas a `atexit` criam um registro das funções em que são executados no último, primeiro em expansão ordem de \(LIFO\).  As funções transmitidas a `atexit` não podem ter parâmetros.  `atexit` e `_onexit` usam o heap para manter o registro das funções.  Assim, o número de funções que podem ser registradas é limitado apenas pela memória heap.  
  
 O código da função de `atexit` não deve conter qualquer dependência em uma DLL que pode já tenha sido descarregado quando a função de `atexit` é chamada.  
  
 Para gerar um aplicativo ANSI\- compatível, use a função de `atexit` do padrão ANSI \(em vez da função semelhante de `_onexit` \).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`atexit`|\<stdlib.h\>|  
  
## Exemplo  
 Esse programa empurra quatro funções na pilha de funções serem executadas quando `atexit` é chamado.  Quando o programa, esses programas são executadas em um último no, primeira out base.  
  
```  
// crt_atexit.c  
#include <stdlib.h>  
#include <stdio.h>  
  
void fn1( void ), fn2( void ), fn3( void ), fn4( void );  
  
int main( void )  
{  
   atexit( fn1 );  
   atexit( fn2 );  
   atexit( fn3 );  
   atexit( fn4 );  
   printf( "This is executed first.\n" );  
}  
  
void fn1()  
{  
   printf( "next.\n" );  
}  
  
void fn2()  
{  
   printf( "executed " );  
}  
  
void fn3()  
{  
   printf( "is " );  
}  
  
void fn4()  
{  
   printf( "This " );  
}  
```  
  
  **Isso é executado pela primeira vez.**  
**Isso é executado em seguida.**   
## Equivalência do .NET Framework  
 [System::Diagnostics::Process::Exited](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.exited.aspx)  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [sair, Exit, Exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [\_onexit, \_onexit\_m](../../c-runtime-library/reference/onexit-onexit-m.md)