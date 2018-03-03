---
title: C2878 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2878
dev_langs:
- C++
helpviewer_keywords:
- C2878
ms.assetid: 83ee3de1-f554-49e8-a840-1f550cee7f69
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b050a77b944f4eee5bc26f8c9e8a84519b6e9d6e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2878"></a>C2878 de erro do compilador
'name': um namespace ou classe com este nome não existe  
  
 Você fez referência a um namespace ou classe que não está definido.  
  
 O exemplo a seguir gera C2878:  
  
```  
// C2878.cpp  
// compile with: /c  
namespace A {}  
namespace B = C;   // C2878 namespace C doesn't exist  
namespace B = A;   
```