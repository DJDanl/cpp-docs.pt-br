---
title: _tempnam_dbg, _wtempnam_dbg | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wtempnam_dbg
- _tempnam_dbg
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
- wtempnam_dbg
- tempnam_dbg
- _tempnam_dbg
- _wtempnam_dbg
dev_langs:
- C++
helpviewer_keywords:
- file names [C++], creating temporary
- tempnam_dbg function
- temporary files, creating
- file names [C++], temporary
- wtempnam_dbg function
- _tempnam_dbg function
- _wtempnam_dbg function
ms.assetid: e3760bb4-bb01-4808-b689-2c45af56a170
caps.latest.revision: 13
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 260c5ae7348516683d8e749a2dcb6cdac6ea0943
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="tempnamdbg-wtempnamdbg"></a>_tempnam_dbg, _wtempnam_dbg
Versões da função [_tempnam, _wtempnam, tmpnam, _wtmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md) que usam a versão de depuração `malloc, _malloc_dbg`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *_tempnam_dbg(  
   const char *dir,  
   const char *prefix,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
wchar_t *_wtempnam_dbg(  
   const wchar_t *dir,  
   const wchar_t *prefix,  
   int blockType,  
   const char *filename,  
   int linenumber   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `dir`  
 O caminho usado no nome de arquivo, se não houver variável de ambiente TMP ou se TMP não for um diretório válido.  
  
 `prefix`  
 A cadeia de caracteres que será pré-anexada a nomes retornados pelo `_tempnam`.  
  
 `blockType`  
 Tipo solicitado de bloco de memória: `_CLIENT_BLOCK` ou `_NORMAL_BLOCK`.  
  
 `filename`  
 Nome do ponteiro do arquivo de origem que solicitou a operação de alocação ou `NULL`.  
  
 `linenumber`  
 Número da linha no arquivo de origem em que a operação de alocação foi solicitada ou `NULL`.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada função retorna um ponteiro para o nome gerado ou `NULL`, caso tenha ocorrido uma falha. Pode ocorrer uma falha se houver um nome de diretório inválido especificado na variável de ambiente TMP e no parâmetro `dir`.  
  
> [!NOTE]
>  `free` (ou `free_dbg`) não precisa ser chamado para ponteiros alocados por `_tempnam_dbg` e `_wtempnam_dbg`.  
  
## <a name="remarks"></a>Comentários  
 O `_tempnam_dbg` e `_wtempnam_dbg` funções são idênticas aos `_tempnam` e `_wtempnam` exceto que, quando `_DEBUG` é definida, essas funções usam a versão de depuração `malloc` e `_malloc_dbg`para alocar memória se `NULL` é passado como o primeiro parâmetro. Para obter mais informações, consulte [_malloc_dbg](../../c-runtime-library/reference/malloc-dbg.md).  
  
 Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, defina o sinalizador `_CRTDBG_MAP_ALLOC`. Quando `_CRTDBG_MAP_ALLOC` é definido, as chamadas a `_tempnam` e `_wtempnam` são remapeadas para `_tempnam_dbg` e `_wtempnam_dbg`, respectivamente, com o `blockType` definido como `_NORMAL_BLOCK`. Assim, não é necessário chamar essas funções explicitamente, a menos que você queira marcar os blocos de heap como `_CLIENT_BLOCK`. Para obter mais informações, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_ttempnam_dbg`|`_tempnam_dbg`|`_tempnam_dbg`|`_wtempnam_dbg`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_tempnam_dbg`, `_wtempnam_dbg`|\<crtdbg.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [_tempnam, _wtempnam, tmpnam, _wtmpnam](../../c-runtime-library/reference/tempnam-wtempnam-tmpnam-wtmpnam.md)   
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Versões de depuração de funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)
