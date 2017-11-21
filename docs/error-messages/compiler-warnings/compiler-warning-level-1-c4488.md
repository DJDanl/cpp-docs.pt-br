---
title: "Compilador (nível 1) de aviso C4488 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4488
dev_langs: C++
helpviewer_keywords: C4488
ms.assetid: 55625e46-ddb5-4c7c-99c7-cd4aa9f879bd
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1312d279eb9174e0863cae413a0014cc58710131
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4488"></a>Compilador C4488 de aviso (nível 1)
'function': requer a palavra-chave 'palavra-chave' para implementar o método de interface 'interface_method'  
  
 Uma classe deve implementar todos os membros da interface da qual ela herda diretamente. Um membro implementado deve ter acessibilidade pública e deve ser marcado como virtual.  
  
## <a name="example"></a>Exemplo  
 C4488 pode ocorrer se um membro de implementado não é público. O exemplo a seguir gera C4488.  
  
```  
// C4488.cpp  
// compile with: /clr /c /W1 /WX  
interface struct MyI {  
   void f1();  
};  
  
// implemented member not public  
ref class B : MyI { virtual void f1() {} };  // C4488  
  
// OK  
ref class C : MyI {  
public:  
   virtual void f1() {}  
};  
```  
  
## <a name="example"></a>Exemplo  
 C4488 pode ocorrer se um membro de implementado não está marcado como virtual. O exemplo a seguir gera C4488.  
  
```  
// C4488_b.cpp  
// compile with: /clr /c /W1 /WX  
interface struct MyI {  
   void f1();  
};  
  
ref struct B : MyI { void f1() {} };   // C4488  
ref struct C : MyI { virtual void f1() {} };   // OK  
```