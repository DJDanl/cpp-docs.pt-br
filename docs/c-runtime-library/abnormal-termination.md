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
caps.latest.revision: 2
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
ms.translationtype: Human Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 37b80a5e21d7310269797d0760be3d9f76d3c581
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="abnormaltermination"></a>_abnormal_termination
Indica se o bloco `__finally` de uma [instrução try-finally](../cpp/try-finally-statement.md) é inserido enquanto o sistema está executado uma lista interna de manipuladores de término.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
int   _abnormal_termination(  
   );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 `true` se o sistema estiver *desenrolando* a pilha, caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 É uma função interna usada para gerenciar o desenrolamento de exceções e não tem o objetivo de ser chamado no código do usuário.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|_abnormal_termination|excpt. h|  
  
## <a name="see-also"></a>Consulte também  
 [Instrução try-finally](../cpp/try-finally-statement.md)
