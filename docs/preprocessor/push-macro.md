---
title: push_macro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- vc-pragma.push_macro
- push_macro_CPP
dev_langs:
- C++
helpviewer_keywords:
- pragmas, push_macro
- push_macro pragma
ms.assetid: ac89efc9-afd1-4dfe-bfd1-497229b3e81d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 70b472ba11445cdc5aa2a192d02d82c51d724b8c
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42541518"
---
# <a name="pushmacro"></a>push_macro
Salva o valor da *macro_name* macro no topo da pilha dessa macro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma push_macro("  
macro_name  
")  
```  
  
## <a name="remarks"></a>Comentários  
 
Você pode recuperar o valor para *macro_name* com `pop_macro`.  
  
Ver [pop_macro](../preprocessor/pop-macro.md) para obter um exemplo.  
  
## <a name="see-also"></a>Consulte também  
 
[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)