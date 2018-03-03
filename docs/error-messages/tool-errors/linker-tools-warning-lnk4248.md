---
title: Aviso LNK4248 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4248
dev_langs:
- C++
helpviewer_keywords:
- LNK4248
ms.assetid: e40523ff-e3cb-4ba6-ab79-23f0f339f6cf
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 01053ddbbb0c7d234f6b465392f5bbe991ea329c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4248"></a>Aviso LNK4248 (Ferramentas de Vinculador)
token typeref indefinido (token) para 'type'; imagem não pode ser executada  
  
 Um tipo não tem uma definição em metadados MSIL.  
  
 LNK4248 pode ocorrer quando há somente uma declaração de encaminhamento de um tipo em um módulo MSIL (compilado com **/clr**), onde o tipo é referenciado no módulo MSIL, e o módulo MSIL é vinculado a um módulo nativo que tenha uma definição para o tipo.  
  
 Nessa situação, o vinculador fornecerá a definição de tipo nativo nos metadados do MSIL, e isso pode fornecer para o comportamento correto.  
  
 No entanto, se uma declaração de tipo de encaminhamento é um tipo CLR, em seguida, definição de tipo nativo do vinculador pode não estar correta  
  
 Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Fornece a definição de tipo no módulo MSIL.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK4248. Defina A estrutura para resolver.  
  
```  
// LNK4248.cpp  
// compile with: /clr /W1  
// LNK4248 expected  
struct A;  
void Test(A*){}  
  
int main() {  
   Test(0);  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir tem uma definição direta de um tipo.  
  
```  
// LNK4248_2.cpp  
// compile with: /clr /c  
class A;   // provide a definition for A here to resolve  
A * newA();  
int valueA(A * a);  
  
int main() {  
   A * a = newA();  
   return valueA(a);  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK4248.  
  
```  
// LNK4248_3.cpp  
// compile with: /c  
// post-build command: link LNK4248_2.obj LNK4248_3.obj  
class A {  
public:   
   int b;  
};  
  
A* newA() {  
   return new A;  
}  
  
int valueA(A * a) {  
   return (int)a;  
}  
```