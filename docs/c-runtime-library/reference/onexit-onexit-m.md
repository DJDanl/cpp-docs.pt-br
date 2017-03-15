---
title: _onexit, _onexit_m | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _onexit
- _onexit_m
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
- _onexit
- onexit_m
- onexit
- _onexit_m
dev_langs:
- C++
helpviewer_keywords:
- onexit function
- registry, registering exit routines
- _onexit_m function
- onexit_m function
- _onexit function
- registering exit routines
- registering to be called on exit
ms.assetid: 45743298-0e2f-46cf-966d-1ca44babb443
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: c35b860471772da42e9b377f5dfae8e713afb781
ms.lasthandoff: 02/25/2017

---
# <a name="onexit-onexitm"></a>_onexit, _onexit_m
Registra uma rotina a ser chamada na hora de saída.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_onexit_t _onexit(  
   _onexit_t function  
);  
_onexit_t_m _onexit_m(  
   _onexit_t_m function  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `function`  
 Ponteiro para uma função a ser chamada na saída.  
  
## <a name="return-value"></a>Valor de retorno  
 `_onexit` retorna um ponteiro para a função se for bem-sucedido ou `NULL` se não houver espaço para armazenar o ponteiro da função.  
  
## <a name="remarks"></a>Comentários  
 A função `_onexit` é passada para o endereço de uma função (`function`) a ser chamada quando o programa terminar normalmente. Chamadas sucessivas para `_onexit` criam um registro das funções que são executadas em ordem UEPS (último a entrar, primeiro a sair). As funções passadas para `_onexit` não podem ter parâmetros.  
  
 No caso de `_onexit` ser chamado de uma DLL, as rotinas registradas com `_onexit` são executadas no descarregamento de uma DLL após `DllMain` ser chamado com DLL_PROCESS_DETACH.  
  
 `_onexit` é uma extensão da Microsoft. Para fins de portabilidade ANSI, use [atexit](../../c-runtime-library/reference/atexit.md). A versão `_onexit_m` da função destina-se ao uso de modo misto.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_onexit`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="output"></a>Saída  
  
```  
This is executed first.  
This is executed next.  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::Diagnostics::Process::Exited](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.exited.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [exit, _Exit, _exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [__dllonexit](../../c-runtime-library/dllonexit.md)
