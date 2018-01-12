---
title: _freea | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _freea
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
- freea
- _freea
dev_langs: C++
helpviewer_keywords:
- _freea function
- freea function
- memory deallocation
ms.assetid: dcd30584-dd9d-443b-8c4c-13237a1cecac
caps.latest.revision: "18"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 921687fbc5d8ab0b509e5a2e43c9c9ff4b18727a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="freea"></a>_freea
Desaloca ou libera um bloco de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _freea(   
   void *memblock   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memblock`  
 Bloqueio de memória anteriormente alocado a ser liberado.  
  
## <a name="return-value"></a>Valor de retorno  
 Nenhum.  
  
## <a name="remarks"></a>Comentários  
 A função `_freea` desaloca um bloco de memória (`memblock`) que foi alocado anteriormente por uma chamada a [malloca](../../c-runtime-library/reference/malloca.md). `_freea` verifica se a memória foi alocada no heap ou na pilha. Se ela tiver sido alocada na pilha, `_freea` não fará nada. Se tiver sido alocada no heap, o número de bytes liberados será equivalente ao número de bytes solicitados quando o bloco foi alocado. Se `memblock` for `NULL`, o ponteiro será ignorado e `_freea` será retornado imediatamente. Tentar liberar um ponteiro inválido (um ponteiro para um bloco de memória que não foi alocado por `_malloca`) pode afetar solicitações posteriores de alocação e causar erros.  
  
 `_freea`chamadas `free` internamente se detectar que a memória é alocada no heap. Um marcador colocado na memória, no endereço imediatamente anterior à memória alocada, determina se a memória está no heap ou na pilha.  
  
 Se ocorrer um erro ao liberar a memória, o `errno` é definido com informações do sistema operacional sobre a natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Após um bloco de memória ter sido liberado, [_heapmin](../../c-runtime-library/reference/heapmin.md) minimiza a quantidade de memória livre no heap juntando as regiões não utilizadas e liberando-as para o sistema operacional. A memória liberada que não for liberada para o sistema operacional será restaurada para o pool livre e ficará disponível para alocação novamente.  
  
 Uma chamada para `_freea` deve acompanhar todas as chamadas para `_malloca`. Também é um erro chamar `_freea` duas vezes na mesma memória. Quando o aplicativo está vinculado a uma versão de depuração das bibliotecas de tempo de execução C, particularmente com recursos [malloc_dbg](../../c-runtime-library/reference/malloc-dbg.md) habilitados definindo `_CRTDBG_MAP_ALLOC`, é mais fácil localizar chamadas ausentes ou duplicadas para `_freea`. Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).  
  
 `_freea` é marcado como `__declspec(noalias)`, o significa que há uma garantia de que a função não modifica variáveis globais. Para obter mais informações, consulte [noalias](../../cpp/noalias.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_freea`|\<stdlib.h> e \<malloc.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [_malloca](../../c-runtime-library/reference/malloca.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [_malloca](../../c-runtime-library/reference/malloca.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [_malloc_dbg](../../c-runtime-library/reference/malloc-dbg.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [_free_dbg](../../c-runtime-library/reference/free-dbg.md)   
 [_heapmin](../../c-runtime-library/reference/heapmin.md)