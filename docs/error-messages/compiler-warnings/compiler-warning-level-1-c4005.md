---
title: "Compilador (nível 1) de aviso C4005 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4005
dev_langs:
- C++
helpviewer_keywords:
- C4005
ms.assetid: 7f2dc79a-9fcb-4d5b-be61-120d9cb487ad
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 21023cf79a2ec25f94dc68cd3a55f722fa8316d8
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-warning-level-1-c4005"></a>Compilador C4005 de aviso (nível 1)
'Identificador': redefinição de macro  
  
 O identificador de macro definido duas vezes. O compilador usa a segunda definição de macro.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Definindo uma macro na linha de comando e no código com um `#define` diretiva.  
  
2.  Macros importadas de arquivos de inclusão.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Remova uma das definições.  
  
2.  Use um [#undef](../../preprocessor/hash-undef-directive-c-cpp.md) diretiva antes da definição de segundo.  
  
 O exemplo a seguir gera C4005:  
  
```  
// C4005.cpp  
// compile with: /W1 /EHsc  
#include <iostream>  
using namespace std;  
  
#define TEST "test1"  
#define TEST "test2"   // C4005 delete or rename to resolve the warning  
  
int main() {  
   cout << TEST << endl;  
}  
```
