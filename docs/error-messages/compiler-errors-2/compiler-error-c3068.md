---
title: C3068 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 1b86e93da3900c7735fe9ff4a7ee4fc9903e5e9a
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3068"></a>C3068 de erro do compilador
'function': uma função 'naked' não pode conter objetos que exigem desenrolamento se ocorreu uma exceção de C++  
  
 O compilador não pôde executar o desenrolamento de pilha em uma [naked](../../cpp/naked-cpp.md) função que lançou uma exceção porque foi criado um objeto temporário na função e tratamento de exceções C++ ([/EHsc](../../build/reference/eh-exception-handling-model.md)) foi especificado.  
  
 Para resolver esse erro, faça pelo menos um dos seguintes:  
  
-   Não compile com /EHsc.  
  
-   Não marque-a como `naked`.  
  
-   Não crie um objeto temporário na função.  
  
 Se uma função cria um objeto temporário na pilha, se a função lançará uma exceção, e se o tratamento de exceções C++ estiver habilitado, o compilador irá limpar a pilha se uma exceção é lançada.  
  
 Quando uma exceção é lançada, compilador gerado código, chamado de prólogo e epílogo e que não estão presente em uma função naked, é executada para uma função.  
  
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
