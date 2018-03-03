---
title: "Substituição de macro | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, macro substitution
- macros, NMAKE
- substitution macros in NMAKE
ms.assetid: 47465cfe-fd92-49db-aebe-7c2d7ecceb73
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7c2ea7a2509e58cfd4da163cc76c018d06c244fc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="macro-substitution"></a>Substituição de macro
Quando *nomedamacro* é invocada, cada ocorrência de *string1* em sua definição de cadeia de caracteres é substituída por *string2*.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
$(macroname:string1=string2)  
```  
  
## <a name="remarks"></a>Comentários  
 Substituição de macro diferencia maiusculas de minúsculas e é literal; *string1* e *string2* não é possível invocar macros. Substituição não modifica a definição original. Você pode substituir o texto em qualquer macro predefinida exceto [ $$@ ](../build/filename-macros.md).  
  
 Sem espaços ou tabs precedem o vírgula; qualquer após os dois-pontos são interpretados como literal. Se *string2* é null, todas as ocorrências de *string1* serão excluídas da cadeia de caracteres de definição da macro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando uma macro NMAKE](../build/using-an-nmake-macro.md)