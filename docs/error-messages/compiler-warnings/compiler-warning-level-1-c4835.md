---
title: "Compilador aviso (nível 1) C4835 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4835
dev_langs:
- C++
helpviewer_keywords:
- C4835
ms.assetid: d2e44c62-7b0e-4a45-943d-97903e27ed9d
caps.latest.revision: 11
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
ms.openlocfilehash: 7eff3fd7ab97b978ccc9e146eabf500c7dbedf0f
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4835"></a>Compilador C4835 de aviso (nível 1)
'variável': o inicializador de dados exportados não será executado até que o código gerenciado é executado pela primeira vez no assembly de host  
  
 Ao acessar dados entre componentes gerenciados, é recomendável que você não use nativo C++ importação e exportação mecanismos. Em vez disso, declare os membros de dados dentro de um tipo gerenciado e referencie os metadados com `#using` no cliente. Para obter mais informações, consulte [#using diretiva](../../preprocessor/hash-using-directive-cpp.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4835.  
  
```  
// C4835.cpp  
// compile with: /W1 /clr /LD  
int f() { return 1; }  
int n = 9;  
  
__declspec(dllexport) int m = f();   // C4835  
__declspec(dllexport) int *p = &n;   // C4835  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir consome o componente criado no exemplo anterior, indicando que o valor das variáveis não conforme o esperado.  
  
```  
// C4835_b.cpp  
// compile with: /clr C4835.lib  
#include <stdio.h>  
__declspec(dllimport) int m;  
__declspec(dllimport) int *p;  
  
int main() {  
   printf("%d\n", m);  
   printf("%d\n", p);  
}  
```  
  
```Output  
0  
268456008  
```
