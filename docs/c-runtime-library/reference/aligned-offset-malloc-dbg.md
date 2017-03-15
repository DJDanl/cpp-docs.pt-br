---
title: _aligned_offset_malloc_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _aligned_offset_malloc_dbg
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
- _aligned_offset_malloc_dbg
- aligned_offset_malloc_dbg
dev_langs:
- C++
helpviewer_keywords:
- _aligned_offset_malloc_dbg function
- aligned_offset_malloc_dbg function
ms.assetid: 6c242307-c59e-4d63-aae5-d8cbec8e021c
caps.latest.revision: 8
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
ms.sourcegitcommit: 84964b0a49b236bae056125de8155b18880eb378
ms.openlocfilehash: 67f314989e0069902ae983805a4f8ce839307ea5
ms.lasthandoff: 02/25/2017

---
# <a name="alignedoffsetmallocdbg"></a>_aligned_offset_malloc_dbg
Aloca memória em um limite de alinhamento especificado (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void * _aligned_offset_malloc_dbg(  
   size_t size,   
   size_t alignment,   
   size_t offset,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `size`  
 Tamanho da alocação de memória solicitada.  
  
 [in] `alignment`  
 O valor de alinhamento, que deve ser um inteiro elevado à segunda potência.  
  
 [in] `offset`  
 O deslocamento na alocação de memória para forçar o alinhamento.  
  
 [in] `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou NULL.  
  
 [in] `linenumber`  
 Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou NULL.  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o bloco de memória alocado ou `NULL`, se a operação tiver falhado.  
  
## <a name="remarks"></a>Comentários  
 `_aligned_offset_malloc_dbg` é uma versão de depuração da função [_aligned_offset_malloc](../../c-runtime-library/reference/aligned-offset-malloc.md). Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, cada chamada para `_aligned_offset_malloc_dbg` é reduzida a uma chamada para `_aligned_offset_malloc`. Tanto o `_aligned_offset_malloc` quanto o `_aligned_offset_malloc_dbg` alocam um bloco de memória no heap de base, mas o `_aligned_offset_malloc_dbg` oferece vários recursos de depuração: buffers em qualquer um dos lados da parte do usuário do bloco para testar se há vazamentos, um parâmetro de tipo do bloco para rastrear tipos de alocação específicos e as informações de `filename`/`linenumber` para determinar a origem das solicitações de alocação.  
  
 `_aligned_offset_malloc_dbg` aloca o bloco de memória com um pouco mais de espaço que o `size` solicitado. O espaço adicional é usado pelo gerenciador de heaps de depuração para vincular os blocos de memória de depuração e fornecer informações do cabeçalho de depuração ao aplicativo e substituir buffers. Quando um bloco é alocado, a parte do usuário do bloco é preenchida com o valor 0xCD e cada um dos buffers de substituição é preenchido com 0xFD.  
  
 `_aligned_offset_malloc_dbg` é útil em situações em que o alinhamento é necessário em um elemento aninhado. Por exemplo, se o alinhamento foi necessário em uma classe aninhada.  
  
 `_aligned_offset_malloc_dbg` é baseado em `malloc`. Para obter mais informações, consulte [malloc](../../c-runtime-library/reference/malloc.md).  
  
 Essa função define `errno` como `ENOMEM` se a alocação da memória tiver falhado ou se o tamanho solicitado for maior que `_HEAP_MAXREQ`. Para obter mais informações sobre `errno`, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md). Além disso, `_aligned_offset_malloc` valida seus parâmetros. Se `alignment` não for um número elevado à segunda potência ou se `offset` for maior ou igual a `size` e diferente de zero, essa função invocará o manipulador de parâmetro inválido, conforme a descrição em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
 Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).  
  
 Para obter informações sobre os tipos de blocos de alocação e como eles são usados, consulte [Types of blocks on the debug heap](/visualstudio/debugger/crt-debug-heap-details) (Tipos de blocos no heap de depuração).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_aligned_offset_malloc_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)
