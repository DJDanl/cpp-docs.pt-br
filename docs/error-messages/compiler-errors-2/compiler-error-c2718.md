---
title: C2718 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2718
dev_langs:
- C++
helpviewer_keywords:
- C2718
ms.assetid: 78cc71f8-c142-46fc-9aed-970635d74f0c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c1428ce92cb3523c231c0afe4901a21523891da1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2718"></a>C2718 de erro do compilador
'parameter': parâmetro real com __declspec(align('#')) não alinhado  
  
 O [alinhar](../../cpp/align-cpp.md) `__declspec` modificador não é permitido em parâmetros de função.  
  
 O exemplo a seguir gera C2718:  
  
```  
// C2718.cpp  
typedef struct __declspec(align(32)) AlignedStruct  {   
   int i;   
} AlignedStruct;  
  
void f2(int i, ...);  
  
void f4() {  
   AlignedStruct as;  
  
   f2(0, as);   // C2718, actual parameter is aligned  
}  
```