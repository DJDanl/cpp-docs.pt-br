---
title: calloc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- calloc
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
- api-ms-win-crt-heap-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- calloc
dev_langs:
- C++
helpviewer_keywords:
- memory allocation, arrays
- calloc function
ms.assetid: 17bb79a1-98cf-4096-90cb-1f9365cd6829
caps.latest.revision: 17
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: a8b0fab02487291625d67706675c62e9a737718f
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="calloc"></a>calloc
Aloca uma matriz na memória com elementos inicializados como 0.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *calloc(   
   size_t num,  
   size_t size   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `num`  
 Número de elementos.  
  
 `size`  
 O comprimento, em bytes, de cada elemento.  
  
## <a name="return-value"></a>Valor retornado  
 `calloc` retorna um ponteiro para o espaço alocado. O espaço de armazenamento ao qual o valor retornado apontou com certeza estará alinhado de modo adequado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja `void`, use uma conversão de tipo no valor retornado.  
  
## <a name="remarks"></a>Comentários  
 A função `calloc` aloca espaço de armazenamento para uma matriz de `num` elementos, cada um com um tamanho de `size` bytes. Cada elemento é inicializado como 0.  
  
 `calloc` definirá `errno` como `ENOMEM` se uma alocação de memória falhar ou se a quantidade de memória solicitada exceder `_HEAP_MAXREQ`. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 `calloc` chama `malloc` para usar a função C++ [_set_new_mode](../../c-runtime-library/reference/set-new-mode.md) para definir o novo modo do manipulador. O novo modo do manipulador indica se, em caso de falha, `malloc` deverá chamar a nova rotina do manipulador conforme definido por [_set_new_handler](../../c-runtime-library/reference/set-new-handler.md). Por padrão, `malloc` não chama a nova rotina do manipulador em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando `calloc` falhar ao alocar memória, `malloc` chame a nova rotina do manipulador da mesma forma que o operador `new` fará quando ele falhar pelo mesmo motivo. Para substituir o padrão, chame  
  
```  
_set_new_mode(1)  
```  
  
 com antecedência em seu programa ou vincule com NEWMODE. OBJ (consulte [Opções de link](../../c-runtime-library/link-options.md)).  
  
 Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas em tempo de execução de C, `calloc` será resolvido como [_calloc_dbg](../../c-runtime-library/reference/calloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).  
  
 `calloc` é marcado como `__declspec(noalias)` e `__declspec(restrict)`, o que representa a garantia de que a função não modifica variáveis globais e que o ponteiro retornado não é um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`calloc`|\<stdlib.h> e \<malloc.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_calloc.c  
// This program uses calloc to allocate space for  
// 40 long integers. It initializes each element to zero.  
  
#include <stdio.h>  
#include <malloc.h>  
  
int main( void )  
{  
   long *buffer;  
  
   buffer = (long *)calloc( 40, sizeof( long ) );  
   if( buffer != NULL )  
      printf( "Allocated 40 long integers\n" );  
   else  
      printf( "Can't allocate memory\n" );  
   free( buffer );  
}  
```  
  
```Output  
Allocated 40 long integers  
```  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)
