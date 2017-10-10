---
title: C2383 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2383
dev_langs:
- C++
helpviewer_keywords:
- C2383
ms.assetid: 6696221d-879c-477a-a0f3-a6edc15fd3d7
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 20f6fa7626541f5fcd06bc2c2c513f52ec443ba4
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2383"></a>C2383 de erro do compilador
'*símbolo*': argumentos padrão não são permitidos neste símbolo  
  
 O compilador do C++ não permitem argumentos padrão em ponteiros para funções.  
  
 Este código foi aceita pelo compilador do Visual C++ em versões anteriores do Visual Studio 2005, mas agora oferece um erro. Para o código que funciona em todas as versões do Visual C++, não atribua um valor padrão para um argumento de ponteiro de função.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2383 e mostra uma possível solução:  
  
```cpp  
// C2383.cpp  
// compile with: /c   
void (*pf)(int = 0);   // C2383  
void (*pf)(int);   // OK  
```
