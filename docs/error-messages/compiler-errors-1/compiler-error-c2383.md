---
title: C2383 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2383
dev_langs:
- C++
helpviewer_keywords:
- C2383
ms.assetid: 6696221d-879c-477a-a0f3-a6edc15fd3d7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 81624ccd7f4857cb2f7d8474d393a9743ab1a2b3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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