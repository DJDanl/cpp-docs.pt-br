---
title: free | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: free
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
f1_keywords: free
dev_langs: C++
helpviewer_keywords:
- memory blocks, deallocating
- free function
ms.assetid: 74ded9cf-1863-432e-9306-327a42080bb8
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 61d750fce6e31923636b4eb8c0181bf405b7be39
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="free"></a>free
Desaloca ou libera um bloco de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void free(   
   void *memblock   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memblock`  
 Bloqueio de memória anteriormente alocado a ser liberado.  
  
## <a name="remarks"></a>Comentários  
 A função `free` desaloca um bloco de memória (`memblock`) que foi alocado anteriormente por uma chamada a `calloc`, `malloc` ou `realloc`. O número de bytes liberados é equivalente ao número de bytes solicitados quando o bloco foi alocado (ou realocado, no caso de `realloc`). Se `memblock` for `NULL`, o ponteiro será ignorado e `free` será retornado imediatamente. Tentar liberar um ponteiro inválido (um ponteiro para um bloco de memória que não foi alocado por `calloc`, `malloc` ou `realloc`) pode afetar solicitações posteriores de alocação e causar erros.  
  
 Se ocorrer um erro ao liberar a memória, o `errno` é definido com informações do sistema operacional sobre a natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Após um bloco de memória ter sido liberado, [_heapmin](../../c-runtime-library/reference/heapmin.md) minimiza a quantidade de memória livre no heap juntando as regiões não utilizadas e liberando-as para o sistema operacional. A memória liberada que não for liberada para o sistema operacional será restaurada para o pool livre e ficará disponível para alocação novamente.  
  
 Quando o aplicativo estiver vinculado a uma versão de depuração das bibliotecas de tempo de execução C, `free` será resolvido como [_free_dbg](../../c-runtime-library/reference/free-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).  
  
 `free` é marcado como `__declspec(noalias)`, o significa que há uma garantia de que a função não modifica variáveis globais. Para obter mais informações, consulte [noalias](../../cpp/noalias.md).  
  
 Para liberar a memória alocada com [_malloca](../../c-runtime-library/reference/malloca.md), use [_freea](../../c-runtime-library/reference/freea.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`free`|\<stdlib.h> e \<malloc.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [malloc](../../c-runtime-library/reference/malloc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [_alloca](../../c-runtime-library/reference/alloca.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [_free_dbg](../../c-runtime-library/reference/free-dbg.md)   
 [_heapmin](../../c-runtime-library/reference/heapmin.md)   
 [_freea](../../c-runtime-library/reference/freea.md)