---
title: Compilador (nível 1) de aviso C4005 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4005
dev_langs:
- C++
helpviewer_keywords:
- C4005
ms.assetid: 7f2dc79a-9fcb-4d5b-be61-120d9cb487ad
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3a06ea88dab6ac7e89f7d53351b54593fd7bd232
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33275370"
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