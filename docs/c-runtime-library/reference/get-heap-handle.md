---
title: _get_heap_handle | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _get_heap_handle
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
- _get_heap_handle
- get_heap_handle
dev_langs:
- C++
helpviewer_keywords:
- heap functions
- memory allocation, heap memory
- _get_heap_handle function
- get_heap_handle function
ms.assetid: a4d05049-8528-494a-8281-a470d1e1115c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0608ef825032f636e09c42c5c522c5c600c649a6
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="getheaphandle"></a>_get_heap_handle
Retorna o identificador do heap usado pelo sistema de tempo de execução do C.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
intptr_t _get_heap_handle( void );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o identificador do heap do Win32 usado pelo sistema de tempo de execução do C.  
  
## <a name="remarks"></a>Comentários  
 Use essa função se quiser chamar [HeapSetInformation](http://msdn.microsoft.com/library/windows/desktop/aa366705) e habilitar o Heap de baixa fragmentação no heap do CRT.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_get_heap_handle`|\<malloc.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="sample"></a>Amostra  
  
```  
// crt_get_heap_handle.cpp  
// compile with: /MT  
#include <windows.h>  
#include <malloc.h>  
#include <stdio.h>  
  
int main(void)  
{  
    intptr_t hCrtHeap = _get_heap_handle();  
    ULONG ulEnableLFH = 2;  
    if (HeapSetInformation((PVOID)hCrtHeap,  
                           HeapCompatibilityInformation,  
                           &ulEnableLFH, sizeof(ulEnableLFH)))  
        puts("Enabling Low Fragmentation Heap succeeded");  
    else  
        puts("Enabling Low Fragmentation Heap failed");  
    return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)