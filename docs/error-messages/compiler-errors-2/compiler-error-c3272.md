---
title: C3272 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3272
dev_langs:
- C++
helpviewer_keywords:
- C3272
ms.assetid: 7cdf254d-f207-4116-a1bf-7386f3b82a6f
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 8447e7eb07cea90da5076fa2c7bf6fe950baf5e5
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3272"></a>C3272 de erro do compilador
'symbol': símbolo requer FieldOffset, porque ele é um membro de tipo typename definida com StructLayout(LayoutKind::Explicit)  
  
Quando `StructLayout(LayoutKind::Explicit)` está em vigor, os campos devem ser marcados com `FieldOffset`.  
  
O exemplo a seguir gera C3272:  
  
```  
// C3272_2.cpp  
// compile with: /clr /c  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
[StructLayout(LayoutKind::Explicit)]  
ref struct X  
{  
   int data_;   // C3272  
   // try the following line instead  
   // [FieldOffset(0)] int data_;  
};  
```  

