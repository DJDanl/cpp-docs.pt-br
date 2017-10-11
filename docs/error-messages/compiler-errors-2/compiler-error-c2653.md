---
title: C2653 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2653
dev_langs:
- C++
helpviewer_keywords:
- C2653
ms.assetid: 3f49e731-affd-43a0-a8d0-181db7650bc3
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: cc7990614283a20e9d07f52187258dbccad7c075
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2653"></a>C2653 de erro do compilador
'Identificador': não é um nome de classe ou namespace  
  
Sintaxe requer uma classe, estrutura, união ou nome de namespace.  
  
O exemplo a seguir gera C2653:  
  
```cpp  
// C2653.cpp  
// compile with: /c  
class yy {  
   void func1(int i);  
};  
  
void xx::func1(int m) {}   // C2653  
void yy::func1(int m) {}   // OK  
```  
  
C2653 também é possível se você tentar definir um *composta namespace*, um namespace que contém um ou mais nomes de namespace aninhado de escopo, quando você usa uma versão do Visual C++ antes da atualização 3 do Visual Studio 2015. Composta namespace não são permitidas definições em C++ antes de C++ 17. A partir do Visual C++ 2015 atualização 3, o compilador suporta as definições do namespace composta quando o [/std:c + + mais recente](../../build/reference/std-specify-language-standard-version.md) opção de compilador é especificada:  
```cpp  
// C2653b.cpp  
namespace a::b {int i;}   // C2653 prior to Visual C++ 2015 Update 3,  
                          // C2429 thereafter. Use /std:c++latest to fix.
namespace a {  
   namespace b {  
      int i;  
   }  
}  
  
int main() {  
   a::b::i = 2;  
}  
```  
