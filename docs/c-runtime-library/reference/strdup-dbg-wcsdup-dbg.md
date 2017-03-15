---
title: _strdup_dbg, _wcsdup_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _strdup_dbg
- _wcsdup_dbg
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
- _wcsdup_dbg
- strdup_dbg
- _strdup_dbg
- wcsdup_dbg
dev_langs:
- C++
helpviewer_keywords:
- _wcsdup_dbg function
- stdup_dbg function
- copying strings
- duplicating strings
- strings [C++], copying
- strings [C++], duplicating
- _strdup_dbg function
- wcsdup_dbg function
ms.assetid: 681db70c-d124-43ab-b83e-5eeea9035097
caps.latest.revision: 11
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
ms.openlocfilehash: 22798d52d78a822c538055b55fd8f10660de780c
ms.lasthandoff: 02/25/2017

---
# <a name="strdupdbg-wcsdupdbg"></a>_strdup_dbg, _wcsdup_dbg
Versões de [_strdup e _wcsdup](../../c-runtime-library/reference/strdup-wcsdup-mbsdup.md) que usam a versão de depuração de `malloc`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_strdup_dbg(  
   const char *strSource,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
wchar_t *_wcsdup_dbg(  
   const wchar_t *strSource,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `strSource`  
 Cadeia de caracteres de origem com terminação nula.  
  
 `blockType`  
 Tipo solicitado de bloco de memória: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou NULL.  
  
 `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou NULL.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retornam um ponteiro para o local de armazenamento para a cadeia de caracteres copiada ou `NULL` se o armazenamento não puder ser alocado.  
  
## <a name="remarks"></a>Comentários  
 As funções `_strdup_dbg` e `_wcsdup_dbg` são idênticas a `_strdup` e `_wcsdup`, exceto pelo fato de que, quando `_DEBUG` é definido, essas funções usam a versão de depuração de `malloc` e `_malloc_dbg` para alocar memória para a cadeia de caracteres duplicada. Para obter informações sobre os recursos de depuração de `_malloc_dbg`, consulte [_malloc_dbg](../../c-runtime-library/reference/malloc-dbg.md).  
  
 Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, defina o sinalizador `_CRTDBG_MAP_ALLOC`. Quando `_CRTDBG_MAP_ALLOC` é definido, as chamadas a `_strdup` e `_wcsdup` são remapeadas para `_strdup_dbg` e `_wcsdup_dbg`, respectivamente, com o `blockType` definido como `_NORMAL_BLOCK`. Assim, não é necessário chamar essas funções explicitamente, a menos que você queira marcar os blocos de heap como `_CLIENT_BLOCK`. Para obter mais informações sobre os tipos de bloco, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tcsdup_dbg`|`_strdup_dbg`|`_mbsdup`|`_wcsdup_dbg`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_strdup_dbg`, `_wcsdup_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões de depuração das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::String::Clone](https://msdn.microsoft.com/en-us/library/system.string.clone.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [_strdup, _wcsdup, _mbsdup](../../c-runtime-library/reference/strdup-wcsdup-mbsdup.md)   
 [Versões de depuração de funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)
