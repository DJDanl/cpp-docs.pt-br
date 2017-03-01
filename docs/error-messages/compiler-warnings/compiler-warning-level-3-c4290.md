---
title: "Compilador aviso (nível 3) C4290 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4290
dev_langs:
- C++
helpviewer_keywords:
- C4290
ms.assetid: d1c6d85b-28e0-4a1f-9d48-23593337a6fb
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 930e95da2f726e7aeda8e80055a857c1410265da
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4290"></a>Compilador C4290 de aviso (nível 3)
especificação de exceção de C++ ignorada exceto para indicar que a função não é __declspec(nothrow)  
  
 Uma função é declarada usando a especificação de exceção, que o Visual C++ aceita, mas não implementa. Código de exceção especificações que são ignoradas durante a compilação podem precisar ser recompilado e vinculado para ser reutilizado em futuras versões com suporte a especificações de exceção.  
  
 Para obter mais informações, consulte [especificações de exceção (acionar)](../../cpp/exception-specifications-throw-cpp.md) .  
  
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
