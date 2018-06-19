---
title: Compilador (nível 4) de aviso C4205 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4205
dev_langs:
- C++
helpviewer_keywords:
- C4205
ms.assetid: 39b5108c-7230-41b4-b2fe-2293eb6aae28
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fc8c811fd8d67964bdef8149aea09d83e4649b99
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33292760"
---
# <a name="compiler-warning-level-4-c4205"></a>Compilador C4205 de aviso (nível 4)
extensão não padrão usada: declaração de função estática no escopo de função  
  
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
  
 Inicializações são inválidas em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).