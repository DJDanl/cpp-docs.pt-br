---
title: _heapadd | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _heapadd
apilocation:
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr80.dll
- msvcrt.dll
- msvcr110.dll
- msvcr90.dll
apitype: DLLExport
f1_keywords:
- heapadd
- _heapadd
dev_langs:
- C++
helpviewer_keywords:
- _heapadd function
- memory, adding to heaps
- heaps, adding memory
- heapadd function
ms.assetid: 4d691fe2-2763-49f4-afb1-62738b7cd3ff
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9c046f9e26848edbbc609b9f3c729a0654fe3718
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="heapadd"></a>_heapadd
Adiciona memória ao heap.  
  
> [!IMPORTANT]
>  Essa função é obsoleta. A partir do Visual Studio 2015, ela não está disponível no CRT.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _heapadd(   
   void *memblock,  
   size_t size   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memblock`  
 Ponteiro para a memória de heap.  
  
 `size`  
 Tamanho da memória a ser adicionada, em bytes.  
  
## <a name="return-value"></a>Valor retornado  
 Se for bem-sucedido, `_heapadd` retornará 0. Caso contrário, a função retornará -1 e definirá `errno` como `ENOSYS`.  
  
 Para obter mais informações sobre este e outros códigos retornados, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 Começando com o Visual C++ versão 4.0, a estrutura de heap subjacente foi movida para as bibliotecas de tempo de execução de C para dar suporte a novos recursos de depuração. Como resultado, `_heapadd` não tem mais suporte em nenhuma plataforma baseada na API do Win32.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_heapadd`|\<malloc.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../c-runtime-library/memory-allocation.md)   
 [free](../c-runtime-library/reference/free.md)   
 [_heapchk](../c-runtime-library/reference/heapchk.md)   
 [_heapmin](../c-runtime-library/reference/heapmin.md)   
 [_heapset](../c-runtime-library/heapset.md)   
 [_heapwalk](../c-runtime-library/reference/heapwalk.md)   
 [malloc](../c-runtime-library/reference/malloc.md)   
 [realloc](../c-runtime-library/reference/realloc.md)