---
title: Compilador aviso (nível 3) C4290 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4290
dev_langs:
- C++
helpviewer_keywords:
- C4290
ms.assetid: d1c6d85b-28e0-4a1f-9d48-23593337a6fb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f03d35e1a3756979d8936647255e2b65afef56d9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33289887"
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