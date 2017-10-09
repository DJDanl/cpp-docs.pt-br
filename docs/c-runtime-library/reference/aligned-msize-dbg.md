---
title: _aligned_msize_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _aligned_msize_dbg
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
- _aligned_msize_dbg
dev_langs:
- C++
helpviewer_keywords:
- _aligned_msize_dbg
ms.assetid: f1c44af0-3f66-4033-81d1-d71d3afecba0
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: c278f9b9860026b3cd097b49cdce691d353e6f50
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="alignedmsizedbg"></a>_aligned_msize_dbg
Retorna o tamanho de um bloco de memória alocado no heap (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t _aligned_msize_dbg(  
   void *memblock,  
   size_t alignment,  
   size_t offset  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `memblock`  
 Ponteiro para o bloco de memória.  
  
 [in] `alignment`  
 O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.  
  
 [in] `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna o tamanho (em bytes) como um inteiro sem sinal.  
  
## <a name="remarks"></a>Comentários  
 Os valores `alignment` e `offset` devem ser os mesmos que os valores passados para a função que alocou o bloco.  
  
 `_aligned_msize_dbg` é uma versão de depuração da função [aligned_msize](../../c-runtime-library/reference/aligned-msize.md). Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, cada chamada para `_aligned_msize_dbg` é reduzida a uma chamada para `_aligned_msize`. `_aligned_msize` e `_aligned_msize_dbg` calculam o tamanho de um bloco de memória no heap de base, mas `_aligned_msize_dbg` adiciona um recurso de depuração: ele inclui os buffers nos dois lados da parte do usuário do bloco de memória no tamanho retornado.  
  
 Esta função valida seu parâmetro. Se `memblock` for um ponteiro nulo ou se `alignment` não for um número elevado à segunda potência, `_msize` invocará um manipulador de parâmetro inválido, conforme a descrição em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se o erro for tratado, a função definirá `errno` como `EINVAL` e retornará –1.  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_aligned_msize_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)
