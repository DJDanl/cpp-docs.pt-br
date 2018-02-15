---
title: _CrtIsValidPointer | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _CrtIsValidPointer
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
- CrtlsValidPointer
- _CrtIsValidPointer
dev_langs:
- C++
helpviewer_keywords:
- CrtIsValidPointer function
- _CrtIsValidPointer function
ms.assetid: 91c35590-ea5e-450f-a15d-ad8d62ade1fa
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e81cd074c9bd69386b300d307525a76515e02522
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="crtisvalidpointer"></a>_CrtIsValidPointer
Verifica se um ponteiro não é nulo. Em versões da biblioteca em tempo de execução C anteriores ao Visual Studio 2010, verifica se um intervalo de memória especificado é válido para leitura e gravação (somente versão de depuração).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _CrtIsValidPointer(   
   const void *address,  
   unsigned int size,  
   int access   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 endereço  
 Aponta para o início do intervalo de memória para testar a validade.  
  
 `size`  
 Tamanho do intervalo de memória especificado (em bytes).  
  
 acesso  
 Acessibilidade de leitura/gravação para determinar o intervalo de memória.  
  
## <a name="return-value"></a>Valor de retorno  
 `_CrtIsValidPointer` retornará TRUE se o ponteiro especificado não for nulo. Nas versões da biblioteca CRT anteriores ao Visual Studio 2010, retornará TRUE se o intervalo de memória for válido para as operações especificadas. Caso contrário, a função retorna FALSE.  
  
## <a name="remarks"></a>Comentários  
 A partir da biblioteca CRT no Visual Studio 2010, o tamanho e os parâmetros de acesso são ignorados e `_CrtIsValidPointer` apenas verifica se o endereço especificado não é nulo. Como esse teste é fácil de ser realizado por conta própria, não recomendamos o uso dessa função. Em versões anteriores ao Visual Studio 2010, a função verifica se o intervalo de memória que começa em `address` e se estende até `size` bytes é válido para as operações de acessibilidade especificadas. Quando `access` for definido como TRUE, o intervalo de memória é verificado para leitura e gravação. Quando `access` for FALSE, o intervalo de memória é validado somente para leitura. Quando [_DEBUG](../../c-runtime-library/debug.md) não está definido, as chamadas a `_CrtIsValidPointer` são removidas durante o pré-processamento.  
  
 Como essa função retorna TRUE ou FALSE, ela pode ser passada para uma das macros [_ASSERT](../../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) para criar um mecanismo simples de tratamento de erro de depuração. O exemplo a seguir causa uma falha de asserção se o intervalo de memória não for válido para as operações de leitura e gravação:  
  
```  
_ASSERTE( _CrtIsValidPointer( address, size, TRUE ) );  
```  
  
 Para obter mais informações sobre como `_CrtIsValidPointer` pode ser usado com outras macros e funções de depuração, consulte [Macros para relatórios](/visualstudio/debugger/macros-for-reporting). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_CrtIsValidPointer`|\<crtdbg.h>|  
  
 `_CrtIsValidPointer` é uma extensão da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo do tópico [_CrtIsValidHeapPointer](../../c-runtime-library/reference/crtisvalidheappointer.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)