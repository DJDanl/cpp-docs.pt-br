---
title: C2107 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2107
dev_langs: C++
helpviewer_keywords: C2107
ms.assetid: 2866a121-884e-4bb5-8613-36de5817000e
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d6123da392cc6437593b0805c5bc6e94f450e282
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2107"></a>C2107 de erro do compilador
índice inválido, indireção não permitida  
  
 Um subscrito é aplicado a uma expressão que não é avaliada como um ponteiro.  
  
## <a name="example"></a>Exemplo  
 C2107 pode ocorrer se você usar incorretamente o `this` ponteiro de um tipo de valor para o indexador de padrão do tipo de acesso. Para obter mais informações, consulte [semântica do ponteiro](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Semantics_of_the_this_pointer).  
  
 O exemplo a seguir gera C2107.  
  
```  
// C2107.cpp  
// compile with: /clr  
using namespace System;  
  
value struct B {  
   property String ^ default[String ^] {  
      String ^ get(String ^ data) {  
         return "abc";  
      }  
   }  
   void Test() {  
      Console::WriteLine("{0}", this["aa"]);   // C2107  
      Console::WriteLine("{0}", this->default["aa"]);   // OK  
   }  
};  
  
int main() {  
   B ^ myb = gcnew B();  
   myb->Test();  
}  
```