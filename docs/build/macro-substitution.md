---
title: "Substituição de macro | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- NMAKE program, macro substitution
- macros, NMAKE
- substitution macros in NMAKE
ms.assetid: 47465cfe-fd92-49db-aebe-7c2d7ecceb73
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: d8e63e071629c2647ccd8f89095fbc7c2285f1a6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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