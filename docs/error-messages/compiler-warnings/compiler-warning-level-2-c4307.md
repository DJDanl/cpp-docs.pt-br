---
title: Compilador (nível 2) do aviso C4307 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4307
dev_langs:
- C++
helpviewer_keywords:
- C4307
ms.assetid: 7cca11e9-be61-49e4-8b15-88b84f0cbf07
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 52914fc5825bda5647308c006b853538f3d6225e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33292026"
---
# <a name="compiler-warning-level-2-c4307"></a>Compilador C4307 de aviso (nível 2)
'operator': estouro de constante integral  
  
 O operador é usado em uma expressão que resulta em uma constante inteira ultrapassar os limites de espaço alocado para ele. Talvez seja necessário usar um tipo maior para a constante. Um **assinado int** contém um valor menor que um `unsigned int` porque o **assinado int** usa um bit para representar o logon.  
  
 O exemplo a seguir gera C4307:  
  
```  
// C4307.cpp  
// compile with: /W2  
int i = 2000000000 + 2000000000;   // C4307  
int j = (unsigned)2000000000 + 2000000000;   // OK  
  
int main()  
{  
}  
```