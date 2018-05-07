---
title: Compilador aviso (nível 3) C4240 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4240
dev_langs:
- C++
helpviewer_keywords:
- C4240
ms.assetid: a2657cdb-18e1-493f-882b-4e10c0bca71d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4f0691230454ffd935d67c99f58b857cdc1ce0f0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-3-c4240"></a>Compilador C4240 de aviso (nível 3)
extensão não padrão usada: acesso a 'classname' agora definido como 'especificador de acesso,' anteriormente foi definido para ser o especificador de acesso  
  
 Em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), você não pode alterar o acesso a uma classe aninhada. Sob as extensões do Microsoft padrão (/Ze), você pode, com este aviso.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4240.cpp  
// compile with: /W3  
class X  
{  
private:  
   class N;  
public:  
   class N  
   {   // C4240  
   };  
};  
  
int main()  
{  
}  
```