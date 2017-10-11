---
title: C2479 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2479
dev_langs:
- C++
helpviewer_keywords:
- C2479
ms.assetid: c74c7869-e65b-4ca1-b6fa-eb39fed4458a
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: fef1f43a82d039377b3259ae06cd9650a3cc9db4
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2479"></a>C2479 de erro do compilador
'Identificador': 'allocate ()' só é válido para itens de dados de extensão static  
  
 O `__declspec( allocate())` sintaxe pode ser usada para dados estáticos somente.  
  
 O exemplo a seguir gera C2479:  
  
```  
// C2479.cpp  
// compile with: /c  
#pragma section("mycode", read)  
static __declspec(allocate("mycode")) void DoNothing() {}   // C2479  
__declspec(allocate("mycode"))  int i = 0;   // OK  
```
