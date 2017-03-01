---
title: _aligned_free | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _aligned_free
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
- aligned_free
- _aligned_free
dev_langs:
- C++
helpviewer_keywords:
- _aligned_free function
- aligned_free function
ms.assetid: ed1ce952-cdfc-4682-85cc-f75d4101603d
caps.latest.revision: 16
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
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 8cd24f11b79ef4148c1a56521ef85593cf766e2e
ms.lasthandoff: 02/25/2017

---
# <a name="alignedfree"></a>_aligned_free
Libera um bloco de memória que foi alocado com [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [_aligned_offset_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _aligned_free (  
   void *memblock  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memblock`  
 Um ponteiro para o bloco de memória que foi retornado para a função `_aligned_malloc` ou `_aligned_offset_malloc`.  
  
## <a name="remarks"></a>Comentários  
 `_aligned_free` é marcado como `__declspec(noalias)`, o significa que há uma garantia de que a função não modifica variáveis globais. Para obter mais informações, consulte [noalias](../../cpp/noalias.md).  
  
 Essa função não valida seu parâmetro, ao contrário das outras funções de CRT _aligned. Se `memblock` for um ponteiro `NULL`, essa função simplesmente não executará nenhuma ação. Ela não altera `errno` nem chama o manipulador de parâmetro inválido. Se ocorrer um erro na função porque as funções _aligned não foram usadas anteriormente para alocar o bloco de memória ou se ocorrer um desalinhamento de memória devido a algum problema imprevisto, a função gerará um relatório de depuração das [Macros _RPT, _RPTF, _RPTW, _RPTFW](../../c-runtime-library/reference/rpt-rptf-rptw-rptfw-macros.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_aligned_free`|\<malloc.h>|  
  
## <a name="example"></a>Exemplo  
 Para obter mais informações, consulte [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Alinhamento de dados](../../c-runtime-library/data-alignment.md)
