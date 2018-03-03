---
title: C2341 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2341
dev_langs:
- C++
helpviewer_keywords:
- C2341
ms.assetid: aa2a7da5-e1c8-4225-9939-5bdc50158f31
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 03ceeb7f34ca7aca58151174c327161b18f3678f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2341"></a>C2341 de erro do compilador
'nome da seção': segmento deve ser definido usando #pragma data_seg, code_seg ou section antes de usar  
  
 Um [alocar](../../cpp/allocate.md) declaração se refere a um segmento que ainda não foi definido por [code_seg](../../preprocessor/code-seg.md), [data_seg](../../preprocessor/data-seg.md), ou [seção](../../preprocessor/section.md) pragmas.  
  
 O exemplo a seguir gera C2341:  
  
```  
// C2341.cpp  
// compile with: /c  
__declspec(allocate(".test"))   // C2341  
int j = 1;  
```  
  
 Possível solução:  
  
```  
// C2341b.cpp  
// compile with: /c  
#pragma data_seg(".test")  
__declspec(allocate(".test"))  
int j = 1;  
```