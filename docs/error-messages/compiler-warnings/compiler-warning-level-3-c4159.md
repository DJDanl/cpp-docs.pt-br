---
title: Compilador aviso (nível 3) C4159 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4159
dev_langs:
- C++
helpviewer_keywords:
- C4159
ms.assetid: e2cf964e-f4b8-4b2c-9569-1abb94307232
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 139a21f5fbb7ce279d96f9df8be6008c2f092287
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-3-c4159"></a>Compilador C4159 de aviso (nível 3)
\#pragma pragma(pop,...): identificador anteriormente enviado 'Identificador' ser exibido  
  
 Seu código-fonte contém um **push** instrução com um identificador para um pragma seguido por um **pop** instrução sem um identificador. Como resultado, ***identificador*** é exibidos e subsequentes usos de ***identificador*** pode causar um comportamento inesperado.  
  
 Para evitar este aviso, forneça um identificador no **pop** instrução. Por exemplo:  
  
```  
// C4159.cpp  
// compile with: /W3  
#pragma pack(push, f)  
#pragma pack(pop)   // C4159  
  
// using the identifier resolves the warning  
// #pragma pack(pop, f)  
  
int main()  
{  
}  
```