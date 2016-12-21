---
title: "Aviso LNK4248 (Ferramentas de Vinculador) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK4248"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4248"
ms.assetid: e40523ff-e3cb-4ba6-ab79-23f0f339f6cf
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4248 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

token não resolvido do token typeref \(\) para o tipo”; “ a imagem não pode executar  
  
 Um tipo não tiver uma definição de metadados de MSIL.  
  
 LNK4248 pode ocorrer quando há somente uma declaração frente de um tipo em um módulo de MSIL \(compilado com **\/clr**\), onde o tipo é referenciado no módulo de MSIL, e onde o módulo de MSIL é vinculado a um módulo nativo que tenha uma definição do tipo.  
  
 Nessa situação, o vinculador fornecerá a definição de tipo nativo nos metadados de MSIL, e isso pode prever o comportamento correto.  
  
 No entanto, se uma declaração de tipo antecipada é um tipo CLR, a definição de tipo nativo do vinculador pode não estar correto  
  
 Para obter mais informações, consulte [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
### Para corrigir este erro  
  
1.  Fornecer a definição de tipo no módulo de MSIL.  
  
## Exemplo  
 O exemplo a seguir produz LNK4248.  Define o struct A para resolver.  
  
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
  
## Exemplo  
 O exemplo a seguir tem uma definição frente de um tipo.  
  
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
  
## Exemplo  
 O exemplo a seguir produz LNK4248.  
  
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