---
title: _findclose | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3b1f79ea7e5c39c4de7ba25699729864688ababf
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
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