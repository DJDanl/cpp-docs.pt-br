---
title: C2392 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2392
dev_langs: C++
helpviewer_keywords: C2392
ms.assetid: 98ced473-6383-46ed-b79c-21857d65dcb2
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 04fecba855d986c735a64ada77d81a28485fc161
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2392"></a>C2392 de erro do compilador
'method1': retornos covariantes tipos não têm suporte no gerenciados ou WinRTtypes, caso contrário 'method2' poderia ser substituído  
  
 Tipos de retorno covariante não são permitidos para funções de membro de tempo de execução do Windows ou ao compilar com o [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) opção.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2392 e mostra como corrigi-lo.  
  
```  
// C2392.cpp  
// compile with: /clr  
public ref struct B {  
public:  
   int i;  
};  
  
public ref struct D: public B{};  
  
public ref struct B1 {  
public:  
   virtual B^ mf() {  
      B^ pB = gcnew B;  
      pB->i = 11;  
      return pB;  
   }  
};  
  
public ref struct D1: public B1 {  
public:  
   virtual D^ mf() override {  // C2392  
   // try the following line instead  
   // virtual B^ mf() override {  
   // return type D^ is covariant with B^, not allowed with CLR types  
      D^ pD = gcnew D;  
      pD->i = 12;  
      return pD;  
   }  
};  
  
int main() {  
   B1^ pB1 = gcnew D1;  
   B^ pB = pB1->mf();  
   D^ pD = dynamic_cast<D^>(pB);  
}  
```