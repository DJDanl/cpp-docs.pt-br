---
title: _free_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _free_dbg
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
- _free_dbg
- free_dbg
dev_langs:
- C++
helpviewer_keywords:
- memory blocks, deallocating
- freeing memory
- _free_dbg function
- free_dbg function
ms.assetid: fc5e8299-616d-48a0-b979-e037117278c6
caps.latest.revision: 16
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
ms.openlocfilehash: 7ab13da1c51d75979656c4b70c4874566296e845
ms.lasthandoff: 02/25/2017

---
# <a name="freedbg"></a>_free_dbg
Libera um bloco de memória no heap (somente a versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _free_dbg(   
   void *userData,  
   int blockType   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `userData`  
 Ponteiro para o bloco de memória alocado a ser liberado.  
  
 `blockType`  
 Tipo do bloco de memória alocado a ser liberado: `_CLIENT_BLOCK`, `_NORMAL_BLOCK` ou `_IGNORE_BLOCK`.  
  
## <a name="remarks"></a>Comentários  
 A função `_free_dbg` é uma versão de depuração da função [free](../../c-runtime-library/reference/free.md). Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, cada chamada para `_free_dbg` é reduzida a uma chamada para `free`. `free` e `_free_dbg` liberam um bloco de memória no heap de base, mas `_free_dbg` acomoda dois recursos de depuração: a capacidade de manter blocos liberados na lista vinculada do heap para simular condições de baixa memória e um parâmetro de tipo de bloco para liberar tipos de alocação específicos.  
  
 O `_free_dbg` realiza uma verificação de validade em todos os arquivos e locais de bloco especificados antes de realizar a ação de liberação. O aplicativo não deve fornecer essas informações. Ao liberar um bloco de memória, o gerenciador de heap de depuração verifica automaticamente a integridade dos buffers nos dois lados da parte do usuário e emite um relatório de erro se tiver ocorrido substituição. Se o campo de bits `_CRTDBG_DELAY_FREE_MEM_DF` do sinalizador [_crtDbgFlag](../../c-runtime-library/crtdbgflag.md) estiver definido, o bloco liberado será preenchido com o valor 0xDD, atribuído ao tipo de bloco `_FREE_BLOCK` e será mantido na lista vinculada de blocos de memória do heap.  
  
 Se ocorrer um erro ao liberar a memória, o `errno` é definido com informações do sistema operacional sobre a natureza da falha. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details). Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração). Para obter informações sobre as diferenças entre chamar uma função de heap padrão e sua versão de depuração em um build de depuração de um aplicativo, consulte [Versões de depuração das funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_free_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Para obter uma amostra de como usar `_free_dbg`, consulte [crt_dbg2](http://msdn.microsoft.com/en-us/21e1346a-6a17-4f57-b275-c76813089167).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [_malloc_dbg](../../c-runtime-library/reference/malloc-dbg.md)
