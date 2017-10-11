---
title: C3068 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3068
dev_langs:
- C++
helpviewer_keywords:
- C3068
ms.assetid: 613e3447-b4a8-4268-a661-297bed63ccdf
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 413376428e33cbc703b3371589777ba4fed0c1f7
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3068"></a>C3068 de erro do compilador
'function': uma função 'naked' não pode conter objetos que possam requerer liberação caso uma exceção de C++  
  
 O compilador não pôde executar o desenrolamento de pilha em uma [naked](../../cpp/naked-cpp.md) função que gerou uma exceção porque um objeto temporário foi criado na função e tratamento de exceções C++ ([/EHsc](../../build/reference/eh-exception-handling-model.md)) foi especificado.  
  
 Para resolver esse erro, faça pelo menos um dos seguintes:  
  
-   Não compile com /EHsc.  
  
-   Não marque-a como `naked`.  
  
-   Não crie um objeto temporário na função.  
  
 Se uma função cria um objeto temporário na pilha, se a função gera uma exceção, e se o tratamento de exceções C++ estiver habilitado, o compilador limpará a pilha se uma exceção for lançada.  
  
 Quando uma exceção é gerada, compilador gerado código, chamado de prólogo e epílogo e que não estão presentes em uma função naked, é executado para uma função.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3068:  
  
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
