---
title: "Erro do Compilador C3535 | Microsoft Docs"
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
  - "C3535"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3535"
ms.assetid: 24449c98-f681-484d-a00b-32533dca3a88
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3535
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não pode deduzir o tipo para o tipo “\- 1 " do tipo “\- 2 "  
  
 O tipo da variável declarada pela palavra\-chave de `auto` não for possível deduzir do tipo da expressão de inicialização.  Por exemplo, esse erro ocorre se a expressão de inicialização avalia a `void`, que não é um tipo.  
  
### Para corrigir este erro  
  
1.  Verifique se o tipo da expressão de inicialização não é `void`.  
  
2.  Verifique se a declaração não é um ponteiro para um tipo fundamental.  Para obter mais informações, consulte [Tipos fundamentais](../../cpp/fundamental-types-cpp.md).  
  
3.  Certifique\-se de que se a declaração é um ponteiro para um tipo, a expressão de inicialização é um tipo de ponteiro.  
  
## Exemplo  
 O exemplo a seguir gerencie C3535 porque a expressão de inicialização avalia a `void`.  
  
```  
// C3535a.cpp  
// Compile with /Zc:auto  
void f(){}  
int main()  
{  
   auto x = f();   //C3535  
   return 0;  
}  
```  
  
## Exemplo  
 O exemplo a seguir gerencie C3535 porque a instrução a seguir declara `x` variável porque um ponteiro para um tipo deduzido, mas o tipo da expressão de inicializador é duplas.  Em virtude disso, o compilador não puder deduzir o tipo da variável.  
  
```  
// C3535b.cpp  
// Compile with /Zc:auto  
int main()  
{  
   auto* x = 123.0;   // C3535  
   return 0;  
}  
```  
  
## Exemplo  
 O exemplo a seguir gerencie C3535 porque `p` variável declara um ponteiro para um tipo deduzido, mas a expressão de inicialização não é um tipo de ponteiro.  
  
```  
// C3535c.cpp  
// Compile with /Zc:auto  
class A { };  
A x;  
auto *p = x;  // C3535  
```  
  
## Consulte também  
 [Palavra\-chave auto](../../cpp/auto-keyword.md)   
 [Tipos fundamentais](../../cpp/fundamental-types-cpp.md)