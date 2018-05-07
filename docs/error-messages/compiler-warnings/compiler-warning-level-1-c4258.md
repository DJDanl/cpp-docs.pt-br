---
title: Compilador (nível 1) de aviso C4258 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4258
dev_langs:
- C++
helpviewer_keywords:
- C4258
ms.assetid: bbb75e6d-6693-4e62-8ed3-b006a0ec55e3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 08a182ed592119fd52247737988810f9ca66b45c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4258"></a>Compilador C4258 de aviso (nível 1)
'variável': definição a partir de loop é ignorado; a definição do escopo delimitador é usada"  
  
 Em [/Ze](../../build/reference/za-ze-disable-language-extensions.md) e [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md), as variáveis definidas em um [para](../../cpp/for-statement-cpp.md) loop estar fora do escopo após a **para** loop termina. Este aviso ocorre se uma variável com o mesmo nome da variável de loop, mas definido no loop delimitador, é usada novamente no escopo que contém o **para** loop. Por exemplo:  
  
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