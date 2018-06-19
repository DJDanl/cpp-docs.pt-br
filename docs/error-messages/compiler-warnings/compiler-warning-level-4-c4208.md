---
title: Compilador (nível 4) de aviso C4208 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4208
dev_langs:
- C++
helpviewer_keywords:
- C4208
ms.assetid: 5cb0a36e-3fb5-422f-a5f9-e40b70776c27
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b61f8b0a6a0ac61982bee79abb81f083d40a48f1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33292357"
---
# <a name="compiler-warning-level-4-c4208"></a>Compilador C4208 de aviso (nível 4)
extensão não padrão usada: excluir [exp] - exp avaliado, mas ignorado  
  
 Extensões da Microsoft (/Ze), é possível excluir uma matriz usando um valor entre colchetes com o [operador delete](../../cpp/delete-operator-cpp.md). O valor será ignorado.  
  
```  
// C4208.cpp  
// compile with: /W4  
int main()  
{  
   int * MyArray = new int[18];  
   delete [18] MyArray;      // C4208  
   MyArray = new int[18];  
   delete [] MyArray;        // ok  
}  
```  
  
 Esses valores são inválidos em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).