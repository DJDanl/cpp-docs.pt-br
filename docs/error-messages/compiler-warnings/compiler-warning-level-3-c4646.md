---
title: "Compilador aviso (nível 3) C4646 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4646
dev_langs:
- C++
helpviewer_keywords:
- C4646
ms.assetid: 23677e8e-603e-40e0-b99a-2e4894a1278e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9b44b85fc8834dcc262b10ee26f34752f8eeb429
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4646"></a>Compilador C4646 de aviso (nível 3)
função declarada com __declspec(noreturn) tem o tipo de retorno não void  
  
 Uma função é marcada com o [noreturn](../../cpp/noreturn.md) `__declspec` modificador deve ter uma [void](../../cpp/void-cpp.md) tipo de retorno.  
  
 O exemplo a seguir gera C4646:  
  
```  
// C4646.cpp  
// compile with: /W3 /WX  
int __declspec(noreturn) TestFunction()  
{   // C4646  make return type void  
}  
```