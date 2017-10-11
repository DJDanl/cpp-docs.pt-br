---
title: Erro fatal C1018 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1018
dev_langs:
- C++
helpviewer_keywords:
- C1018
ms.assetid: 2ceb8a99-30b2-4b80-bf42-e9f3305b3c52
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 4bab21cfcdbc0336e7485055c989314fa3710e8f
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1018"></a>Erro fatal C1018
#elif inesperado  
  
 O `#elif` diretiva aparece fora de um `#if`, `#ifdef`, ou `#ifndef` construir. Use `#elif` apenas dentro de uma dessas construções.  
  
 O exemplo a seguir gera C1018:  
  
```  
// C1018.cpp  
#elif      // C1018  
#endif  
  
int main() {}  
```  
  
 Possível solução:  
  
```  
// C1018b.cpp  
#if 1  
#elif  
#endif  
  
int main() {}  
```
