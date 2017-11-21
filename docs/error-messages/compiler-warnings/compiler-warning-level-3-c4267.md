---
title: "Compilador aviso (nível 3) C4267 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4267
dev_langs: C++
helpviewer_keywords: C4267
ms.assetid: 2fa2f13f-fa4f-47bb-ad8f-6cb19cfc91e6
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: fd30633dcf38a3f6e7a65ee1f2046c1d8731f114
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-3-c4267"></a>Compilador C4267 de aviso (nível 3)
'var': conversão de 'size_t' para 'type', possível perda de dados  
  
 O compilador detectou uma conversão de `size_t` para um tipo menor.  
  
 Para corrigir esse aviso, use `size_t` em vez de `type`. Como alternativa, use um tipo integral é pelo menos tão grande quanto `size_t`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4267.  
  
```  
// C4267.cpp  
// compile by using: cl /W4 C4267.cpp  
void Func1(short) {}  
void Func2(int) {}  
void Func3(long) {}  
void Func4(size_t) {}  
  
int main() {  
   size_t bufferSize = 10;  
   Func1(bufferSize);   // C4267 for all platforms  
   Func2(bufferSize);   // C4267 only for 64-bit platforms  
   Func3(bufferSize);   // C4267 only for 64-bit platforms  
   Func4(bufferSize);   // OK for all platforms  
}  
```