---
title: _local_unwind2 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _local_unwind2
apilocation:
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr100.dll
- msvcr110.dll
- msvcr80.dll
- msvcr90.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- _local_unwind2
- local_unwind2
dev_langs:
- C++
helpviewer_keywords:
- _local_unwind2 function
- local_unwind2 function
ms.assetid: 44f1fa82-e01e-490f-a6e6-18fc6811c28c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3b0c027623f5b562219e46c67ef730754538d602
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="localunwind2"></a>_local_unwind2
Função CRT interna. Executa todos os manipuladores de terminação listados na tabela de escopo indicada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _local_unwind2(  
   PEXCEPTION_REGISTRATION xr,  
   int stop  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `xr`  
 Um registro que é associado a uma tabela de escopo.  
  
 [in] `stop`  
 O nível lexical que indica onde o `_local_unwind2` deve parar.  
  
## <a name="remarks"></a>Comentários  
 Esse método só é usado pelo ambiente de tempo de execução. Não chame o método no seu código.  
  
 Quando esse método executa manipuladores de terminação, ele começa no nível lexical atual e avança nos níveis lexicais até atingir o número indicado por `stop`. Não executa manipuladores de terminação no nível indicado por `stop`.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)