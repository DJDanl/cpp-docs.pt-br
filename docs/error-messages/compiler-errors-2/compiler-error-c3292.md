---
title: C3292 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3292
dev_langs:
- C++
helpviewer_keywords:
- C3292
ms.assetid: ead485cc-5471-4e10-b361-300589ff5b70
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b5bad02a4c7eae9a30855596ccb1695430c4f15e
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3292"></a>C3292 de erro do compilador
o namespace cli não pode ser reaberto  
  
 O namespace cli não pode ser declarado em seu código.  Para obter mais informações, consulte [plataforma, padrão e cli Namespaces](../../windows/platform-default-and-cli-namespaces-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3292.  
  
```  
// C3292.cpp  
// compile with: /clr /c  
namespace cli {};   // C3292  
```
