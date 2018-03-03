---
title: "Compilador (nível 4) de aviso C4214 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4214
dev_langs:
- C++
helpviewer_keywords:
- C4214
ms.assetid: 9b8db279-1f12-4a6b-a923-2db22acd1947
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 46df65f9e920eae788088d9e4ec219b6bf93e96f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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