---
title: Aviso LNK4248 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4248
dev_langs:
- C++
helpviewer_keywords:
- LNK4248
ms.assetid: e40523ff-e3cb-4ba6-ab79-23f0f339f6cf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e3b67661d1ad260f388f8425420711ae2f708ce3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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