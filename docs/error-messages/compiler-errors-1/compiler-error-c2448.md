---
title: C2448 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2448
dev_langs:
- C++
helpviewer_keywords:
- C2448
ms.assetid: e255df3c-f861-4b4d-a193-8768cef061a5
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: f289baff628ad2139940f023de36b7f936775b61
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2448"></a>C2448 de erro do compilador
'Identificador': inicializador function-style parece ser uma definição de função  
  
 A definição da função está incorreta.  
  
 Esse erro pode ser causado por uma lista formal de linguagem C de estilo antigo.  
  
 O exemplo a seguir gera C2448:  
  
```  
// C2448.cpp  
void func(c)  
   int c;  
{}   // C2448  
```
