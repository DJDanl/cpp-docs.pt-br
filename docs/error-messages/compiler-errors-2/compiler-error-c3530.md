---
title: C3530 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3530
dev_langs: C++
helpviewer_keywords: C3530
ms.assetid: 21be81ce-b699-4c74-81bc-80a0c34d2d5a
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 0d66e76fc3e44a037f52aa6e217fae848f1338d2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3530"></a>C3530 de erro do compilador
'auto' não pode ser combinado com nenhum outro especificador de tipo  
  
 Um especificador de tipo é usado com o `auto` palavra-chave.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Não use um especificador de tipo em uma declaração de variável que usa o `auto` palavra-chave.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3530 porque variável `x` é declarada com ambos os `auto` palavra-chave e tipo `int`, e como o exemplo é compilado com **/ZC: auto**.  
  
```  
// C3530.cpp  
// Compile with /Zc:auto  
int main()  
{  
   auto int x;   // C3530  
   return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Palavra-chave auto](../../cpp/auto-keyword.md)