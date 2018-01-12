---
title: "Compilador (nível 1) de aviso C4218 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4218
dev_langs: C++
helpviewer_keywords: C4218
ms.assetid: d6c3cd90-4518-49e9-ae86-4ba9e2761d98
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 156a43f57f52f50f6542f3502658d5e0e16f1bd9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4218"></a>Compilador C4218 de aviso (nível 1)
extensão não padrão usada: deve especificar pelo menos uma classe de armazenamento ou um tipo  
  
 Com as extensões do Microsoft padrão (/Ze), você pode declarar uma variável sem especificar uma classe de armazenamento ou do tipo. O tipo padrão é `int`.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4218.c  
// compile with: /W4  
i;  // C4218  
  
int main()  
{  
}  
```  
  
 Essas declarações são inválidas em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).