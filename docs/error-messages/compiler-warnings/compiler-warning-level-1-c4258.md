---
title: "Compilador aviso (nível 1) C4258 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4258
dev_langs:
- C++
helpviewer_keywords:
- C4258
ms.assetid: bbb75e6d-6693-4e62-8ed3-b006a0ec55e3
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0f3da4315033fe33282526c6a67de6b6666c8604
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4258"></a>Compilador C4258 de aviso (nível 1)
'variável': definição do loop é ignorado; a definição de escopo delimitador é usada"  
  
 Em [/Ze](../../build/reference/za-ze-disable-language-extensions.md) e [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md), variáveis definidas em uma [para](../../cpp/for-statement-cpp.md) loop saem do escopo após o **para** loop termina. Este aviso ocorre se uma variável com o mesmo nome da variável de loop, mas definido no loop delimitador, é usada novamente no escopo que contém o **para** loop. Por exemplo:  
  
```  
// C4258.cpp  
// compile with: /Zc:forScope /W1  
int main()  
{  
   int i;  
   {  
      for (int i =0; i < 1; i++)  
         ;  
      i = 20;   // C4258 i (in for loop) has gone out of scope  
   }  
}  
```
