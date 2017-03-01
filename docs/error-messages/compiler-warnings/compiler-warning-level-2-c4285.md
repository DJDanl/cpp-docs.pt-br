---
title: "Compilador aviso (nível 2) C4285 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4285
dev_langs:
- C++
helpviewer_keywords:
- C4285
ms.assetid: fa14de1f-fc19-4eec-8bea-81003636e12f
caps.latest.revision: 6
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
ms.openlocfilehash: 2de96d76b28d1e1798591beca70e7f6247710386
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-2-c4285"></a>Compilador C4285 de aviso (nível 2)
tipo de retorno para ' identifier::operator – >' é recursiva se aplicadas usando a notação de infixo  
  
 Especificado **operator–>()** função não pode retornar o tipo para o qual ela está definida ou uma referência para o tipo para o qual ela está definida.  
  
 O exemplo a seguir gera C4285:  
  
```  
// C4285.cpp  
// compile with: /W2  
class C  
{  
public:  
    C operator->();   // C4285  
   // C& operator->();  C4285, also  
};  
  
int main()  
{  
}  
```
