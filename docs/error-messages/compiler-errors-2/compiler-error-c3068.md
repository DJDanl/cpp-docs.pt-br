---
title: "Erro do Compilador C3068 | Microsoft Docs"
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
  - "C3068"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3068"
ms.assetid: 613e3447-b4a8-4268-a661-297bed63ccdf
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3068
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: uma função “despida” não pode conter objetos que exigem o desenrolamento se a exceção ocorreu criando c  
  
 O compilador não pôde executar a pilha que desenrola em uma função de [despido](../Topic/naked%20\(C++\).md) que jogasse uma exceção porque um objeto temporário foi criado na função e manipulação de exceção de[\/EHsc](../../build/reference/eh-exception-handling-model.md)\(C\+\+\) foi especificado.  
  
 Para resolver esse erro, siga pelo menos um dos seguintes:  
  
-   Não compile com \/EHsc.  
  
-   Não marque a função como `naked`.  
  
-   Não crie um objeto temporário na função.  
  
 Se uma função cria um objeto temporário na pilha, se a função gerou uma exceção, e se a manipulação de exceção C\+\+ está habilitada, o compilador limpará a pilha se uma exceção é gerada.  
  
 Quando uma exceção é gerada, o código gerado o compilador, chamou o prólogo e o epílogo e que não estão presentes em uma função despida, é executado para uma função.  
  
## Exemplo  
 O seguinte exemplo gera C3068:  
  
```  
// C3068.cpp  
// compile with: /EHsc  
// processor: x86  
class A {  
public:  
   A(){}  
   ~A(){}  
};  
  
void b(A){}  
  
__declspec(naked) void c() {  
   b(A());   // C3068   
};  
```