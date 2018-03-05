---
title: ___lc_collate_cp_func | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- ___lc_collate_cp_func
apilocation:
- msvcr120.dll
- msvcrt.dll
- msvcr100.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr90.dll
apitype: DLLExport
f1_keywords:
- ___lc_collate_cp_func
dev_langs:
- C++
helpviewer_keywords:
- ___lc_collate_cp_func
ms.assetid: 46ccc084-7ac9-4e5d-9138-e12cb5845615
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fe7ff6ce073f84a87e2243ab98d3b99af0dfd22c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="lccollatecpfunc"></a>___lc_collate_cp_func
Função CRT interna. Recupera a página de código de agrupamento atual do thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
UINT ___lc_codepage_func(void);  
```  
  
## <a name="return-value"></a>Valor retornado  
 A página de código de agrupamento atual do thread.  
  
## <a name="remarks"></a>Comentários  
 `___lc_collate_cp_func` é uma função CRT interna usada por outras funções CRT para obter a página de código de agrupamento atual do armazenamento local do thread para os dados do CRT. Essas informações também estão disponíveis usando a função [_get_current_locale](../c-runtime-library/reference/get-current-locale.md).  
  
 Funções CRT internas são específicas da implementação e estão sujeitas a alteração em cada versão. Não recomendamos usá-las no seu código.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`___lc_collate_cp_func`|crt\src\setlocal.h|  
  
## <a name="see-also"></a>Consulte também  
 [_get_current_locale](../c-runtime-library/reference/get-current-locale.md)   
 [setlocale, _wsetlocale](../c-runtime-library/reference/setlocale-wsetlocale.md)   
 [_create_locale, _wcreate_locale](../c-runtime-library/reference/create-locale-wcreate-locale.md)   
 [_free_locale](../c-runtime-library/reference/free-locale.md)