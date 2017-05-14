---
title: _findclose | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _findclose
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
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _findclose
- findclose
dev_langs:
- C++
helpviewer_keywords:
- _findclose function
- findclose function
ms.assetid: 9216c573-0878-444c-b5d7-cdaf16fb9163
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: fcd76f8daec9c90374989a82f4b4b2f85b4cb5c7
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="findclose"></a>_findclose
Fecha o identificador de pesquisa especificado e libera os recursos associados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _findclose(   
   intptr_t handle   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `handle`  
 Identificador de pesquisa retornado por uma chamada anterior a `_findfirst`.  
  
## <a name="return-value"></a>Valor de retorno  
 Se tiver êxito, `_findclose` retornará 0. Caso contrário, retornará -1 e define `errno` para `ENOENT`, que indica se a correspondência não mais arquivos pôde ser encontrado.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_findclose`|\<io.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Chamadas do sistema](../../c-runtime-library/system-calls.md)   
 [Funções de pesquisa de nome de arquivo](../../c-runtime-library/filename-search-functions.md)
