---
title: atexit | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- atexit
apilocation:
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
apitype: DLLExport
f1_keywords:
- atexit
dev_langs:
- C++
helpviewer_keywords:
- processing, at exit
- atexit function
ms.assetid: 92c156d2-8052-4e58-96dc-00128baac6f9
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 6d0d85ffc7f3ed71a26a947dd66c710e76388e96
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="atexit"></a>atexit
Processa a função especificada na saída.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int atexit(  
   void (__cdecl *func )( void )  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `func`  
 Função a ser chamada.  
  
## <a name="return-value"></a>Valor de retorno  
 `atexit` retorna 0 se for bem-sucedido ou um valor diferente de zero se ocorrer um erro.  
  
## <a name="remarks"></a>Comentários  
 A função `atexit` é passada para o endereço de uma função (`func`) a ser chamada quando o programa terminar normalmente. Chamadas sucessivas para `atexit` criam um registro das funções que são executadas na ordem UEPS (último a entrar, primeiro a sair). As funções passadas para `atexit` não podem ter parâmetros. `atexit` e `_onexit` usam o heap para conter o registro das funções. Assim, o número de funções que podem ser registradas é limitado apenas pela memória de heap.  
  
 O código na função `atexit` não deve conter nenhuma dependência de nenhuma DLL que possa já ter sido descarregada quando a função `atexit` é chamada.  
  
 Para gerar um aplicativo em conformidade com ANSI, use a função `atexit` do padrão ANSI (em vez da função `_onexit` semelhante).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`atexit`|\<stdlib.h>|  
  
## <a name="example"></a>Exemplo  
 Esse programa envia quatro funções para a pilha de funções a serem executadas quando `atexit` é chamado. Quando o programa é encerrado, esses programas são executados no esquema último a entrar, primeiro a sair.  
  
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
  
```Output  
This is executed first.  
This is executed next.  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [_onexit, _onexit_m](../../c-runtime-library/reference/onexit-onexit-m.md)
