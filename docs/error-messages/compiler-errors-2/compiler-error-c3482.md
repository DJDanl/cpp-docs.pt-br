---
title: C3482 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3482
dev_langs: C++
helpviewer_keywords: C3482
ms.assetid: bf99558e-bef4-421c-bb16-dcd9c54c1011
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4ff7a17d663be7168c5743838d782043d7c0ee92
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3482"></a>C3482 de erro do compilador
'this' só pode ser usado como uma captura de lambda dentro de uma função de membro não estático  
  
 Você não pode passar `this` à lista de captura de uma expressão lambda que é declarada em um método estático ou uma função global.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
-   Converter a função delimitador para um método não estático, ou  
  
-   Remover o `this` ponteiro da lista de captura da expressão lambda.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3482:  
  
```  
// C3482.cpp  
// compile with: /c  
  
class C  
{  
public:  
   static void staticMethod()  
   {  
      [this] {}(); // C3482  
   }  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)