---
title: C3209 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3209
dev_langs:
- C++
helpviewer_keywords:
- C3209
ms.assetid: 1de44e39-69d1-4894-8f89-ff92136e8e5d
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 99cffcf55850035bc114c5b158ad3fde304234f0
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3209"></a>C3209 de erro do compilador
'class': classe genérica deve ser gerenciada ou WinRTclass  
  
 Uma classe genérica deve ser uma classe gerenciada ou uma classe de tempo de execução do Windows.  
  
 O exemplo a seguir gera C3209 e mostra como corrigi-lo:  
  
```  
// C3209.cpp  
// compile with: /clr  
generic <class T>  
class C {};   // C3209  
  
// OK - ref class can be generic  
generic <class T>  
ref class D {};  
```
