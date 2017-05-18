---
title: _CrtIsMemoryBlock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CrtIsMemoryBlock
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
- CrtlsMemoryBlock
- _CrtIsMemoryBlock
dev_langs:
- C++
helpviewer_keywords:
- _CrtIsMemoryBlock function
- CrtIsMemoryBlock function
ms.assetid: f7cbbc60-3690-4da0-a07b-68fd7f250273
caps.latest.revision: 14
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
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: e24601f4161244c2a941a89648060e06ff226736
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="crtismemoryblock"></a>_CrtIsMemoryBlock
Verifica se um bloco de memória especificado está no heap local e se ele tem um identificador de tipo de bloco de heap de depuração válido (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _CrtIsMemoryBlock(   
   const void *userData,  
   unsigned int size,  
   long *requestNumber,  
   char **filename,  
   int *linenumber   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `userData`  
 Ponteiro para o início do bloco de memória a ser verificado.  
  
 [in] `size`  
 Tamanho do bloco especificado (em bytes).  
  
 [out] `requestNumber`  
 Ponteiro para o número de alocação do bloco ou `NULL`.  
  
 [out] `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou o bloco ou `NULL`.  
  
 [out] `linenumber`  
 Ponteiro para o número de linha no arquivo de origem ou `NULL`.  
  
## <a name="return-value"></a>Valor de retorno  
 `_CrtIsMemoryBlock` retornará `TRUE` se o bloco de memória especificado estiver localizado no heap local e tiver um identificador de tipo de bloco de heap de depuração válido; caso contrário, a função retornará `FALSE`.  
  
## <a name="remarks"></a>Comentários  
 A função `_CrtIsMemoryBlock` verifica se um bloco de memória especificado está localizado no heap local do aplicativo e se ele tem um identificador de tipo de bloco válido. Essa função também pode ser usada para obter o número de ordem de alocação do objeto e o nome do arquivo de origem/número de linha em que a alocação de bloco de memória foi originalmente solicitada. Passar valores não NULL para os parâmetros `requestNumber`, `filename` ou `linenumber` faz com que `_CrtIsMemoryBlock` defina esses parâmetros com os valores no cabeçalho de depuração do bloco de memória, caso ele encontre o bloco no heap local. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtIsMemoryBlock` são removidas durante o pré-processamento.  
  
 Se `_CrtIsMemoryBlock` falhar, ele retornará `FALSE` e os parâmetros de saída serão inicializados com os valores padrão: `requestNumber` e `lineNumber` são definidos como 0 e `filename` é definido como `NULL`.  
  
 Como essa função retorna `TRUE` ou `FALSE`, ela pode ser passada para uma das macros [_ASSERT](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) para criar um mecanismo simples de tratamento de erro de depuração. O seguinte exemplo causa uma falha de asserção se o endereço especificado não está localizado no heap local:  
  
```  
_ASSERTE( _CrtIsMemoryBlock( userData, size, &requestNumber,   
&filename, &linenumber ) );  
```  
  
 Para obter mais informações sobre como `_CrtIsMemoryBlock` pode ser usado com outras macros e funções de depuração, consulte [Macros para relatórios](/visualstudio/debugger/macros-for-reporting). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtIsMemoryBlock`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo do tópico [_CrtIsValidHeapPointer](../../c-runtime-library/reference/crtisvalidheappointer.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)
