---
title: "Compilador aviso (nível 3) C4290 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4290
dev_langs:
- C++
helpviewer_keywords:
- C4290
ms.assetid: d1c6d85b-28e0-4a1f-9d48-23593337a6fb
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f70a278cb3e660e89e1aba067cab9c20aacf8f62
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4290"></a>Compilador C4290 de aviso (nível 3)
Especificação de exceção de C++ ignorada exceto to indicar que a função não é nothrow  
  
 Uma função é declarada usando a especificação de exceção, que aceita do Visual C++, mas não implementa. Código com a exceção especificações são ignoradas durante a compilação precisa ser recompilado e vinculado para ser reutilizado em futuras versões com suporte de especificações de exceção.  
  
 Para obter mais informações, consulte [especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md) .  
  
 Você pode evitar esse aviso usando o [aviso](../../preprocessor/warning.md) pragma:  
  
```  
#pragma warning( disable : 4290 )  
```  
  
 O exemplo de código a seguir gera C4290:  
  
```  
// C4290.cpp  
// compile with: /EHs /W3 /c  
void f1(void) throw(int) {}   // C4290  
  
// OK  
void f2(void) throw() {}  
void f3(void) throw(...) {}  
```