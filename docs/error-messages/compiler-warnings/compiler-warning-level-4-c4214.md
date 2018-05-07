---
title: Compilador (nível 4) de aviso C4214 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4214
dev_langs:
- C++
helpviewer_keywords:
- C4214
ms.assetid: 9b8db279-1f12-4a6b-a923-2db22acd1947
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0efe0666ded5428dcc40a1900f263cfc522a1502
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4214"></a>Compilador C4214 de aviso (nível 4)
extensão não padrão usada: tipos diferentes de int de campo de bits  
  
 Com as extensões do Microsoft padrão (/Ze), os membros de estrutura de campo de bits podem ser de qualquer tipo de inteiro.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4214.c  
// compile with: /W4  
struct bitfields  
{  
   unsigned short j:4;  // C4214  
};  
  
int main()  
{  
}  
```  
  
 Esses campos de bit são inválidos em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).