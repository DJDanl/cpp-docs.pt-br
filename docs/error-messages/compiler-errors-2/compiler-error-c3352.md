---
title: C3352 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3352
dev_langs:
- C++
helpviewer_keywords:
- C3352
ms.assetid: f233bed7-474e-425f-aad2-7801578169d4
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 65643abc883cfd0674dbb908c8ab26f274f65cd4
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3352"></a>C3352 de erro do compilador
'function': a função especificada não coincide com o tipo delegado 'type'  
  
 A lista de parâmetros para `function` e o representante não coincidem.  
  
 Para obter mais informações, consulte [delegado (extensões de componentes C++)](../../windows/delegate-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3352:  
  
```  
// C3352.cpp  
// compile with: /clr  
delegate int D( int, int );  
ref class C {  
public:  
   int mf( int ) {  
      return 1;  
   }  
  
   // Uncomment the following line to resolve.  
   // int mf(int, int) { return 1; }  
};  
  
int main() {  
   C^ pC = gcnew C;  
   System::Delegate^ pD = gcnew D( pC, &C::mf );   // C3352  
}  
```  

