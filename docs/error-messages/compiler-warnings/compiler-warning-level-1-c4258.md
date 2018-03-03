---
title: "Compilador (nível 1) de aviso C4258 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4258
dev_langs:
- C++
helpviewer_keywords:
- C4258
ms.assetid: bbb75e6d-6693-4e62-8ed3-b006a0ec55e3
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 436ef3dd9984750885390a3974572b9d86bd7243
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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