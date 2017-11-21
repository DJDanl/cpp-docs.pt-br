---
title: push_macro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc-pragma.push_macro
- push_macro_CPP
dev_langs: C++
helpviewer_keywords:
- pragmas, push_macro
- push_macro pragma
ms.assetid: ac89efc9-afd1-4dfe-bfd1-497229b3e81d
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ea7f842518f21e553198e8ee80894df25b8562dc
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="pushmacro"></a>push_macro
Salva o valor da *macro_name* macro no topo da pilha da macro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma push_macro("  
macro_name  
")  
  
```  
  
## <a name="remarks"></a>Comentários  
 Você pode recuperar o valor de *macro_name* com **pop_macro**.  
  
 Consulte [pop_macro](../preprocessor/pop-macro.md) para obter um exemplo.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)