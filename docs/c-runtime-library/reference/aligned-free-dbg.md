---
title: _aligned_free_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _aligned_free_dbg
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
- _aligned_free_dbg
- aligned_free_dbg
dev_langs: C++
helpviewer_keywords:
- _aligned_free_dbg function
- aligned_free_dbg function
ms.assetid: eb0cb3c8-0992-4db8-bac3-65f1b8311ca6
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9ea0dd62e2b76bef5e55fb152eecfc4c12d01fdf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="alignedfreedbg"></a>_aligned_free_dbg
Libera um bloco de memória que foi alocado com [aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) ou [aligned_offset_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md) (somente depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _aligned_free_dbg(  
   void *memblock  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memblock`  
 Um ponteiro para o bloco de memória que foi retornado para a função `_aligned_malloc` ou `_aligned_offset_malloc`.  
  
## <a name="remarks"></a>Comentários  
 A função `_aligned_free_dbg` é uma versão de depuração da função [_aligned_free](../../c-runtime-library/reference/aligned-free.md). Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, cada chamada para `_aligned_free_dbg` é reduzida a uma chamada para `_aligned_free`. Ambos `_aligned_free` e `_aligned_free_dbg` liberar um bloco de memória no heap de base, mas `_aligned_free_dbg` acomoda um recurso de depuração: a capacidade de manter liberada blocos em lista vinculada do heap para simular condições de memória insuficiente.  
  
 O `_aligned_free_dbg` realiza uma verificação de validade em todos os arquivos e locais de bloco especificados antes de realizar a ação de liberação. O aplicativo não deve fornecer essas informações. Ao liberar um bloco de memória, o gerenciador de heap de depuração verifica automaticamente a integridade dos buffers nos dois lados da parte do usuário e emite um relatório de erro se tiver ocorrido substituição. Se o campo de bits `_CRTDBG_DELAY_FREE_MEM_DF` do sinalizador [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md) estiver definido, o bloco liberado será preenchido com o valor 0xDD, atribuído ao tipo de bloco `_FREE_BLOCK` e será mantido na lista vinculada de blocos de memória do heap.  
  
 Se ocorrer um erro ao liberar a memória, o `errno` é definido com informações do sistema operacional sobre a natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_aligned_free_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)