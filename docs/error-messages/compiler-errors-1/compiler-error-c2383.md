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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0d9cbb01d1ad0f2ea65d59334cb88140ef18fce0
ms.openlocfilehash: faa2aa2c29ea34009f0812a3796d450a6877ca48
ms.contentlocale: pt-br
ms.lasthandoff: 04/12/2017

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
