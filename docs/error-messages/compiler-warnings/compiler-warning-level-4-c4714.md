---
title: Compilador (nível 4) de aviso C4714 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4714
dev_langs:
- C++
helpviewer_keywords:
- C4714
ms.assetid: 22c7fd0c-899d-4e9b-95f3-725b2c49fb46
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f0f327e7ffc5d2fe00abe3c0845af10a846243bf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4714"></a>Compilador C4714 de aviso (nível 4)
função 'function' marcada como forceinline não embutida  
  
 A função fornecida foi selecionada para expansão embutida, mas o compilador não executou o inlining.  
  
 Embora `__forceinline` é uma indicação mais forte para o compilador que `__inline`, inlining ainda é realizada a critério do compilador, mas nenhum heurística é usadas para determinar os benefícios de inlining essa função.  
  
 Em alguns casos, o compilador será embutido não uma função específica por motivos mecânicos. Por exemplo, o compilador vai não embutido:  
  
-   Uma função se resultaria em combinação SEH e C++ EH.  
  
-   Algumas funções de cópia construído objetos passados por valor quando o /EHS / - GX//EHa está ativado.  
  
-   Funções que retornam um objeto unwindable por valor quando o /EHS / - GX//EHa está ativado.  
  
-   Funções com assembly embutido ao compilar sem - Og/Ox/O1/O2.  
  
-   Funções com uma lista de argumentos variável.  
  
-   Uma função com um **tente** instrução (tratamento de exceções C++).  
  
 O exemplo a seguir gera C4714:  
  
```  
// C4714.cpp  
// compile with: /Ob1 /GX /W4  
__forceinline void func1()  
{  
   try  
   {  
   }  
   catch (...)  
   {  
   }  
}  
  
void func2()  
{  
   func1();   // C4714  
}  
  
int main()  
{  
}  
```