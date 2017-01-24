---
title: "Erro do Compilador C3821 | Microsoft Docs"
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
  - "C3821"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3821"
ms.assetid: 2b327c7a-5faf-443c-ae82-944fae25b4df
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3821
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: o tipo gerenciado ou função não podem ser usados em uma função não gerenciado  
  
 As funções com assembly embutido ou [setjmp](../../c-runtime-library/reference/setjmp.md) não podem conter tipos de valor ou classes gerenciadas.  Para corrigir esse erro, remova o assembly embutido e `setjmp` ou remover objetos gerenciados.  
  
 C3821 também poderá ocorrer se você tentar usar o armazenamento automático em uma função de vararg.  Para obter mais informações, consulte [Variable Argument Lists \(...\) \(C\+\+\/CLI\)](../../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md) e [Semântica da pilha do C\+\+ para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).  
  
## Exemplo  
 O exemplo a seguir produz C3821.  
  
```  
// C3821a.cpp  
// compile with: /clr /c  
public ref struct R {};  
void test1(...) {  
   R r;   // C3821  
}  
```  
  
## Exemplo  
 O exemplo a seguir produz C3821.  
  
```  
// C3821b.cpp  
// compile with: /clr  
// processor: /x86  
ref class A {  
   public:  
   int i;  
};  
  
int main() {  
   // cannot use managed classes in this function  
   A ^a;     
  
   __asm {  
      nop  
   }  
} // C3821  
```  
  
## Exemplo  
 O exemplo a seguir produz C3821.  
  
```  
// C3821c.cpp  
// compile with: /clr:oldSyntax  
// processor: /x86  
__gc  class A {  
   public:  
   int i;  
};  
  
int main() {  
   // cannot use managed classes in this function  
   A *a;     
  
   __asm {  
      nop  
   }  
} // C3821  
```