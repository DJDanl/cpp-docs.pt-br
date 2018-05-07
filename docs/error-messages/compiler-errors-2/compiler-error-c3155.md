---
title: C3155 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3155
dev_langs:
- C++
helpviewer_keywords:
- C3155
ms.assetid: b04a42e1-64e7-40f8-81fe-c7945348b2cf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 383727d6f1665544654c047f37f094a38d6b5309
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3155"></a>C3155 de erro do compilador
atributos não são permitidos em um indexador de propriedades  
  
Uma propriedade indexada foi declarada incorretamente. Para obter mais informações, consulte [como: usar propriedades no C + + CLI](../../dotnet/how-to-use-properties-in-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3155.  
  
```  
// C3155.cpp  
// compile with: /clr /c  
using namespace System;  
ref struct R {  
   property int F[[ParamArray] int] {   // C3155  
   // try the following line instead  
   // property int F[ int] {   // OK  
      int get(int i) {   
         return 0;   
      }  
   }  
};  
```