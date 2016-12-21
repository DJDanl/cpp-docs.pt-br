---
title: "Erro do Compilador C3861 | Microsoft Docs"
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
  - "C3861"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3861"
ms.assetid: 0a1eee30-b3db-41b1-b1e5-35949c3924d7
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3861
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'identifier': identificador não encontrado  
  
 O compilador não pôde resolver uma referência a um identificador, mesmo usando pesquisa dependente de argumento.  
  
 Para corrigir esse erro, verifique se a declaração de identificador de caso e a ortografia.  Verifique [operadores de resolução de escopo](../../cpp/scope-resolution-operator.md) e namespace [usando diretivas](../../misc/using-directive-cpp.md) são usados corretamente.  Se o identificador for declarado em um arquivo de cabeçalho, verifique se o cabeçalho incluído antes de ser referenciado.  Verifique também se o identificador não é excluído por [diretivas de compilação condicional](../../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md).  
  
## Exemplo  
 O exemplo a seguir gera c3861:.  
  
```  
// C3861.cpp  
void f2(){}  
int main() {  
   f();   // C3861  
   f2();   // OK  
}  
```  
  
## Exemplo  
 Classes de exceção na biblioteca padrão C\+\+ passam para o `std` namespace.  
  
```  
// C3861_b.cpp  
// compile with: /EHsc  
#include <iostream>  
int main() {  
   try {  
      throw exception("Exception");   // C3861  
      // try the following line instead  
      // throw std::exception("Exception");  
   }  
   catch (...) {  
      std::cout << "caught an exception" << std::endl;  
   }  
}  
```