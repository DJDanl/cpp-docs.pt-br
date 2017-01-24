---
title: "Erro do Compilador C3409 | Microsoft Docs"
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
  - "C3409"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3409"
ms.assetid: e372d9fa-230c-4b28-b6d3-6ad81ccf9dbb
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3409
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

empty o bloco do atributo não é permitido  
  
 Os colchetes são interpretados pelo compilador como um bloco de [atributo](../../windows/cpp-attributes-reference.md) , mas nenhum atributo for localizado.  
  
 O compilador pode gerar esse erro quando você usa colchetes como parte da definição de uma expressão de lambda.  Esse erro ocorre quando o compilador não pode determinar se os colchetes são parte da definição de uma expressão de lambda ou bloco do atributo.  Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).  
  
### Para corrigir este erro  
  
1.  Se os colchetes são parte de um bloco de atributo:  
  
    1.  Fornecer um ou mais atributos no bloco do atributo.  
  
    2.  Remover o pacote do atributo.  
  
2.  Se os colchetes são parte de uma expressão de lambda:  
  
    1.  Verifique se a expressão de lambda válidos segue regras de sintaxe.  
  
         Para obter mais informações sobre a sintaxe da expressão de lambda, consulte [Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md).  
  
## Exemplo  
 O exemplo a seguir gerenciar C3409.  
  
```  
// C3409.cpp  
// compile with: /c  
#include <windows.h>  
[]   // C3409  
class a {};  
  
// OK  
[object, uuid("00000000-0000-0000-0000-000000000000")]  
__interface x {};  
  
[coclass, uuid("00000000-0000-0000-0000-000000000001")]  
class b : public x {};  
```  
  
## Exemplo  
 O exemplo C3409 gerencie como uma expressão de lambda usa a especificação de `mutable` , mas não fornece uma lista de parâmetros.  O compilador não pode determinar se os colchetes são parte da definição de uma expressão de lambda ou bloco do atributo.  
  
```  
// C3409b.cpp  
  
int main()  
{  
   [] mutable {}();  
}  
```  
  
## Consulte também  
 [atributo](../../windows/cpp-attributes-reference.md)   
 [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)   
 [Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md)