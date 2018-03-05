---
title: "Manipulação de buffer | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.memory
dev_langs:
- C++
helpviewer_keywords:
- buffers, manipulation routines
- buffers
ms.assetid: 164f4860-ce66-412c-8291-396fbd70f03e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 942d0f881ed6453921f6082024be5247a1bb1b65
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="buffer-manipulation"></a>Manipulação de buffer
Use estas rotinas para trabalhar com áreas de memória em uma base byte por byte.  
  
### <a name="buffer-manipulation-routines"></a>Rotinas de manipulação de buffer  
  
|Rotina|Use|  
|-------------|---------|  
|[_memccpy](../c-runtime-library/reference/memccpy.md)|Copiar caracteres de um buffer para outro até que determinada caractere ou determinado número de caracteres foram copiados|  
|[memchr, wmemchr](../c-runtime-library/reference/memchr-wmemchr.md)|Retorna o ponteiro para a primeira ocorrência dentro de um número especificado de caracteres, de determinado caractere no buffer|  
|[memcmp, wmemcmp](../c-runtime-library/reference/memcmp-wmemcmp.md)|Compare o número especificado de caracteres de dois buffers|  
|[memcpy, wmemcpy](../c-runtime-library/reference/memcpy-wmemcpy.md), [memcpy_s, wmemcpy_s](../c-runtime-library/reference/memcpy-s-wmemcpy-s.md)|Copia o número especificado de caracteres de um buffer para outro|  
|[_memicmp, _memicmp_l](../c-runtime-library/reference/memicmp-memicmp-l.md)|Compare o número especificado de caracteres de dois buffers independentemente do caso|  
|[memmove, wmemmove](../c-runtime-library/reference/memmove-wmemmove.md),[memmove_s, wmemmove_s](../c-runtime-library/reference/memmove-s-wmemmove-s.md)|Copia o número especificado de caracteres de um buffer para outro|  
|[memset, wmemset](../c-runtime-library/reference/memset-wmemset.md)|Dado o caractere para inicializar o número especificado de bytes no buffer de uso|  
|[_swab](../c-runtime-library/reference/swab.md)|Troca os bytes de dados e armazená-os no local especificado|  
  
 Quando as áreas de origem e de destino se sobrepõem, apenas `memmove` é garantido para copiar o código-fonte completo corretamente.  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)