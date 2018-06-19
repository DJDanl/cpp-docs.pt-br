---
title: C2571 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2571
dev_langs:
- C++
helpviewer_keywords:
- C2571
ms.assetid: c6522616-dee9-4d7d-9bf8-30a7e1deaadf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 96dea582cf5d1211d57eac94a7f70458a51542ae
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33230760"
---
# <a name="compiler-error-c2571"></a>C2571 de erro do compilador
'function': função virtual não pode estar em union 'union'  
  
 Uma união é declarada com uma função virtual. Você pode declarar uma função virtual somente em uma classe ou estrutura.  Possíveis resoluções:  
  
1.  Altere a união de uma classe ou estrutura.  
  
2.  Torna a função não virtual.  
  
 O exemplo a seguir gera C2571:  
  
```  
// C2571.cpp  
// compile with: /c  
union A {  
   virtual void func1();   // C2571  
   void func2();   // OK  
};  
```