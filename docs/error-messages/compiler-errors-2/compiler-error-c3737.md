---
title: C3737 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3737
dev_langs: C++
helpviewer_keywords: C3737
ms.assetid: ca2aeb23-2491-4ccb-8838-884abf7065c8
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: af179d622ffe8354352cc6b87ab009b825e55b36
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3737"></a>C3737 de erro do compilador
'delegate': um delegate não deve possuir uma convenção de chamada explícita  
  
 Não é possível especificar o [convenção de chamada](../../cpp/calling-conventions.md) para um `delegate`.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3737:  
  
```  
// C3737a.cpp  
// compile with: /clr  
delegate void __stdcall MyFunc();   // C3737  
// Try the following line instead.  
// delegate void MyFunc();  
  
int main() {  
}  
```  
