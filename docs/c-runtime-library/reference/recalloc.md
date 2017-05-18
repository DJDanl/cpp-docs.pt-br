---
title: _recalloc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _recalloc
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
- _recalloc
- recalloc
dev_langs:
- C++
helpviewer_keywords:
- _recalloc function
- recalloc function
ms.assetid: 1db8305a-3f03-418c-8844-bf9149f63046
caps.latest.revision: 9
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: ae78e17f66448de46e36ea7d6dc6e3121b306c68
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="recalloc"></a>_recalloc
Uma combinação de `realloc` e `calloc`. Realoca uma matriz na memória e inicializa seus elementos como 0.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *_recalloc(   
   void *memblock  
   size_t num,  
   size_t size   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memblock`  
 Ponteiro para o bloco de memória alocado anteriormente.  
  
 `num`  
 Número de elementos.  
  
 `size`  
 O comprimento, em bytes, de cada elemento.  
  
## <a name="return-value"></a>Valor de retorno  
 `_recalloc` retorna um ponteiro `void` para o bloco de memória realocado (e possivelmente movido).  
  
 Se não houver memória suficiente para expandir o bloco para o tamanho determinado, o bloco original será deixada inalterado e `NULL` é retornado.  
  
 Se o tamanho solicitado for zero, então o bloco apontado por `memblock` é liberado; o valor retornado é `NULL` e `memblock` é deixado apontando para um bloco liberado.  
  
 O valor retornado indica um espaço de armazenamento que sempre está sutilmente alinhado para armazenamento de qualquer tipo de objeto. Para obter um ponteiro para um tipo que não seja `void`, use uma conversão de tipo no valor retornado.  
  
## <a name="remarks"></a>Comentários  
 A função `_recalloc` altera o tamanho de um bloco de memória alocado. O argumento `memblock` aponta para o início do bloco de memória. Se `memblock` é `NULL`, `_recalloc` se comporta da mesma maneira que [calloc](../../c-runtime-library/reference/calloc.md) e aloca um novo bloco de `num`  *  `size` bytes. Cada elemento é inicializado como 0. Se `memblock` não for `NULL`, ele deverá ser um ponteiro retornado por uma chamada anterior para `calloc`, [malloc](../../c-runtime-library/reference/malloc.md) ou [realloc](../../c-runtime-library/reference/realloc.md).  
  
 Como o novo bloco pode estar em um novo local de memória, não há garantia que o ponteiro retornado por `_recalloc` seja aquele passado por meio do argumento `memblock`.  
  
 `_recalloc` definirá `errno` para `ENOMEM` se a alocação de memória falhar ou se a quantidade de memória solicitada exceder `_HEAP_MAXREQ`. Para obter informações sobre esse e outros códigos de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 `recalloc` chama `realloc` para usar a função C++ [_set_new_mode](../../c-runtime-library/reference/set-new-mode.md) para definir o novo modo de manipulador. O novo modo do manipulador indica se, em caso de falha, `realloc` deverá chamar a nova rotina do manipulador conforme definido por [_set_new_handler](../../c-runtime-library/reference/set-new-handler.md). Por padrão, `realloc` não chama a nova rotina do manipulador em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando `_recalloc` falhar ao alocar memória, `realloc` chame a nova rotina do manipulador da mesma forma que o operador `new` fará quando ele falhar pelo mesmo motivo. Para substituir o padrão, chame  
  
```  
_set_new_mode(1)  
```  
  
 no início do programa ou vincule com NEWMODE.OBJ.  
  
 Quando o aplicativo está vinculado com uma versão de depuração das bibliotecas de tempo de execução do C, `_recalloc` resolve [recalloc_dbg](../../c-runtime-library/reference/recalloc-dbg.md). Para obter mais informações sobre como o heap é gerenciado durante o processo de depuração, consulte [The CRT Debug Heap](/visualstudio/debugger/crt-debug-heap-details) (O heap de depuração do CRT).  
  
 `_recalloc` é marcado como `__declspec(noalias)` e `__declspec(restrict)`, o que representa a garantia de que a função não modifica variáveis globais e que o ponteiro retornado não é um alias. Para obter mais informações, consulte [noalias](../../cpp/noalias.md) e [restrict](../../cpp/restrict.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_recalloc`|\<stdlib.h> e \<malloc.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [_recalloc_dbg](../../c-runtime-library/reference/recalloc-dbg.md)   
 [_aligned_recalloc](../../c-runtime-library/reference/aligned-recalloc.md)   
 [_aligned_offset_recalloc](../../c-runtime-library/reference/aligned-offset-recalloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [Opções de link](../../c-runtime-library/link-options.md)
