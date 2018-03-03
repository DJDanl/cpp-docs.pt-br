---
title: "Compilador (nível 1) de aviso C4835 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4835
dev_langs:
- C++
helpviewer_keywords:
- C4835
ms.assetid: d2e44c62-7b0e-4a45-943d-97903e27ed9d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 92e2d17ada58773a34d8c2d14424dd88e74a06d3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4835"></a>Compilador C4835 de aviso (nível 1)
'variável': o inicializador para dados exportados não será executado até que o código gerenciado é executado pela primeira vez no host assembly  
  
 Ao acessar dados entre os componentes gerenciados, é recomendável que você não usa a importação de C++ nativo e mecanismos de exportação. Em vez disso, declara os membros de dados dentro de um tipo gerenciado e fazer referência o metadados com `#using` no cliente. Para obter mais informações, consulte [#using diretiva](../../preprocessor/hash-using-directive-cpp.md).  
  
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
 O exemplo a seguir utiliza o componente criado no exemplo anterior, indicando que o valor das variáveis não conforme o esperado.  
  
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