---
title: _abnormal_termination | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _abnormal_termination
apilocation:
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr90.dll
- msvcr120.dll
- msvcrt.dll
- msvcr80.dll
- msvcr100.dll
apitype: DLLExport
f1_keywords:
- _abnormal_termination
dev_langs:
- C++
helpviewer_keywords:
- _abnormal_termination
ms.assetid: 952970a4-9586-4c3d-807a-db729448c91c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fc205afd297c7cce87ae630369551e02f3109d88
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="abnormaltermination"></a>_abnormal_termination
Indica se o bloco `__finally` de uma [instrução try-finally](../cpp/try-finally-statement.md) é inserido enquanto o sistema está executado uma lista interna de manipuladores de término.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
int   _abnormal_termination(  
   );  
```  
  
## <a name="return-value"></a>Valor retornado  
 `true` se o sistema estiver *desenrolando* a pilha, caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 É uma função interna usada para gerenciar o desenrolamento de exceções e não tem o objetivo de ser chamado no código do usuário.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|_abnormal_termination|excpt. h|  
  
## <a name="see-also"></a>Consulte também  
 [Instrução try-finally](../cpp/try-finally-statement.md)