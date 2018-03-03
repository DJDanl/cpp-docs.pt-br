---
title: C2042 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2042
dev_langs:
- C++
helpviewer_keywords:
- C2042
ms.assetid: e111788f-41ce-405a-9824-a4c1c26059e6
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 583c813c2fe3eeca5372954c5ba547531093fe6d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2042"></a>C2042 de erro do compilador
conectado/unsigned palavras-chave mutuamente exclusivas  
  
 As palavras-chave `signed` e `unsigned` são usados em uma única declaração.  
  
 O exemplo a seguir gera C2042:  
  
```  
// C2042.cpp  
unsigned signed int i;   // C2042  
```  
  
 Possível solução:  
  
```  
// C2042b.cpp  
// compile with: /c  
unsigned int i;  
signed int ii;  
```