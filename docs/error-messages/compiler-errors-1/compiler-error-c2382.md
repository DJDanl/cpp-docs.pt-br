---
title: C2382 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2382
dev_langs:
- C++
helpviewer_keywords:
- C2382
ms.assetid: 4d4436f9-d0d6-4bd0-b8ec-767b89adfb2f
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 28107642008aba7d71365306eae4646fb3f01318
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2382"></a>C2382 de erro do compilador
'function': redefinição; especificações de exceção diferente  
  
 Em [/Za](../../build/reference/za-ze-disable-language-extensions.md), esse erro indica que uma sobrecarga de função foi tentada somente o [especificação de exceção](../../cpp/exception-specifications-throw-cpp.md).  
  
 O exemplo a seguir gera C2382:  
  
```  
// C2382.cpp  
// compile with: /Za /c  
void f1(void) throw(int) {}  
void f1(void) throw(char) {}   // C2382  
void f2(void) throw(char) {}   // OK  
```
