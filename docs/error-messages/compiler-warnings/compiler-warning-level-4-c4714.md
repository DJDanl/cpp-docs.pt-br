---
title: "Compilador aviso (nível 4) C4714 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4714
dev_langs:
- C++
helpviewer_keywords:
- C4714
ms.assetid: 22c7fd0c-899d-4e9b-95f3-725b2c49fb46
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
ms.openlocfilehash: 8e98b52b5344f4b590ff35bdd58d8861d776589e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4714"></a>Compilador C4714 de aviso (nível 4)
função 'function' marcado como forceinline não embutida  
  
 A função fornecida foi selecionada para a expansão embutida, mas o compilador não executou o inlining.  
  
 Embora `__forceinline` é uma indicação mais forte para o compilador que `__inline`, inlining ainda é realizada a critério do compilador, mas nenhum heurística é usada para determinar os benefícios de inlining essa função.  
  
 Em alguns casos, o compilador criará não embutir uma função específica por motivos mecânicos. Por exemplo, o compilador não embutirá:  
  
-   Uma função se resultaria na combinação de SEH e C++ EH.  
  
-   Algumas funções de cópia criada objetos passados por valor quando EHs / - GX//EHa está ativado.  
  
-   Funções que retornam um objeto liberáveis por valor quando EHs / - GX//EHa está ativado.  
  
-   Funções com assembly embutido ao compilar sem - Og/Ox/O1/O2.  
  
-   Funções com uma lista de argumentos variável.  
  
-   Uma função com um **tente** instrução (manipulação de exceção C++).  
  
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
