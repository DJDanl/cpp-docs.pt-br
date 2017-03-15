---
title: "Compilador aviso (nível 4) C4205 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4205
dev_langs:
- C++
helpviewer_keywords:
- C4205
ms.assetid: 39b5108c-7230-41b4-b2fe-2293eb6aae28
caps.latest.revision: 7
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
ms.openlocfilehash: a80839d5c052ef0e52526cea6adcba68994d8de9
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4205"></a>Compilador C4205 de aviso (nível 4)
extensão não padrão usada : declaração de função static em escopo de função  
  
 Com extensões da Microsoft (/Ze) **estático** funções podem ser declaradas dentro de outra função. A função tem escopo global.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4205.c  
// compile with: /W4  
void func1()  
{  
   static int func2();  // C4205  
};  
  
int main()  
{  
}  
```  
  
 Inicializações são inválidas em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).
